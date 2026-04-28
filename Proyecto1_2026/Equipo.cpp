#include "Equipo.h"
#include <sstream>
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
void Equipo::setID(string id) {this->id = id;}
void Equipo::setNombre(string nombre) { this->nombre = nombre; }
void Equipo::setCriticidad(int criticidad)	{this->criticidad = criticidad;}
void Equipo::setEstado(bool estado) { this->estado = estado; }
void Equipo::setTiempoActivo(int tiempoActivo){ this->tiempoActivo = tiempoActivo; }
void Equipo::setPrioridad(double prioridad) { this->prioridad = prioridad; }

string Equipo::MostrarEquipo()
{
	stringstream s;
	s << "El Id del Equipo es: " << id << endl;
	s << "El nombre del equipo es: " <<nombre<< endl;
	s << "El numero del cripticidad: "<<criticidad << endl;
	s << "El estado es: "<<estado << endl;
	s << "Numero de horas activas es: "<<tiempoActivo << endl;
	s << "La prioridad del equipo es: "<<prioridad << endl;
	return s.str();
}
