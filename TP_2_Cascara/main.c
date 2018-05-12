#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"




int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[Personas];

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
                Agregar_Persona(lista);

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
                crearGrafica (lista);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
