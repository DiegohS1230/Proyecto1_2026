#include "Equipo.h"
Equipo::Equipo(string id, string nombre, int criticidad, bool estado, int tiempoActivo, double prioridad) {
	this->id = id;
	this->nombre = nombre;
	this->criticidad = criticidad;
	this->estado = estado;
	this->tiempoActivo = tiempoActivo;
	this->prioridad = prioridad;
}
Equipo::~Equipo() {}
string Equipo::getID() { return id; }
string Equipo::getNombre() {return nombre;}
int Equipo::getCriticidad() { return criticidad; }
bool Equipo::getestado() { return estado; }
int Equipo::getTiempoActivo() { return tiempoActivo; }
double Equipo::getPrioridad() { return prioridad; }
//sets