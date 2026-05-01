#include "Simulador.h"
#include "Mante_Preventivo.h"
#include "Mante_Correctivo.h"

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
    limpiar.close();
    for (int dia = 1; dia <= dias; dia++) {
        simularDia(dia);
        generarReporteDiario(dia);
    }
    guardarReporteEnArchivo();
}

void Simulador::simularDia(int dia)
{
    ofstream archivo("reporte_simulacion.txt", ios::app);
    if (!archivo.is_open()) {
        throw ClassExceptio("No se pudo abrir el archivo de reporte.");
    }
    cout << "\n==============================" << endl;
    cout << "          DIA " << dia << endl;
    cout << "==============================" << endl;
    archivo << "\n==============================" << endl;
    archivo << "          DIA " << dia << endl;
    archivo << "==============================" << endl;
    if (!equipos) {
        throw ClassExceptio("No hay equipos cargados en el simulador.");
    }

    equipos->degradarTodos();
    equipos->calcularPrioridades();
    equipos->ordenarPorPrioridad();
    Equipo** top3 = equipos->obtenerTop3();
    for (int i = 0; i < 3; i++) {
        if (top3[i] && tecnicos[i]->estaDisponible()) {
            tecnicos[i]->asignarEquipo(top3[i]);
            cout << "\nEquipo atendido numero: " << (i + 1) << endl;
            cout << top3[i]->MostrarEquipo() << endl;
            archivo << "\nTecnico asignado: " << tecnicos[i]->getNombreTec() << endl;
            archivo << "Equipo atendido numero: " << (i + 1) << endl;
            archivo << top3[i]->MostrarEquipo() << endl;
            Mantenimiento* mantenimiento = seleccionarMantenimiento(top3[i]);
            if (!mantenimiento) {
                delete[] top3;
                throw ClassExceptio("No se encontro un mantenimiento valido.");
            }
            cout << "Tipo de mantenimiento: " << mantenimiento->getTipo() << endl;
            cout << mantenimiento->descripcion() << endl;
            archivo << "Tipo de mantenimiento: " << mantenimiento->getTipo() << endl;
            archivo << mantenimiento->descripcion() << endl;
            Mante_Correctivo* correctivo = dynamic_cast<Mante_Correctivo*>(mantenimiento);
            if (correctivo) {
                cout << "Mantenimiento correctivo detectado." << endl;
                archivo << "Mantenimiento correctivo detectado." << endl;

                correctivo->repararFallaCritica();
                archivo << "Reparacion critica realizada." << endl;
            }
            tecnicos[i]->ejecutarMantenimiento();
            archivo << tecnicos[i]->getNombreTec() << " esta ejecutando mantenimiento..." << endl;
            mantenimiento->aplicar(top3[i]); 
            cout << "\nDespues del mantenimiento:" << endl;
            cout << top3[i]->MostrarEquipo() << endl;
            archivo << "\nDespues del mantenimiento:" << endl;
            archivo << top3[i]->MostrarEquipo() << endl;
            tecnicos[i]->liberar();
            archivo << tecnicos[i]->getNombreTec() << " ha quedado disponible." << endl;
        }
    }
	//Se duplica la info par que en el reporte diario se muestre el estado actualizado de los equipos despues de los mantenimientos realizados en el dia
    delete[] top3;

    equipos->calcularPrioridades();

    archivo.close();
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
    ofstream archivo("reporte_simulacion.txt", ios::app);
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