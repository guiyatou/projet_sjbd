#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"JSON_checker.h"
/*creation de la commande pour
les fichiers d'entrees*/           
int verifInputCommande(int argc,char const *argv[]){
	int i;
	for (i = 1; i < argc ; i++)
	{ 		
		if(strcmp("-i",argv[i])==0){
            if(i+1<argc){
            	if(strcmp("xml",argv[i+1])==0 ){
            
           		return 1;
            	}else if (strcmp("json",argv[i+1])==0){
            		return 2;
            	}
            }
		}  
	}
	return 0;
}/*creation de la commande qui permet de
decider si on veut afficher les traces ou pas*/
int verifTrace(int argc,char const *argv[]){
	int i;
	for (i = 1; i < argc ; i++)
	{
		if(strcmp("-t",argv[i])==0){
            return 1;
		}
	}
	return 0;
 }
 /*creation de la commande pour les fichier
 de sorties*/
int verifOutputCommande(int argc,char const *argv[]){
int i;
int t;
	for (i = 1; i < argc ; i++)
	{
		if(strcmp("-o",argv[i])==0){
            if(i+1<argc){
            	t = strlen(argv[i+1]);
            	if(t>4){
            		
            		if(argv[i+1][t-1]=='g' && argv[i+1][t-2]=='v' && argv[i+1][t-3]=='s' && argv[i+1][t-4]=='.'){
            			return 1;
            		}
            	}
            }
		}
    }
       return 0;
}
char* getName(int argc,char const *argv[]){
	int i;
	for (i = 1; i < argc ; i++)
	{
		if(strcmp("-o",argv[i])==0){
			return (char *)argv[i+1];
        }
   	}
	return NULL;
}
	char* getFichier(int argc,char const *argv[]){
	int i;
	for (i = 1; i < argc ; i++)
	{
		if(strcmp("-f",argv[i])==0){
			return (char *)argv[i+1];
		}
	}
		return 0;
	}
char* getHttp(int argc,char const *argv[]){ 
	int i;
	for (i = 1; i < argc ; i++)
	{
		if(strcmp("-h",argv[i])==0){
			return (char *)argv[i+1];
		}
	}
      return 0;
}
