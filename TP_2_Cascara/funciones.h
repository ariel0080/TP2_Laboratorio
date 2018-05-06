#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]); //lista



/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

//FUNCIONES GRAFICAS

void crearMenu(void); // lista

void crearGrafica (int,int,int);

// FUNCIONES DE VALIDACION DE ENTRADA

void hacerConsulta (int); //Lista 1nombre 2 edad 3 dni

int validarInt (char[]); //listo

void leerDato(char[]);//listo

void HardCodeLista(EPersona[]); //Lista

void listarTodo(EPersona[]); //lista

void vaciarLista(EPersona[]); //listo

int contar_caracteres(char[]); //listo



#endif // FUNCIONES_H_INCLUDED
