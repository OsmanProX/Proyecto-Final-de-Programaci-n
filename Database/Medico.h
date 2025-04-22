#ifndef MEDICO_H
#define MEDICO_H

#include <string>

class Medico {
private:
    int id;
    std::string nombre;
    std::string especialidad;
    std::string telefono;

public:
    Medico();
    Medico(int id, const std::string& nombre, const std::string& especialidad, const std::string& telefono);

    // Getters
    int getId() const;
    std::string getNombre() const;
    std::string getEspecialidad() const;
    std::string getTelefono() const;

    // Setters
    void setId(int id);
    void setNombre(const std::string& nombre);
    void setEspecialidad(const std::string& especialidad);
    void setTelefono(const std::string& telefono);
};

#endif
