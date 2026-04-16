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
	string getNombre();
	int getCriticidad();
	bool getestado();
	int getTiempoActivo();
	double getPrioridad();
	//stes
	void setID(string id);
	void setNombre(string nombre);
	void setCriticidad(int criticidad);
	void setEstado(bool estado);
	void setTiempoActivo(int tiempoActivo);
	void setPrioridad(double prioridad);
	//To String
	string MostrarEquipo();
};

