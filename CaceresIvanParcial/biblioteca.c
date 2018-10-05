#include <stdio_ext.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <string.h>

static int isInt(char*cadena);
static int getInt(int*pResultado);
static float isFloat(char*cadena);
static int getFloat(float*pResultado);
static int isLetras(char*pBuffer);
static int isEmail(char* pBuffer);

int utn_getInt(int* pResultado,char*mensaje,char*mensajeError,int min,int max,int reintentos)
{
    int retorno;
    int numero;

    while(reintentos>0)
    {
        printf("%s",mensaje);
        if(getInt(&numero)==1)
        {
            if(numero<=max && numero>=min)
                break;
        }
            __fpurge(stdin);
            reintentos--;
            printf("%s",mensajeError);
    }
    if(reintentos==0)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
        *pResultado=numero;
    }
    return retorno;
}
static int getInt(int*pResultado)
{
    int retorno=-1;
    char buffer[64];
    scanf("%s",buffer);

    if(isInt(buffer))
    {
        *pResultado=atoi(buffer);
        retorno=1;
    }
    return retorno;
}
static int isInt(char*cadena)
{
    int retorno=-1;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
            {
                break;
            }
            i++;
        }
        if(cadena[i]=='\0')
        {
            retorno=1;
        }
    }
    return retorno;
}

int utn_getFloat(float* pResultado,char*mensaje,char*mensajeError,int min,int max,int reintentos)
{
    int retorno;
    float numero;

    while(reintentos>0)
    {
        printf("%s",mensaje);
        if(getFloat(&numero)==1)
        {
            if(numero<=max && numero>=min)
                break;
        }
            __fpurge(stdin);
            reintentos--;
            printf("%s",mensajeError);
    }
    if(reintentos==0)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
        *pResultado=numero;
    }
    return retorno;
}

static int getFloat(float*pResultado)
{
    int retorno=-1;
    char buffer[64];
    scanf("%s",buffer);

    if(isFloat(buffer))
    {
        *pResultado=atof(buffer);
        retorno=1;
    }
    return retorno;
}
static float isFloat(char*cadena)
{
    int retorno=-1;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
            {
                break;
            }
            i++;
        }
        if(cadena[i]=='0')
        {
            retorno=1;
        }
    }
    return retorno;
}

int getString(char* pBuffer,int limite)
{
    char bufferString[4096];
    int retorno=-1;

    if(pBuffer != NULL && limite>0)
    {
        __fpurge(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);
        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString)<=limite)
        {
            strncpy(pBuffer,bufferString,limite);
            retorno=0;
        }
    }
    return retorno;
}

int utn_getLetras(char* pBuffer,int limite,int reintentos,char* msg,char* msgError)
{
    int retorno=-1;
    char buffer[limite];
    if(pBuffer != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getString(buffer,limite)==0 && isLetras(buffer)==0)
            {
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                {
                    printf("%s",msgError);
                }
        }while(reintentos>=0);
    }
    return retorno;
}
static int isLetras(char*pBuffer)
{
    int retorno=-1;
    int i=0;
    if(pBuffer != NULL)
    {
        do
        {
            if((*(pBuffer+i)<65 || *(pBuffer+i)>90) && (*(pBuffer+i)<97 || *(pBuffer+i)>122))
            {
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer))
        {
            retorno=0;
        }
    }
    return retorno;
}
int utn_getLetrasYNumeros(char* pBuffer,int limite,char* msg)
{
    int retorno=-1;
    char aux[limite];
    printf("%s",msg);
    if(pBuffer != NULL && limite>0 && getString(aux,limite)==0)
    {
        retorno=0;
        strncpy(pBuffer,aux,limite);
    }
    return retorno;
}

int utn_getEmail(char* pBuffer,int limite,int reintentos,char* msg,char* msgError)
{
    int retorno=-1;
    char buffer[limite];
    if(pBuffer != NULL && limite>0 && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getString(buffer,limite)==0 && isEmail(buffer)==0)
            {
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
            {
                printf("%s",msgError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
static int isEmail(char* pBuffer)
{
    int retorno=-1;
    int i;
    int flagArroba=0;
    int flagPunto=0;

    if(pBuffer != NULL)
    {
        for(i=0;i<strlen(pBuffer);i++)
        {
            if(i==0 && (pBuffer[i]==64 || pBuffer[i]==46))
            {
                break;
            }
            if(pBuffer[i] != 45 && pBuffer[i] != 46 && pBuffer[i] != 95 && pBuffer[i] < 65 && pBuffer[i] > 90
                && pBuffer[i] < 48 && pBuffer[i] > 57 && pBuffer[i] < 97 && pBuffer[i] > 122)
               {
                break;
               }
               if(pBuffer[i]==64)
               {
                    if(flagArroba==1)
                    {
                        break;
                    }
                    flagArroba=1;
               }
               if(flagArroba==1)
               {
                    if(pBuffer[i]==46)
                    {
                        flagPunto=1;
                    }
               }
               if(pBuffer[i]==46 && (pBuffer[i+1]==64 || pBuffer[i+1]==46 || pBuffer[i-1]==64))
               {
                    break;
               }
        }
        if(i==strlen(pBuffer) && flagArroba==1 && flagPunto==1)
        {
            retorno=0;
        }
    }
    return retorno;
}

int ordenInsertion(int* pArray,int limite)
{
    int i;
    int j;
    int temp;

    for(i=1;i<limite;i++)
    {
        temp=*(pArray+i);
        j=i-1;
        while(j>=0 && temp< *(pArray+j))
        {
            *(pArray+j+1)=*(pArray+j);
            j--;
        }
        *(pArray+j+1)=temp;
    }
    return 0;
}
int generarId(void)
{
    static int id=0;
    id++;
    return id;
}
/*int utn_getCuit(char* pBuffer,int limite,int reintentos,char* msg,char* msgError)
{
    int retorno=-1;
    char aux[limite];
    printf("%s",msg);
    if(pBuffer != NULL && limite>0 && getString(aux,limite)==0)
    {
        retorno=0;
        strncpy(pBuffer,aux,limite);
    }
    return retorno;
}*/
