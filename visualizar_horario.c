#include <stdio.h>
#include <string.h>
#include "visualizar_horario.h"
#include "imprimir_horario.h"

void visualizar_horario(int *option)
{
    FILE *file;
    int counter;
    char path[] = "doctores.txt";
    char line[50];
    size_t lenght = 0;

    file = fopen(path, "r");

    if (file)
    {
        while (fgets(line, sizeof(line), file) != NULL)
        {
            if (line[strlen(line) - 1] == '\n')
            {
                line[strlen(line) - 1] == '\0';
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

    if (*option < 1 || *option > counter)
    {
        printf("\nEse doctor no se encuentra en la lista\n\n");
        return;
    }
    
    imprimir_horario(option, counter);
}