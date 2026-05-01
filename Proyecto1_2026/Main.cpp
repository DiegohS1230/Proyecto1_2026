#include <iostream>
#include <sstream>
#include "LisEquipo.h"
#include "Equipo.h"
#include "Incidencia.h"
#include "Simulador.h"

using namespace std;

int main()
{
	try {
		LisEquipo* listaEquipos = new LisEquipo();

		// Crear 100 equipos
		for (int i = 1; i <= 100; i++) {
			stringstream id;
			id << "EQ-" << i;

			stringstream nombre;
			nombre << "Equipo de computo #" << i;

			int criticidad = (i % 10) + 1;      // valores entre 1 y 10
			int estado = 60 + (i % 40);         // valores entre 60 y 99
			int tiempoActivo = i % 5;           // valores entre 0 y 4
			double prioridad = 0.0;

			Equipo* equipo = new Equipo(
				id.str(),
				nombre.str(),
				criticidad,
				estado,
				tiempoActivo,
				prioridad
			);

			listaEquipos->agregarEquipo(equipo);
		}

		// Crear 300 incidencias, 3 por equipo
		for (int i = 1; i <= 100; i++) {
			stringstream idEquipo;
			idEquipo << "EQ-" << i;

			Equipo* equipo = listaEquipos->buscarPorId(idEquipo.str());

			for (int j = 1; j <= 3; j++) {
				stringstream idIncidencia;
				idIncidencia << "INC-" << i << "-" << j;

				string descripcion;
				string severidad;

				if (j == 1) {
					descripcion = "Falla de red";
					severidad = "ALTA";
				}
				else if (j == 2) {
					descripcion = "Sistema operativo lento";
					severidad = "MEDIA";
				}
				else {
					descripcion = "Mantenimiento pendiente";
					severidad = "BAJA";
				}

				Incidencia* incidencia = new Incidencia(
					idIncidencia.str(),
					descripcion,
					severidad,
					1,
					true
				);

				equipo->agregarIncidencia(incidencia);
			}
		}

		cout << "Datos de prueba cargados correctamente." << endl;
		cout << "Equipos creados: 100" << endl;
		cout << "Incidencias creadas: 300" << endl;

		Simulador simulador(listaEquipos, 3);
		simulador.ejecutarSimulacion();
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}