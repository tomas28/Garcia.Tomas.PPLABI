#include <stdio.h>
#include <stdlib.h>
#include "marca.h"
#include "trabajo.h"
#include "servicios.h"
#include "tipo.h"
#include "trabajo.h"
#include <string.h>
#define TAMN 1000
#define TAMT 4
#define TAMMA 4
#define TAMS 4

void inicializarTrabajo(etrabajo* trabajo,int tam)
{

    for(int i=0; i < tam; i++)
    {
        trabajo[i].isEmpty = 1;
    }
}

int buscarTrabajoLibre(etrabajo* trabajo, int tam){
    int i;
    int index=-1;

        for(i=0; i<tam; i++){
            if(trabajo[i].isEmpty==1){
            index=i;
            break;
        }
    }

    return index;
}

void altaTrabajo(etrabajo trabajo[],int tam, enotebook notebook[], int tamn, int* id){
    int i;
    i= buscarTrabajoLibre(trabajo,tam);
    if(i!=-1 && verificarArray(notebook,tam)!=0){

        notebookListar(notebook,TAMN);
        printf("ingrese la ID de una notebook\n ");
        fflush(stdin);
        scanf("%d",&trabajo[i].idNotebook);

         while(verificarIdNotebook(notebook, TAMN, trabajo[i].idNotebook )==-1 ){
            printf("ingrese una ID existente\n");
            fflush(stdin);
            scanf("%d",&trabajo[i].idNotebook);
        }

         printf("ingrese la ID del servicio:\n\n 20000) Bateria\n 20001) Antivirus:\n 20002) Actualizacion:\n 20003) Fuente:\n ");
        fflush(stdin);
        scanf("%d",&trabajo[i].idServicio);

         while(trabajo[i].idServicio < 20000 || trabajo[i].idServicio >20003 ){
            printf("ingrese una ID existente\n");
            fflush(stdin);
            scanf("%d",&trabajo[i].idServicio);
        }
         printf("ingrese el dia \n ");
        fflush(stdin);
        scanf("%d",&trabajo[i].fecha.dia);

         while(trabajo[i].fecha.dia <= 0 || trabajo[i].fecha.dia >31 ){
            printf("ingrese un dia entre 0 y 31\n");
            fflush(stdin);
            scanf("%d",&trabajo[i].fecha.dia);
        }
        printf("ingrese el mes \n ");
        fflush(stdin);
        scanf("%d",&trabajo[i].fecha.mes);

         while(trabajo[i].fecha.mes <= 0 || trabajo[i].fecha.mes >12 ){
            printf("ingrese un mes entre 0 y 12\n");
            fflush(stdin);
            scanf("%d",&trabajo[i].fecha.mes);
        }
        printf("ingrese el anio \n ");
        fflush(stdin);
        scanf("%d",&trabajo[i].fecha.anio);

         while(trabajo[i].fecha.anio < 0  ){
            printf("ingrese un anio positivo\n");
            fflush(stdin);
            scanf("%d",&trabajo[i].fecha.anio);
        }
        (*id)++;
        trabajo[i].id=*id;
        trabajo[i].isEmpty=0;

    }
    else
    {
        printf("No hay una notebook existente\n");
    }

}

int trabajoListar(etrabajo trabajo[], int tam)
{
    int retorno=-1;
    int i;
    if(trabajo!=NULL && tam>=0)
    {
         printf("ID |ID notebook  |ID servicio |fecha\n");
        for(i=0;i<tam;i++)
        {
            if(trabajo[i].isEmpty!=1)
            {
                printf("\n  %d| %d| %d| %d/%d/%d  \n",trabajo[i].id, trabajo[i].idNotebook, trabajo[i].idServicio, trabajo[i].fecha.dia, trabajo[i].fecha.mes, trabajo[i].fecha.anio);

            }
        }
        retorno=0;
    }
    return retorno;
}


