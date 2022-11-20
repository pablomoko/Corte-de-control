#include <stdlib.h>
#include <stdio.h>
#include "funciones_archivo.h"

status_t abrir_archivo_lectura(FILE **archivo,const char *nombre_archivo){
	
    if(nombre_archivo == NULL || archivo == NULL){
		return ERROR_NULL_POINTER;
	}
	
    if((*archivo=fopen(nombre_archivo,"rt"))==NULL){
		return ERROR_NO_FILE;
	}
	return OK;
}
status_t abrir_archivo_escritura(FILE **archivo,const char *nombre_archivo){
	
    if(nombre_archivo == NULL || archivo == NULL){
		return ERROR_NULL_POINTER;
	}
	
    if((*archivo=fopen(nombre_archivo,"wt"))==NULL){
		return ERROR_NO_FILE;
	}
	return OK;
}
status_t cerrar_archivo(FILE **archivo){

    if (archivo == NULL){
        return ERROR_NULL_POINTER;
    }
    
	if((fclose(*archivo))!=0){
		return ERROR_CLOSING_FILE;
	}
	*archivo=NULL;

	return OK;
}
status_t destruir_archivo(FILE **archivo,const char *nombre_archivo){

    status_t st;

    if (archivo == NULL || nombre_archivo == NULL){
        return ERROR_NULL_POINTER;
    }
    if((st = cerrar_archivo(archivo))!=OK){
        return st;
    }

    remove(nombre_archivo);

    return OK;
}
bool_t archivo_corrupto(unsigned int len){

    return (len < MAX_CAMPOS) ? TRUE :FALSE;
    
}