/*
 * utn.h
 *
 *  Created on: 23 may. 2022
 *      Author: Soriano Baccarelli Lucas
 */

#ifndef UTN_H_
#define UTN_H_

/// @brief pide ingresar la calle y lo devuelve
///
/// @param calleIngresada
/// @param textoMostrar
/// @return
void validarCalle(char calleIngresada[], char * textoMostrar);

/// @brief pide al usuario un dato a traves de string y cambia el ultimo bit de '\n' a '\0'
///
/// @param cadena por donde se devuelve el string
/// @param longitud tamaño del string
/// @return devuelve -1 si hay error - 0 si esta bien

int myGets(char *cadena, int longitud);

/// @brief transforma el string de esNumerica y myGets a un entero
///
/// @param pResultado donde se devuelve el entero obtenido
/// @return devuelve -1 si hay error - 0 si esta bien

int getInt(int *pResultado);

/// @brief verifica que todos sus digitos sson numericos
///
/// @param cadena por donde devuelve el string
/// @return devuelve 0 si hay error o - 1 si esta bien

int esNumerica(char *cadena);

/// @brief pide al usuario ingresar un entero usando getInt, lo verifica y lo devuelve
///
///
/// @param pResultado por el cual devuelve el entero
/// @param mensaje que se imprime para pedir el dato al usuario
/// @param mensajeError se imprime cuando el usuario no ingreso un entero
/// @param minimo delimita el numero minimo a ingresar
/// @param maximo delimita el numero maximo a ingresar
/// @return devuelve -1 si hay error - 0 si esta bien

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);

#endif /* UTN_H_ */
