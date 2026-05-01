#include "Tecnico.h"
#include <sstream>

Tecnico::Tecnico(string nombre, string id, bool ocupado)
{
    this->nombre = nombre;
    this->id = id;
    this->ocupado = ocupado;
}

Tecnico::~Tecnico()
{
    //Vacio
}
//gets
string Tecnico::getNombreTec(){return nombre;}
string Tecnico::getIDTec(){return id;}
bool Tecnico::getOcupadoTec(){return ocupado;}
//sets
void Tecnico::setNombreTec(string nombre){this->nombre = nombre;}
void Tecnico::setIDTec(string id){this->id = id;}
void Tecnico::setOcupadoTec(bool ocupado){this->ocupado = ocupado;}

string Tecnico::MostrarTecnico()
{
    stringstream s;
    s << "Nombre del Tecnico: " << nombre << endl;
    s << "El ID del Tecnico: " << id << endl;
    if (ocupado) s << "El Tecnico esta ocupado " << endl;
    else s << "El Tecnico no esta ocupado " << endl;
    return s.str();
}

bool Tecnico::estaDisponible()
{
    return !ocupado;
}

void Tecnico::asignarEquipo(Equipo* equipo)
{
    if (!equipo) return;
    ocupado = true;
    cout << nombre << " fue asignado al equipo: "
        << equipo->getNombre() << endl;

}

void Tecnico::ejecutarMantenimiento()
{
    cout << nombre << " esta ejecutando mantenimiento..." << endl;
}

void Tecnico::liberar()
{
    ocupado = false;
    cout << nombre << " ha quedado disponible." << endl;
}
