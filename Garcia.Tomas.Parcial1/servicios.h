#ifndef SERVICIOS_L_H
#define SERVICIOS_L_H
typedef struct{

    int id;
    char descripcion[26];
    float precio;
}eservicios;
void hardcodearServicios(eservicios servicios[], int tam);
int serviciosListar(eservicios servicios[], int tam);
#endif//SERVICIOS_H
