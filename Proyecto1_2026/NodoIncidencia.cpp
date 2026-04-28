#include "NodoIncidencia.h"

NodoIncidencia::NodoIncidencia(NodoIncidencia* siguiente, Incidencia* dato)
{
	this->dato = dato;
	this->siguiente = siguiente;
}

NodoIncidencia::~NodoIncidencia(){//Vacio
}

Incidencia* NodoIncidencia::getDato(){return dato;}
NodoIncidencia* NodoIncidencia::getSiguiente(){return siguiente;}

void NodoIncidencia::setIncidencia(Incidencia* dato){this->dato = dato;}
void NodoIncidencia::setSiguiente(NodoIncidencia* siguiente){this->siguiente = siguiente;}
