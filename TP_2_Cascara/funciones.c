#include <stdio.h>
#include <conio.h>
#include "funciones.h"
#include <string.h>



void crearMenu(void)
{
        system("cls");
        system("COLOR A");
        printf("**************************************************************\n");
        printf("**************************************************************\n");
        printf("**                                                          **\n");
        printf("**\t1- Agregar persona                                  **\n");
        printf("**\t2- Borrar persona                                   **\n");
        printf("**\t3- Imprimir lista ordenada por nombre               **\n");
        printf("**\t4- Imprimir grafico de edades                       **\n");
        printf("**                                                          **\n");
        printf("**\t5- Salir                                            **\n");
        printf("**                                                          **\n");
        printf("**************************************************************\n");
        printf("**************************************************************\n\n\n");

}


void hacerConsulta (int tipoConsulta)
{
        switch (tipoConsulta)
        {
            case 1:

                printf("\t Por favor ingrese nombre de la persona: ");
                break;
            case 2:

                printf("\t Por favor ingrese edad de la persona <0-120>: ");
                break;
            case 3:

                printf("\t Por favor ingrese dni de la persona: ");
                break;

        }
}

void HardCodeLista(EPersona lista[])
{
    char hardNombre[][20]={"Juan Perez","Ricardo Fort", "Diego Maradona","Susana Gimenez","Diego Diaz","Boby Goma","Benji Price","Oliver Atom","Moni Argento","Pepe Argento","Marcelo Tinelli","Ragnar Lodbrok","Laguerta Lodbrok","Helge Doppler","Jonas Kahnwald","Mikkel Nielsen","Charlotte Doppler","Bartosz Tiedemann","Claudia Tiedemann","Katharina Nielsen"};
    int hardEdad[] = {23,44,55,66,77,88,99,101,18,72,33,44,15,32,24,65,31,60,29,11};
    int hardDni[] = {23726357,44927483,558263482,66826472,778294872,888273517,99222111,10122555,18999999,72555555,33555444,44444444,15323212,32212333,24212888,65555555,31323999,60657888,29456789,11827999};

    for(int i=0;i<20;i++)
    {


        strcpy(lista[i].nombre,hardNombre[i]);
        lista[i].edad = hardEdad[i];
        lista[i].dni = hardDni[i];
        lista[i].estado = 1;
    }

}

void listarTodo(EPersona lista[])
{
    for (int a=0;a<20;a++)
    {
        printf("=============Registro: %d",a);
        printf("===============\n");
        printf("Nombre: %s\n",lista[a].nombre);
        printf("Edad: %d\n",lista[a].edad);
        printf("DNI: %d\n",lista[a].dni);
        printf("Estado: %d\n",lista[a].estado);
        printf("========================================\n\n\n\n");
    }
}

void vaciarLista(EPersona lista[])
{
    for (int i=0;i<20;i++)
    lista[i].estado = 0;
}

int obtenerEspacioLibre(EPersona lista[])
{
    int indice;
    int i=0;
    while (lista[i].estado == 1 && i<20)
        {
            i++;
            if (i==20){return -1;}
        }
    return indice;

}

void leerDato(char dato[])
{
 fgets(dato,50,stdin);
}

int contar_caracteres(char dato[])
{
    char c= dato[0];
    int i=0;
    while(c != '\0')
    {
        i++;
        c = dato[i];
    }
    return i-1;
}

int validarInt (char dato[])
{
   int i=0;
   while(dato[i] != '\0')
   {
       if (dato[i] >= '0' && dato[i] <='9')
       {
           i++;

       }else return -1;

   }return atoi(dato);
}
