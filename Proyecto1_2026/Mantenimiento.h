#pragma once
#include <string>
#include <iostream>
using namespace std;
class Equipo; 
class Mantenimiento
{
public:
    virtual ~Mantenimiento() {};
    virtual void aplicar(Equipo* equipo) = 0;
    virtual string getTipo() = 0;
    virtual string descripcion() = 0;
   
};

