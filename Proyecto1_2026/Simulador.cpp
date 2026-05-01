#include "Simulador.h"
#include "Mante_Preventivo.h"
#include "Mante_Correctivo.h"
#include <fstream>
#include <iostream>

Simulador::Simulador(LisEquipo* equipos, int dias): equipos(equipos),mantenimientos(new List_Mante())
{
	this->dias = dias;
    mantenimientos->agregarMantenimiento(new Mante_Preventivo());
    mantenimientos->agregarMantenimiento(new Mante_Correctivo());
    tecnicos[0] = new Tecnico("Carlos", "TEC-01");
    tecnicos[1] = new Tecnico("Maria", "TEC-02");
    tecnicos[2] = new Tecnico("Jose", "TEC-03");
}

Simulador::~Simulador()
{
    delete equipos;
    delete mantenimientos;
    for (int i = 0; i < 3; i++) {
        delete tecnicos[i];
    }
}

void Simulador::ejecutarSimulacion(){
    ofstream limpiar("reporte_simulacion.txt");
    limpiar << "REPORTE COMPLETO DE SIMULACION" << endl;
    limpiar.close();
    for (int dia = 1; dia <= dias; dia++) {
        simularDia(dia);
        generarReporteDiario(dia);
    }
    guardarReporteEnArchivo();
}

void Simulador::simularDia(int dia)
{
    cout << "\n--- Simulando dia " << dia << " ---" << endl;

    // Recorre todos los equipos, actualiza su estado diario y aplica mantenimientos si es necesario.
    TemplateNodo<Equipo>* nodo = equipos->getPrimero();
    while (nodo) {
        Equipo* equipo = nodo->getDato();
        if (equipo) {
            equipo->actualizarDia(); // degradar, aumentar tiempo y recalcular prioridad

            if (equipo->necesitaMantenimiento()) {
                Mantenimiento* mante = seleccionarMantenimiento(equipo);
                if (mante) {
                    // Buscar un técnico disponible y ejecutar mantenimiento
                    for (int i = 0; i < 3; ++i) {
                        if (tecnicos[i] && tecnicos[i]->estaDisponible()) {
                            tecnicos[i]->asignarEquipo(equipo);
                            tecnicos[i]->ejecutarMantenimiento();
                            mante->aplicar(equipo);
                            tecnicos[i]->liberar();
                            break;
                        }
                    }
                }
            }
        }
        nodo = nodo->getSiguiente();
    }

    // Recalcular prioridades globales después de los cambios del día
    equipos->calcularPrioridades();
}

void Simulador::generarReporteDiario(int dia)
{
    cout << "\n----- REPORTE DEL DIA " << dia << " -----" << endl;
    cout << "Riesgo global del laboratorio: " << equipos->calcularRiesgoGlobal() << endl;
    cout << "Equipos pendientes de atencion: " << equipos->contarPendientes() << endl;
    cout << "Estado general:" << endl;
    cout << equipos->mostrarEquipos() << endl;

    ofstream archivo("reporte_simulacion.txt", ios::app);

    if (!archivo.is_open()) {
        throw ClassExceptio("No se pudo abrir el archivo para escribir el reporte diario.");
    }

    archivo << "\n==============================" << endl;
    archivo << "          DIA " << dia << endl;
    archivo << "==============================" << endl;
    archivo << "Riesgo global del laboratorio: " << equipos->calcularRiesgoGlobal() << endl;
    archivo << "Equipos pendientes de atencion: " << equipos->contarPendientes() << endl;
    archivo << "Estado general:" << endl;
    archivo << equipos->mostrarEquipos() << endl;

    archivo.close();
}

void Simulador::guardarReporteEnArchivo()
{
    ofstream archivo("reporte_simulacion.txt", ios::app);

    if (!archivo.is_open()) {
        throw ClassExceptio("No se pudo abrir el archivo para escribir el reporte final.");
    }

    archivo << "\n========== REPORTE FINAL ==========" << endl;
    archivo << "Riesgo global final: " << equipos->calcularRiesgoGlobal() << endl;
    archivo << "Equipos pendientes finales: " << equipos->contarPendientes() << endl;
    archivo << "Estado final de los equipos:" << endl;
    archivo << equipos->mostrarEquipos() << endl;

    archivo.close();

    cout << "Reporte guardado en reporte_simulacion.txt" << endl;
}

Mantenimiento* Simulador::seleccionarMantenimiento(Equipo* equipo)
{
    if (!equipo) return nullptr;
    if (equipo->tieneIncidenciasActivas() || equipo->getEstado() < 50) {
        return mantenimientos->buscarPorId("Correctivo");
    }
    return mantenimientos->buscarPorId("Preventivo");
}
