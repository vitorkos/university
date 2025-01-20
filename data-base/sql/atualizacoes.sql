UPDATE Consultas
SET hora = '19:00'
WHERE codp = (SELECT codp FROM Pacientes WHERE nome = 'Ana');

DELETE FROM Pacientes
WHERE codp NOT IN (SELECT codp FROM Consultas);

DELETE FROM Pacientes
WHERE codp NOT IN (SELECT codp FROM Consultas);

UPDATE Ambulatorios
SET andar = (SELECT andar FROM Ambulatorios WHERE nroa = 1),
    capacidade = 2 * (SELECT MAX(capacidade) FROM Ambulatorios)
WHERE nroa = 4;

INSERT INTO Medicos (codm, nome, idade, especialidade, CPF, cidade, nroa)
SELECT codf, nome, idade, (SELECT especialidade FROM Medicos WHERE codm = 2), CPF, cidade, (SELECT nroa FROM Medicos WHERE codm = 2)
FROM Funcionarios
WHERE codf = 3;


