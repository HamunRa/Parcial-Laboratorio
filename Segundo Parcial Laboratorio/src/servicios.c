#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "servicios.h"

/// @fn Passenger Passenger_new*()
/// @brief abre la memoria dinamica de la lista y vacia todos los datos
///
/// @return retorna el pasajero vacio
eServicio* servicio_new() {
	eServicio* servicioAux;

		servicioAux = (eServicio*) malloc (sizeof(eServicio));

		return servicioAux;

}

/// @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// @brief carga los datos obtenidos en el pasajero vacio
///
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param tipoPasajeroStr
/// @param precioStr
/// @param flycodeStr
/// @param estadoDeVuelo
/// @return retorna el pasajero cargado con los datos
eServicio* servicio_newParametros(char *idStr, char *descripcion, char *tipo,
		char *precioUnitario, char *cantidad, char *totalServicio) {
	eServicio *nuevoServicio = servicio_new();
	int idAux;
	int tipoAux;
	char tipoChar[30];
	float precioAux;
	int cantidadAux;
	float totalAux;

	idAux = atoi(idStr);
	tipoAux = atoi(tipo);
	comparacionDeTipo(tipoAux, tipoChar);
	precioAux = atof(precioUnitario);
	cantidadAux = atoi(cantidad);
	totalAux = atof(totalServicio);

	int retorno = 0;

	if (nuevoServicio != NULL) {

		if (servicio_setId(nuevoServicio, idAux) == 0) {

			if (servicio_setDescripcion(nuevoServicio, descripcion) == 0) {

				if (servicio_setTipo(nuevoServicio, tipoChar) == 0) {

					if (servicio_setPrecio(nuevoServicio, precioAux)
							== 0) {

						if (servicio_setCantidad(nuevoServicio, cantidadAux)
								== 0) {

							if (servicio_setTotal(nuevoServicio,
									totalAux) == 0) {

								retorno = 1;
							}

						}
					}
				}
			}
		}
		if (retorno != 1) {
			free(nuevoServicio);
			nuevoServicio = NULL;
		}
	}
	return nuevoServicio;
}
/// @fn int Passenger_setId(Passenger*, int)
/// @brief setea el id
///
/// @param this
/// @param id
/// @return
int servicio_setId(eServicio *this, int id) {
	int retorno = -1;

		if(this != NULL && id > 0)
		{
			this->id = id;
			retorno = 0;
		}

		return retorno;
}
/// @fn int Passenger_getId(Passenger*, int*)
/// @brief obtiene el id
///
/// @param this
/// @param id
/// @return
int servicio_getId(eServicio *this, int *id) {
	int retorno = -1;

	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int servicio_setDescripcion(eServicio *this, char *descripcion) {
	int retorno = -1;

	if (this != NULL && descripcion != NULL) {
		strcpy(this->descripcion, descripcion);
		retorno = 0;
	}

	return retorno;

}

int servicio_getDescripcion(eServicio *this, char *descripcion) {
	int retorno = -1;

	if (this != NULL && descripcion != NULL) {
		strcpy(descripcion, this->descripcion);
		retorno = 0;
	}

	return retorno;
}

int servicio_setTipo(eServicio *this, char *tipo) {
	int retorno = -1;

	if (tipo != NULL && this != NULL) {
		strcpy(this->tipo, tipo);
		retorno = 0;
	}
	return retorno;
}

int servicio_getTipo(eServicio *this, char *tipo) {
	strcpy(tipo, this->tipo);
	if (!(strcmp(tipo, this->tipo))) {
		return 1;
	}
	return 0;
}

int servicio_setPrecio(eServicio *this, float precioUnitario) {
	int retorno = -1;

	if(this != NULL && precioUnitario > 0)
	{
		this->precio = precioUnitario;
		retorno = 0;
	}

	return retorno;
}

int servicio_getPrecio(eServicio *this, float *precioUnitario) {
	int retorno = -1;

	if(this != NULL && precioUnitario != NULL)
	{
		*precioUnitario = this->precio;
		retorno = 0;
	}

	return retorno;
}

int servicio_setCantidad(eServicio *this, int cantidad) {
	int retorno = -1;

	if(this != NULL && cantidad > 0)
	{
		this->cantidad = cantidad;
		retorno = 0;
	}

	return retorno;
}

int servicio_getCantidad(eServicio *this, int *cantidad) {
	int retorno = -1;

	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		retorno = 0;
	}

	return retorno;
}
int servicio_setTotal(eServicio *this, float precioTotalServicio) {
	int retorno = -1;

	if(this != NULL && precioTotalServicio >= 0)
	{
		this->totalServicio = precioTotalServicio;
		retorno = 0;
	}

	return retorno;
}

int servicio_getTotal(eServicio *this, float *precioTotalServicio) {
	int retorno = -1;

		if(this != NULL && precioTotalServicio != NULL)
		{
			*precioTotalServicio = this->totalServicio;
			retorno = 0;
		}

		return retorno;
}

int servicio_newServicio(char *totalServicio) {
	eServicio *nuevoServicio = servicio_new();
	float totalServicioAux;
	int validar = 0;

	totalServicioAux = atof(totalServicio);
	if (nuevoServicio != NULL) {
		if (servicio_setTotal(nuevoServicio, totalServicioAux) == 0) {

			validar = 1;
		}
	}
	if (validar != 1) {
		free(nuevoServicio);
		nuevoServicio = NULL;
	}
	return validar;
}
/// @fn int Passenger_listEntera(LinkedList*)
/// @brief muestra toda la lista mediante un for
///
/// @param pArrayListPassenger
/// @return
int servicio_Lista(LinkedList *pArraylistaServicios) {
	Node *indice = pArraylistaServicios->pFirstNode;
	eServicio *leer;

	printf(
			"\nID | Descripcion | Tipo  |  Precio | Cantidad | Total \n");
	for (; indice != NULL; indice = indice->pNextNode) {
		leer = indice->pElement;
		servicio_listaUno(leer);

	}
	return 1;
}

/// @fn void Passenger_listaUno(Passenger*)
/// @brief lista todos los datos una vez
///
/// @param lecturaDeDato
void servicio_listaUno(eServicio *lecturaDeDato) {
	if (lecturaDeDato != NULL) {
		printf("%d |  ", lecturaDeDato->id);
		printf(lecturaDeDato->descripcion);
		printf("  |  ");
		printf(lecturaDeDato->tipo);
		printf("  |  ");
		printf("%.2f |  ", lecturaDeDato->precio);
		printf("%d  |  ", lecturaDeDato->cantidad);
		printf("%.2f", lecturaDeDato->totalServicio);
		printf("\n");
	}

}
int servicio_descripcionComparados(void *descripcionA, void *descripcionB) {
	int validar;
	char descripcionAuxA[50];
	char descripcionAuxB[50];

	eServicio *a;
	eServicio *b;

	a = (eServicio*) descripcionA;
	b = (eServicio*) descripcionB;

	servicio_getDescripcion(a, descripcionAuxA);
	servicio_getDescripcion(b, descripcionAuxB);

	if (strcmp(descripcionAuxA, descripcionAuxB) == 0) {
		validar = 0;
	} else {
		if (strcmp(descripcionAuxA, descripcionAuxB) > 0) {
			validar = 1;
		} else {
			validar = -1;
		}
	}
	return validar;
}
int primerFilter(void *servicio) {
	int retorno = 0;
	eServicio *filtrando = servicio;

	if (strcmp(filtrando->tipo, "Minorista") == 0) {
		retorno = 1;
	}
	return retorno;
}

int segundoFilter(void *servicio) {
	int retorno = 0;
	eServicio *filtrando = servicio;

	if (strcmp(filtrando->tipo, "Mayorista") == 0) {
		retorno = 1;
	}
	return retorno;
}
int tercerFilter(void *servicio) {
	int retorno = 0;
	eServicio *filtrando = servicio;

	if (strcmp(filtrando->tipo, "Exportar") == 0) {
		retorno = 1;
	}
	return retorno;
}

int servicioMapeo(void *elemento) {
	eServicio *precioFinal;
	precioFinal = elemento;
	float precioAPasar;

	precioAPasar = precioFinal->precio * precioFinal->cantidad;
	servicio_setTotal(precioFinal, precioAPasar);

	return 0;
}
int comparacionDeTipo(int tipo, char *tipoAux) {

	switch (tipo) {
	case 1:
		strcpy(tipoAux, "Minorista");
		break;
	case 2:
		strcpy(tipoAux, "Mayorista");
		break;
	case 3:
		strcpy(tipoAux, "Exportar");
		break;
	}

	return 0;
}
