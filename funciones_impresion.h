#ifndef IMPRESION_H
#define IMPRESION_H
#include "funciones_error.h"
#include "idiomas.h"
#include "constantes.h"
#include "funciones_cliente.h"

status_t imprimir_anio_transacciones(FILE *outfile,unsigned int anio);
status_t imprimir_id_cliente(FILE *outfile, unsigned int id);
status_t imprimir_total_mesual(FILE* outfile,client_t cliente,unsigned int mes);
status_t imprimir_total_anual(FILE* outfile, client_t cliente);

#endif