#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h >
int main()
{    xmlDocPtr doc;
    xmlNodePtr racine;
    xmlNodePtr racinee;
    //ouverture du fichier xml
    doc = xmlParseFile("fc.xml");
    if (doc == NULL)
    {
        fprintf(stderr,"le document XML est invalide \n");

    }
    else{
        fprintf(stderr " le document XML est valide\n");
    }

    return 0;
}
