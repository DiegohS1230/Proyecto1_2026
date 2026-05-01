#pragma once
#include "Equipo.h"
class Mantenimiento
{
public:
    virtual void aplicar(Equipo* equipo) = 0;
    virtual string getTipo() = 0;
    virtual ~Mantenimiento() {}
};

