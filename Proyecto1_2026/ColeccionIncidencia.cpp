#include "ColeccionIncidencia.h"
#include <sstream>

ColeccionIncidencia::ColeccionIncidencia()
{
	primero = nullptr;
	Actual = nullptr;
}

ColeccionIncidencia::~ColeccionIncidencia()
{
	while (primero) {
		Actual = primero;
		primero = primero->getSiguiente();
		delete Actual->getDato();
		delete Actual;
	}
}

bool ColeccionIncidencia::Agregar(Incidencia* dato)
{
	if (dato) { 
		primero = new NodoIncidencia(primero, dato);
		return true;
	}
	return false;
}

bool ColeccionIncidencia::Eliminar(string id)
{
	Actual = primero;
	while (Actual) {
		if (Actual->getDato()->getId() == id) {
			NodoIncidencia* temp = Actual;
			Actual = Actual->getSiguiente();
			delete temp->getDato();
			delete temp;
			return true;
		}
		Actual = Actual->getSiguiente();
	}
	return false;
}

Incidencia* ColeccionIncidencia::Buscar(string id)
{
	Actual = primero;
	while (Actual) {
		if (Actual->getDato()->getId() == id) {
			return Actual->getDato();
		}
		Actual = Actual->getSiguiente();
	}
    return nullptr;
}

string ColeccionIncidencia::MostrarIncidencias()
{
	stringstream s;
	s << "Incidencias en la Coleccion: " << endl;
	Actual = primero;
	while (Actual) {
		s<<Actual->getDato()->mostrarIncidencias()<<endl;
		Actual = Actual->getSiguiente();
	}
    return s.str();
}
int ColeccionIncidencia::contarIncidenciasActivas() //Cuenta el numero de incidencias activas en la coleccion y devuelve ese numero.
{
	int contador = 0;
	Actual = primero;
	while (Actual) {
		if (Actual->getDato()->getActiva()) {
			contador++;
		}
		Actual = Actual->getSiguiente();
	}
	return contador;
}
bool ColeccionIncidencia::tieneIncidenciasActivas() //Devuelve true si hay al menos una incidencia activa.
{
	Actual = primero;
	while (Actual) {
		if (Actual->getDato()->getActiva()) {
			return true;
		}
		Actual = Actual->getSiguiente();
	}
	return false;
}
bool ColeccionIncidencia::resolverUnaIncidenciaActiva() //Resuelve la primera incidencia activa que encuentra en la coleccion y devuelve true.
{
	Actual = primero;
	while (Actual) {
		if (Actual->getDato()->getActiva()) {
			Actual->getDato()->cerrar();
			return true;
		}
		Actual = Actual->getSiguiente();
	}
	return false;
}

bool ColeccionIncidencia::resolverIncidencia(string id)
{
	Actual = primero;
	while (Actual) {
		if (Actual->getDato()->getId() == id) {
			if (Actual->getDato()->getActiva()) {
				Actual->getDato()->cerrar();
				return true;
			}
			return false; //Si la incidencia no esta activa no se puede resolver.
		}
		Actual = Actual->getSiguiente();
	}
	return false;
}

void ColeccionIncidencia::resolverTodas() //Resuelve todas las incidencias activas en la colección.
{
	Actual = primero;
	while (Actual) {
		if (Actual->getDato()->getActiva()) {
			Actual->getDato()->cerrar();
		}
		Actual = Actual->getSiguiente();
	}
}
string ColeccionIncidencia::mostrarIncidenciasActivas() //Muestra solo las incidencias que estan activas en la colección.
{
	stringstream s;
	s << "Incidencias Activas en la Coleccion: " << endl;
	Actual = primero;
	while (Actual) {
		if (Actual->getDato()->getActiva()) {
			s<<Actual->getDato()->mostrarIncidencias()<<endl;
		}
		Actual = Actual->getSiguiente();
	}
	return s.str();
}
int ColeccionIncidencia::cantidadTotal() //Cuenta el total de incidencias en la coleccion, sin importar su estado.
{
	int contador = 0;
	Actual = primero;
	while (Actual) {
		contador++;
		Actual = Actual->getSiguiente();
	}
	return contador;
}
bool ColeccionIncidencia::estaVacia()
{
	return primero == nullptr; //Si primero es nullptr la colección esta vacia.