#pragma once
#include "Mantenimiento.h"
class Mante_Correctivo : public Mantenimiento
{
public:
	void aplicar(Equipo* equipo) override;
	string getTipo() override;
	string descripcion() override;
	void repararFallaCritica();
};

