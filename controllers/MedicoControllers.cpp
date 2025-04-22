#include "MedicoControllers.h"
#include <iostream>

MedicoController::MedicoController() {}

bool MedicoController::insertarMedico(const Medico& medico) {
    ODBCConnection conexion;
    if (!conexion.conectar("", "", "")) {
        std::cerr << "❌ No se pudo conectar a la base de datos desde MedicoController." << std::endl;
        return false;
    }

    std::string query = "INSERT INTO Medicos (nombre, especialidad, telefono) VALUES ('" +
        medico.getNombre() + "', '" +
        medico.getEspecialidad() + "', '" +
        medico.getTelefono() + "')";

    bool exito = conexion.ejecutar(query);
    conexion.desconectar();
    return exito;
}
