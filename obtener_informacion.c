#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obtener_informacion.h"

char *obtener_archivo(int counter_name_doctor)
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
        while (counter < counter_name_doctor && fgets(name_doctor, sizeof(name_doctor), file) != NULL)
        {
            if (counter == counter_name_doctor - 1)
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


int **leer_horarios(char *name_file)
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


void liberar_horarios(int** horario)
{
    for (int i = 0; i < 16; i++)
    {
        free(horario[i]);
    }
    free(horario);
}