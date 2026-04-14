#pragma once
#include <iostream>
using namespace std;
class Incidencia
{
private: 
	string id;
	string descripcion;
	string severidad;
	int diaAparicion;
	bool activa;
public:
	Incidencia(string id = "", string descripcion = "", string severidad = "", int diaAparicion = 0, bool activa = false);
	~Incidencia();
	//gets
	string getId();
	string getDescripcion();
	string getSeveridad();
	int getDiaAparicion();
	bool getActiva();
	//sets
	void setId(string id);
	void setDescripcion(string descripcion);
	void setSeveridad(string severidad);
	void setDiaAparicion(int diaAparicion);
	void setActiva(bool activa);
	string mostrarIncidencias();

};

