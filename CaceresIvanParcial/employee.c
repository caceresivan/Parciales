#include <stdio_ext.h>
#include <stdlib.h>
#include "employee.h"
#include "biblioteca.h"
#include <string.h>

static int searchEmptyIndex(Employee* pBuffer,int limite,int*index);

int initEmployees(Employee* pBuffer,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int altaEmployee(Employee* pBuffer,int limite,int id,char* name,char* lastName,float salary,int sector)
{
    int index;

    if(searchEmptyIndex(pBuffer,limite,&index)==0)
    {
        pBuffer[index].id=id;
        pBuffer[index].isEmpty=0;
        strcpy(pBuffer[index].lastName,lastName);
        strcpy(pBuffer[index].name,name);
        pBuffer[index].salary=salary;
        pBuffer[index].sector=sector;
    }

    return 0;
}
int findEmployeeById(Employee* pBuffer,int limite,int id)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(pBuffer[i].isEmpty==0 && pBuffer[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int bajaEmployee(Employee* pBuffer,int limite,int id)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(pBuffer[i].isEmpty==0 && pBuffer[i].id==id)
        {
            pBuffer[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int modificarById(Employee* pBuffer,int limite,int id)
{
    int i;
    int auxSector,opcion;
    char auxName[60];
    char auxLastName[60];
    float auxSalary;
    int retorno=-1;

    if(pBuffer != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pBuffer[i].id==id && pBuffer[i].isEmpty==0)
            {
                retorno=0;
                if(utn_getInt(&opcion,"\n1) Modificar nombre \n2) Modificar Apellido\n3) Modificar salario\n4) Modificar sector\nIngrese una opcion: ","Ingrese una opcion valida.",1,4,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            if(utn_getLetras(auxName,CANTIDADEMPLOYEES,3,"\n Ingrese el nombre: ","\n Error, ingrese un nombre valido.")==0)
                            {
                                strcpy(pBuffer[i].name,auxName);
                            }
                            break;
                        case 2:
                             if(utn_getLetras(auxLastName,CANTIDADEMPLOYEES,3,"\n Ingrese el apellido: ","\n Error, ingrese un apellido valido.")==0)
                            {
                                strcpy(pBuffer[i].lastName,auxLastName);
                            }
                            break;
                        case 3:
                            if(utn_getFloat(&auxSalary,"\n Ingrese salario: ","Error, ingrese un salario valido",0,999999,3)==0)
                            {
                                pBuffer[i].salary=auxSalary;
                            }
                            break;
                        case 4:
                            if(utn_getInt(&auxSector,"\n Ingrese sector: ","Error, ingrese un sector valido",1,3,3)==0)
                            {
                                pBuffer[i].sector=auxSector;
                            }
                            break;
                    }
                }
                break;

            }
        }
    }
    return retorno;
}
int ordenByLastNameOrSector(Employee* pBuffer,int limite,int flag)
{
    int i;
    int flagOrden=1;
    int retorno=-1;

    if(pBuffer != NULL && limite>0 && (flag==0 || flag==1))
    {
        while(flagOrden==1)
        {
            flagOrden=0;
            for(i=0;i<(limite-1);i++)
            {
                if((flag==0 && strcmp(pBuffer[i].lastName,pBuffer[i+1].lastName)<0) ||
                   (flag==0 && strcmp(pBuffer[i].lastName,pBuffer[i+1].lastName)>0))
                   {
                        emp_swap(pBuffer,i,i+1);
                        flagOrden=1;
                        retorno=0;
                   }else
                   if(strcmp(pBuffer[i].lastName,pBuffer[i+1].lastName)==0 &&(
                      (flag==0 && pBuffer[i].sector < pBuffer[i+1].sector) ||
                       (flag==1 && pBuffer[i].sector > pBuffer[i+1].sector)))
                       {
                            flagOrden=1;
                            retorno=0;
                            emp_swap(pBuffer,i,i+1);
                       }
            }
        }
    }
    return retorno;
}
int printEmployees(Employee* pBuffer,int limite)
{
    int i;
    int retorno=-1;

    if(pBuffer != NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(pBuffer[i].isEmpty==0)
            {
                retorno=0;

                printf("\n ID: %d",pBuffer[i].id);
                printf("\t Nombre: %s",pBuffer[i].name);
                printf("\t LastName: %s",pBuffer[i].lastName);
                printf("\t Salary: %.2f",pBuffer[i].salary);
                printf("\t Sector: %d",pBuffer[i].sector);
            }
        }
    }
    return retorno;
}
static int searchEmptyIndex(Employee* pBuffer,int limite,int*index)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(pBuffer[i].isEmpty==1)
        {
            *index=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int emp_swap(Employee* pBuffer,int indiceDestino,int indiceOrigen)
{
    Employee aux[1];

    if(pBuffer != NULL && indiceDestino != indiceOrigen)
    {
        strcpy(aux[0].lastName,pBuffer[indiceDestino].lastName);
        strcpy(aux[0].name,pBuffer[indiceDestino].name);
        pBuffer[indiceDestino].salary=pBuffer[indiceOrigen].salary;
        pBuffer[indiceDestino].id=pBuffer[indiceOrigen].id;
        pBuffer[indiceDestino].sector=pBuffer[indiceOrigen].sector;
        pBuffer[indiceDestino].isEmpty=pBuffer[indiceOrigen].isEmpty;

        strcpy(pBuffer[indiceOrigen].lastName,aux[0].lastName);
        strcpy(pBuffer[indiceOrigen].name,aux[0].name);
        pBuffer[indiceOrigen].salary=aux[0].salary;
        pBuffer[indiceOrigen].id=aux[0].id;
        pBuffer[indiceOrigen].sector=aux[0].sector;
        pBuffer[indiceOrigen].isEmpty=aux[0].isEmpty;
    }
    return 0;
}
int emp_totalPromedioYMayoresAlPromedio(Employee* pBuffer,int limite,int* cantidadMayor,float* promedio,float* total)
{
    int i;
    int contador=0;
    int acum=0;

    if(pBuffer != NULL && limite>0 && cantidadMayor != NULL && total != NULL && promedio != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(pBuffer[i].isEmpty==0)
            {
                acum+=pBuffer[i].salary;
                contador++;
            }
        }
        *total=acum;
        *promedio=acum/contador;
        contador=0;

        for(i=0;i<limite;i++)
        {
            if(pBuffer[i].isEmpty==0 && pBuffer[i].salary > *promedio)
            {
                contador++;
            }
        }
    }
    *cantidadMayor=contador;
    return 0;
}

int ingresoForzado(Employee* pBuffer,int limite,char* name,char* lastName,int id,float salary,int sector)
{
    int aux;

    searchEmptyIndex(pBuffer,limite,&aux);
    strcpy(pBuffer[aux].name,name);
    strcpy(pBuffer[aux].lastName,lastName);
    pBuffer[aux].id=generarId();
    pBuffer[aux].salary=salary;
    pBuffer[aux].sector=sector;
    pBuffer[aux].isEmpty=0;

    return 0;
}
