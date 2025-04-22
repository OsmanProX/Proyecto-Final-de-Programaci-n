#include <iostream>
#include <string>
#include "controllers/PacienteController.h"
#include "../Proyecto-Final-de-Programaci-n//controllers/MedicoControllers.h"
#include "../Proyecto-Final-de-Programaci-n//controllers/CitaControllers.h"
#include "ODBCConnect/ODBCConnection.h"

void menuPrincipal() {
    std::cout << "\n======= SISTEMA DE CITAS MÉDICAS =======\n";
    std::cout << "1. Registrar paciente\n";
    std::cout << "2. Registrar médico\n";
    std::cout << "3. Crear cita\n";
    std::cout << "4. Ver pacientes\n";
    std::cout << "5. Ver médicos\n";
    std::cout << "6. Ver citas\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";
}
// Hola
int main() {
    ODBCConnection conexion;
    if (!conexion.conectar("", "", "")) {
        std::cerr << "❌ No se pudo establecer la conexión con la base de datos.\n";
        return 1;
    }

    PacienteController pacienteCtrl(&conexion);
    MedicoController medicoCtrl(&conexion);
    CitaController citaCtrl(&conexion);

    int opcion;
    do {
        menuPrincipal();
        std::cin >> opcion;
        std::cin.ignore(); // limpiar buffer

        switch (opcion) {
            case 1: {
                std::string nombre, apellido, telefono;
                std::cout << "Nombre: "; std::getline(std::cin, nombre);
                std::cout << "Apellido: "; std::getline(std::cin, apellido);
                std::cout << "Teléfono: "; std::getline(std::cin, telefono);
                pacienteCtrl.agregar(nombre, apellido, telefono);
                break;
            }
            case 2: {
                std::string nombre, especialidad, telefono;
                std::cout << "Nombre: "; std::getline(std::cin, nombre);
                std::cout << "Especialidad: "; std::getline(std::cin, especialidad);
                std::cout << "Teléfono: "; std::getline(std::cin, telefono);
                medicoCtrl.agregar(nombre, especialidad, telefono);
                break;
            }
            case 3: {
                int id_paciente, id_medico;
                std::string fecha, motivo;
                std::cout << "ID del paciente: "; std::cin >> id_paciente;
                std::cout << "ID del médico: "; std::cin >> id_medico;
                std::cin.ignore();
                std::cout << "Fecha y hora (YYYY-MM-DD HH:MM:SS): "; std::getline(std::cin, fecha);
                std::cout << "Motivo: "; std::getline(std::cin, motivo);
                citaCtrl.agregar(id_paciente, id_medico, fecha, motivo);
                break;
            }
            case 4:
                pacienteCtrl.mostrarTodos();
                break;
            case 5:
                medicoCtrl.mostrarTodos();
                break;
            case 6:
                citaCtrl.mostrarTodos();
                break;
            case 0:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "❌ Opción no válida.\n";
        }

    } while (opcion != 0);

    conexion.desconectar();
    return 0;
}
