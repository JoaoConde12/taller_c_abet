#ifndef OBTENER_INFORMACION_H
#define OBTENER_INFORMACION_H

char *obtener_nombre_doctor(int *option, int counter);
char *obtener_archivo_doctor(int counter_name_doctor);
int **leer_horario_doctor(char *name_file);
void liberar_horario(int** horario);

#endif
