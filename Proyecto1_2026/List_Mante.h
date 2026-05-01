#pragma once
#include"Mantenimiento.h"
#include"TemplateNodo.h"
class List_Mante
{
private: 
	TemplateNodo<Mantenimiento>* primero;
	TemplateNodo<Mantenimiento>* actual;
public:
	List_Mante();
	~List_Mante();
	bool agregarMantenimiento(Mantenimiento* mante);
	bool eliminar(string id);
	Mantenimiento* buscarPorId(string id);
	string mostrarMantenimientos();

};

