#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define Personas 20

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


/**
 * Crea menu - solo lo grafica no interactura con usuario
 * \param void
 * \return void
 *
 */
void crearMenu(void);

/**
 * Crea gráfico de barras rudimentario que muestra rango de edades
 * \param lista de donde se consultan las edades cargadas
 * \return void
 *
 */
void crearGrafica (EPersona[]);



/**
 * Imprime tipo de consulta (por nombre, edad o dni)
 * \param 1 nombre 2 edad 3 dni
 *
 * \return void
 *
 */
void hacerConsulta (int);

/**
 * Valida si la cadena de caracteres pasada como parametro es entera
 * \param cadena de caracteres a verificar
 *
 * \return el entero en caso de ser valido, -1 en caso de error (-1 es un valor imposible en los parametros ingresados (edad y dni)
 *
 */
int validarInt (char[]);

/**
 * Pide ingresar texto por teclado y lo guarda en el arreglo
 * \param char[]
 * \return void
 *
 */
void leerDato(char[]);

/**
 * Carga valores en los registros para poder realizar pruebas con el programa sin tener que ingresar 20 registros
 * \param EPersona[]
 * \return void
 *
 */
void HardCodeLista(EPersona[]);

/**
 * Lista los registros cargados en memoria (solo los activos)
 * \param EPersona[]
 * \return void
 *
 */
void listarTodo(EPersona[]);

/**
 * Funcion que pone todos los registros como "borrables" usada solo en pruebas con el tp.
 * \param EPersona[]
 * \return void
 *
 */
void vaciarLista(EPersona[]);

/**
 * Cuenta los caracteres del arreglo que se pasa como parámetro. Usada en validaciones. Devuelve la cantidad de caracteres
 * \param char[]
 * \return int - cantidad de caracteres del arreglo
 *
 */
int contar_caracteres(char[]);

/**
 * Funcion que agrega un nuevo registro al arreglo de  estructuras.
 * \param EPersona[] - arreglo en donde se carga el registro ingresado
 *
 * \return void
 *
 */
void Agregar_Persona(EPersona[]);

/**
 * Borra un registro, solicitando dni a borrar
 * \param EPersona[]
 * \return void
 *
 */
void borrar_Persona(EPersona[]);

/**
 * Ordena los registros por nombre, en forma descendente
 * \param EPersona[]
 * \param int - cantidad de registros que contiene el areglo de personas
 * \return void
 *
 */
void ordenar_x_Nombre(EPersona[], int);




#endif // FUNCIONES_H_INCLUDED
