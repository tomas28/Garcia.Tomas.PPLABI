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
#define TAMS 4

void hardcodearServicios(eservicios servicios[], int tam)
{
    eservicios auxServicios[] =
    {
        {20000, "Bateria",250},
        {20001, "Antivirus",300},
        {20002, "Actualizacion",400},
        {20003, "Fuente",600}
    };

    for(int i=0; i<tam; i++)
    {
        servicios[i] = auxServicios[i];
    }
}

int serviciosListar(eservicios servicios[], int tam)
{
    int retorno=-1;
    int i;
    if(servicios!=NULL && tam>=0)
    {
         printf("ID  |Descripcion| Precio\n");
        for(i=0;i<tam;i++)
        {
            printf("\n %2d|  %5s| %f \n",servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        retorno=0;
    }
    return retorno;
}
