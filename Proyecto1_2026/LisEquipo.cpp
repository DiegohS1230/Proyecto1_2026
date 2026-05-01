#include "LisEquipo.h"
#include <sstream>
#include "List_Mante.h"

TemplateNodo<Equipo>* LisEquipo::dividirLista(TemplateNodo<Equipo>* inicio)
{
	TemplateNodo<Equipo>* lento = inicio; //El puntero lento se mueve un nodo a la vez
	TemplateNodo<Equipo>* rapido = inicio->getSiguiente(); //El puntero rapido se mueve dos nodos a la vez

	while (rapido && rapido->getSiguiente()) { //Mientras el puntero rapido no haya llegado al final de la lista, se mueve el puntero lento una vez y el rapido dos veces
        lento = lento->getSiguiente();
        rapido = rapido->getSiguiente()->getSiguiente();
    }

	TemplateNodo<Equipo>* segundaMitad = lento->getSiguiente(); //El puntero lento ahora esta en el nodo medio de la lista, por lo que el nodo siguiente del puntero lento es el inicio de la segunda mitad de la lista
    lento->setSiguiente(nullptr);

    return segundaMitad;
}

TemplateNodo<Equipo>* LisEquipo::mezclarPorPrioridad(TemplateNodo<Equipo>* izquierda, TemplateNodo<Equipo>* derecha)
{
    if (!izquierda) {return derecha;}
	if (!derecha) { return izquierda; } //Si una de las listas esta vacia, se devuelve la otra lista como resultado de la mezcla

	if (izquierda->getDato()->getPrioridad() >= derecha->getDato()->getPrioridad()) { //Si el nodo de la lista izquierda tiene una prioridad mayor o igual a la del nodo de la lista derecha, se agrega el nodo de la lista izquierda a la lista resultante y se llama recursivamente a la funcion para mezclar el resto de las listas
        izquierda->setSiguiente(mezclarPorPrioridad(izquierda->getSiguiente(), derecha));
        return izquierda;
    }
    else {
		derecha->setSiguiente(mezclarPorPrioridad(izquierda, derecha->getSiguiente()));  //Si el nodo de la lista derecha tiene una prioridad mayor a la del nodo de la lista izquierda, se agrega el nodo de la lista derecha a la lista resultante y se llama recursivamente a la funcion para mezclar el resto de las listas
        return derecha;
    }
}

TemplateNodo<Equipo>* LisEquipo::mergeSort(TemplateNodo<Equipo>* inicio)
{
	if (!inicio || !inicio->getSiguiente()) { return inicio; } //Si la lista esta vacia o tiene un solo nodo, se devuelve la lista tal cual, ya que esta ordenada

    TemplateNodo<Equipo>* segundaMitad = dividirLista(inicio);
    TemplateNodo<Equipo>* izquierda = mergeSort(inicio);
	TemplateNodo<Equipo>* derecha = mergeSort(segundaMitad);//Se divide la lista en dos mitades, se ordena cada mitad recursivamente y luego se mezclan las mitades ordenadas para obtener la lista ordenada completa
    return mezclarPorPrioridad(izquierda, derecha);
}

int LisEquipo::funcionHash(string id)
{
    int suma = 0;
    for (int i = 0; i < id.length(); i++) suma += id[i];
    return suma % TAM_HASH;
}

void LisEquipo::insertarHash(Equipo* equipo)
{
    if (!equipo) return;
    int posicion = funcionHash(equipo->getID());
    tablaHash[posicion] = new TemplateNodo<Equipo>(equipo, tablaHash[posicion]);
}

LisEquipo::LisEquipo()
{
    primero = nullptr;
    actual = nullptr;
	//Inicializacion de la tabla hash
    for (int i = 0; i < TAM_HASH; i++) {
        tablaHash[i] = nullptr;
	}
}

LisEquipo::~LisEquipo()
{
    while (primero) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual->getDato();
        delete actual;
    }

    for (int i = 0; i < TAM_HASH; i++) {
        TemplateNodo<Equipo>* aux = tablaHash[i];
        while (aux) {
            TemplateNodo<Equipo>* temp = aux;
            aux = aux->getSiguiente();
            delete temp;
        }
        tablaHash[i] = nullptr;
    }
}

TemplateNodo<Equipo>* LisEquipo::getPrimero()
{
    return primero;
}

TemplateNodo<Equipo>* LisEquipo::getActual()
{
    return actual;
}

void LisEquipo::setPrimero(TemplateNodo<Equipo>* primero)
{
    this->primero = primero;
}

void LisEquipo::setActual(TemplateNodo<Equipo>* actual)
{
    this->actual = actual;
}

bool LisEquipo::agregarEquipo(Equipo* equipo)
{
    if (equipo) {
        primero = new TemplateNodo<Equipo>(equipo, primero);
		insertarHash(equipo); //Se agrega el equipo a la lista y a la tabla hash para facilitar su busqueda por id.
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
        TemplateNodo<Equipo>* porEliminar = actual;
        actual->setSiguiente(porEliminar->getSiguiente());
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
    int posicion = funcionHash(id);
    TemplateNodo<Equipo>* aux = tablaHash[posicion];
    while (aux) {
        if (aux->getDato()->getID() == id) {
            return aux->getDato();
        }

        aux = aux->getSiguiente();
    }
    throw ClassExceptio("No se encontró el equipo con el ID especificado.");
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