#include "List_Mante.h"
#include <sstream>
List_Mante::List_Mante()
{
	primero = nullptr;
	actual = nullptr;
}

List_Mante::~List_Mante()
{
	while (primero) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual->getDato();
		delete actual;
	}
}

bool List_Mante::agregarMantenimiento(Mantenimiento* mante)
{
	if (mante) {
		primero = new TemplateNodo<Mantenimiento>(mante, primero);
		return true;
	}
	return false;
}
Mantenimiento* List_Mante::buscarPorId(string id)
{
	actual = primero;
	while (actual) {
		if (actual->getDato()->getTipo() == id) {
			return actual->getDato();
		}
		actual = actual->getSiguiente();
	}
	return nullptr;
}
string List_Mante::mostrarMantenimientos()
{
	actual = primero;
	stringstream s;
	while (actual) {
		s << "Tipo: " << actual->getDato()->getTipo() << endl;
		s << actual->getDato()->descripcion() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}
