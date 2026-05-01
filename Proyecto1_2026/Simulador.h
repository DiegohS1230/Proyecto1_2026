#pragma once
#include "LisEquipo.h"
#include <fstream>
#include "ClassExceptio.h"
#include "Mantenimiento.h"
class Simulador {
private:
    LisEquipo* equipos;
    int dias;

public:
    Simulador(LisEquipo* equipos, int dias = 30);
    ~Simulador();
    void ejecutarSimulacion();
    void simularDia(int dia);
    void generarReporteDiario(int dia);
    void guardarReporteEnArchivo();
    Mantenimiento* seleccionarMantenimiento(Equipo* equipo);
};
