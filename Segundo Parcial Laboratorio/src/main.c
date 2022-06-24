#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "servicios.h"

int main() {
	setbuf(stdout, NULL);
	int flagMenu = 0;
	int flagCargar = 0;

	char path[30];
	int menu = 0;

	LinkedList *listaServicios = ll_newLinkedList();

	do {
		printf("\n\t|--------------------------------------------|");
		printf("\n\t|\t\tMenu de Opciones\t     |\n"
				"\t|\t\t\t\t\t     |");
		printf(
				"\n\t| 1. Cargar archivo\t\t\t     |\n"
				"\t| 2. Imprimir lista\t\t\t     |\n"
				"\t| 3. Asignar totales\t\t\t     |\n"
				"\t| 4. Filtrar por tipo\t\t\t     |\n"
				"\t| 5. Mostrar servicios\t\t\t     |\n"
				"\t| 6. Guardar servicios\t\t\t     |\n"
				"\t| 7. Salir\t\t\t\t     |\n"
				"\t|\t\t\t\t\t     |"
		"\n\t|--------------------------------------------|"

				"\n\t  Ingrese una opcion:");
		fflush(stdin);
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			if (flagCargar == 0) {
				flagCargar = 1;
				printf("\n\tIngrese el nombre del archivo a abrir:");
				fflush(stdin);
				gets(path);
				controller_loadFromText(path, listaServicios);
				flagMenu = 1;

			} else {
				printf("Solo se puede cargar una vez\n");
			}
			break;
		case 2:
			if (flagMenu == 0) {
				printf("\tPrimero debe cargar el archivo");
			} else {
				controller_ListServicio(listaServicios);
			}
			break;
		case 3:
			if (flagMenu == 0) {
				printf("\tPrimero debe cargar el archivo");
			} else {
				controller_addservicio(listaServicios);

			}
			break;
		case 4:
			if (flagMenu == 0) {
				printf("\tPrimero debe cargar el archivo");
			} else {
				controller_filter(listaServicios);
			}
			break;
		case 5:
			if (flagMenu == 0) {
				printf("\tPrimero debe cargar el archivo");
			} else {
				controller_sortdescripcion(listaServicios);
				controller_ListServicio(listaServicios);
			}
			break;
		case 6:
			if (flagMenu == 0) {
				printf("\tPrimero debe cargar el archivo");
			} else {
				printf("\tIngrese el nombre del archivo a guardar.");
				fflush(stdin);
				gets(path);
				controller_saveAsText(path, listaServicios);
			}

			break;
		case 7:
				printf("\n\t  Apagando Sistema.\n");
			break;
		default:
			printf("\tOpcion no valida.\n");
			break;

		}
	} while (menu != 7);
	return 0;
}
