#ifndef SERVICE_H_
#define SERVICE_H_

typedef struct {
	int id;
	char descripcion[50];
	char tipo[50]; //1-MINORISTA, 2-MAYORISTA, 3-EXPORTAR
	float precio;
	int cantidad;
	float totalServicio;

} eServicio;

eServicio* servicio_new();
eServicio* servicio_newParametros(char *idStr, char *descripcion, char *tipo,
		char *precioUnitario, char *cantidad, char *totalServicio);
int servicio_newServicio(char *precioFinal);

int servicio_setId(eServicio *this, int id);
int servicio_getId(eServicio *this, int *id);

int servicio_setDescripcion(eServicio *this, char *descripcion);
int servicio_getDescripcion(eServicio *this, char *descripcion);

int servicio_setTipo(eServicio *this, char *tipo);
int servicio_getTipo(eServicio *this, char *tipo);

int servicio_setPrecio(eServicio *this, float precioUnitario);
int servicio_getPrecio(eServicio *this, float *precioUnitario);

int servicio_setCantidad(eServicio *this, int cantidad);
int servicio_getCantidad(eServicio *this, int *cantidad);

int servicio_setTotal(eServicio *this, float precioTotalServicio);
int servicio_getTotal(eServicio *this, float *precioTotalServicio);

int servicio_Lista(LinkedList *pArraylistaServicios);
void servicio_listaUno(eServicio *lecturaDeDato);
int servicio_idDisponible(LinkedList *pArraylistaServicios);

int servicio_descripcionComparados(void *descripcionA, void *descripcionB);
int primerFilter(void *servicio);
int segundoFilter(void *servicio);
int tercerFilter(void *servicio);
int servicioMapeo(void *elemento);

int comparacionDeTipo(int tipo, char *tipoAux);

#endif /* SERVICE_H_ */
