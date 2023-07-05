#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imprimir_horario.h"
#include "obtener_informacion.h"


void imprimir_horario(int *option, int counter)
{
    FILE *file;
    char path[] = "C:\\Users\\dell-pc\\Repositorios\\taller_c_abet\\doctores.txt";
    char line[50];
    int counter_name_doctor = 0;
    char *file_doctor_value;
    int **horario;

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
                counter_name_doctor++;
            }
            fclose(file);

            file_doctor_value = obtener_archivo(counter_name_doctor);
            FILE *file_doctor = fopen(file_doctor_value, "r");
            horario = leer_horarios(file_doctor_value);

            int hour = 7;
            int minute = 1;
            int check_hour = 0;
            int total_hours = 14;
            int day = 0;
            int total_days = 7;
            int value = 0;
            
            printf("_____________________________________________________________________________________________________________________________________\n");
            printf("                                                         Doctor/a %s                                                                  \n", line);
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("    Hora     |     Lunes      |    Martes      |    Miercoles   |     Jueves     |     Viernes    |    Sabado      |     Domingo    |\n");
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            while (hour <= total_hours)
            {
                if (hour < 10 && minute % 2 == 1)
                {
                    printf("0%d:00 - 0%d:20|", hour, hour);
                    check_hour++;
                }
                if (hour < 10 && minute % 2 == 0)
                {
                    printf("0%d:30 - 0%d:50|", hour, hour);
                    check_hour++;
                }
                if (hour >= 10 && minute % 2 == 1)
                {
                    printf("%d:00 - %d:20|", hour, hour);
                    check_hour++;
                }
                if (hour >= 10 && minute % 2 == 0)
                {
                    printf("%d:30 - %d:50|", hour, hour);
                    check_hour++;
                }
                while (day < total_days)
                {
                    if (horario[check_hour - 1][day] == 0)
                    {
                        printf("       -        ");
                    }
                    else
                    {
                        printf("  Cita agendada ");
                    }
                    printf("|");
                    day++;
                }
                day = 0;
                minute++;
                if(check_hour % 2 == 0)
                {
                    hour++;
                }
                printf("\n");
            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            liberar_horarios(horario);
        }
        else
        {
            printf("No se pudo abrir el archivo\n");
        }
    }
}
