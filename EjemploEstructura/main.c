#include <stdio.h>
#include <stdlib.h>

#define TAM 5
typedef struct{
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[50];
    int estado;
}T_Alumno;


int main()
{

    T_Alumno list_alumnos[TAM];


    return 0;
}


T_Alumno *cargar()
{
    T_Alumno *PAlumno= (T_Alumno *) malloc (sizeof( T_Alumno));
    return    PAlumno;
}
