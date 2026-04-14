#pragma once
#include <iostream>
using namespace std;
class Equipo{
private:
	string id;
	string nombre;
	int criticidad;
	bool estado;
	int tiempoActivo;
	double prioridad;
public:
	Equipo(string id, string nombre, int criticidad, bool estado, int tiempoActivo, double prioridad);
	~Equipo();
	string getID();
	String getNombre();
	int getCriticidad();
	bool getestado();
	int getTiempoActivo();
	double getPrioridad();
	//stes
	void setID();
	void setNombre();
	void setCriticidad();
	void setEstado();
	void setTiempoActivo();
	void setPrioridad();
	//To String
	string MostrarEquipo();
};

