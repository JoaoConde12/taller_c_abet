#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    //Declaración de variables
    int user_option;

    //Creación del menú
    printf("******************** Sistema de agendacion de citas ********************\n");
    printf("\n\t1. Agendar una cita\n");
    printf("\t2. Editar una cita\n");
    printf("\t3. Eliminar una cita\n");
    printf("\t4. Visualizar horario\n");
    printf("\t5. Reiniciar horarios\n");
    printf("\t6. Salir del programa\n");
    printf("\nSeleccione una opcion: ");
    scanf("%d", &user_option);
    
    switch (user_option)
    {
    case 1:
        //Código para agendar cita
        break;

    case 2:
        //Código para editar cita
        break;

    case 3:
        //Código para eliminar cita
        break;

    case 4:
        //Código para visualizar horario
        break;

    case 5:
        //Código para reiniciar los horarios
        break;

    case 6:
        //Código para salir del programa
        break;
    
    default:
        break;
    }    

    return 0;
}
