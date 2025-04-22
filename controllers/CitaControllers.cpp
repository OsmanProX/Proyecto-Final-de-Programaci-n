#include "CitaControllers.h"
#include <iostream>

CitaController::CitaController() {}

bool CitaController::insertarCita(const Cita& cita) {
    ODBCConnection conexion;
    if (!conexion.conectar("", "", "")) {
        std::cerr << "❌ No se pudo conectar a la base de datos desde CitaController." << std::endl;
        return false;
    }

    std::string query = "INSERT INTO Citas (idPaciente, fecha, hora, motivo) VALUES (" +
        std::to_string(cita.getIdPaciente()) + ", '" +
        cita.getFecha() + "', '" +
        cita.getHora() + "', '" +
        cita.getMotivo() + "')";

    bool exito = conexion.ejecutar(query);
    conexion.desconectar();
    return exito;
}
