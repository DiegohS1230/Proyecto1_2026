#pragma once
#include <iostream>
#include "Incidencia.h"
using namespace std;
class Tecnico{
private: 
	string nombre;
	string id;
	bool ocupado;
public:
	Tecnico(string nombre = " ", string id = " ", bool ocupado = false);
	~Tecnico();
	//gets
	string getNombreTec();
	string getIDTec();
	bool getOcupadoTec();
	//sets
	void setNombreTec(string nombre);
	void setIDTec(string id);
	void setOcupadoTec(bool ocupado);
	//toString
	string MostrarTecnico();
	//Metodos de comportamiento
	void asignarIncidencia(Incidencia* incidencia);
	void liberar();
	bool estaDisponible();
	void atenderIncidencia(Incidencia* incidencia);
};

