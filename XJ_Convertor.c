#include<stdio.h>
#include<stdlib.h
#include<string.h>
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
}
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
int main(int argc,char const *argv[])
{
	
	int failed = 0;
	if(!verifInputCommande(argc,argv)){
		printf("Syntax Error : Veuillez renseinger l'option -i [-i xml/json]\n");
		failed=1;
	}
	if(!verifOutputCommande(argc,argv)){
		printf("Syntax Error : Veuillez renseinger l'option -o [-o nomfichier.svg]\n");
		failed=1;
	}

	if(!failed){
		FILE* file = NULL;
		file = fopen(getName(argc,argv),"w+");
		printf("Bravo vous avez avez reussit\n");
		if(verifTrace(argc,argv)){
			printf("Vous avez decider d'afficher la trace !");
		}else{
			printf("Oups vous n'avez pas defini la trace !\n");
		}
	}
	return 0;
}
