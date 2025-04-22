#ifndef CITA_H
#define CITA_H

#include <string>

class Cita {
private:
    int id;
    int idPaciente;
    std::string fecha;
    std::string hora;
    std::string motivo;

public:
    Cita();
    Cita(int id, int idPaciente, const std::string& fecha, const std::string& hora, const std::string& motivo);

    // Getters
    int getId() const;
    int getIdPaciente() const;
    std::string getFecha() const;
    std::string getHora() const;
    std::string getMotivo() const;

    // Setters
    void setId(int id);
    void setIdPaciente(int idPaciente);
    void setFecha(const std::string& fecha);
    void setHora(const std::string& hora);
    void setMotivo(const std::string& motivo);
};

#endif
