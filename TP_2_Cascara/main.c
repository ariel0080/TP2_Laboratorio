#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX_INT 2147483647


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[20];
    char dato[50];

    while(seguir=='s')
    {
        crearMenu();

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                HardCodeLista(lista);
                //vaciarLista(lista);
                listarTodo(lista);
                system("pause");
                printf("espaciolibre %d",obtenerEspacioLibre(lista));
                system("pause");
                system("cls");
                hacerConsulta(1);
                leerDato(dato);
                printf("Ingresado: %s",dato);
                printf("Lo ngresado tiene estos caracteres: %d",contar_caracteres(dato));

                system("pause");
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
