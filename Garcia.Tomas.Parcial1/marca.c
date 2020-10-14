#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "marca.h"
#include "marca.h"
#include "servicios.h"
#include "tipo.h"
#include "trabajo.h"
#define TAMT 4
#define TAMMA 4

void hardcodearMarcas(emarca marca[], int tam)
{
    emarca auxMarca[] =
    {
        {1000, "Compaq"},
        {1001, "Asus"},
        {1002, "Acer"},
        {1003, "HP"}
    };

    for(int i=0; i<tam; i++)
    {
        marca[i] = auxMarca[i];
    }
}

int marcaListar(emarca marca[], int tam)
{
    int retorno=-1;
    int i;
    if(marca!=NULL && tam>=0)
    {
         printf("ID  |Descripcion|\n");
        for(i=0;i<tam;i++)
        {
            printf("\n %2d|  %5s|  \n",marca[i].id, marca[i].descripcion);
        }
        retorno=0;
    }
    return retorno;
}
