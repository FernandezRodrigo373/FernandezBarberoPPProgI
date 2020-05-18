#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

typedef struct
{
   int id;
   char procesador[30];
   char marca[20];
   float precio;

}Notebook;


int aplicarDescuento(float precio);
int ordenarArray(Notebook vec[], int tam);
void hardcodearDatos(Notebook vec[], int cant);
int menu();




int main()
{
    float precio;

    Notebook componentes[TAM] = { {1000 , "I5", "Intel", 10000}, {1001 , "5", "Ryzen", 11000}, {1002 , "I7", "Intel", 17000} };

    hardcodearDatos(componentes, TAM);

    switch(menu())
    {
        case 1:
            printf("Ingrese el precio del producto: ");
            scanf("%f", &precio);


            aplicarDescuento(precio);
            break;

        case 2:
            ordenarArray(componentes, TAM);
            break;
    }







    return 0;
}

int menu()
{
    int opcion;

    printf("1 - aplicarDescuento\n");
    printf("2 - ordenarArray\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);


    return opcion;
}


int aplicarDescuento(float precio)
{
    float valorConDescuento;
    int descuento = 5;
    float precioFinal;

    system("cls");

    valorConDescuento = (float) precio*descuento/100;

    precioFinal = precio - valorConDescuento;

    printf("Valor con descuento es: %.2f", precioFinal);

    return precioFinal;
}

/*int contarCaracteres(char cadena[], char caracter)
{
    int contadorCaracteres;




    return contadorCaracteres;
}*/

int ordenarArray(Notebook vec[], int tam)
{
    int allOk = -1;

    Notebook auxNotebook;

    system("cls");
    printf("-------------Lista de Componentes-------------\n\n");


    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            allOk = 0;
                if(vec[i].marca > vec[j].marca)
                {
                    auxNotebook = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxNotebook;
                }
                else if(vec[i].marca == vec[j].marca && vec[i].precio == vec[j].precio)
                {
                    auxNotebook = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxNotebook;
                }
        }
    }

    for(int i = 0; i < tam; i++)
    {
        printf("%7d | %7s | %7s | %7.2f \n", vec[i].id, vec[i].procesador, vec[i].marca, vec[i].precio);
    }

    return allOk;
}

void hardcodearDatos(Notebook vec[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        vec[i].id = vec[i].id;
        strcpy(vec[i].procesador, vec[i].procesador);
        strcpy(vec[i].marca, vec[i].marca);
        vec[i].precio = vec[i].precio;
    }
}







