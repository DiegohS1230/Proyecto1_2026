#include "Simulador.h"
#include "Mante_Preventivo.h"
#include "Mante_Correctivo.h"

Simulador::Simulador(LisEquipo* equipos, int dias): equipos(equipos),dias(dias),mantenimientos(new List_Mante())
{
    mantenimientos->agregarMantenimiento(new Mante_Preventivo());
    mantenimientos->agregarMantenimiento(new Mante_Correctivo());
}

Simulador::~Simulador()
{
    delete equipos;
    delete mantenimientos;
}

void Simulador::ejecutarSimulacion(){
    for (int dia = 1; dia <= dias; dia++) {
        simularDia(dia);
        generarReporteDiario(dia);
    }
    guardarReporteEnArchivo();
}

void Simulador::simularDia(int dia)
{
    cout << "\n==============================" << endl;
    cout << "          DIA " << dia << endl;
    cout << "==============================" << endl;

    if (!equipos) throw ClassExceptio("No hay equipos cargados en el simulador.");
    equipos->degradarTodos();
    equipos->calcularPrioridades();
    equipos->ordenarPorPrioridad();
    Equipo** top3 = equipos->obtenerTop3();
    for (int i = 0; i < 3; i++) {
        if (top3[i]) {
            cout << "\nEquipo atendido numero: " << (i + 1) << endl;
            cout << top3[i]->MostrarEquipo() << endl;

            Mantenimiento* mantenimiento = seleccionarMantenimiento(top3[i]);

            cout << "Tipo de mantenimiento: " << mantenimiento->getTipo() << endl;
            cout << mantenimiento->descripcion() << endl;

            mantenimiento->aplicar(top3[i]);

            cout << "Tipo de mantenimiento: " << mantenimiento->getTipo() << endl;
            cout << mantenimiento->descripcion() << endl;

            Mante_Correctivo* correctivo = dynamic_cast<Mante_Correctivo*>(mantenimiento);
            if (correctivo) {
                cout << "Mantenimiento correctivo detectado." << endl;
                correctivo->repararFallaCritica();
            }

            mantenimiento->aplicar(top3[i]);

            // NO eliminar aquí: el objeto pertenece a List_Mante y será gestionado por esa lista.
            // delete mantenimiento;
        }
    }
    delete[] top3;
    equipos->calcularPrioridades();
}


void Simulador::generarReporteDiario(int dia)
{
    cout << "\n----- REPORTE DEL DIA " << dia << " -----" << endl;
    cout << "Riesgo global del laboratorio: "<< equipos->calcularRiesgoGlobal() << endl;
    cout << "Equipos pendientes de atencion: "<< equipos->contarPendientes() << endl;
    cout << "Estado general:" << endl;
    cout << equipos->mostrarEquipos() << endl;
}

void Simulador::guardarReporteEnArchivo()
{
    ofstream archivo("reporte_simulacion.txt");
    if (!archivo.is_open()) throw ClassExceptio("No se pudo abrir el archivo para escribir el reporte.");
    archivo << "REPORTE GENERAL DE SIMULACION" << endl;
    archivo << "Riesgo global final: " << equipos->calcularRiesgoGlobal() << endl;
    archivo << "Equipos pendientes finales: " << equipos->contarPendientes() << endl;
    archivo << endl;
    archivo << equipos->mostrarEquipos() << endl;
    archivo.close();
    cout << "Reporte guardado en reporte_simulacion.txt" << endl;
}

Mantenimiento* Simulador::seleccionarMantenimiento(Equipo* equipo)
{
    if (equipo->calcularRiesgo() >= 50 || equipo->contarIncidenciasActivas() > 0) {
        return mantenimientos->buscarPorId("Correctivo");
    }

    return mantenimientos->buscarPorId("Preventivo");
}