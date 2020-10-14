#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "tipo.h"
#include "notebook.h"
#include "servicios.h"
#include "tipo.h"
#include "trabajo.h"
#define TAMT 4
#define TAMMA 4
void hardcodearTipo(etipo tipo[], int tam)
{
    etipo auxTipo[] =
    {
        {5000, "Gamer",},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
    };

    for(int i=0; i<tam; i++)
    {
        tipo[i] = auxTipo[i];
    }
}

int verificarIdTipo(etipo tipo[], int tam, int id){
    int retorno=-1;
        for(int i = 0; i < tam; i++ ){
            if(tipo[i].id == id){
                retorno = 0;
            }
        }
    return retorno;
}

int tipoListar(etipo tipo[], int tam)
{
    int retorno=-1;
    int i;
    if(tipo!=NULL && tam>=0)
    {
         printf("ID  |Descripcion|\n");
        for(i=0;i<tam;i++)
        {
            printf("\n %2d|  %5s|  \n",tipo[i].id, tipo[i].descripcion);
        }
        retorno=0;
    }
    return retorno;
}
