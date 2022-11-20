#ifndef LINEAS__H
#define LINEAS__H
#include <time.h>
#include "bool.h"
#include "funciones_cadenas.h"
#include "funciones_error.h"
#include "constantes.h"
#include "funciones_archivo.h"

status_t saltar_linea(FILE* infile,bool_t * eof);
status_t procesar_linea(string **campos,bool_t *eof,size_t *len,FILE* infile);
status_t procesar_campos(unsigned int * ID, unsigned int * anio, unsigned int *mes , unsigned int *monto, string *campos);
status_t convertir_fecha(unsigned int * mes ,unsigned int * anio ,time_t fecha_unix);

#endif

