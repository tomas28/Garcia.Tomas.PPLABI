#include "fecha.h"
#include "notebook.h"
#ifndef TRABAJO_L_H
#define TRABAJO_L_H
typedef struct{
    int id;
    int idNotebook;
    int idServicio;
    efecha fecha;
    int isEmpty;
}etrabajo;
#endif//TRABAJO_H

void inicializarTrabajo(etrabajo* trabajo,int tam);
int buscarTrabajoLibre(etrabajo* trabajo, int tam);
void altaTrabajo(etrabajo trabajo[],int tam, enotebook notebook[], int tamn, int* id);
int trabajoListar(etrabajo trabajo[], int tam);
void hardcodearTrabajo(etrabajo trabajo[], int tam);
