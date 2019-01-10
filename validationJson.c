

/* main.c */
/*
    This program demonstrates a simple application of JSON_checker. It reads
    a JSON text from STDIN, producing an error message if the text is rejected.

        % JSON_checker <test/pass1.json
*/

#include <stdlib.h>
#include <stdio.h>
#include "JSON_checker.h"

int main(int argc, char* argv[]) {
FILE* jsonfile;
	jsonfile=fopen(argv[1],"r");
    JSON_checker jc = new_JSON_checker(20);
    char file; 
    for (;;)  { 
    	file=fgetc(jsonfile);
			    if (file==EOF)
			    {
			    	break;
			    }
        
        if (!JSON_checker_char(jc,file)) {
            fprintf(stderr, "JSON_checker_char: syntax error\n");
            exit(1);
        }

 
 }
 if (!JSON_checker_done(jc)) {
        fprintf(stderr, "JSON_checker_end: syntax error\n");
        exit(1);


    }
      return 0;
}
