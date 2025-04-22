#ifndef PACIENTECONTROLLER_H
#define PACIENTECONTROLLER_H

#include "../Database/Paciente.h"
#include "../ODBCConnect/ODBCConnection.h"

class PacienteController {
public:
    PacienteController();
    bool insertarPaciente(const Paciente& paciente);
};

#endif
