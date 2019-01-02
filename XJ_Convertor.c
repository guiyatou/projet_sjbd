#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JSON_checker.h"
/*inclusion des bibliotheques pour la validation des fichiers en xml*/
#include<libxml/parser.h>
#include<libxml/xmlschema.h>
//verification des parametres d'entrees
int verifInputCommande(int argc,char const *argv[]){
	int i;
	for (i = 1; i < argc ; i++)
	{
	   if(strcmp("-i",argv[i])==0){
              if(i+1<argc){
            	   if(strcmp("xml",argv[i+1])==0 ){//retourne 1 si c'est un fichier xml
            		return 1;
            	   }else if (strcmp("json",argv[i+1])==0){//retourne 2 si c'est un fichier json
            		return 2;
            	   }
               }
	    }
	}
	return 0;
}
//fonction pour verifier la trace
int verifTrace(int argc,char const *argv[]){
	int i;
	for (i = 1; i < argc ; i++)
	{
		if(strcmp("-t",argv[i])==0){//comparaison entre la iéme element et '-t'
            return 1;
		}
	}
	return 0;
}/*creation de la commande pour gerer les fichiers de
sorties*/
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
char* FichierInput(int argc,char const *argv[]){
	int i;
	for (i = 1; i < argc ; i++)
	{
		if(strcmp("-f",argv[i])==0){

                   return (char *)argv[i+1];
		}
	}
	return 0;
}
char* Input_http(int argc,char const *argv[]){
	int i;
	for (i = 1; i < argc ; i++)
	{
		if(strcmp("-h",argv[i])==0){
		  }	return (char *)argv[i+1];
		}
	}
	return 0 ;
}

enum{
error_occured=-1;// une erreur est survenue lors de la validation
not_valid=0;// le document n'est pas valide
valid=1;//le document est valide 
}
/*fonction de la validation d'un arbre DOM a l'aide de xml schema*/
	int validation_xmlschema(xmlDocPtr,doc const char *xml_schema , int afficher_erreurs);
	int ret;
	xmlschemaptr schema;
	xmlschemavalidCtxtPtr vctxt;
	xmlschemaparserCtxtPtr pctxt;
	//ouverture du fichier xml schema
	if((pctxt=xmlSchemaNewParserCtxt(xml_schema)==NULL){
		return ERROR_OCCURED;
	}
	//chargement du contenu xml shema
	shema= (pctxt);
	xmlSchemaFreeParserCtxtPtr(pctxt);
	if(shema==NULL){
		return ERROR_OCCURED;
	}
	//creation du contexte de validation
	if(vctx=xmlschemavalidCtxtPtr(shema)==NULL){
		xmlSchemaFree(schema);
		return ERROR_OCCURED;

	}
	//traitement des erreurs de validation
	if(afficher_erreurs){
		xmlschemaSetValidError(vctxt, (xmlSchemaValidityErrotFuncCtxtPtr) fprintf (xmlSchemaValidityWarningFuncCtxtPtr) fprintf (stderr));
	
	}
       //validation
	ret=(xmlschemavalidateDoc(vctxt doc))= 0? valid:not_valid);
		//liberation de la memoire
		xmlSchemaFree(shema);
		xmlSchemaFreeValidCtxt(vctxt);
		return ret;

}
int main(int argc,char const *argv[])
{
	
	int failed = 0;
	/*on verifie bien si le format xml ou json est bien formate*/
	if(!verifInputCommande(argc,argv)){
		printf("Syntax Error : Veuillez renseinger l'option -i [-i xml/json]\n");
		failed=1;
	}
	/*on verifie si le fichier de sortie est en svg*/
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
	int not_valid=0;
	if(!verifvalidation_shema( doc,xml_schema,afficher_erreurs ){
		printf("syntax error: le document n'est pas valide \n");
		not_valid=2;	
	}
	int ERROR_OCCURED=-1;
	if(!verifvalidation_shema( doc,xml_schema,afficher_erreurs ){
		printf("error: une erreur est survenue lors de la validation);
		       ERROR_OCCURED=2;
		       }
		       

#define TRUE  1
#define FALSE 0
#define GOOD 0xBABAB00E
#define __   -1     /* */

/*
*/

enum classes {
    C_SPACE,  /*  */
    C_WHITE,  /* */
    C_LCURB,  /* {  */
    C_RCURB,  /* } */
    C_LSQRB,  /* [ */
    C_RSQRB,  /* ] */
    C_COLON,  /* : */
    C_COMMA,  /* , */
    C_QUOTE,  /* " */
    C_BACKS,  /* \ */
    C_SLASH,  /* / */
    C_PLUS,   /* + */
    C_MINUS,  /* - */
    C_POINT,  /* . */
    C_ZERO ,  /* 0 */
    C_DIGIT,  /* 123456789 */
    C_LOW_A,  /* a */
    C_LOW_B,  /* b */
    C_LOW_C,  /* c */
    C_LOW_D,  /* d */
    C_LOW_E,  /* e */
    C_LOW_F,  /* f */
    C_LOW_L,  /* l */
    C_LOW_N,  /* n */
    C_LOW_R,  /* r */
    C_LOW_S,  /* s */
    C_LOW_T,  /* t */
    C_LOW_U,  /* u */
    C_ABCDF,  /* ABCDF */
    C_E,      /* E */
    C_ETC,    /* */
    NR_CLASSES
};

static int ascii_class[128] = {
/**/
    
    __,      __,      __,      __,      __,      __,      __,      __,
    __,      C_WHITE, C_WHITE, __,      __,      C_WHITE, __,      __,
    __,      __,      __,      __,      __,      __,      __,      __,
    __,      __,      __,      __,      __,      __,      __,      __,

    C_SPACE, C_ETC,   C_QUOTE, C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_PLUS,  C_COMMA, C_MINUS, C_POINT, C_SLASH,
    C_ZERO,  C_DIGIT, C_DIGIT, C_DIGIT, C_DIGIT, C_DIGIT, C_DIGIT, C_DIGIT,
    C_DIGIT, C_DIGIT, C_COLON, C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,

    C_ETC,   C_ABCDF, C_ABCDF, C_ABCDF, C_ABCDF, C_E,     C_ABCDF, C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_LSQRB, C_BACKS, C_RSQRB, C_ETC,   C_ETC,

    C_ETC,   C_LOW_A, C_LOW_B, C_LOW_C, C_LOW_D, C_LOW_E, C_LOW_F, C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_ETC,   C_LOW_L, C_ETC,   C_LOW_N, C_ETC,
    C_ETC,   C_ETC,   C_LOW_R, C_LOW_S, C_LOW_T, C_LOW_U, C_ETC,   C_ETC,
    C_ETC,   C_ETC,   C_ETC,   C_LCURB, C_ETC,   C_RCURB, C_ETC,   C_ETC
};


/*

*/
enum states {
    GO,  /* start    */
    OK,  /* ok       */
    OB,  /* object   */
    KE,  /* key      */
    CO,  /* colon    */
    VA,  /* value    */
    AR,  /* array    */
    ST,  /* string   */
    ES,  /* escape   */
    U1,  /* u1       */
    U2,  /* u2       */
    U3,  /* u3       */
    U4,  /* u4       */
    MI,  /* minus    */
    ZE,  /* zero     */
    IN,  /* integer  */
    FR,  /* fraction */
    FS,  /* fraction */
    E1,  /* e        */
    E2,  /* ex       */
    E3,  /* exp      */
    T1,  /* tr       */
    T2,  /* tru      */
    T3,  /* true     */
    F1,  /* fa       */
    F2,  /* fal      */
    F3,  /* fals     */
    F4,  /* false    */
    N1,  /* nu       */
    N2,  /* nul      */
    N3,  /* null     */
    NR_STATES
};


static int state_transition_table[NR_STATES][NR_CLASSES] = {
/*
    

                 blanc                                      1-9                                   ABCDF  etc
             space |  {  }  [  ]  :  ,  "  \  /  +  -  .  0  |  a  b  c  d  e  f  l  n  r  s  t  u  |  E  |*/
/**/ {GO,GO,-6,__,-5,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/**/ {OK,OK,__,-8,__,-7,__,-3,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/**/ {OB,OB,__,-9,__,__,__,__,ST,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/**/ {KE,KE,__,__,__,__,__,__,ST,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/**/ {CO,CO,__,__,__,__,-2,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/**/ {VA,VA,-6,__,-5,__,__,__,ST,__,__,__,MI,__,ZE,IN,__,__,__,__,__,F1,__,N1,__,__,T1,__,__,__,__},
/**/ {AR,AR,-6,__,-5,-7,__,__,ST,__,__,__,MI,__,ZE,IN,__,__,__,__,__,F1,__,N1,__,__,T1,__,__,__,__},
/**/ {ST,__,ST,ST,ST,ST,ST,ST,-4,ES,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST,ST},
/**/ {__,__,__,__,__,__,__,__,ST,ST,ST,__,__,__,__,__,__,ST,__,__,__,ST,__,ST,ST,__,ST,U1,__,__,__},
/**/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,U2,U2,U2,U2,U2,U2,U2,U2,__,__,__,__,__,__,U2,U2,__},
/*u2     U2*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,U3,U3,U3,U3,U3,U3,U3,U3,__,__,__,__,__,__,U3,U3,__},
/*u3     U3*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,U4,U4,U4,U4,U4,U4,U4,U4,__,__,__,__,__,__,U4,U4,__},
/*u4     U4*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,ST,ST,ST,ST,ST,ST,ST,ST,__,__,__,__,__,__,ST,ST,__},
/*  */ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,ZE,IN,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/**/ {OK,OK,__,-8,__,-7,__,-3,__,__,__,__,__,FR,__,__,__,__,__,__,E1,__,__,__,__,__,__,__,__,E1,__},
/*    IN*/ {OK,OK,__,-8,__,-7,__,-3,__,__,__,__,__,FR,IN,IN,__,__,__,__,E1,__,__,__,__,__,__,__,__,E1,__},
/*   FR*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,FS,FS,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/*  */ {OK,OK,__,-8,__,-7,__,-3,__,__,__,__,__,__,FS,FS,__,__,__,__,E1,__,__,__,__,__,__,__,__,E1,__},
/*     E1*/ {__,__,__,__,__,__,__,__,__,__,__,E2,E2,__,E3,E3,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/*     E2*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,E3,E3,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/*   E3*/ {OK,OK,__,-8,__,-7,__,-3,__,__,__,__,__,__,E3,E3,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/*tr     T1*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,T2,__,__,__,__,__,__},
/*    T2*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,T3,__,__,__},
/*true   T3*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,OK,__,__,__,__,__,__,__,__,__,__},
/*    F1*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,F2,__,__,__,__,__,__,__,__,__,__,__,__,__,__},
/*f    F2*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,F3,__,__,__,__,__,__,__,__},
/*   F3*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,F4,__,__,__,__,__},
/* */ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,OK,__,__,__,__,__,__,__,__,__,__},
/*    N1*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,N2,__,__,__},
/*    N2*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,N3,__,__,__,__,__,__,__,__},
/*   N3*/ {__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,OK,__,__,__,__,__,__,__,__}
};


/*
    
*/
enum modes {
    MODE_ARRAY,
    MODE_DONE,
    MODE_KEY,
    MODE_OBJECT
};

static void
destroy(JSON_checker jc)
{
/*
    .
*/
    jc->valid = 0;
    free((void*)jc->stack);
    free((void*)jc);
}


static int
reject(JSON_checker jc)
{
/*
    
*/
    destroy(jc);
    return FALSE;
}


static int
push(JSON_checker jc, int mode)
{
/*

*/
    jc->top += 1;
    if (jc->top >= jc->depth) {
        return FALSE;
    }
    jc->stack[jc->top] = mode;
    return TRUE;
}


static int
pop(JSON_checker jc, int mode)
{
/*
*/
    if (jc->top < 0 || jc->stack[jc->top] != mode) {
        return FALSE;
    }
    jc->top -= 1;
    return TRUE;
}


JSON_checker
new_JSON_checker(int depth)
{
/*
*/
    JSON_checker jc = (JSON_checker)malloc(sizeof(struct JSON_checker_struct));
    jc->valid = GOOD;
    jc->state = GO;
    jc->depth = depth;
    jc->top = -1;
    jc->stack = (int*)calloc(depth, sizeof(int));
    push(jc, MODE_DONE);
    return jc;
}


int
JSON_checker_char(JSON_checker jc, int next_char)
{
/*

*/
    int next_class, next_state;
/*
  
*/
    if (jc->valid != GOOD) {
        return FALSE;
    }
    if (next_char < 0) {
        return reject(jc);
    }
    if (next_char >= 128) {
        next_class = C_ETC;
    } else {
        next_class = ascii_class[next_char];
        if (next_class <= __) {
            return reject(jc);
        }
    }
/*
    */
    next_state = state_transition_table[jc->state][next_class];
    if (next_state >= 0) {
/*
  
*/
        jc->state = next_state;
/*
    
*/
    } else {
        switch (next_state) {
/*  } */
        case -9:
            if (!pop(jc, MODE_KEY)) {
                return reject(jc);
            }
            jc->state = OK;
            break;

/* } */ case -8:
            if (!pop(jc, MODE_OBJECT)) {
                return reject(jc);
            }
            jc->state = OK;
            break;

/* ] */ case -7:
            if (!pop(jc, MODE_ARRAY)) {
                return reject(jc);
            }
            jc->state = OK;
            break;

/* { */ case -6:
            if (!push(jc, MODE_KEY)) {
                return reject(jc);
            }
            jc->state = OB;
            break;

/* [ */ case -5:
            if (!push(jc, MODE_ARRAY)) {
                return reject(jc);
            }
            jc->state = AR;
            break;

/* " */ case -4:
            switch (jc->stack[jc->top]) {
            case MODE_KEY:
                jc->state = CO;
                break;
            case MODE_ARRAY:
            case MODE_OBJECT:
                jc->state = OK;
                break;
            default:
                return reject(jc);
            }
            break;

/* , */ case -3:
            switch (jc->stack[jc->top]) {
            case MODE_OBJECT:
/*
    
*/
                if (!pop(jc, MODE_OBJECT) || !push(jc, MODE_KEY)) {
                    return reject(jc);
                }
                jc->state = KE;
                break;
            case MODE_ARRAY:
                jc->state = VA;
                break;
            default:
                return reject(jc);
            }
            break;

/* : */ case -2:
/*
.
*/
            if (!pop(jc, MODE_KEY) || !push(jc, MODE_OBJECT)) {
                return reject(jc);
            }
            jc->state = VA;
            break;
/*
    
*/
        default:
            return reject(jc);
        }
    }
    return TRUE;
}


int
JSON_checker_done(JSON_checker jc)
{
/*
    
*/
    if (jc->valid != GOOD) {
        return FALSE;
    }
    int result = jc->state == OK && pop(jc, MODE_DONE);
    destroy(jc);
    return result;
}

	return 0;
}
