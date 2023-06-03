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

        //Comprobación de si es la tecla es distinta a una letra del alfabeto
        if (!(isalpha(*key)))
        {
            printf("No es una letra. Intenta otra vez\n\n");
        }
        //Comprobación de si la tecla es distinta a la letra 'v'
        else if (!(*key == 'v' || *key == 'V'))
        {
            printf("No es la letra 'v'. Intenta otra vez\n\n");
        }
        //Se vuelve al menú principal y se limpia la consola
        else
        {
            system("cls");
            break;
        }
    }
    while (*key != 'v' || *key != 'V');
}