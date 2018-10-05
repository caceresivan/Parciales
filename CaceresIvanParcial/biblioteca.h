#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

int utn_getInt(int* pResultado,char* msg,char* msgError,int min,int max,int reintentos);
int utn_getFloat(float* pResultado,char*mensaje,char*mensajeError,int min,int max,int reintentos);
int getString(char* pBuffer,int limite);
int utn_getLetras(char* pBuffer,int limite,int reintentos,char* msg,char* msgError);
int utn_getLetrasYNumeros(char* pBuffer,int limite,char* msg);
int ordenInsertion(int* pArray,int limite);
int generarId(void);

#endif // BIBLIOTECA_H_INCLUDED
