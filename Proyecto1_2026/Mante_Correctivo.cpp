#include "Mante_Correctivo.h"

void Mante_Correctivo::aplicar(Equipo* equipo)
{
    cout << "Aplicando mantenimiento correctivo a " << equipo->getNombre() << endl;
	equipo->setEstado("Mantenimiento Correctivo");
}

string Mante_Correctivo::getTipo() {return "Correctivo";}
