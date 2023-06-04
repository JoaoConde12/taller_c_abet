#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendar_cita.h"
#include "editar_cita.h"
#include "eliminar_cita.h"
#include "visualizar_horarios.h"
#include "reiniciar_horarios.h"
#include "volver.h"


int main()
{
    //Declaración de variables
    int user_option;
    int user_option_doctor;
    char key;

    //Creación del menú
    do
    {
        printf("\n******************** Sistema de agendacion de citas ********************\n");
        printf("\n\t1. Agendar una cita\n");
        printf("\t2. Editar una cita\n");
        printf("\t3. Eliminar una cita\n");
        printf("\t4. Visualizar horario\n");
        printf("\t5. Reiniciar horarios\n");
        printf("\t6. Salir del programa\n");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &user_option);
        printf("\n");
        
        switch (user_option)
        {
        case 1:
            //Código para agendar cita
            agendar_cita(&user_option_doctor);
            volver(&key);
            break;

        case 2:
            //Código para editar cita
            volver(&key);
            break;

        case 3:
            //Código para eliminar cita
            volver(&key);
            break;

        case 4:
            //Código para visualizar horario
            volver(&key);
            break;

        case 5:
            //Código para reiniciar los horarios
            volver(&key);
            break;

        case 6:
            //Código para salir del programa
            break;
        
        default:
            printf("Opcion fuera de rango. Intenta otra vez.\n\n");
            break;
        }
    }
    while (user_option != 6);    

    return 0;
}
