#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define Personas 20



int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[Personas];
    char dato[50];

    vaciarLista(lista);
    HardCodeLista(lista);



    while(seguir=='s')
    {
        crearMenu();

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                Agregar_Persona(lista,dato);
                /*HardCodeLista(lista);
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

                system("pause");*/
                break;
            case 2:
                borrar_Persona(lista);
                break;
            case 3:
                ordenar_x_Nombre(lista,Personas);
                listarTodo(lista);
                system("pause");
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
