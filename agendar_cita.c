#include <stdio.h>
#include <stdlib.h>
#include "agendar_cita.h"

FILE *fd;

void agendar_cita(int *option)
{
    int c;
    char path[] = "C:\\Users\\dell-pc\\Repositorios\\taller_c_abet\\archivos\\doctores.txt";
    fd = fopen(path, "r");

    printf("\n");

    while ((c = fgetc(fd)) != EOF)
    {
        if (c == '\n')
        {
            printf("\n");
        }
        else
        {
            putchar(c);
        }
    }

    printf("\n\nSeleccione el doctor: ");
    scanf("%d", option);
}