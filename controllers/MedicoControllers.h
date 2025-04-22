#ifndef MEDICOCONTROLLER_H
#define MEDICOCONTROLLER_H

#include "../Database/Medico.h"
#include "../ODBCConnect/ODBCConnection.h"

class MedicoController {
public:
    MedicoController();
    bool insertarMedico(const Medico& medico);
};

#endif
