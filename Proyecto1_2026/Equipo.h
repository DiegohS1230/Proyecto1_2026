#pragma once
#include "ColeccionIncidencia.h"
#include "Incidencia.h"
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
	//Metodos de comportamiento;
	void activar();
	void desactivar();
	void aumentarTiempoActivo(int horas);
	void reducirTiempoActivo(int horas);
	bool necesitaRevision();
	double calcularPrioridad();
	void asociarIncidencia(Incidencia* incidencia);
};

