#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[20];

    while(seguir=='s')
    {
        crearMenu();

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
              aux = leerDato();
              //system("cls");
              printf("%s",aux);

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
