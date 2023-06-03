#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "volver.h"

void volver(char *key)
{
    do
    {     //Método para esperar la respuesta del usuario
        printf("Presiona la tecla 'v' para volver: ");
        scanf(" %c", key);

        if (!(isalpha(*key)))
        {
            printf("No es una letra. Intenta otra vez\n");
        }
        else if (!(*key == 'v' || *key == 'V'))
        {
            printf("No es la letra 'v'. Intenta otra vez\n");
        }
        else
        {
            system("cls");
            break;
        }
    }
    while (*key != 'v' || *key != 'V');
}