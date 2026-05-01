#pragma once
#include "ColeccionIncidencia.h"
#include "Incidencia.h"
class Equipo{
private:
	string id;
	string nombre;
	int criticidad;
	int estado;
	int tiempoActivo;
	double prioridad;
	ColeccionIncidencia* incidencias;
public:
	Equipo(string id, string nombre, int criticidad, int estado, int tiempoActivo, double prioridad);
	~Equipo();
	string getID();
	string getNombre();
	int getCriticidad();
	int getEstado();
	int getTiempoActivo();
	double getPrioridad();
	ColeccionIncidencia* getIncidencias();
	//sets	
	void setID(string id);
	void setNombre(string nombre);
	void setCriticidad(int criticidad);
	void setEstado(int estado);
	void setTiempoActivo(int tiempoActivo);
	void setPrioridad(double prioridad);
	void setIncidencias(ColeccionIncidencia* incidencias);
	//To String
	string MostrarEquipo();
	//Metodos de comportamiento;
	void agregarIncidencia(Incidencia* incidencia);
	int contarIncidenciasActivas();
	bool tieneIncidenciasActivas();
	void degradarse();
	void aumentarTiempoInactivo();
	void actualizarDia();
	void calcularPrioridad();
	void recibirMantenimiento();
	void resolverUnaIncidencia();
	void reiniciarTiempoInactivo();
	bool necesitaMantenimiento();
	double calcularRiesgo();
};

