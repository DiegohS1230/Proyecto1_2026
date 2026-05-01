#include "Equipo.h"
#include <sstream>
Equipo::Equipo(string id, string nombre, int criticidad, bool estado, int tiempoActivo, double prioridad) {
	this->id = id;
	this->nombre = nombre;
	this->criticidad = criticidad;
	this->estado = estado;
	this->tiempoActivo = tiempoActivo;
	this->incidencias = new ColeccionIncidencia();
	this->prioridad = prioridad;
}
Equipo::~Equipo() {
	delete incidencias;
}
string Equipo::getID() { return id; }
string Equipo::getNombre() {return nombre;}
int Equipo::getCriticidad() { return criticidad; }
bool Equipo::getestado() { return estado; }
int Equipo::getTiempoActivo() { return tiempoActivo; }
double Equipo::getPrioridad() { return prioridad; }
ColeccionIncidencia* Equipo::getIncidencias() { return incidencias; }
//sets
void Equipo::setID(string id) {this->id = id;}
void Equipo::setNombre(string nombre) { this->nombre = nombre; }
void Equipo::setCriticidad(int criticidad)	{this->criticidad = criticidad;}
void Equipo::setEstado(bool estado) { this->estado = estado; }
void Equipo::setTiempoActivo(int tiempoActivo){ this->tiempoActivo = tiempoActivo; }
void Equipo::setPrioridad(double prioridad) { this->prioridad = prioridad; }
void Equipo::setIncidencias(ColeccionIncidencia* incidencias) { this->incidencias = incidencias; }

string Equipo::MostrarEquipo()
{
	stringstream s;
	s << "El Id del Equipo es: " << id << endl;
	s << "El nombre del equipo es: " <<nombre<< endl;
	s << "El numero del cripticidad: "<<criticidad << endl;
	s << "El estado es: "<<estado << endl;
	s << "Numero de horas activas es: "<<tiempoActivo << endl;
	s << "La prioridad del equipo es: "<<prioridad << endl;
	if(incidencias) s << "Numero de incidencias: "<<incidencias->MostrarIncidencias() << endl;
	return s.str();
}
//Metodos de comportamiento
void Equipo::agregarIncidencia(Incidencia* incidencia)
{
	if(incidencia)incidencias->Agregar(incidencia);
}

int Equipo::contarIncidenciasActivas()
{
	int contador = 0;





	return contador;
}

bool Equipo::tieneIncidenciasActivas()
{
	return false;
}

void Equipo::degradarse()
{
}

void Equipo::aumentarTiempoInactivo()
{
}

void Equipo::actualizarDia()
{
}

void Equipo::calcularPrioridad()
{
}

void Equipo::recibirMantenimiento()
{
}

void Equipo::resolverUnaIncidencia()
{
}

void Equipo::reiniciarTiempoInactivo()
{
}

bool Equipo::necesitaMantenimiento()
{
	return false;
}

double Equipo::calcularRiesgo()
{
	return 0.0;
}
