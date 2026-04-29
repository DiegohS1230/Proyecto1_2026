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
	Equipo* buscarPorId(string id);
	Equipo* buscarPorNombre(string nombre);
	Equipo* obtenerEquipoMayorPrioridad();
	void ordenarPorPrioridad();
	void actualizarPrioridades();
	void simularDia(int dia);
};
}
