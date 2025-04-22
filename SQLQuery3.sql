-- Datos de ejemplo: Pacientes
INSERT INTO Pacientes (nombre, apellido, telefono)
VALUES
('Juan', 'Pérez', '12345678'),
('María', 'Gómez', '87654321'),
('Luis', 'Ramírez', '55667788');
GO

-- Datos de ejemplo: Médicos
INSERT INTO Medicos (nombre, especialidad, telefono)
VALUES
('Dr. Ana Torres', 'Pediatría', '11112222'),
('Dr. Carlos Méndez', 'Cardiología', '22223333'),
('Dra. Sofía Reyes', 'Dermatología', '33334444');
GO

-- Datos de ejemplo: Citas
INSERT INTO Citas (id_paciente, id_medico, fecha, motivo)
VALUES
(1, 2, '2025-04-21 10:00:00', 'Chequeo general'),
(2, 1, '2025-04-22 09:00:00', 'Consulta pediátrica'),
(3, 3, '2025-04-23 14:00:00', 'Problema en la piel');
GO

-- Datos de ejemplo: Usuarios
INSERT INTO Usuarios (username, contrasena, rol, activo)
VALUES
('admin', 'admin123', 'admin', 1),
('recepcion', 'recep123', 'recepcionista', 1),
('dr.carlos', 'medico123', 'doctor', 1);
GO
--INFORMACION YA INGRESADA
