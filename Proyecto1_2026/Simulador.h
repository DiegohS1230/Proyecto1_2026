#pragma once
#include "LisEquipo.h"
#include <fstream>
#include "ClassExceptio.h"
#include "Mantenimiento.h"
#include "List_Mante.h"
#include "Mante_Preventivo.h"
#include "Mante_Correctivo.h"
#include "Tecnico.h"
class Simulador {
private:
    LisEquipo* equipos{ nullptr };
    int dias;
	List_Mante* mantenimientos{ nullptr }; //Se inicializa para evitar problemas de punteros nulos al intentar acceder a la lista de mantenimientos en el metodo seleccionarMantenimiento.
    Tecnico* tecnicos[3];
public:
    Simulador(LisEquipo* equipos, int dias = 30);
    ~Simulador();
    void ejecutarSimulacion();
    void simularDia(int dia);
    void generarReporteDiario(int dia);
    void guardarReporteEnArchivo();
    Mantenimiento* seleccionarMantenimiento(Equipo* equipo);
};
