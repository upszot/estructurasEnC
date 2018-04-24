#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
// la forma vieja.. que recibia posicion de memoria del campo donde habia que cargar...
// y sin control de longitud
void get_char(char *sms,char *texto)
{
    fflush(stdin);
    printf("%s ",sms);
    gets(texto);
}
*/

char *get_char(char *sms,int LongitudCadena)
{
    char  Aux_texto[200];
    char Texto[LongitudCadena];

    do
    {
        fflush(stdin);
        printf("%s ",sms);
        gets(Aux_texto);
        fflush(stdin);

        if(strlen(Aux_texto)+1<LongitudCadena)
        {
            strcpy(Texto,Aux_texto);
        }
        else
        {
            printf("\n Usted exedio la longitud Maxima permitida del campo (%d) ",LongitudCadena -1);
            printf("\n Por favor reingrese el dato pedido:" );
        }
    }while(strlen(Aux_texto)+1>=LongitudCadena);
    return Texto;
}

int get_int_entre(char *sms,int minimo, int maximo)
{
    int dato;
    do
    {
        printf("%s ",sms);
        scanf("%d",dato);
        if(dato < minimo || dato > maximo)
        {
            printf("\nDebe ser entre %d y %d \n",minimo,maximo);
        }
    } while(dato < minimo || dato > maximo);
    return dato;
}


int Get_intMayor_X(char *sms,int X)
{
    int dato;
    do
    {
        printf("%s ",sms);
        scanf("%d",dato);
    } while(dato < X);
    return dato;
}

float calculapromedio(int nota1,int nota2)
{
    float aux;
    aux=(float) nota1+nota2/2;
    return aux;
}

float CalculaPromedio_N_Numeros(int numeros[],int Cantidad)
{
    float Promedio;
    int sumatoria=0;
    int i;
    for (i=0;i<Cantidad;i++)
    {
        sumatoria=sumatoria+numeros[i];
    }
    Promedio=(float) sumatoria/i-1;
    return Promedio;
}
