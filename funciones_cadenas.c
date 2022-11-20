#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones_cadenas.h"

status_t leer_linea(string * s, bool_t * eof,FILE* infile){
    size_t alloc_size, used_size;
    char * aux_id;
    int c;

    if (s == NULL || eof == NULL || infile == NULL)
        return ERROR_NULL_POINTER;

    if ((*s = malloc(INIT_CHOP)) == NULL)
        return ERROR_MEMORY;
    alloc_size = INIT_CHOP;
    used_size = 0;


    while ((c = fgetc(infile)) != LF ){

        if (used_size == alloc_size - 1){
            if ((aux_id = realloc(*s,alloc_size + CHOP_SIZE)) == NULL){
                free(*s);
                *s = NULL;
                return ERROR_MEMORY;
            }
            *s = aux_id;
            alloc_size += CHOP_SIZE;
        }
        (*s)[used_size++] = c;

    (*s)[used_size] = NUL;
    (*eof) = (c == EOF) ? TRUE : FALSE;

        if (c == EOF){
        break;
        }
    }

    return OK;
}
string * parsear_linea(string src, char delim, size_t *len){
    string *arr;	
    char   *p, *q;	
    char    tokens[2];	
    size_t i;	
    string line;

    if (src == NULL || len == NULL){	
            return NULL;
    }    

    tokens[0] = delim;	
    tokens[1] = '\0';

    if ((duplicar_cadena(&line,src)) != OK){		
        *len = 0;		
        return NULL;	
    } 

    for (i = 0, *len = 1; line[i]; i++){		
        if (line[i] == delim){
        (*len)++;
        }		
    }

    if ((arr = (string *) malloc( (*len) * sizeof(string))) == NULL){		
        *len = 0;		
        free(line);		
        return NULL;	
    }	
            
    for ( q = line, i=0; (p = strtok(q,tokens)) != NULL; q = NULL, i++){	
    
        if (duplicar_cadena(&arr[i],p)!= OK){
            destruir_cadena(arr,i);			
            free(line);			
            *len = 0;			
            return NULL;	     
        }	
    }	

        free(line);
        return arr;
}
status_t destruir_cadena(char* *arr,size_t len){

    size_t j;

    if (arr == NULL){
        return ERROR_NULL_POINTER;
    }
    for ( j = 0; j < len; j++){
        free(arr[j]);
        arr[j]= NULL;
    }
    return OK;
}
status_t duplicar_cadena(char **ss, const char *s){

	if(s == NULL || ss == NULL)
		return ERROR_NULL_POINTER;

	*ss = (char *) malloc(sizeof(char) * (strlen(s)+1));

	if(*ss == NULL)
		return ERROR_OUT_OF_MEMORY;

	strcpy(*ss, s);

	return OK;
}

