#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio_ext.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <string.h>
#define CANTIDADCLIENTES 100

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    char cuit[20];
    int isEmpty;
} Cliente;

//int emp_swap(Cliente* pBuffer,int indiceDestino,int indiceOrigen);
int initCliente(Cliente* pBuffer,int limite);
int altaCliente(Cliente* pBuffer,int limite,int id,char* name,char* lastName,char* cuit);
int buscarClienteById(Cliente* pBuffer,int limite,int id);
int bajaCliente(Cliente* pBuffer,int limite,int id);
int ordenByLastNameOrSector(Cliente* pBuffer,int limite,int flag);
int printCliente(Cliente* pBuffer,int limite);
int modificarById(Cliente* pBuffer,int limite,int id);
int emp_totalPromedioYMayoresAlPromedio(Cliente* pBuffer,int limite,int* cantidadMayor,float* promedio,float* total);
int ingresoForzado(Cliente* pBuffer,int limite,char* name,char* lastName,int id,float salary,int sector);

#endif // CLIENTE_H_INCLUDED
