#ifndef validacion_H_INCLUDED
#define validacion_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int validacion(char valor[10])
{
    for(int i = 0; i < strlen(valor);i++)
    {
        if (valor[i] == '.')
        {
            break;
        }
        
        if(!(isdigit(valor[i])))
        {
        printf("\nNumero no valido");
        return 0;
        }
    }
    return 1;    
}
#endif