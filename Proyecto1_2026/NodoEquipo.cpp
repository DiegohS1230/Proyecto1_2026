#include "NodoEquipo.h"

NodoEquipo::NodoEquipo(Equipo* dato, NodoEquipo* siguientes)
{
	this->dato = dato;
	this->siguiente = siguiente;
}

NodoEquipo::~NodoEquipo() {
	//vacio
}

Equipo* NodoEquipo::getDato()
{
	return dato;
}

NodoEquipo* NodoEquipo::getSiguiente()
{
	return siguiente;
}

void NodoEquipo::setDato(Equipo* dato)
{
	this->dato = dato;
}

void NodoEquipo::setNodoSiguiente(NodoEquipo* siguiente)
{
	this->siguiente = siguiente;
}
