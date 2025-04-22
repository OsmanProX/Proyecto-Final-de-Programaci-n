#include "ODBCConnection.h"
#include <iostream>

ODBCConnection::ODBCConnection() : conectado(false) {
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
}

ODBCConnection::~ODBCConnection() {
    desconectar();
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
}

bool ODBCConnection::conectar(const std::string& dsn_unused, const std::string& usuario, const std::string& contrasena) {
    SQLCHAR outstr[1024];
    SQLSMALLINT outstrlen;

    std::string connStr =
        "Driver={ODBC Driver 18 for SQL Server};"
        "Server=DESKTOP-BDPT4MM;"
        "Database=DBSISTEMA_CONSULTAS;"
        "Uid=sa;"
        "Pwd=6789juanpatito.;"
        "Encrypt=yes;"
        "TrustServerCertificate=yes;";

    SQLRETURN ret = SQLDriverConnect(hDbc, NULL,
        (SQLCHAR*)connStr.c_str(), SQL_NTS,
        outstr, sizeof(outstr), &outstrlen, SQL_DRIVER_COMPLETE);

    if (SQL_SUCCEEDED(ret)) {
        conectado = true;
        return true;
    } else {
        std::cerr << "❌ Error al conectar con SQL Server usando ODBC Driver 18.\n";
        return false;
    }
}

void ODBCConnection::desconectar() {
    if (conectado) {
        SQLDisconnect(hDbc);
        conectado = false;
    }
}

SQLHDBC ODBCConnection::getConexion() {
    return hDbc;
}

bool ODBCConnection::ejecutar(const std::string& query) {
    SQLHSTMT hStmt;
    SQLRETURN ret;

    ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        std::cerr << "❌ No se pudo asignar el manejador de sentencia." << std::endl;
        return false;
    }

    ret = SQLExecDirect(hStmt, (SQLCHAR*)query.c_str(), SQL_NTS);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        std::cerr << "❌ Error al ejecutar la consulta: " << query << std::endl;
        SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        return false;
    }

    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    return true;
}
