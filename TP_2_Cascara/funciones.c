#include <stdio.h>
#include <conio.h>
#include "funciones.h"
#include <string.h>
#include <windows.h>



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
    char hardNombre[][20]={"Martha Nielsen","Mikkel Nielsen", "Katharina Nielsen","Tronte Nielsen","Agnes Nielsen","Jonas Kahnwald","Hannah Kahnwald","Daniel Kahnwald","Franziska Doppler","Elisabeth Doppler","Charlotte Doppler","Bernd Doppler","Greta Doppler","Bartosz Tiedemann","Regina Tiedemann","Claudia Tiedemann","Egon Tiedemann","Doris Tiedemann","Ines Kahnwald","Mads Nielsen"};
    int hardEdad[] = {2,44,55,66,77,88,99,101,18,72,33,44,15,32,24,65,31,30,29,11};
    int hardDni[] = {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};

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
        if(lista[a].estado ==1)
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
}

void vaciarLista(EPersona lista[])
{
    for (int i=0;i<20;i++)
    lista[i].estado = 0;
}

int obtenerEspacioLibre(EPersona lista[])
{

    int i=0;
    while (lista[i].estado == 1 && i<20)
        {
            i++;
            if (i==20){return -1;}
        }
    return i;

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
   //printf("estoy dentro de validar int, muestro dato %s",dato);
   while(dato[i] != '\0' && (dato[i]=='0' || dato[i]=='1' || dato[i]=='2' || dato[i]=='3' || dato[i]=='4' || dato[i]=='5' || dato[i]=='6' || dato[i]=='7' || dato[i]=='8' || dato[i]=='9')){i++;}
   if(dato[i+1]=='\0') {return atoi(dato);}
   else return -1;


}

int buscarPorDni(EPersona lista[], int dni)
{
int indice=0;

    do{
        if(lista[indice].dni==dni && lista[indice].estado)
        {
            break;
        }
    }while(++indice<20);

    if(indice<20){
        return indice;
    }else{
        return -1;
    }
}

void Agregar_Persona(EPersona lista[])
{
    char dato[50];
    int indice;
    indice = obtenerEspacioLibre(lista);
    if (indice == -1)
    {
        system("cls");
        printf("\t\t\t NO HAY REGISTROS LIBRES PARA INGRESAR DATOS, BORRE ALGUNO QUE NO UTILIZA, GRACIAS!");
        system("pause");
    }
    else
    {
        hacerConsulta(1);
        leerDato(dato);
        //printf("el dato es: %s y el indice es: %d",dato,indice);
        strcpy(lista[indice].nombre,dato);

        hacerConsulta(2);
        leerDato(dato);
        //printf("%d  %d",contar_caracteres(dato),validarInt(dato));
            while(contar_caracteres(dato)>9 || validarInt(dato)==-1)
                {
                    printf("\n\t Ha ingresado caracteres invalidos o ha excedido el rango [9 caracteres], favor ingresar nuevamente edad\n\n");
                    hacerConsulta(2);
                    leerDato(dato);
                }
        lista[indice].edad = validarInt(dato);
        hacerConsulta(3);
        leerDato(dato);
            while(contar_caracteres(dato)>9 || validarInt(dato)==-1)
                {
                    printf("\n\t Ha ingresado caracteres invalidos o ha excedido el rango [9 caracteres], favor ingresar nuevamente edad\n\n");
                    hacerConsulta(3);
                    leerDato(dato);
                }
        if (buscarPorDni(lista,validarInt(dato))== -1)
        {
                lista[indice].dni = validarInt(dato);
                lista[indice].estado =1;
               // printf("\n\nEl resultado de validar por dni es, %d\n\n",buscarPorDni(lista,validarInt(dato)));
                system("pause");
        }
        else
            {
                lista[indice].estado=0;
                printf("\n\nYA EXISTE UN RESGITRO PARA EL DNI: %d\n\n",validarInt(dato));
                system("pause");
            }

    }

}


void borrar_Persona(EPersona lista[])
{
    char aux[50];
    int indice;
    char resp;
    printf("\n\n\tIngrese el DNI del registro que desea borrar: ");
    leerDato(aux);
    while(contar_caracteres(aux)>9 || validarInt(aux)==-1)
                {
                    printf("\n\t Ha ingresado caracteres invalidos o ha excedido el rango [9 caracteres], favor ingresar nuevamente edad\n\n");
                    hacerConsulta(3);
                    leerDato(aux);
                }
    indice = buscarPorDni(lista,validarInt(aux));
    if(indice!= -1)
    {
        printf("\nEsta seguro de eliminar el registro correspondiente a:\n");
        printf("%s\n",lista[indice].nombre);
        printf("Edad: %d\n",lista[indice].edad);
        printf("DNI: %d\n\n",lista[indice].dni);
        printf("s para borrar, cualquier otro caracter para desistir\n");
        scanf("%c",&resp);
        fflush(stdin);
        if (resp=='s'){lista[buscarPorDni(lista,validarInt(aux))].estado =0;}
    }
    else
    {
        printf("\n\nEl DNI ingresado no existe en los registros\n\n");
        system("pause");
    }

}

void ordenar_x_Nombre(EPersona lista[], int cantidad)
{

  int c, d,edad,estado,dni;
  char t[50];

  for (c = 0 ; c < ( cantidad - 1 ); c++)
  {
    for (d = 0 ; d < cantidad - c - 1; d++)
    {

      if (strcmp(lista[d].nombre,lista[d+1].nombre)>0)
      {
        strcpy(t,lista[d].nombre);
        edad=lista[d].edad;
        dni = lista[d].dni;
        estado = lista[d].estado;
        strcpy(lista[d].nombre,lista[d+1].nombre);
        lista[d].edad = lista[d+1].edad;
        lista[d].dni = lista[d+1].dni;
        lista[d].estado = lista[d+1].estado;
        strcpy(lista[d+1].nombre,t);
        lista[d+1].edad = edad;
        lista[d+1].dni =dni;
        lista[d+1].estado=estado;

      }
    }
  }
}

void crearGrafica (EPersona lista[])
{
    int vector_cantidades[3]={0,0,0};
    int maximo;


    for(int i=0;i<Personas;i++)
    {
        if (lista[i].estado==1)
        {
            if (lista[i].edad <= 18) {vector_cantidades[0]++;}
            if (lista[i].edad > 18 && lista[i].edad < 36) {vector_cantidades[1]++;}
            if (lista[i].edad > 35) {vector_cantidades[2]++;}
        }

    }

    system("cls");
    printf("\nGRAFICA DE EDADES DE LAS PERSONAS EN EL REGISTRO DE DATOS\n");
    printf("=========================================================\n\n\n\n");

    maximo = vector_cantidades[0];

    if (vector_cantidades[1]>maximo) maximo=vector_cantidades[1];
    if (vector_cantidades[2]>maximo) maximo=vector_cantidades[2];

     for(int i=maximo;i>=0;i--){
        if((vector_cantidades[0]-i)>0){
            printf("      ***      ||");
        }else{
            printf("               ||");
        }
        if((vector_cantidades[1]-i)>0){
            printf("      ***      ||");
        }else{
            printf("               ||");
        }
        if((vector_cantidades[2]-i)>0){
            printf("      ***       ");
        }
        printf("\n");
    }
    printf("=================================================\n");
    printf(" Menores de 18 ||  entre 19-35  ||   Mayores 35\n\n");
    printf("\nMenores de 18 a%cos: %d",164,vector_cantidades[0]);
    printf("\t Entre 19 y 35 a%cos: %d",164,vector_cantidades[1]);
    printf("\t Mayores de 35 a%cos: %d\n\n",164,vector_cantidades[2]);
    system("pause");
}







