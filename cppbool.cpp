cpp Proyecto1_2026/LisEquipo.cpp
#include "Simulador.h"
#include "Mante_Preventivo.h"
#include "Mante_Correctivo.h"
#include <fstream>
bool LisEquipo::eliminar(string nombre)
{
    if (!primero) throw ClassExceptio("No hay equipos cargados en el simulador.");
    // Caso primer nodo
    if (primero->getDato()->getNombre() == nombre) {
        TemplateNodo<Equipo>* temp = primero;
        primero = primero->getSiguiente();
        delete temp->getDato();
        delete temp;
        return true;
    }
    // Buscar en el resto de la lista
    TemplateNodo<Equipo>* anterior = primero;
    TemplateNodo<Equipo>* actual = primero->getSiguiente();
    while (actual) {
        if (actual->getDato()->getNombre() == nombre) {
            anterior->setSiguiente(actual->getSiguiente());
            delete actual->getDato();
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }
    // No encontrado
    return false;
}