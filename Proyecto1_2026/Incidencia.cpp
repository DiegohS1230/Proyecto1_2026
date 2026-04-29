#include "Incidencia.h"
#include <sstream>

Incidencia::Incidencia(string id, string descripcion, string severidad, int diaAparicion, bool activa)
{
    this->id = id;
    this->activa = activa;
    this->descripcion = descripcion;
    this->severidad = severidad;
    this->diaAparicion = diaAparicion;

}

Incidencia::~Incidencia(){//vacio
}
//gets
string Incidencia::getId(){return id;}
string Incidencia::getDescripcion(){return descripcion;}
string Incidencia::getSeveridad(){return severidad;}
int Incidencia::getDiaAparicion(){return diaAparicion;}
bool Incidencia::getActiva(){return activa;}
//sets
void Incidencia::setId(string id){this->id = id;}
void Incidencia::setDescripcion(string descripcion) { this->descripcion = descripcion; }
void Incidencia::setSeveridad(string severidad) { this->severidad = severidad; }
void Incidencia::setDiaAparicion(int diaAparicion) { this->diaAparicion = diaAparicion; }
void Incidencia::setActiva(bool activa) { this->activa = activa; }
//toString
string Incidencia::mostrarIncidencias()
{
    stringstream s;
    s << "El Id del Equipo: " << id << endl;
    s << "La descripcion es: " <<descripcion<< endl;
    s << "La severidad es: " <<severidad<< endl;
    s << "Dia de Aparicion de la Incidencia: "<<diaAparicion << endl;
    s << "La incidencia esta activa: "<<activa << endl;
    return s.str();
}
