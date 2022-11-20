#include "funciones_error.h"

string status[] = {
    MSJ_ST_OK,
    MSJ_ST_EROR_INVOCACION,
    MSJ_ST_INGRESO_INVALIDO,
    MSJ_ST_ERROR_PUNTERO_NULO,
    MSJ_ST_ERROR_MEMORIA,
    MSJ_ST_ERROR_SIN_MEMORIA,
    MSJ_ST_ERROR_APERTURA_ARCHIVO,
    MSJ_ST_ERROR_ARCHIVO_CORRUPTO,
    MSJ_ST_ERROR_CERRADO_ARCHIVO,
    MSJ_ST_ERROR_ARCHIVO_NO_ENCONTRADO
};

status_t mostrar_error(status_t st){
  
   fprintf(stdout,"%s: %s\n",MSJ_ERROR ,status[st]);

   return OK;
   
}