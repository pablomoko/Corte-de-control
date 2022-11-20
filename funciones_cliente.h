#ifndef CLIENTE__H
#define CLIENTE__H

#include "funciones_error.h"

typedef struct {
    unsigned int monto_mes;
    unsigned int monto_total;
} client_t;

status_t inicializar_monto_mes(client_t* cliente);
status_t inicializar_monto_total(client_t* cliente);
status_t cargar_monto_cliente(client_t *cliente,unsigned int monto);

#endif