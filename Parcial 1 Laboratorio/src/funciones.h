/*
 * funciones.h
 *
 *  Created on: 23 may. 2022
 *      Author: Soriano Baccarelli Lucas
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define VACIO -1

struct{

int idVivienda;
char calle[25];
int cantidadPersonas;
int cantidadHabitaciones;
int tipoVivienda; //1 casa 2 Departamento 3 Casilla 4 Rancho
int legajoCensista;
int isEmpty;
}typedef Vivienda;

struct{
int legajoCensista;
char nombre[50];
int edad;
char telefono[12];
int isEmptyCenso;
}typedef Censista;

/// @brief Inicializa el array de censista
///
/// @param list
/// @param tamCenso
/// @return
int iniciarCensista(Censista *list, int tamCenso);

/// @brief carga los datos de los censistas
///
/// @param list
/// @param tamCenso
/// @param legajoCensista
/// @param nombre
/// @param edad
/// @param telefono
/// @return
int cargaCenso(Censista *list, int tamCenso, int legajoCensista, char nombre[], int edad, char telefono[]);

/// @brief muestra el listado de todos los censistas cargados en la array
///
/// @param lista
/// @param tamCenso
/// @return
int mostrarCensistas(Censista *list,int  tamCenso);

/// @brief Inicializa el array de vivienda
///
/// @param list
/// @param tam
/// @return
int iniciarVivienda(Vivienda *list, int tam);

/// @brief carga los datos de las viviendas
///
/// @param list
/// @param tam
/// @param idVivi
/// @param calle
/// @param cantidadPersonas
/// @param cantidadHabitantes
/// @param tipoVivienda
/// @param legajoCensista
/// @return
int cargarVivienda(Vivienda *list, int tam, int idVivi, char calle[], int cantidadPersonas, int cantidadHabitantes, int tipoVivienda, int legajoCensista);

/// @brief Modifica los datos de la vivienda atraves de su ID
///
/// @param list
/// @param tam
/// @param idVivi
/// @return
int modificarVivienda(Vivienda *list, int tam, int idVivi);

/// @brief elimina una viviendra del array atraves de su ID
///
/// @param list
/// @param tam
/// @param idVivi
/// @return
int borrarVivienda(Vivienda *list, int tam, int idVivi);

/// @brief Ordenada la lista mediante un orden determinado
///
/// @param list
/// @param tam
/// @param ordenar
/// @return
int ordenarViviendas(Vivienda *list, int tam);

/// @brief muestra el listado de las viviendas ingresadas
///
/// @param list
/// @param tam
/// @return
int mostrarVivienda(Vivienda *list, int tam, Censista *listCen);

#endif /* FUNCIONES_H_ */
