#include "LisEquipo.h"
#include <sstream>

NodoEquipo* LisEquipo::dividirLista(NodoEquipo* inicio)
{
	NodoEquipo* lento = inicio; //El puntero lento se mueve un nodo a la vez
	NodoEquipo* rapido = inicio->getSiguiente(); //El puntero rapido se mueve dos nodos a la vez

	while (rapido && rapido->getSiguiente()) { //Mientras el puntero rapido no haya llegado al final de la lista, se mueve el puntero lento una vez y el rapido dos veces
        lento = lento->getSiguiente();
        rapido = rapido->getSiguiente()->getSiguiente();
    }

	NodoEquipo* segundaMitad = lento->getSiguiente(); //El puntero lento ahora esta en el nodo medio de la lista, por lo que el nodo siguiente del puntero lento es el inicio de la segunda mitad de la lista
    lento->setNodoSiguiente(nullptr);

    return segundaMitad;
}

NodoEquipo* LisEquipo::mezclarPorPrioridad(NodoEquipo* izquierda, NodoEquipo* derecha)
{
    if (!izquierda) {return derecha;}
	if (!derecha) { return izquierda; } //Si una de las listas esta vacia, se devuelve la otra lista como resultado de la mezcla

	if (izquierda->getDato()->getPrioridad() >= derecha->getDato()->getPrioridad()) { //Si el nodo de la lista izquierda tiene una prioridad mayor o igual a la del nodo de la lista derecha, se agrega el nodo de la lista izquierda a la lista resultante y se llama recursivamente a la funcion para mezclar el resto de las listas
        izquierda->setNodoSiguiente(mezclarPorPrioridad(izquierda->getSiguiente(), derecha));
        return izquierda;
    }
    else {
		derecha->setNodoSiguiente(mezclarPorPrioridad(izquierda, derecha->getSiguiente()));  //Si el nodo de la lista derecha tiene una prioridad mayor a la del nodo de la lista izquierda, se agrega el nodo de la lista derecha a la lista resultante y se llama recursivamente a la funcion para mezclar el resto de las listas
        return derecha;
    }
}

NodoEquipo* LisEquipo::mergeSort(NodoEquipo* inicio)
{
	if (!inicio || !inicio->getSiguiente()) { return inicio; } //Si la lista esta vacia o tiene un solo nodo, se devuelve la lista tal cual, ya que esta ordenada

    NodoEquipo* segundaMitad = dividirLista(inicio);
    NodoEquipo* izquierda = mergeSort(inicio);
	NodoEquipo* derecha = mergeSort(segundaMitad);//Se divide la lista en dos mitades, se ordena cada mitad recursivamente y luego se mezclan las mitades ordenadas para obtener la lista ordenada completa
    return mezclarPorPrioridad(izquierda, derecha);
}

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
    if (!primero) throw ClassExceptio("No hay equipos cargados en el simulador.");
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
        s<<actual->getDato()->MostrarEquipo()<<endl;
        actual = actual->getSiguiente();
    }
    return s.str();
}
//metodos de comportamiento
void LisEquipo::degradarTodos()
{
	actual = primero;
    while (actual) {
        actual->getDato()->degradarse();
        actual = actual->getSiguiente();
	}
}

void LisEquipo::calcularPrioridades()
{
	actual = primero;
    while (actual) {
        actual->getDato()->calcularPrioridad();
        actual = actual->getSiguiente();
	}
}

Equipo* LisEquipo::buscarPorId(string id)
{
    actual = primero;
    while (actual) {
        if (actual->getDato()->getID() == id) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

Equipo** LisEquipo::obtenerTop3()
{
    ordenarPorPrioridad();
    Equipo** top3 = new Equipo * [3];
    for (int i = 0; i < 3; i++) {
        top3[i] = nullptr;
    }

    actual = primero;
    int contador = 0;
    while (actual && contador < 3) {
        top3[contador] = actual->getDato();
        actual = actual->getSiguiente();
        contador++;
    }
    return top3;
}

double LisEquipo::calcularRiesgoGlobal()
{
	if (!primero) { return 0.0; } //Si la lista esta vacia, se devuelve un riesgo global de 0.0 para evitar division por cero.
    double suma = 0.0;
    int contador = 0;
    actual = primero;
    while (actual) {
		suma += actual->getDato()->calcularRiesgo(); //Se recorre la lista de equipos y se suma el riesgo de cada equipo utilizando el metodo calcularRiesgo de la clase Equipo.
        contador++;
        actual = actual->getSiguiente();
    }
    return suma / contador;
}

int LisEquipo::contarPendientes()
{
    int contador = 0;
    actual = primero;
    while (actual) {
		if (actual->getDato()->necesitaMantenimiento()) { //Se recorre la lista de equipos y se cuenta cuántos equipos necesitan mantenimiento.
            contador++;
        }
        actual = actual->getSiguiente();
    }
    return contador;
}

void LisEquipo::ordenarPorPrioridad()
{
	primero = mergeSort(primero);//Se ordena la lista de equipos por prioridad utilizando el algoritmo de ordenamiento merge sort
    actual = primero;
}