#include <iostream>
#include <sstream>
#include "LisEquipo.h"
#include "Equipo.h"
#include "Incidencia.h"
#include "Simulador.h"
#include "ClassExceptio.h"

using namespace std;

int main()
{
	try {
		LisEquipo* listaEquipos = new LisEquipo();

		string tiposEquipo[10] = {
			"Servidor academico",
			"Router principal",
			"Switch de red",
			"Computadora de laboratorio",
			"Proyector de aula",
			"Impresora multifuncional",
			"Punto de acceso WiFi",
			"Equipo de videoconferencia",
			"Servidor de bases de datos",
			"Estacion de trabajo docente"
		};

		for (int i = 1; i <= 100; i++) {
			stringstream id;
			id << "EQ-" << i;

			stringstream nombre;
			nombre << tiposEquipo[i % 10] << " #" << i;

			int criticidad = (i % 10) + 1;
			int estado = 60 + (i % 40);
			int tiempoActivo = i % 5;
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
					descripcion = "Falla de conectividad de red";
					severidad = "ALTA";
				}
				else if (j == 2) {
					descripcion = "Rendimiento lento del sistema";
					severidad = "MEDIA";
				}
				else {
					descripcion = "Mantenimiento preventivo pendiente";
					severidad = "BAJA";
				}

				equipo->agregarIncidencia(new Incidencia(
					idIncidencia.str(),
					descripcion,
					severidad,
					1,
					true
				));
			}
		}

		cout << "Datos de prueba cargados correctamente." << endl;
		cout << "Equipos creados: 100" << endl;
		cout << "Incidencias creadas: 300" << endl;

		Simulador simulador(listaEquipos, 30);
		simulador.ejecutarSimulacion();
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}