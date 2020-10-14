#include <stdio.h>
#include <stdlib.h>
#include "marca.h"
#include "notebook.h"
#include "servicios.h"
#include "tipo.h"
#include "trabajo.h"
#include <string.h>
#define TAMN 1000
#define TAMT 4
#define TAMMA 4
#define TAMS 4

int main()
{
    char seguir;

    enotebook notebook[TAMN];
    etipo tipo[TAMT];
    emarca marca[TAMMA];
    eservicios servicio[TAMS];

    int flag=0;


    inicializarNotebook(notebook,TAMN);
    hardcodearTipo(tipo,TAMT);
    hardcodearMarcas(marca,TAMMA);
    hardcodearServicios(servicio,TAMS);


    while(seguir != 's'){
        printf("\n 1-Alta notebook \n 2-Modificar notebook \n 3-Baja notebook \n 4-Listar notebook \n 5-Listar marcas \n 6-Listar tipos \n 7-Listar servicios \n 0-Salir \n\n\n");
        fflush(stdin);
        scanf("%c",&seguir);


        system("cls");

        switch(seguir)
            {
            case '1':

                printf("\nAlta notebook\n\n");

                altaNotebook(notebook,TAMN);
                system("pause");
                flag=1;
                break;

            case '2':
                if (flag==1){
                    printf("\nmodificar notbook\n\n");
                    notebookModificar(notebook,TAMN,tipo,TAMT);
                }else{
                    printf("no se puede modificar sin dar alta una notbook\n");
                }
                system("pause");
                break;

            case '3':
                if (flag==1){
                    printf("\baja notebook\n\n");
                    notebookBaja(notebook,TAMN);
                }else{
                    printf("no se puede dar de baja sin antes dar de alta una notbook\n");
                }
                system("pause");
                break;

            case '4':
                if(flag==1){
                    printf("\n listar notbook\n\n");
                    notebookListarTodos(notebook,TAMN);

                }else{
                    printf("no se puede listar  agregar una notbook");
                }
                    system("pause");
                break;

            case '5':

                    printf("\n Listar marcas\n\n");
                    marcaListar(marca,TAMMA);

                system("pause");
                break;
            case '6':
                    printf("\n listar tipos\n\n");
                    tipoListar(tipo,TAMT);
                    system("pause");
                break;

            case '7':

                    printf("\nListar servicios\n\n");
                    serviciosListar(servicio,TAMS);
                system("pause");
                break;


            case '0':
                printf("usted salio del programa\n");
                seguir='s';
                system("pause");
                break;

            default:
                printf("\n Opcion invalida\n\n");
                system("pause");
                system("break");

        }
        system("cls");

    }
    return 0;
}
