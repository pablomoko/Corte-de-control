#ifndef CADENAS__H
#define CADENAS__H
#include <stdlib.h>
#include <stdio.h>
#include "constantes.h"
#include "funciones_error.h"
#include "bool.h"


status_t leer_linea(string * s, bool_t * eof,FILE* infile);
string * parsear_linea(string src, char delim, size_t *len);
status_t destruir_cadena(char* *arr,size_t len);
status_t duplicar_cadena(char **ss, const char *s);

#endif