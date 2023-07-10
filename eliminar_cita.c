#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eliminar_cita.h"
#include "imprimir_horario.h"
#include "obtener_informacion.h"

void eliminar_citar(int *option)
{
    FILE *file;
    int counter;
    char path[] = "C:\\Users\\dell-pc\\Repositorios\\taller_c_abet\\doctores.txt";
    char line[50];
    int row;
    int column;
    char *file_doctor_value;
    int **horario;

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

    printf("\nInserta el ID para seleccionar la hora (Inserta solo el numero): ");
    scanf("%d", &row);
    printf("\nInserta el numero del dia (Ejemplo: Lunes = 1; Martes = 2; Miercoles = 3): ");
    scanf("%d", &column);
    printf("\n");

    file_doctor_value = obtener_archivo_doctor(*option);
    horario = leer_horario_doctor(file_doctor_value);

    if (row >= 1 && row <= 16 && column >= 1 && column <= 7)
    {
        if (horario[row - 1][column - 1] == 1)
        {
            horario[row - 1][column - 1] = 0;
            printf("La cita ha sido borrada exitosamente.\n");

            FILE *file_doctor = fopen(file_doctor_value, "w");
            if (file_doctor)
            {
                for (int i = 0; i < 16; i++)
                {
                    for (int j = 0; j < 7; j++)
                    {
                        fprintf(file_doctor, "%d ", horario[i][j]);
                    }
                    fprintf(file_doctor, "\n");
                }
                fclose(file_doctor);
            }
        }
        else
        {
            printf("Ese horario no tiene cita.\n");
        }
    }
    printf("\n");
    
    liberar_horario(horario);
}