#include <iostream>
#include "Equipo.h"
#include "Incidencia.h"

using namespace std;

int main()
{
    cout << "===== PRUEBA BASICA DEL PROYECTO =====" << endl;

    Equipo* equipo1 = new Equipo("EQ-001", "Microscopio", 9, 80, 0, 0.0);

    Incidencia* inc1 = new Incidencia("INC-001", "Lente sucio", "Alta", 1, true);
    Incidencia* inc2 = new Incidencia("INC-002", "Falla de luz", "Media", 1, true);

    equipo1->agregarIncidencia(inc1);
    equipo1->agregarIncidencia(inc2);

    cout << "\n--- Estado inicial ---" << endl;
    equipo1->calcularPrioridad();
    cout << equipo1->MostrarEquipo() << endl;

    cout << "\n--- Despues de actualizar un dia ---" << endl;
    equipo1->actualizarDia();
    cout << equipo1->MostrarEquipo() << endl;

    cout << "\n--- Despues de recibir mantenimiento ---" << endl;
    equipo1->recibirMantenimiento();
    cout << equipo1->MostrarEquipo() << endl;

    cout << "\n--- Despues de otro dia ---" << endl;
    equipo1->actualizarDia();
    cout << equipo1->MostrarEquipo() << endl;

    delete equipo1;

    cout << "\n===== FIN DE LA PRUEBA =====" << endl;

    return 0;
}