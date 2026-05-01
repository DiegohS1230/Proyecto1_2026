#include <iostream>
#include "Simulador.h"
#include "LisEquipo.h"
#include "Equipo.h"
#include "Incidencia.h"

using namespace std;

int main()
{
	try {
		LisEquipo* listaEquipos = new LisEquipo();
		//SE CREAN LOS EQUIPOS Y SE LES ASIGNAN INCIDENCIAS (Datos quemados)
		Equipo* eq1 = new Equipo("EQ-001", "Servidor de laboratorio", 10, 75, 0, 0.0);
		Equipo* eq2 = new Equipo("EQ-002", "Router principal", 9, 80, 0, 0.0);
		Equipo* eq3 = new Equipo("EQ-003", "Switch de red", 8, 85, 0, 0.0);
		Equipo* eq4 = new Equipo("EQ-004", "Computadora de aula 1", 6, 70, 0, 0.0);
		Equipo* eq5 = new Equipo("EQ-005", "Proyector del laboratorio", 5, 90, 0, 0.0);
		//Se agregan incidencias a los equipos
		eq1->agregarIncidencia(new Incidencia("INC-001", "Sobrecalentamiento del servidor", "ALTA", 1, true));
		eq1->agregarIncidencia(new Incidencia("INC-002", "Disco duro con errores", "ALTA", 1, true));
		eq2->agregarIncidencia(new Incidencia("INC-003", "Perdida intermitente de conexion", "MEDIA", 1, true));
		eq3->agregarIncidencia(new Incidencia("INC-004", "Puertos de red fallando", "MEDIA", 1, true));
		eq4->agregarIncidencia(new Incidencia("INC-005", "Sistema operativo lento", "BAJA", 1, true));
		eq4->agregarIncidencia(new Incidencia("INC-006", "Teclado con fallas", "BAJA", 1, true)); 
		eq5->agregarIncidencia(new Incidencia("INC-007", "Imagen borrosa", "MEDIA", 1, true));
		//Se agregan los equipos a la lista de equipos
		listaEquipos->agregarEquipo(eq1);
		listaEquipos->agregarEquipo(eq2);
		listaEquipos->agregarEquipo(eq3);
		listaEquipos->agregarEquipo(eq4);
		listaEquipos->agregarEquipo(eq5);

		Simulador simulador(listaEquipos, 30);
		simulador.ejecutarSimulacion();
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}