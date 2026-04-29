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
