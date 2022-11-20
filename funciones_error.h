#ifndef ERRORES_H
#define ERRORES_H
#include <stdlib.h>
#include <stdio.h>
#include "idiomas.h"
#include "constantes.h"

typedef enum {
    OK ,
    ERROR_INVOCATION ,
    ERROR_INVALID_INPUT ,
    ERROR_NULL_POINTER ,
    ERROR_MEMORY ,
	ERROR_OUT_OF_MEMORY ,
    ERROR_OPENING_FILE ,
    ERROR_CORRUPT_FILE ,
    ERROR_CLOSING_FILE ,
    ERROR_NO_FILE

} status_t;



status_t mostrar_error(status_t st);

#endif