#pragma once
#include "Equipo.h"
#include "TemplateNodo.h"
#include "ClassExceptio.h"
class LisEquipo
{
private:
	TemplateNodo<Equipo>* primero;
	TemplateNodo<Equipo>* actual;
	//Metodos Ordenamiento (ORDENAMIENTO)
	TemplateNodo<Equipo>* dividirLista(TemplateNodo<Equipo>* inicio);
	TemplateNodo<Equipo>* mezclarPorPrioridad(TemplateNodo<Equipo>* izquierda, TemplateNodo<Equipo>* derecha);
	TemplateNodo<Equipo>* mergeSort(TemplateNodo<Equipo>* inicio);

	//Metodos busqueda Hash simple
	static const int TAM_HASH = 101;
	TemplateNodo<Equipo>* tablaHash[TAM_HASH];
	int funcionHash(string id);
	void insertarHash(Equipo* equipo);
public:
	LisEquipo();
	~LisEquipo();
	//gets
	TemplateNodo<Equipo>* getPrimero();
	TemplateNodo<Equipo>* getActual();
	//sets
	void setPrimero(TemplateNodo<Equipo>* primero);
	void setActual(TemplateNodo<Equipo>* actual);
	//basicos
	bool agregarEquipo(Equipo* equipo);
	bool eliminar(string nombre);
	string mostrarEquipos();
	//metodos de comportamiento
	void degradarTodos();
	void calcularPrioridades();
	Equipo* buscarPorId(string id);
	Equipo** obtenerTop3();
	double calcularRiesgoGlobal();
	int contarPendientes();
	//Metodos de ordenamiento
	void ordenarPorPrioridad();
};