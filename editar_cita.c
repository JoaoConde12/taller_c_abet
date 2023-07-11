#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editar_cita.h"
#include "imprimir_horario.h"
#include "obtener_informacion.h"

void editar_cita(int *option)
{
    FILE *file;
    int counter;
    char path[] = "C:\\Users\\dell-pc\\Repositorios\\taller_c_abet\\doctores.txt";
    char line[50];
    int row;
    int column;
    int new_row;
    int new_column;
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

    printf("\nESCOGER HORA A MODIFICAR:\n");
    printf("\nInserta el ID para seleccionar la hora (Inserta solo el numero): ");
    scanf("%d", &row);
    printf("Inserta el numero del dia (Ejemplo: Lunes = 1; Martes = 2; Miercoles = 3): ");
    scanf("%d", &column);
    printf("\n");

    printf("ESCOGER HORA A INSERTAR:\n");
    printf("\nInserta el ID para seleccionar la hora (Inserta solo el numero): ");
    scanf("%d", &new_row);
    printf("Inserta el numero del dia (Ejemplo: Lunes = 1; Martes = 2; Miercoles = 3): ");
    scanf("%d", &new_column);
    printf("\n");

    if (row == new_row && column == new_column)
    {
        printf("No puedes escoger el mismo horario para editar la cita.\n\n");
        return;
    }

    file_doctor_value = obtener_archivo_doctor(*option);
    horario = leer_horario_doctor(file_doctor_value);

    if (row >= 1 && row <= 16 && column >= 1 && column <= 7 && new_row >= 1 && new_row <= 16 && new_column >= 1 && new_column <= 7)
    {
        if (horario[row - 1][column - 1] == 1 && horario[new_row - 1][new_column - 1] == 0)
        {
            horario[row - 1][column - 1] = 0;
            horario[new_row - 1][new_column - 1] = 1;
            printf("La cita ha sido editada exitosamente.\n");

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
            printf("Ese horario no tiene cita o donde querias modificar la cita esta agendado.\n");
        }
    }
    else
    {
        printf("Ese horario esta fuera de rango.\n");
    }
    printf("\n");
    
    liberar_horario(horario);
}