import requests
import json
import fjson

myJsonData = parsingXml.getEntites(XJ_Convertor.fjson)
relations = parsingXml.getRelations(XJ_Convertor.fjson)
listEntites = []
# Recuperation de la liste des entites
for entite in myJsonData:
    listEntites.append(entite)
# Recuperation de la liste des entités

for i in range(len(myJsonData)):
    for key in myJsonData[i].keys():
      listEntites.append(key)

# Recuperation des noms des entites que l'on enregistre dans la variable "listEntites"
i=0
entityCoordsList = []
for entite in myJsonData:
    listAttributs = []
    for key in myJsonData[entite]['attributs']:
        listAttributs.append(key)
entityCoordsList = []
# Recuperation des noms des entités que l'on enregistre dans la variable "listEntites"
print('Liste des entites et leurs attributs: ')
for i in range(len(listEntites)):
    listAttributs = []
    listAssocs = []

    # Recuperation des noms des attributs que l'on enregistre dans la variable "listAttributs"
    nbAttributs = len(myJsonData[i][listEntites[i]]['attributs'])
    print('\t' + listEntites[i])
    for j in range(nbAttributs):
        for key in myJsonData[i][listEntites[i]]['attributs'][j].keys():
            listAttributs.append(key)
print('\t\t' + key)


print(listEntites)
participants = []
for relation in relations:
    nomAssoc = relation
    for k in range(len(listEntites)):
        if listEntites[k] in relations[relation]['multiplicite']:
            cardDeb = relations[relation]['multiplicite'][listEntites[k]]
            firstEntity = listEntites[k]
            break
    for enfant in relations[relation]['multiplicite']:
        cardFin = relations[relation]['multiplicite'][enfant]
        secondEntity = enfant
# print entityCoordsList


for i in range(len(listEntites)):
    # Recuperations des differentes associations
    nbAssocs = len(myJsonData[i][listEntites[i]]['relations']['associations'])
    for j in range(nbAssocs):
            # for key in myJsonData[i][listEntites[i]]['relations']['associations'][j].keys():
            #     listAssocs.append(key)
            #     print(key)
            nomAutreEntite = myJsonData[i][listEntites[i]]['relations']['associations'][j]["nomAutreEntite"]
            cardDeb = myJsonData[i][listEntites[i]]['relations']['associations'][j]["cardDeb"]
            cardFin = myJsonData[i][listEntites[i]]['relations']['associations'][j]["cardFin"]
            nomAssoc = myJsonData[i][listEntites[i]]['relations']['associations'][j]["nomAssoc"]
