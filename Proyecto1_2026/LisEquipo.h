#pragma once
#include "NodoEquipo.h"
class LisEquipo
{
private:
	NodoEquipo* primero;
	NodoEquipo* actual;
	//Metodos privados (ORDENAMIENTO)
	NodoEquipo* dividirLista(NodoEquipo* inicio);
	NodoEquipo* mezclarPorPrioridad(NodoEquipo* izquierda, NodoEquipo* derecha);
	NodoEquipo* mergeSort(NodoEquipo* inicio);
public:
	LisEquipo();
	~LisEquipo();
	//gets
	NodoEquipo* getPrimero();
	NodoEquipo* getActual();
	//sets
	void setPrimero(NodoEquipo* primero);
	void setActual(NodoEquipo* actual);
	//basicos
	bool agregarEquipo(Equipo* equipo);
	bool eliminar(string nombre);
	string mostrarEquipos();
	//metodos de comportamiento
	void degradarTodos();
	void calcularPrioridades();
	Equipo* buscarPorId(string id);
	Equipo** obtenerTop3();
	double calcularRiesgoGlobal();
	int contarPendientes();
	//Metodos de ordenamiento
	void ordenarPorPrioridad();
};

