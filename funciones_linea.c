#include "funciones_linea.h"

status_t saltar_linea(FILE* infile,bool_t * eof){

    status_t st;
    string str;

    if ((st = leer_linea(&str,eof,infile)) != OK){  
        fclose(infile);
        return st;
    }
    
    if (*eof == TRUE){  
        free(str);
        return ERROR_CORRUPT_FILE;
    }    

    free(str);
    str = NULL;

    return OK;    
}    
status_t procesar_linea(string **campos,bool_t *eof,size_t *len,FILE* infile){

    status_t st;
    string str;
	
    if ((st = leer_linea(&str,eof,infile)) != OK){ 
        fclose(infile);
        return st;
    }
        else{
            *campos = parsear_linea (str,DEL,len); 
            free(str);
        }

        if (archivo_corrupto(*len) == TRUE ){
            if ((st = cerrar_archivo(&infile)) != OK ){
                mostrar_error(st);
                return EXIT_FAILURE;
            }  
            return ERROR_CORRUPT_FILE;
        }
        

    return OK;
}
status_t procesar_campos(unsigned int * ID, unsigned int * anio, unsigned int *mes , unsigned int *monto, string *campos){
    
    string ptr;
    unsigned int temp;
    size_t i;

    if (ID == NULL || anio == NULL || mes == NULL || campos == NULL){
        return ERROR_NULL_POINTER;
    }

    for (i = 0; i < MAX_CAMPOS; i++){

        temp = strtoul(campos[i], &ptr, 10);

        switch (i){
        case CAMPO_ID:
            *ID = temp;
            break;
        case CAMPO_MES:
            convertir_fecha(mes,anio,temp);                
            break;
        case CAMPO_MONTO:
            *monto = temp ;
            break; 
        }

    }
    return OK;
}
status_t convertir_fecha(unsigned int * mes ,unsigned int * anio ,time_t fecha_unix){
	
    struct tm *st;

    if (mes == NULL || anio == NULL){
        return ERROR_NULL_POINTER;
    }

    st = localtime(&fecha_unix);

    *mes = st->tm_mon;
    *anio  = st->tm_year + 1900 ;

    return OK;
}