#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "constantes.h"
#include "funciones_error.h"
#include "idiomas.h"
#include "funciones_archivo.h"
#include "funciones_cadenas.h"
#include "funciones_impresion.h"
#include "funciones_linea.h"

status_t validar_argumentos(int argc, char *argv[]);

int main(int argc,char *argv[]){

    FILE *infile,*outfile;
    client_t cliente;
    unsigned int id,mes,monto,anio,aux_mes,aux_id;
    status_t st;
	size_t len;
    string *campos;
    bool_t eof;

    if ((st = validar_argumentos(argc, argv)) != OK){
        mostrar_error(st);
        return EXIT_FAILURE;
    }

    if ((st = abrir_archivo_lectura(&infile,argv[CMD_ARG_POS_SECOND_VALUE_TOKEN + 1])) != OK){
        mostrar_error(st);
        return EXIT_FAILURE;
    }
    if ((st = abrir_archivo_escritura(&outfile,argv[CMD_ARG_POS_FIRST_VALUE_TOKEN + 1])) != OK){
        mostrar_error(st);
        return EXIT_FAILURE;
    }    
    
    if ((st=saltar_linea(infile,&eof))!= OK){
        mostrar_error(st);
        return EXIT_FAILURE;
    }
    
    if ((st = procesar_linea(&campos,&eof,&len,infile)) != OK){
        mostrar_error(st);
        return EXIT_FAILURE;
    }

    if ((st = procesar_campos(&id,&anio,&mes,&monto,campos)) != OK){
        destruir_cadena(campos,len);
        free(campos); 
        mostrar_error(st);
        return EXIT_FAILURE;
    }
    destruir_cadena(campos,len);
    free(campos); 
    
    imprimir_anio_transacciones(outfile,anio);

    while (eof == FALSE){
        aux_id = id;
        inicializar_monto_total(&cliente);
        imprimir_id_cliente(outfile,id);

        while (( eof == FALSE ) && ( aux_id == id )){
            aux_mes = mes;
            inicializar_monto_mes(&cliente);

            while (( eof == FALSE ) && ( aux_id == id ) && (aux_mes == mes)){
                
                cargar_monto_cliente(&cliente,monto);
                
                if ((st = procesar_linea(&campos,&eof,&len,infile)) != OK){
                    if (cerrar_archivo(&outfile) != OK ){
                        return EXIT_FAILURE;
                    }   
                    destruir_cadena(campos,len);
                    free(campos);        
                    mostrar_error(st);
                    return EXIT_FAILURE;
                }
                if ((st = procesar_campos(&id,&anio,&mes,&monto,campos)) != OK){
                    destruir_cadena(campos,len);
                    free(campos); 
                    mostrar_error(st);
                    return EXIT_FAILURE;
                }
                destruir_cadena(campos,len);
                free(campos); 
            }
            if (eof==TRUE){
                cargar_monto_cliente(&cliente,monto);
            }
           imprimir_total_mesual(outfile,cliente,aux_mes);
        }
        imprimir_total_anual(outfile,cliente);
    }

    if ((st = cerrar_archivo(&infile)) != OK ){
        mostrar_error(st);
        return EXIT_FAILURE;
    }    

    if ((st = cerrar_archivo(&outfile)) != OK ){
        mostrar_error(st);
        return EXIT_FAILURE;
    }  

    return EXIT_SUCCESS;
}

status_t validar_argumentos(int argc, char *argv[]) {
    
    if (argv == NULL){
        return ERROR_NULL_POINTER;
    }
    
    if(argc != MAX_ARGS) {
        return ERROR_INVOCATION;
    }
    
    if(strcmp(argv[CMD_ARG_POS_FIRST_VALUE_TOKEN], CMD_ARG_FIRST_VALUE_TOKEN)) {
        return ERROR_INVOCATION;
    }

    if(strcmp(argv[CMD_ARG_POS_SECOND_VALUE_TOKEN], CMD_ARG_SECOND_VALUE_TOKEN)) {
        return ERROR_INVOCATION;
    }

    return OK;
}