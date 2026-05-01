#pragma once
#include <iostream>
#include "Incidencia.h"
#include"TemplateNodo.h"
class ColeccionIncidencia
{
private:
	TemplateNodo<Incidencia>* primero;
	TemplateNodo<Incidencia>* Actual;
public:
	//Constructor
	ColeccionIncidencia();
	~ColeccionIncidencia();
	//Metodos basicos de colecciones
	bool Agregar(Incidencia* dato);
	bool Eliminar(string id);
	Incidencia* Buscar(string id); 
	string MostrarIncidencias();
	// Metodos de comportamiento
	int contarIncidenciasActivas();
	bool tieneIncidenciasActivas();
	bool resolverUnaIncidenciaActiva();
	bool resolverIncidencia(string id);
	void resolverTodas();
	string mostrarIncidenciasActivas();
	int cantidadTotal();
	bool estaVacia();

};

