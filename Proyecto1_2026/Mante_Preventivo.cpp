#include "Mante_Preventivo.h"
void Mante_Preventivo::aplicar(Equipo* equipo){
		cout << "Aplicando mantenimiento preventivo a " << equipo->getNombre() << endl;
		equipo->setEstado("Mantenimiento Preventivo");
}

string Mante_Preventivo::getTipo(){return "Preventivo";}

