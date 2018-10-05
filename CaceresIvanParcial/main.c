#include <stdio_ext.h>
#include <stdlib.h>
#include "cliente.h"
#include "biblioteca.h"
#include <string.h>

int menu(int* opcion);
int main()
{
    Cliente clientes[CANTIDADCLIENTES];
    int opcion;

    initCliente(clientes,CANTIDADCLIENTES);

    do
    {
        system("clear");
        menu(&opcion);
        switch(opcion)
        {
            case 1:
                altaCliente(clientes,CANTIDADCLIENTES,generarId(),"ivan","caceres","1-39715495-6");
                printCliente(clientes,CANTIDADCLIENTES);
                    break;
            case 2:
                printf("Ingrese ID de cliente a modificar: \n");

                buscarClienteById(clientes,CANTIDADCLIENTES,clientes->id);
                modificarById(clientes,CANTIDADCLIENTES,clientes->id);
                printCliente(clientes,CANTIDADCLIENTES);
                break;
            //case 3:
            /*case 4:
            case 5:
            case 6:
            case 7:
            case 8:*/
        }
    }while(opcion != 8);
    return 0;
}

int menu(int* opcion)
{
    printf("\n 1) Altas \n 2) Modificar \n 3) Baja \n 4) Vender Afiche \n 5) Editar venta \n 6) Cobrar venta \n 7) Imprimir clientes \n 8) Salir.");
    utn_getInt(opcion,"\n Ingrese opcion: ","\n Error, ingrese opcion valida.",1,8,5);

    return 0;
}
