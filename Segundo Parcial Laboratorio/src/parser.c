#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "servicios.h"

#include "string.h"
#include "ctype.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServicioFromText(FILE *pArchivo, LinkedList *pArraylistaServicios) {

	int retorno = -1;
	if (pArchivo != NULL) {
		if (pArraylistaServicios != NULL) {
			eServicio *newService;
			char idAux[30];
			char descAux[30];
			char tipoAux[30];
			char precioAux[30];
			char cantAux[30];
			char totalAux[30];

			fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux,
					descAux, tipoAux, precioAux, cantAux, totalAux);

			while (1) {
				if (fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
						idAux, descAux, tipoAux, precioAux, cantAux, totalAux)
						== 6) {
					newService = servicio_newParametros(idAux, descAux, tipoAux,
							precioAux, cantAux, totalAux);

					if (newService != NULL) {
						if (ll_add(pArraylistaServicios, newService) == 0) {
							retorno = 0;
						}
					}
				}

				if (feof(pArchivo) != 0) {
					break;
				}
			}
		}
	}

	return retorno;

}
