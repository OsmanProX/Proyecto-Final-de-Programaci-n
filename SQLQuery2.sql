-- Crear la base de datos
CREATE DATABASE DBSISTEMA_CONSULTAS;
GO

-- Usar la base de datos reci�n creada
USE DBSISTEMA_CONSULTAS;
GO

-- Tabla: Pacientes
CREATE TABLE Pacientes (
    id INT IDENTITY(1,1) PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    apellido VARCHAR(100) NOT NULL,
    telefono VARCHAR(20),
    fecha_registro DATETIME DEFAULT GETDATE()
);
GO

-- Tabla: Medicos
CREATE TABLE Medicos (
    id INT IDENTITY(1,1) PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    especialidad VARCHAR(100) NOT NULL,
    telefono VARCHAR(20),
    fecha_registro DATETIME DEFAULT GETDATE()
);
GO

-- Tabla: Citas
CREATE TABLE Citas (
    id INT IDENTITY(1,1) PRIMARY KEY,
    id_paciente INT NOT NULL,
    id_medico INT NOT NULL,
    fecha DATETIME NOT NULL,
    motivo VARCHAR(255),
    FOREIGN KEY (id_paciente) REFERENCES Pacientes(id),
    FOREIGN KEY (id_medico) REFERENCES Medicos(id)
);
GO

-- Tabla: Usuarios (para login de empleados o administraci�n)
CREATE TABLE Usuarios (
    id INT IDENTITY(1,1) PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    contrasena VARCHAR(255) NOT NULL,
    rol VARCHAR(50) CHECK (rol IN ('admin', 'recepcionista', 'doctor')),
    activo BIT DEFAULT 1
);
GO

-- Tabla: Especialidades (opcional para normalizaci�n futura)
CREATE TABLE Especialidades (
    id INT IDENTITY(1,1) PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL
);
GO

-- Agregar columna FK en Medicos para Especialidades (si decides usarla)
-- ALTER TABLE Medicos
-- ADD id_especialidad INT,
-- FOREIGN KEY (id_especialidad) REFERENCES Especialidades(id);
-- GO
