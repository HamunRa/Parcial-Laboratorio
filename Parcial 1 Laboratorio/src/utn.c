/*
 * utn.c
 *
 *  Created on: 23 may. 2022
 *      Author: Soriano Baccarelli Lucas
 */
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void validarCalle(char calleIngresada[], char *textoMostrar){
	printf(textoMostrar);
	fflush(stdin);
	gets(calleIngresada);
}

int myGets(char *cadena, int longitud) {

	int retorno = -1;
	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int esNumerica(char *cadena) {

	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (isalpha(cadena[i]) != 0) {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int getInt(int *pResultado) {

	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo) {

	int bufferInt;
	int retorno = -1;

	while (retorno != 0) {
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}
