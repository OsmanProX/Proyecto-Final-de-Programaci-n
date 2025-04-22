#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

class Paciente {
private:
    int id;
    std::string nombre;
    std::string apellido;
    std::string telefono;

public:
    Paciente();
    Paciente(int id, const std::string& nombre, const std::string& apellido, const std::string& telefono);

    // Getters
    int getId() const;
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getTelefono() const;

    // Setters
    void setId(int id);
    void setNombre(const std::string& nombre);
    void setApellido(const std::string& apellido);
    void setTelefono(const std::string& telefono);
};

#endif
