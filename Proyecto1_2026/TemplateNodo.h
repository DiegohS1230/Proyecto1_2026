#pragma once
template <typename T>
class TemplateNodo
{
private:
	T* dato;
	TemplateNodo<T>* siguiente;
public:
	TemplateNodo(T* dato, TemplateNodo<T>* siguiente = nullptr) : dato(dato), siguiente(siguiente) {}
	T* getDato() { return dato; }
	TemplateNodo<T>* getSiguiente() { return siguiente; }
	void setSiguiente(TemplateNodo<T>* siguiente) { this->siguiente = siguiente; }
	void setDato(T* dato) { this->dato = dato; }
};

