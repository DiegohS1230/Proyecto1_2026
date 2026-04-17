#include "LisEquipo.h"
#include <sstream>

LisEquipo::LisEquipo()
{
    primero = nullptr;
    actual = nullptr;
}

LisEquipo::~LisEquipo()
{
    while (primero) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual->getDato();
        delete actual;
    }
}

NodoEquipo* LisEquipo::getPrimero()
{
    return primero;
}

NodoEquipo* LisEquipo::getActual()
{
    return actual;
}

void LisEquipo::setPrimero(NodoEquipo* primero)
{
    this->primero = primero;
}

void LisEquipo::setActual(NodoEquipo* actual)
{
    this->actual = actual;
}

bool LisEquipo::agregarEquipo(Equipo* equipo)
{
    if (equipo) {
        primero = new NodoEquipo(equipo, primero);
        return true;
    }

    return false;
}

bool LisEquipo::eliminar(string nombre)
{
    actual = primero;
    if (primero->getDato()->getNombre() == nombre) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual->getDato();
        delete actual;
        return true;
    }else{
        while (actual->getDato()->getNombre() !=nombre) actual = actual->getSiguiente();
        NodoEquipo* porEliminar = actual;
        actual->setNodoSiguiente(porEliminar->getSiguiente());
        delete porEliminar->getDato();
        delete porEliminar;
        return true;
    }


    return false;
}

string LisEquipo::mostrarEquipos()
{
    stringstream s;
    actual = primero;
    while (actual) {
        s<<actual->getDato()<<endl;
        actual = actual->getSiguiente();
    }
    return s.str();
}
