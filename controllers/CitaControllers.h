#ifndef CITACONTROLLER_H
#define CITACONTROLLER_H

#include <string>
#include "../ODBCConnect/ODBCConnection.h"
#include "../Database/Cita.h"

class CitaController {
public:
    CitaController();
    bool insertarCita(const Cita& cita);
};

#endif
