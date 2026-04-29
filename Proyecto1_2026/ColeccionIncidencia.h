#pragma once
#include <iostream>
#include"NodoIncidencia.h"
class ColeccionIncidencia
{
private:
	NodoIncidencia* primero;
	NodoIncidencia* Actual;
public:
	ColeccionIncidencia();
	~ColeccionIncidencia();
	bool Agregar(Incidencia* dato);
	bool Eliminar(string id);
	Incidencia* Buscar(string id);
	string MostrarIncidencias();
	int contarActivasPorEquipo(string idEquipo);
	void actualizarIncidencias(int diaActual);
	void generarIncidenciaAleatoria(int diaActual);
	string mostrarActivas();
};

