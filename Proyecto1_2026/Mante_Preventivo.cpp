#include "Mante_Preventivo.h"
void Mante_Preventivo::aplicar(Equipo* equipo){
		cout << "Aplicando mantenimiento preventivo a " << equipo->getNombre() << endl;
		equipo->setEstado(equipo->getEstado() + 20);
}

string Mante_Preventivo::getTipo(){return "Preventivo";}

string Mante_Preventivo::descripcion()
{
	return "Mantenimiento preventivo: mejora moderada del estado del equipo.";
}

