#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"XJ_Convertor.h"   
int main (int argc,char const *argv[])
{
	
	int failed = 0;

	if(!verifInputCommande(argc,argv)){
		printf("Syntax Error : Veuillez renseigner l'option -i [-i xml/json]\n");
		failed=1;
	}
	if(!verifInputCommande(argc,argv)){
		printf("Syntax Error : Veuillez renseigner l'option -f [-f fichier_input]\n");
		failed=1;
    }
   if(!verifInputCommande(argc,argv)){
		printf("Syntax Error : Veuillez renseigner l'option -h [-h url_Http]\n");
		failed=1;
    }

	if(!failed){
		FILE* file = NULL;
		file = fopen(getName(argc,argv),"w+");
		printf("Bravo vous avez avez reussit\n");
		if(verifTrace(argc,argv)){
			printf("Vous avez decider d'afficher la trace !"); 
		}
		else{
			printf("Oups vous n'avez pas defini la trace !\n");
		}
		
	}
	return 0;
 }
 
 
