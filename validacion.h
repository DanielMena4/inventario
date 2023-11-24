#ifndef validacion_H_INCLUDED
#define validacion_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

// Función de validación que verifica si una cadena representa un número válido dada es una entrada numérica válida. Devuelve 1 si es válido, 0 en caso contrario.
int validacion(char valor[10])
{
    
// Recorre cada carácter de la cadena, utiliza un bucle for para recorrer cada carácter de la cadena.
    for(int i = 0; i < strlen(valor);i++)
    {

// Si encuentra un punto (.), termina el bucle (break).
        if (valor[i] == '.')
        {
            break;
        }  
        
// Si el carácter no es un dígito, imprime un mensaje y devuelve 0 (no válido)
        if(!(isdigit(valor[i])))
        {
        printf("\nNumero no valido");
        return 0;
        }
    }
    
// Si la cadena ha pasado todas las validaciones, devuelve 1 (válido)
    return 1;    
}

// fin de la directiva de preprocesador #endif 
#endif 
