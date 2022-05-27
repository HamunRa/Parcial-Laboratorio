/*
 * funciones.c
 *
 *  Created on: 23 may. 2022
 *      Author: Soriano Baccarelli Lucas
 */

#include "funciones.h"
#include <string.h>
#include <stdio.h>

int iniciarCensista(Censista *list, int tamCenso) {

	for (int i = 0; i < tamCenso; i++) {
		list[i].isEmptyCenso = VACIO;
	}
	return 0;
}

int cargaCenso(Censista *list, int tamCenso, int legajoCensista,
		char nombre[], int edad, char telefono[]) {
	int retorno = -1;

	if (list != NULL) {

		for (int i = 0; i < tamCenso; i++) {
			if (list[i].isEmptyCenso == VACIO) {
				list[i].isEmptyCenso = 0;
				list[i].legajoCensista = legajoCensista;
				strcpy(list[i].nombre, nombre);
				list[i].edad = edad;
				strcpy(list[i].telefono, telefono);

				i = tamCenso + 1;
			}
		}
	}
	return retorno;
}

int mostrarCensistas(Censista *list, int tamCenso) {

	printf("\nListado de Censistas: \n\n");
	for (int i = 0; i < tamCenso; i++) {
		if (list[i].isEmptyCenso != -1) {
			printf("%d | ", list[i].legajoCensista);
			printf(list[i].nombre);
			printf(" | ");
			printf("%d ", list[i].edad);
			printf(" | ");
			printf(list[i].telefono);
			printf("\n");
		}
	}
	return 0;
}

int iniciarVivienda(Vivienda *list, int tam) {

	for (int i = 0; i < tam; i++) {
		list[i].isEmpty = VACIO;
		list[i].idVivienda = VACIO;
	}
	return 0;

}

int cargarVivienda(Vivienda *list, int tam, int idVivi, char calle[],
		int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda,
		int legajoCensista) {

	int retorno = -1;

	if (list != NULL) {

		for (int i = 0; i < tam; i++) {
			if (list[i].isEmpty == VACIO) {
				list[i].isEmpty = 0;
				list[i].idVivienda = idVivi;
				strcpy(list[i].calle, calle);
				list[i].cantidadPersonas = cantidadPersonas;
				list[i].cantidadHabitaciones = cantidadHabitaciones;
				list[i].tipoVivienda = tipoVivienda;
				list[i].legajoCensista = legajoCensista;

				printf("\nEl id de la vivienda es: %d\n", idVivi);

				i = tam + 1;
			}
		}
	}
	return retorno;
}

int modificarVivienda(Vivienda *list, int tam, int idVivi) {

	int posicion =-1;

	for (int i = 0; i < tam; i++) {
		if (list[i].idVivienda == idVivi) {
			posicion = i;
			i = tam + 1;
		}
	}

	return posicion;
}

int borrarVivienda(Vivienda *list, int tam, int idVivi) {

	int borrarId = -1;
	int retorno = 0;
	borrarId = modificarVivienda(list, tam, idVivi);

	if (borrarId == -1) {
		retorno = -1;
	}

	list[borrarId].isEmpty = -1;

	return retorno;
}

int ordenarViviendas(Vivienda *list, int tam) {

	Vivienda auxiliar;
	int retorno = -1;

	if (list != NULL) {
		if (tam >= 0) {
				for (int i = 0; i < tam; i++) {
					for (int j = i + 1; j < tam - 1; j++) {
						if (strcmp(list[i].calle, list[j].calle) > 0) {
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
						if (strcmp(list[i].calle, list[j].calle) == 0) {
							if (list[i].cantidadPersonas
									> list[j].cantidadPersonas) {
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
			} else {
				for (int i = 0; i < tam; i++) {
					for (int j = i + 1; j < tam - 1; j++) {
						if (strcmp(list[i].calle, list[j].calle) < 0) {
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
						if (strcmp(list[i].calle, list[j].calle) == 0) {
							if (list[i].cantidadPersonas
									> list[j].cantidadPersonas) {
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
			}
			retorno = 0;
	}

	return retorno;
}

int mostrarVivienda(Vivienda *list, int tam, Censista *listCen) {

	printf("\nListado de Viviendas: \n\n");

	for (int i = 0; i < tam; i++) {
		if (list[i].isEmpty != -1) {
			if (list[i].legajoCensista == 100) {
				printf("%d | ", listCen[0].legajoCensista);
				printf(listCen[0].nombre);
				printf(" | ");
				printf("%d ", listCen[0].edad);
				printf(" | ");
				printf(listCen[0].telefono);
				printf("\n");
			}
			if  (list[i].legajoCensista == 101){
				printf("%d | ", listCen[1].legajoCensista);
				printf(listCen[1].nombre);
				printf(" | ");
				printf("%d ", listCen[1].edad);
				printf(" | ");
				printf(listCen[1].telefono);
				printf("\n");
			}
			if (list[i].legajoCensista == 102){
				printf("%d | ", listCen[2].legajoCensista);
				printf(listCen[2].nombre);
				printf(" | ");
				printf("%d ", listCen[2].edad);
				printf(" | ");
				printf(listCen[2].telefono);
				printf("\n");
			}
			printf("%d | ", list[i].idVivienda);
			printf(list[i].calle);
			printf(" | ");
			printf("%d ", list[i].cantidadPersonas);
			printf(" | ");
			printf("%d ",list[i].cantidadHabitaciones);
			printf(" | ");
			if (list[i].tipoVivienda == 1) {
				printf("Casa | ");
			} else {
				if (list[i].tipoVivienda == 2) {
					printf("Departamento | ");
				} else {
					if (list[i].tipoVivienda == 3){
						printf("Casilla |");
					}else {
						printf("Rancho |");
					}
				}
			}
			printf("%d ", list[i].legajoCensista);
			printf("\n");
		}
	}
	return 0;
}

int cantidadCensado(Censista *list, Vivienda *listViv, int tam){

	int censistaUno = 0;
	int censistaDos = 0;
	int censistaTres = 0;

	for (int i = 0; i < tam; i++) {
		if (list[i].legajoCensista == 100) {
			censistaUno++;
		} else {
			if (list[i].legajoCensista == 101) {
				censistaDos++;
			} else {
				if (list[i].legajoCensista == 102) {
					censistaTres++;
				}
			}
		}
	}

	if(censistaUno > censistaDos && censistaUno > censistaTres){
		printf("El censista con mas viviendas censadas es Ana.");
	}else if (censistaDos > censistaUno && censistaDos > censistaTres){
		printf("El censista con mas viviendas censadas es Juan.");
	}else{
		printf("El censista con mas viviendas censadas es Sol.");
	}
	return 0;
}

