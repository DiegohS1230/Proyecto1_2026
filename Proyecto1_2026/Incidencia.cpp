#include "Incidencia.h"
#include <sstream>

Incidencia::Incidencia(string id, string descripcion, string severidad, int diaAparicion, bool activa)
{
    this->id = id;
    this->activa = activa;
    this->descripcion = descripcion;
    this->severidad = convertirMayusculas(severidad);
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
void Incidencia::setSeveridad(string severidad) { this->severidad = convertirMayusculas(severidad); }
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

void Incidencia::activar() {this->activa = true;}
void Incidencia::resolver(){this->activa = false;}
bool Incidencia::estaActiva(){return activa;}

int Incidencia::calcularDiasActiva(int diaActual) {
    if(!activa) return 0;
    if(diaActual < diaAparicion) return 0;
    return diaActual - diaAparicion +1;
}

int Incidencia::obtenerPesoSeveridad()
{
    if (severidad == "BAJA") return 1;
    if (severidad == "MEDIA") return 2;
    if (severidad == "ALTA") return 3;
    return 0;
}

string Incidencia::convertirMayusculas(string texto) //Convierte el texto a mayusculas.
{
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = toupper(texto[i]);
    }

    return texto;
}

