#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "servicios.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArraylistaServicios) {
	FILE *pFile;
	int retorno;
	pFile = fopen(path, "r");
	if (pFile == NULL) {
		retorno = 0;
	} else {
		parser_ServicioFromText(pFile, pArraylistaServicios);
		fclose(pFile);
		retorno = 1;
	}
	return retorno;
}

int controller_addservicio(LinkedList *pArraylistaServicios) {

	ll_map(pArraylistaServicios, servicioMapeo);
	return 0;
}

/** \brief Listar servicios
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListServicio(LinkedList *pArraylistaServicios) {

	if (pArraylistaServicios != NULL) {
		servicio_Lista(pArraylistaServicios);
	}
	return 0;
}

/** \brief Ordenar servicios
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortdescripcion(LinkedList *pArraylistaServicios) {
	int order;
	printf("Ingrese el orden que desea (0 ascendente | 1 descendente)");
	scanf("%d", &order);
	ll_sort(pArraylistaServicios, servicio_descripcionComparados, order);

	return 0;
}
int controller_saveAsText(char *path, LinkedList *pArraylistaServicios) {
	FILE *pFile;

	int retorno = 1;
	pFile = fopen(path, "w");
	if (pFile == NULL) {
		retorno = 0;
	}

	int id;
	char descripcion[30];
	char tipo[30];
	float precio;
	int cantidad;
	float precioTotal;

	Node *indice = pArraylistaServicios->pFirstNode;
	fprintf(pFile, "%s,%s,%s,%s,%s,%s\n", "id", "descripcion", "tipo", "precio",
			"cantidad", "precioTotal");

	for (; indice != NULL; indice = indice->pNextNode) {

		servicio_getId(indice->pElement, &id);
		servicio_getDescripcion(indice->pElement, descripcion);
		servicio_getTipo(indice->pElement, tipo);
		servicio_getPrecio(indice->pElement, &precio);
		servicio_getCantidad(indice->pElement, &cantidad);
		servicio_getTotal(indice->pElement, &precioTotal);

		fprintf(pFile, "%d,%s,%s,%f,%d,%f\n", id, descripcion, tipo, precio,
				cantidad, precioTotal);

	}

	fclose(pFile);

	return retorno;

}

int controller_filter(LinkedList *pArraylistaServicios) {
	LinkedList *newList;
	char path[30];
	int order;
	printf("Ingrese el tipo que desea filtrar (1, 2 o 3)\n");
	scanf("%d", &order);
	switch (order) {
	case 1:
		newList = ll_filter(pArraylistaServicios, primerFilter);
		break;
	case 2:
		newList = ll_filter(pArraylistaServicios, segundoFilter);
		break;
	case 3:
		newList = ll_filter(pArraylistaServicios, tercerFilter);
		break;
	}
	controller_ListServicio(newList);

	printf("Ingrese un nombre para el archivo filtrado\n");
	fflush(stdin);
	gets(path);
	controller_saveAsText(path, newList);

	return 0;
}
