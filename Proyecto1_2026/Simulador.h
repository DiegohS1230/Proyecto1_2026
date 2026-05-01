#pragma once
class Simulador
{
public:                     
    void cargarDatosIniciales();
    void simular30Dias();
    void simularDia(int dia);
    void seleccionarTop3();
    void generarReporteDiario(int dia);
    void guardarReporteEnArchivo();
};

