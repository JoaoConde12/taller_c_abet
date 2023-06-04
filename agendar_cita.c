#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendar_cita.h"

void agendar_cita(int *option)
{
    FILE *file;
    int counter;
    char path[] = "C:\\Users\\dell-pc\\Repositorios\\taller_c_abet\\archivos\\doctores.txt";
    char line[50];
    size_t lenght = 0;

    file = fopen(path, "r");

    if (file)
    {
        while (fgets(line, sizeof(line), file) != NULL)
        {
            if (line[strlen(line) - 1] == '\n')
            {
                line[strlen(line) - 1] == '\O';
            }
            printf("\t%d. %s", counter + 1, line);
            counter++;
        }
        fclose(file);
    }
    else
    {
        printf("No se pudo abrir el archivo");
    }
    printf("\n\nSeleccione un doctor: ");
    scanf("%d", option);
}
