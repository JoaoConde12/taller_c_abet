#ifndef OBTENER_INFORMACION_H
#define OBTENER_INFORMACION_H

char *obtener_archivo(int counter_name_doctor);
int **leer_horarios(char *name_file);
void liberar_horarios(int** horario);


#endif