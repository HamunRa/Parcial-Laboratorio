/*
 ============================================================================
 Name        : Parcial.c
 Author      : Soriano Baccarelli Lucas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

int main(void) {

	setbuf(stdout, NULL);
	int menu;
	int subMenu;
	int tam = 30000;
	int tamCenso = 5;
	int banderaCarga = 0;

//Vivienda
	int idVivienda = 20000;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int buscarId;
	int posicionVivienda;
	int borrar;

//Censistas
	int legajoCenso;

//Llamar estructuras


	Censista empleados[5] = {{100, "Ana", 34, "1203-2345"},
							{101, "Juan", 24, "4301-54678"},
							{102, "Sol", 47, "5902-37487"}};
	Vivienda censo[tam];

//Inicializar arrays
	iniciarCensista(empleados, tamCenso);
	iniciarVivienda(censo, tam);

	do {
		printf("\n1. ALTA VIVIENDA\n"
				"2. MODIFICAR VIVIENDA\n"
				"3. BAJA VIVIENDA\n"
				"4. LISTAR VIVIENDAS\n"
				"5. LISTAR CENSISTAS\n"
				"6. Salir\n"
				"\nIngrese la opcion deseada: ");
		scanf("%d", &menu);
		fflush(stdin);

		switch (menu) {
		case 1:
			validarCalle(calle, "\nIngrese el nombre de la calle");
			utn_getInt(&cantidadPersonas,
					"\nIngrege la cantidad de personas que viven en la vivienda",
					"Error, ingrese un valor valido", 1, 100);
			utn_getInt(&cantidadHabitaciones,
					"\nIngrege la cantidad habitaciones",
					"Error, ingrege un valor valido", 1, 100);
			utn_getInt(&tipoVivienda,
					"\nIngrese el tipo de vivienda(1. Casa, 2. Departamento, 3. Casilla, 4. Rancho)",
					"Error, Ingrese una opcion valida", 1, 4);
			utn_getInt(&legajoCenso,
					"\nIngrege el legajo del censista(100, 101, 102)",
					"Error, legajo equivocado", 100, 102);
			idVivienda++;
			banderaCarga = 1;
			cargarVivienda(censo, tam, idVivienda, calle, cantidadPersonas,
					cantidadHabitaciones, tipoVivienda, legajoCenso);
			break;
		case 2:
			if (banderaCarga == 0) {
				printf("\nFalta ingresar viviendas.\n");
				break;
			}
			printf("\nIngrese la ID de la Vivienda\n");
			fflush(stdin);
			scanf("%d", &buscarId);

			posicionVivienda = modificarVivienda(censo, tam, buscarId);

			if (posicionVivienda == -1) {
				printf("No existe esa ID");
			} else {
				do {
					printf("\n1. Modificar calle.\n"
							"2. Modificar cantidad de personas.\n"
							"3. Modificar cantidad de habitaciones.\n"
							"4. Modificar tipo de vivienda.\n"
							"5. Modificar el legajo del censista.\n"
							"6. Volver al menu principal.\n");
					scanf("%d", &subMenu);
					fflush(stdin);

					switch (subMenu) {
					case 1:
						validarCalle(censo[posicionVivienda].calle,
								"\nIngrese la calle.");
						break;
					case 2:
						utn_getInt(&censo[posicionVivienda].cantidadPersonas,
								"\nIngrese la cantidad de personas.",
								"Error, ingrese un valor valido", 1, 100);
						break;
					case 3:
						utn_getInt(
								&censo[posicionVivienda].cantidadHabitaciones,
								"\nIngrese la cantidad de habitaciones.",
								"Error, ingrese un valor valido", 1, 100);
						break;
					case 4:
						utn_getInt(&censo[posicionVivienda].tipoVivienda,
								"\nIngrese el tipo de vivienda.(1. Casa,2. Departamento,3. Casilla,4. Rancho)",
								"Error, ingrese un opcion valida", 1, 4);
						break;
					case 5:
						utn_getInt(&censo[posicionVivienda].legajoCensista,
								"\nIngrese el legajo del censista.(100, 101, 102)",
								"Error, legajo equivocado", 100, 102);
						break;
					case 6:
						printf("Regresando al menu principal.");
						break;

					default:
						printf("\nOpcion no valida.");

					}
				} while (subMenu != 6);
			}

			break;

		case 3:
			if (banderaCarga == 0) {
				printf("\nFalta ingresar viviendas.\n");
				break;
			}
			printf("\nIngrege la id de la vivienda a Borrar.\n");
			fflush(stdin);
			scanf("%d", &borrar);

			borrarVivienda(censo, tam, borrar);
			printf("La ID Se borro");

			break;
		case 4:
			if (banderaCarga == 0) {
				printf("\nFalta ingresar viviendas.\n");
				break;
			}
			ordenarViviendas(censo, tam);
			mostrarVivienda(censo, tam, empleados);

			break;
		case 5:
			mostrarCensistas(empleados, tamCenso);
			break;
		case 6:
			printf("\n¡Hasta la proxima!");
			break;

		default:

			printf("\nOpcion no valida.\n");
			break;
		}

	} while (menu != 6);

	return EXIT_SUCCESS;
}
