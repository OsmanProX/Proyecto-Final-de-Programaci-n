cmake_minimum_required(VERSION 3.15)
project(ProyectoPrograma)

set(CMAKE_CXX_STANDARD 20)



add_executable(ProyectoPrograma
        main.cpp
        ODBCConnect/ODBCConnection.cpp
        Database/Cita.cpp
        controllers/CitaControllers.cpp
        Database/Medico.cpp
        controllers/MedicoControllers.cpp
        Database/Paciente.cpp
        controllers/PacienteController.cpp

)

target_link_libraries(ProyectoPrograma odbc32)
