DELETE FROM Consultas
WHERE codp = 1;

-- Remover o paciente Ana (codp = 1)
DELETE FROM Pacientes
WHERE codp = 1;

UPDATE Pacientes
SET cidade = 'Ilhota'
WHERE nome = 'Paulo';

UPDATE Consultas
SET data = '2006-07-04', hora = '12:00'
WHERE codm = 1 AND codp = 4;

UPDATE Pacientes
SET idade = idade + 1, doenca = 'cancer'
WHERE nome = 'Ana';

UPDATE Pacientes
SET idade = idade + 1, doenca = 'cancer'
WHERE nome = 'Ana';

DELETE FROM Funcionarios
WHERE codf = 4;

DELETE FROM Consultas
WHERE hora > '19:00';

DELETE FROM Pacientes
WHERE doenca = 'cancer' OR idade < 10;

DELETE FROM Medicos
WHERE cidade = 'Biguacu' OR cidade = 'Palhoca';

