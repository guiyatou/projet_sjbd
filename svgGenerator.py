import svgwrite
import json_extraction
import sys
import XJ_Convertor

def drowMySvgFile(svgFile,extractedData):
    try:

        entities = extractedData["allEntities"]
        dwg = svgwrite.Drawing(svgFile, profile='tiny')
        entityCoordsList = []
        x=18
        y=15
        i=0
        for entity in entities:
            attributes = extractedData[entity]["attributes"]
            print("\t {}".format(attributes))
            
            previewX = x
            previewY = y

            dwg.add(dwg.line((0, 0), (0, 200), stroke=svgwrite.rgb(10, 10, 16, '%')))
            dwg.add(dwg.text(entity, insert=(x, y), fill='black'))
        for attribute in attributes:
            previewY+=30
            dwg.add(dwg.text(attribute, insert=(x, previewY), fill='black'))
            x+=300
        if (i % 2 == 0):
        # Creation du rectangle contenant les infos de l'entite
            dwg.add(dwg.rect(insert = (10, i*150 + 10),
                            size = ("150px", "130px"),
                            stroke_width = "1",
                            stroke = "black",
                            fill = "rgb(46, 250, 99)"))

            entityCoords = {   
              "nomEntite": entity,
              "previewX" : 10,
              "previewY" : i*150 + 10
            }

            entityCoordsList.append(entityCoords)          

            dwg.add(dwg.rect(insert = (10, i*150 + 10),
                            size = ("150px", "26px"),
                            stroke_width = "1",
                            stroke = "black",
                            fill = "rgb(46, 250, 99)"))
        
            # Affichage du nom de l'entité
            dwg.add(dwg.text(entity,
                            insert=(20, i*150 + 30),
                            stroke='none',
                            fill="rgb(42, 42, 42)",
                            font_size='15px',
                            font_weight="bold")
            )

            # Affichage de la liste des attributs
            for k in range(len(attribute)):
                dwg.add(dwg.text(attribute[k],
                                insert=(20, i*150 + 40 + (k+1)*20),
                                stroke='none',
                                fill="rgb(15, 15, 15)",
                                font_size='15px',
                                font_weight="bold")
                )
        else:
            # Creation du rectangle contenant les infos de l'entité
            dwg.add(dwg.rect(insert = (400, (i - 1)*150 + 10),
                            size = ("150px", "130px"),
                            stroke_width = "1",
                            stroke = "black",
                            fill = "rgb(46, 250, 99)"))

            entityCoords = {
                "nomEntite": entity,
                "coordX": 400,
                "coordY": (i - 1)*150 + 10
            }
            entityCoordsList.append(entityCoords)

            dwg.add(dwg.rect(insert = (400, (i - 1)*150 + 10),
                            size = ("150px", "26px"),
                            stroke_width = "1",
                            stroke = "black",
                            fill = "rgb(46, 250, 99)")
            )

            # Affichage du nom de l'entité
            dwg.add(dwg.text(entity,
                    insert=(410, (i - 1)*150 + 30),
                    stroke='none',
                    fill="rgb(15, 15, 15)",
                    font_size='15px',
                    font_weight="bold")
            )

            # Affichage de la liste des attributs
            for k in range(len(attribute)):
                          dwg.add(dwg.text(attribute[k],
                          insert=(410, (i - 1)*150 + 40 + (k+1)*20),
                          stroke='none',
                          fill="rgb(15, 15, 15)",
                          font_size='15px',
                          font_weight="bold"))
        dwg.save()
        print("\n\t\tFichier svg genere avec succes\n")
    except Exception as errors:
        print("Echec de la creation du fichier {}".format(errors))   
        sys.exit(1)               