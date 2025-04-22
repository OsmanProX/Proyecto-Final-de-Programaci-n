#ifndef ODBCCONNECTION_H
#define ODBCCONNECTION_H

#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <string>

class ODBCConnection {
private:
    SQLHENV hEnv;
    SQLHDBC hDbc;
    bool conectado;

public:
    ODBCConnection();
    ~ODBCConnection();

    bool conectar(const std::string& dsn_unused, const std::string& usuario, const std::string& contrasena);
    void desconectar();

    SQLHDBC getConexion(); // Para acceder a la conexión desde controladores
    bool ejecutar(const std::string& query); // Ejecutar consultas tipo INSERT, UPDATE, DELETE
};

#endif
