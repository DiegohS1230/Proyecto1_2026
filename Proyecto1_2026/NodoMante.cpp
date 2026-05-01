#include "NodoMante.h"

NodoMante::NodoMante(Mantenimiento* dato, NodoMante* siguiente)
{
	this->dato = dato;
	this->siguiente = siguiente;
}

NodoMante::~NodoMante()
{
}
Mantenimiento* NodoMante::getDato()
{
	return dato;
}
NodoIncidencia* NodoMante::getSiguiente()
{
	return siguiente;
}	

void NodoMante::setDato(Mantenimiento* dato)
{
	this->dato = dato;
}

void NodoMante::setNodoSiguiente(NodoMante* siguiente)
{
	this->siguiente = siguiente;
}
