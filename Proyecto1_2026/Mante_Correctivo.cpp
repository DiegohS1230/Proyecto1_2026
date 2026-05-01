#include "Mante_Correctivo.h"
#include "Equipo.h"

void Mante_Correctivo::aplicar(Equipo* equipo)
{
    cout << "Aplicando mantenimiento correctivo a " << equipo->getNombre() << endl;
	equipo->setEstado(equipo->getEstado() + 20);
}

string Mante_Correctivo::getTipo() {return "Correctivo";}

string Mante_Correctivo::descripcion()
{
	return "Mantenimiento correctivo: mejora fuerte y resuelve una incidencia.";
}

void Mante_Correctivo::repararFallaCritica()
{
	cout << "Reparacion critica realizada." << endl;
}
