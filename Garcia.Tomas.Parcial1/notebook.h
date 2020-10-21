#ifndef NOTEBOOK_L_H
#define NOTEBOOK_L_H
#include "tipo.h"
typedef struct{

    int id;
    char modelo[21];
    float precio;
    int idMarca;
    int idTipo;
    int isEmpty;
}enotebook;
#endif//NOTEBOOK_H

void inicializarNotebook(enotebook* notebook,int tam);
int buscarNotebookLibre(enotebook* notebook, int tam);
void altaNotebook(enotebook notebook[],int tam);
int notebookBuscarID(enotebook notebook[], int tam, int valorBuscado, int* posicion);
int notebookModificar(enotebook* notebook, int tam, etipo tipo[], int tamT);
int notebookListar(enotebook notebook[], int tam);
int notebookBaja(enotebook notebook[], int tam);
int notebookListarTodos(enotebook notebook[], int tam);
int verificarIdNotebook(enotebook notebook[], int tam, int id);
int verificarArray(enotebook notebook[], int tam);
