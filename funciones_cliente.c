#include "funciones_cliente.h"

status_t inicializar_monto_mes(client_t* cliente){

    if (cliente == NULL){
        return ERROR_NULL_POINTER;
    }
    cliente->monto_mes = 0 ;


    return OK;

}
status_t inicializar_monto_total(client_t* cliente){

    if (cliente == NULL){
        return ERROR_NULL_POINTER;
    }
    cliente->monto_total = 0 ;

    return OK;

}
status_t cargar_monto_cliente(client_t *cliente,unsigned int monto){

    if (cliente == NULL){
        return ERROR_NULL_POINTER;
    }

    cliente->monto_mes += monto;  
    cliente->monto_total += monto;
    
    return OK;
}
