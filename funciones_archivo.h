#ifndef ARCHIVOS__H
#define ARCHIVOS__H

#include "constantes.h"
#include "funciones_error.h"
#include "bool.h"


status_t abrir_archivo_lectura(FILE **archivo,const char *nombre_archivo);
status_t cerrar_archivo(FILE **archivo);
status_t abrir_archivo_escritura(FILE **archivo,const char *nombre_archivo);
status_t destruir_archivo(FILE **archivo,const char *nombre_archivo);
bool_t archivo_corrupto(unsigned int len);

#endif