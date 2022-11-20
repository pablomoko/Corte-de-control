#include <stdio.h>
#include <stdlib.h>
#include "funciones_impresion.h"

string datos_cliente[] = {
    ANIO,
    CLIENTE,
    MES,
    TOTAL
};

string months[] = {
    MES_1,
    MES_2,
    MES_3,
    MES_4,
    MES_5,
    MES_6,
    MES_7,
    MES_8,
    MES_9,
    MES_10,
    MES_11,
    MES_12
};

status_t imprimir_anio_transacciones(FILE *outfile,unsigned int anio){

    if (outfile == NULL){
        return ERROR_NULL_POINTER;
    }
    fprintf(outfile,"%s: %d\n",datos_cliente[0],anio);
    fprintf(outfile,SEPARADOR_IMPRESION);    
    return OK;
}
status_t imprimir_id_cliente(FILE *outfile, unsigned int id){

    if (outfile == NULL){
        return ERROR_NULL_POINTER;
    }
    
    fprintf(outfile,"%s: %d\n",datos_cliente[CAMPO_ID+1],id);

    return OK;
}
status_t imprimir_total_mesual(FILE* outfile,client_t cliente,unsigned int mes){

    unsigned int temp;

    if (outfile == NULL){
        return ERROR_NULL_POINTER;
    }
    temp = cliente.monto_mes;

    fprintf(outfile,"%s: %s total :%d\n",datos_cliente[CAMPO_MES+1],months[mes],temp);
            
    return OK;
    
}
status_t imprimir_total_anual(FILE* outfile, client_t cliente){

    if (outfile == NULL){
        return ERROR_NULL_POINTER;
    }    
    fprintf(outfile,"%s:%d\n",datos_cliente[3],cliente.monto_total);
    fprintf(outfile,SEPARADOR_IMPRESION);  

    return OK;   
}