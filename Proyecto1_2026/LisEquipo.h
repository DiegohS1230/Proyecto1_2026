#pragma once
#include "NodoEquipo.h"
class LisEquipo
{
private:
	NodoEquipo* primero;
	NodoEquipo* actual;
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
	void ordenarPorPrioridad();
	Equipo* buscarPorId(string id);
	Equipo** obtenerTop3();
	double calcularRiesgoGlobal();
	int contarPendientes();
};
}
