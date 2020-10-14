#ifndef TIPO_L_H
#define TIPO_L_H
typedef struct{
    int id;
    char descripcion [21];
}etipo;




void hardcodearTipo(etipo tipo[], int tam);
int verificarIdTipo(etipo tipo[], int tam, int id);
int tipoListar(etipo tipo[], int tam);
#endif//TIPO_H
