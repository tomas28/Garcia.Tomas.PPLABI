#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "marca.h"
#include "notebook.h"
#include "servicios.h"
#include "tipo.h"
#include "trabajo.h"
#define TAMN 1000
#define TAMT 4
#define TAMMA 4

void inicializarNotebook(enotebook* notebook,int tam)
{

    for(int i=0; i < tam; i++)
    {
        notebook[i].isEmpty = 1;
    }
}

int buscarNotebookLibre(enotebook* notebook, int tam){
    int i;
    int index=-1;

        for(i=0; i<tam; i++){
            if(notebook[i].isEmpty==1){
            index=i;
            break;
        }
    }

    return index;
}

void altaNotebook(enotebook notebook[],int tam){
    int i;
    i= buscarNotebookLibre(notebook,tam);
    if(i!=-1){
        printf("ingrese una ID : ");
        fflush(stdin);
        scanf("%d",&notebook[i].id);

         while(notebook[i].id < 0 ){
            printf("ingrese una ID positiva\n");
            fflush(stdin);
            scanf("%d",&notebook[i].id);
        }
        printf("ingrese un modelo: ");
        fflush(stdin);
        gets(notebook[i].modelo);
        printf("ingrese la ID de la marca:\n\n 1000) Compaq\n 1001) Asus\n 1002) Acer\n 1003) HP\n ");
        fflush(stdin);
        scanf("%d",&notebook[i].idMarca);

         while(notebook[i].idMarca < 1000 || notebook[i].idMarca >1003 ){
            printf("ingrese una ID existente\n");
            fflush(stdin);
            scanf("%d",&notebook[i].idMarca);
        }
        printf("ingrese un precio : ");
        fflush(stdin);
        scanf("%f",&notebook[i].precio);

         while(notebook[i].id < 0 ){
            printf("ingrese unprecio positivo\n");
            fflush(stdin);
            scanf("%f",&notebook[i].precio);
        }

        printf("ingrese la ID de tipo:\n\n 5000) Compaq\n 5001) Asus\n 5002) Acer\n 5003) HP\n ");
        fflush(stdin);
        scanf("%d",&notebook[i].idTipo);

         while(notebook[i].idTipo < 5000 || notebook[i].idTipo >5003 ){
            printf("ingrese una ID existente\n");
            fflush(stdin);
            scanf("%d",&notebook[i].idTipo);
        }

        notebook[i].isEmpty=0;

    }
    else
    {
        printf("No hay espacio\n");
    }

}

int notebookBuscarID(enotebook notebook[], int tam, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(notebook!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(notebook[i].isEmpty==1)
                continue;
            else if(notebook[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int notebookModificar(enotebook* notebook, int tam, etipo tipo[], int tamT)
{
    int retorno=-1;
    int posicion;
    int idNo;
    char opcion;

    if(notebook!=NULL && tam>0)
    {
        int i;
        notebookListar(notebook,TAMN);
        printf("ingrese la id de la notebook a modificar");
        scanf("%d",&idNo);
        i=notebookBuscarID(notebook,tam,idNo,&posicion);
        if(i==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                notebookListar(notebook,TAMN);
                printf("ingrese una opcion:\n a)- cambiar tipo\n b)- cambiar precio\n s)- salir\n");
                fflush(stdin);
                scanf("%c",&opcion);
                switch(opcion)
                {
                    case 'a':
                        printf("ingrese el nuevo ID de orquesta: ");
                        scanf("%d",&notebook[posicion].idTipo);

                        while(verificarIdTipo(tipo , TAMT, notebook[i].idTipo )== -1){
                            printf("ingrese una ID existente\n");
                            fflush(stdin);
                            scanf("%d",&notebook[i].idTipo);
                        }
                        system("pause");
                        break;

                    case 'b':
                        printf("ingrese el nuevo precio: ");
                        scanf("%f",&notebook[posicion].precio);

                        while(notebook[posicion].precio < 0 ){
                            printf("ingrese un precio positivo\n");
                            fflush(stdin);
                            scanf("%f",&notebook[posicion].precio);
                        }
                        system("pause");
                        break;

                    case 's':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
                system("cls");

            }while(opcion!='s');
            retorno=0;
        }
    }
    return retorno;
}

int notebookListar(enotebook notebook[], int tam)
{
    int retorno=-1;
    int i;
    if(notebook!=NULL && tam>=0)
    {
         printf("ID  |modelo| precio | ID de tipo | \n");
        for(i=0;i<tam;i++)
        {
            if(notebook[i].isEmpty!=1)
            {
                printf("\n %2d|  %5s| %.2f| %d | \n",notebook[i].id, notebook[i].modelo, notebook[i].precio, notebook[i].idTipo);

            }
        }
        retorno=0;
    }
    return retorno;
}

int notebookBaja(enotebook notebook[], int tam)
{
    int retorno=-1;
    int posicion;
    int idNo;
    notebookListar(notebook,TAMN);

    if(notebook!=NULL && tam>0)
    {
        printf("ingrese la id que se busca");
        scanf("%d",&idNo);
        if(notebookBuscarID(notebook,tam,idNo,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            notebook[posicion].isEmpty=1;
            notebook[posicion].id=0;
            strcpy(notebook[posicion].modelo,"");
            notebook[posicion].precio = 0;
            notebook[posicion].idTipo = 0;
            notebook[posicion].idMarca = 0;
            retorno=0;
            printf("se elimino correctamente\n");
        }
    }
    return retorno;
}

int notebookListarTodos(enotebook notebook[], int tam)
{
    int retorno=-1;
    int i;
    if(notebook!=NULL && tam>=0)
    {
         printf("ID |marca  |precio | ID de Marca| ID de Tipo\n");
        for(i=0;i<tam;i++)
        {
            if(notebook[i].isEmpty!=1)
            {
                printf("\n %2d|  %5s| %f| %d| %d|  \n",notebook[i].id, notebook[i].modelo, notebook[i].precio,notebook[i].idMarca,notebook[i].idTipo);

            }
        }
        retorno=0;
    }
    return retorno;
}
