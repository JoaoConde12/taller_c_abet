#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imprimir_horario.h"

void imprimir_horario(int *option, int counter)
{
    FILE *file;
    char path[] = "C:\\Users\\dell-pc\\Repositorios\\taller_c_abet\\archivos\\doctores.txt";
    char line[50];

    if (*option >= 1 && *option <= counter)
    {
        file = fopen(path, "r");
        if (file)
        {
            counter = 0;
            while (counter < *option && fgets(line, sizeof(line), file) != NULL)
            {
                if (line[strlen(line) - 1] == '\n')
                {
                    line[strlen(line) - 1] = '\0';
                }
                counter++;
            }
            fclose(file);
            printf("____________________________________________________________________________________________________________________________\n");
            printf("                                                 Doctor %s                                                                  \n", line);
            printf("-----------------------------------------------------------------------------------------------------------------------------\n");
            printf(" Hora|       Lunes    |    Martes      |    Miercoles   |     Jueves     |     Viernes    |    Sabado      |     Domingo    |\n");
            printf("-----------------------------------------------------------------------------------------------------------------------------\n");

        }
        else
        {
            printf("No se pudo abrir el archivo\n");
        }
    }
}
