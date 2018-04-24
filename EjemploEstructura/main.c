#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Func_Graficas.h"
#include "Func_GetDatos.h"

enum boolean{TRUE=1, FALSE=0};
//
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
//void menu();
//hacer...

//void cargarAlumno(T_Alumno *Alumno);
T_Alumno PedirAlumno();
void cargarAlumnos(T_Alumno *Alumno,int cant);

void MostrarCampos(T_Alumno Alumno);
void mostrarAlumnos(T_Alumno vector[],int cant);

void modificarAlumno();
void borrarAlumno();
void ordenarPor();

float calculapromedio(int nota1,int nota2);

//void get_char(char *sms,char *nombre);





int main()
{
    T_Alumno list_alumnos[TAM];
    char seguir='s';
    int opcion;


    //------------- BORRAR -------
    T_Alumno alumno;
//    cargarAlumno(&alumno);
    alumno=PedirAlumno();
    MostrarCampos(alumno);

    system("pause");
    //-------------------

    do
    {
        menu();
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1: //Alta
                cargarAlumnos(list_alumnos,TAM);
                break;
            case 4://Mostrar
                mostrarAlumnos(list_alumnos,TAM);
                break;
            case 9://salir
                seguir = 'n';
                break;
        }//FIN switch(opcion)

    }while(seguir=='s');

    return 0;
}


T_Alumno *cargar()
{
    T_Alumno *PAlumno= (T_Alumno *) malloc (sizeof( T_Alumno));
    return    PAlumno;
}



void cargarAlumnos(T_Alumno *Alumno,int cant)
{
    char continuar;
    for(int i=0;i<cant;i++)
    {
        //cargarAlumno(&Alumno[i]);
        Alumno[i]=PedirAlumno();

        printf("\n Desea Cargar otro alumno: (s/n) ");
        scanf("%c",continuar);
        if(continuar=='n')
        {
            i=cant;
        }
    }
}

/*
void cargarAlumno(T_Alumno *Alumno)
{//Carga datos de 1 alumno

    strcpy(Alumno->nombre, get_char("Ingrese el nombre del alumno:",50));
    Alumno->legajo=Get_intMayor_X("Ingrese Legajo: ",1);
    Alumno->nota1=get_int_entre("Ingrese la 1er nota del alumno: ",1,10);
    Alumno->nota2=get_int_entre("Ingrese la 2da nota del alumno: ",1,10);
    Alumno->promedio=calculapromedio(Alumno->nota2,Alumno->nota2);
    Alumno->estado=TRUE;
}
*/
T_Alumno PedirAlumno()
{//Carga datos, y devuelve un alumno
    T_Alumno aux_Alumno;
    strcpy(aux_Alumno.nombre, get_char("Ingrese el nombre del alumno:",50));
    aux_Alumno.legajo=Get_intMayor_X("Ingrese Legajo: ",1);
    aux_Alumno.nota1=get_int_entre("Ingrese la 1er nota del alumno: ",1,10);
    aux_Alumno.nota2=get_int_entre("Ingrese la 2da nota del alumno: ",1,10);
    aux_Alumno.promedio=calculapromedio(aux_Alumno.nota1,aux_Alumno.nota2);
    aux_Alumno.estado=TRUE;

    return aux_Alumno;
}

void mostrarAlumnos(T_Alumno vector[],int cant)
{
    for(int i =0;i<cant;i++)
    {
        if(vector[i].estado == TRUE)
        {
            MostrarCampos(vector[i]);
        }
    }
}

void MostrarCampos(T_Alumno Alumno)
{
    printf("\n Nombre: %s",Alumno.nombre);
    printf("\n Legajo: %d",Alumno.legajo);
    printf("\n 1ra Nota: %d",Alumno.nota1);
    printf("\n 2da Nota: %d",Alumno.nota2);
    printf("\n Promedio: %f",Alumno.promedio);
    printf("\n\n");
    system("pause");
}
