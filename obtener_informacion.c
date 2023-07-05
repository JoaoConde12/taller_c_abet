#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obtener_informacion.h"


char *obtener_nombre_doctor(int *option, int counter)
{
    FILE *file;
    char path[] = "C:\\Users\\dell-pc\\Repositorios\\taller_c_abet\\doctores.txt";
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
        }
        else
        {
            printf("No se pudo abrir el archivo\n");
        }
    }
    else
    {
        printf("\nEse doctor no se encuentra en la lista\n\n");
    }

    return strdup(line);
}


char *obtener_archivo_doctor(int option)
{
    FILE *file;
    char path[] = "C:\\Users\\dell-pc\\Repositorios\\taller_c_abet\\doctores.txt";
    char path_doctors[] = "C:\\Users\\dell-pc\\Repositorios\\taller_c_abet\\archivos_doctores\\";
    char name_doctor[100];
    char file_doctor_value[100];
    char line[50];
    int counter = 0;

    file = fopen(path, "r");
    counter = 0;
    if (file)
    {
        while (counter < option && fgets(name_doctor, sizeof(name_doctor), file) != NULL)
        {
            if (counter == option - 1)
            {
                name_doctor[strcspn(name_doctor, "\n")] = '\0';
                strcpy(file_doctor_value, path_doctors);
                strcat(file_doctor_value, name_doctor);
                strcat(file_doctor_value, ".txt");
                break;
            }
            counter++;
        }
        fclose(file);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }
    return strdup(file_doctor_value);
}


int **leer_horario_doctor(char *name_file)
{
    FILE *file = fopen(name_file, "r");

    if (file == NULL)
    {
        printf("No se pudo abrir el archivo del doctor\n");
        return NULL;
    }

    int **horario = (int**)malloc(16 * sizeof(int*));

    for (int i = 0; i < 16; i++)
    {
        horario[i] = (int*)malloc(7 * sizeof(int));
        for (int j = 0; j < 7; j++)
        {
            fscanf(file, "%d", &horario[i][j]);
        }
    }
    fclose(file);

    return horario;
}


void liberar_horario(int** horario)
{
    for (int i = 0; i < 16; i++)
    {
        free(horario[i]);
    }
    free(horario);
}