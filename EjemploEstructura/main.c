#include <stdio.h>
#include <stdlib.h>

enum boolean{TRUE=1, FALSE=0};

#define TAM 5
typedef struct{
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[50];
    int estado;
}T_Alumno;

T_Alumno *cargar();
void menu();
//hacer...
void cargarAlumno();
void mostrarAlumnos(T_Alumno vector[],int cant);
void modificarAlumno();
void borrarAlumno();
void ordenarPor();

int main()
{

    T_Alumno list_alumnos[TAM];


    return 0;
}

void menu()
{
        printf("\n 1. Alta");
        printf("\n 1. Baja");
        printf("\n 1. Modificacion");
        printf("\n 1. Orden");
        printf("\n\n");
}

T_Alumno *cargar()
{
    T_Alumno *PAlumno= (T_Alumno *) malloc (sizeof( T_Alumno));
    return    PAlumno;
}

void mostrarAlumnos(T_Alumno vector[],int cant)
{
    for(int i =0;i<cant;i++)
    {
            printf("\n Nombre: %s",vector->nombre);
            printf("\n Legajo: %d",vector->legajo);
            printf("\n 1ra Nota: %d",vector->nota1);
            printf("\n 2da Nota: %d",vector->nota2);
            printf("\n Promedio: %f",vector->promedio);
            printf("\n Estado: %d",vector->estado);
            printf("\n\n");
    }

}
