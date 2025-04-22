#include "Paciente.h"

Paciente::Paciente() : id(0), nombre(""), apellido(""), telefono("") {}

Paciente::Paciente(int id, const std::string& nombre, const std::string& apellido, const std::string& telefono)
    : id(id), nombre(nombre), apellido(apellido), telefono(telefono) {}

int Paciente::getId() const { return id; }
std::string Paciente::getNombre() const { return nombre; }
std::string Paciente::getApellido() const { return apellido; }
std::string Paciente::getTelefono() const { return telefono; }

void Paciente::setId(int id) { this->id = id; }
void Paciente::setNombre(const std::string& nombre) { this->nombre = nombre; }
void Paciente::setApellido(const std::string& apellido) { this->apellido = apellido; }
void Paciente::setTelefono(const std::string& telefono) { this->telefono = telefono; }
