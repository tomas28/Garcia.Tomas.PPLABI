#ifndef MARCA_L_H
#define MARCA_L_H
typedef struct{

    int id;
    char descripcion[21];
}emarca;

#endif//MARCA_H
int marcaListar(emarca marca[], int tam);
void hardcodearMarcas(emarca marca[], int tam);
