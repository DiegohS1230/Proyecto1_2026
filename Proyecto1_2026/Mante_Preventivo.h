#pragma once
#include "Mantenimiento.h"
class Mante_Preventivo : public Mantenimiento
{
	public:
		void aplicar(Equipo* equipo) override;
		string getTipo() override;
};

