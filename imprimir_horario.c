#include <stdio.h>
#include "imprimir_horario.h"
#include "obtener_informacion.h"


void imprimir_horario(int *option, int counter)
{
    char *name_doctor;
    char *file_doctor_value;
    int **horario;

    name_doctor = obtener_nombre_doctor(option, counter);
    file_doctor_value = obtener_archivo_doctor(*option);
    FILE *file_doctor = fopen(file_doctor_value, "r");
    horario = leer_horario_doctor(file_doctor_value);

    int hour = 7;
    int minute = 1;
    int check_hour = 0;
    int total_hours = 14;
    int day = 0;
    int total_days = 7;
    int value = 0;
            
    printf("______________________________________________________________________________________________________________________________________________\n");
    printf("                                                         Doctor/a %s                                                                  \n", name_doctor);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  ID  |     Hora      |     Lunes      |    Martes      |    Miercoles   |     Jueves     |     Viernes    |    Sabado      |     Domingo    |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
    while (hour <= total_hours)
    {
        if (check_hour + 1 < 10)
        {
            printf("  %d   |", check_hour + 1);
        }
        else
        {
            printf("  %d  |", check_hour + 1);
        }
        if (hour < 10 && minute % 2 == 1)
        {
            printf(" 0%d:00 - 0%d:20 |", hour, hour);
            check_hour++;
        }
        if (hour < 10 && minute % 2 == 0)
        {
            printf(" 0%d:30 - 0%d:50 |", hour, hour);
            check_hour++;
        }
        if (hour >= 10 && minute % 2 == 1)
        {
            printf(" %d:00 - %d:20 |", hour, hour);
            check_hour++;
        }
        if (hour >= 10 && minute % 2 == 0)
        {
            printf(" %d:30 - %d:50 |", hour, hour);
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
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
    liberar_horario(horario);
    fclose(file_doctor);
}
