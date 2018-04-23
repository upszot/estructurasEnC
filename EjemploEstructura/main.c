#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Func_Graficas.h"


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

void cargarAlumno(T_Alumno *Alumno);
void cargarAlumnos(T_Alumno *Alumno,int cant);

void MostrarCampos(T_Alumno Alumno);
void mostrarAlumnos(T_Alumno vector[],int cant);

void modificarAlumno();
void borrarAlumno();
void ordenarPor();

float calculapromedio(int nota1,int nota2);

void get_char(char *sms,char *nombre);
void get_int(char *sms,int dato);
void get_int_entre(char *sms,int dato,int minimo, int maximo);

int main()
{
    T_Alumno list_alumnos[TAM];
    char seguir='s';
    int opcion;
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
        }//FIN switch(opcion)

    }while(seguir=='s');

    return 0;
}


T_Alumno *cargar()
{
    T_Alumno *PAlumno= (T_Alumno *) malloc (sizeof( T_Alumno));
    return    PAlumno;
}

void get_char(char *sms,char *texto)
{
    fflush(stdin);
    printf("%s ",sms);
    gets(texto);
}
void get_intMayor0(char *sms,int dato)
{
    do
    {
        printf("%s ",sms);
        scanf("%d",dato);
    } while(dato < 1);
}
void get_int_entre(char *sms,int dato,int minimo, int maximo)
{
    do
    {
        printf("%s ",sms);
        scanf("%d",dato);
        if(dato < minimo || dato > maximo)
        {
            printf("\nDebe ser entre %d y %d \n",minimo,maximo);
        }
    } while(dato < minimo || dato > maximo);
}

void cargarAlumnos(T_Alumno *Alumno,int cant)
{
    char continuar;
    for(int i=0;i<cant;i++)
    {
        cargarAlumno(&Alumno[i]);

        printf("\n Desea Cargar otro alumno: (s/n) ");
        scanf("%c",continuar);
        if(continuar=='n')
        {
            i=cant;
        }
    }
}

void cargarAlumno(T_Alumno *Alumno)
{
    get_char("Ingrese el nombre del alumno:",Alumno->nombre);
    get_intMayor0("Ingrese Legajo: ",Alumno->legajo);
    get_int_entre("Ingrese la 1er nota del alumno: ",Alumno->nota1,1,10);
    get_int_entre("Ingrese la 2da nota del alumno: ",Alumno->nota2,1,10);

    Alumno->promedio=calculapromedio(Alumno->nota2,Alumno->nota2);
    Alumno->estado=TRUE;
}

float calculapromedio(int nota1,int nota2)
{
    float aux;
    aux=(float) nota1+nota2/2;
    return aux;
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
