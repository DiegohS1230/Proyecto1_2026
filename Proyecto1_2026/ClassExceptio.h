#pragma once
#include <exception>
#include <string>
using namespace std;
class ClassExceptio : public exception
{
private:
	string mensaje;

public:
	ClassExceptio(string mensaje) {
		this->mensaje = mensaje;
	}

	const char* what() const noexcept override {
		return mensaje.c_str();
	}
};

