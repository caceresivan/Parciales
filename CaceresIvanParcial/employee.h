#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <stdio_ext.h>
#include <stdlib.h>
#include "employee.h"
#include "biblioteca.h"
#include <string.h>
#define CANTIDADEMPLOYEES 100

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

int emp_swap(Employee* pBuffer,int indiceDestino,int indiceOrigen);
int initEmployees(Employee* pBuffer,int limite);
int addEmployee(Employee* pBuffer,int limite,int id,char* name,char* lastName,float salary,int sector);
int findEmployeeById(Employee* pBuffer,int limite,int id);
int removeEmployee(Employee* pBuffer,int limite,int id);
int ordenByLastNameOrSector(Employee* pBuffer,int limite,int flag);
int printEmployees(Employee* pBuffer,int limite);
int modificarById(Employee* pBuffer,int limite,int id);
int emp_totalPromedioYMayoresAlPromedio(Employee* pBuffer,int limite,int* cantidadMayor,float* promedio,float* total);
int ingresoForzado(Employee* pBuffer,int limite,char* name,char* lastName,int id,float salary,int sector);

#endif // EMPLOYEE_H_INCLUDED
