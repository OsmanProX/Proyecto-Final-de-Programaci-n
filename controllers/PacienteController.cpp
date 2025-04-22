#include "PacienteController.h"
#include <iostream>

PacienteController::PacienteController() {}

bool PacienteController::insertarPaciente(const Paciente& paciente) {
    ODBCConnection conexion;
    if (!conexion.conectar("", "", "")) {
        std::cerr << "❌ No se pudo conectar a la base de datos desde PacienteController." << std::endl;
        return false;
    }

    std::string query = "INSERT INTO Pacientes (nombre, apellido, telefono) VALUES ('" +
        paciente.getNombre() + "', '" +
        paciente.getApellido() + "', '" +
        paciente.getTelefono() + "')";

    bool exito = conexion.ejecutar(query);
    conexion.desconectar();
    return exito;
}
