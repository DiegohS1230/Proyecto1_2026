#include "Mante_Correctivo.h"

void Mante_Correctivo::aplicar(Equipo* equipo)
{
    cout << "Aplicando mantenimiento correctivo a " << equipo->getNombre() << endl;
	equipo->setEstado(equipo->getEstado() - 20);
}

string Mante_Correctivo::getTipo() {return "Correctivo";}
