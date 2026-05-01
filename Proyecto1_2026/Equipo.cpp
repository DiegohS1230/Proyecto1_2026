#include "Equipo.h"
#include <sstream>
Equipo::Equipo(string id, string nombre, int criticidad, int estado, int tiempoActivo, double prioridad) {
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
int Equipo::getEstado() { return estado; }
int Equipo::getTiempoActivo() { return tiempoActivo; }
double Equipo::getPrioridad() { return prioridad; }
ColeccionIncidencia* Equipo::getIncidencias() { if (incidencias) return incidencias; else throw ClassExceptio("No hay incidencias cargadas en el equipo."); }
//sets
void Equipo::setID(string id) {this->id = id;}
void Equipo::setNombre(string nombre) { this->nombre = nombre; }
void Equipo::setCriticidad(int criticidad)	{this->criticidad = criticidad;}
void Equipo::setEstado(int estado) { this->estado = estado; }
void Equipo::setTiempoActivo(int tiempoActivo){ this->tiempoActivo = tiempoActivo; }
void Equipo::setPrioridad(double prioridad) { this->prioridad = prioridad; }
void Equipo::setIncidencias(ColeccionIncidencia* incidencias) { if (incidencias) this->incidencias = incidencias; }

string Equipo::MostrarEquipo()
{
	stringstream s;
	s << "El Id del Equipo es: " << id << endl;
	s << "El nombre del equipo es: " <<nombre<< endl;
	s << "El numero del cripticidad: "<<criticidad << endl;
	s << "El estado es: "<<estado << endl;
	s << "Numero de horas activas es: "<<tiempoActivo << endl;
	s << "La prioridad del equipo es: "<<prioridad << endl;
	if(incidencias) s << "Numero de incidencias Activas : " <<incidencias->contarIncidenciasActivas() << endl;
	return s.str();
}
//Metodos de comportamiento
void Equipo::agregarIncidencia(Incidencia* incidencia) { if (incidencia)incidencias->Agregar(incidencia); } //Agrega una incidencia a la coleccion de incidencias del equipo.
int Equipo::contarIncidenciasActivas() { return incidencias->contarIncidenciasActivas(); } //	Llama al metodo contarIncidenciasActivas de la coleccion de incidencias.
bool Equipo::tieneIncidenciasActivas() { return incidencias->tieneIncidenciasActivas(); }//	Llama al metodo tieneIncidenciasActivas de la coleccion de incidencias.

void Equipo::degradarse() //Degrada el estado del equipo en 5 puntos cada vez que se llama a este metodo, pero el estado no puede ser menor a 0.
{
	if (estado > 0) estado -= 5; 
	if (estado < 0) estado = 0;
}

void Equipo::aumentarTiempoInactivo() { tiempoActivo++; } //Aumenta el tiempo activo del equipo en 1 cada vez que se llama a este metodo.

void Equipo::actualizarDia() //Actualiza el estado del equipo cada dia, degradandolo y aumentando su tiempo inactivo, ademas de recalcular su prioridad.
{
	degradarse();
	aumentarTiempoInactivo();
	calcularPrioridad();
}

void Equipo::calcularPrioridad() //Calcula la prioridad del equipo en base a su criticidad, el numero de incidencias activas y el tiempo activo
{
	int activas = contarIncidenciasActivas();
	prioridad = (criticidad * 0.5) +(activas * 0.3) + (tiempoActivo * 0.2);
}

void Equipo::recibirMantenimiento() //Recibe mantenimiento, lo que aumenta el estado del equipo en 20 puntos, pero el estado no puede ser mayor a 100. Ademas reinicia el tiempo inactivo, resuelve una incidencia activa y recalcula la prioridad.
{
	estado += 20;
	if (estado > 100) estado = 100;
	reiniciarTiempoInactivo();
	resolverUnaIncidencia();
	calcularPrioridad();
}

void Equipo::resolverUnaIncidencia() { if (incidencias) incidencias->resolverUnaIncidenciaActiva(); } //Resuelve una incidencia activa del equipo, llamando al metodo resolverUnaIncidenciaActiva de la coleccion de incidencias.
void Equipo::reiniciarTiempoInactivo() { tiempoActivo = 0; } //Reinicia el tiempo activo del equipo a 0.
bool Equipo::necesitaMantenimiento() { return estado <= 50 || contarIncidenciasActivas() > 0; } //Devuelve true si el estado del equipo es menor o igual a 50 o si tiene al menos una incidencia activa, indicando que el equipo necesita mantenimiento. 
double Equipo::calcularRiesgo() { return (100 - estado) + contarIncidenciasActivas() * 10 + criticidad; } //Calcula el riesgo del equipo en base a su estado, el numero de incidencias activas y su criticidad. 

void Equipo::mejorarEstado(int puntos)
{
	estado += puntos;
	if (estado > 100) {estado = 100;}
}