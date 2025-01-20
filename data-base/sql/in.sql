SELECT nome, CPF
FROM Medicos
WHERE CPF IN (SELECT CPF FROM Pacientes);

SELECT codp, nome
FROM Pacientes
WHERE codp IN (SELECT codp FROM Consultas WHERE hora > '14:00');

SELECT nome, idade
FROM Medicos
WHERE codm IN (SELECT codm FROM Consultas WHERE codp = (SELECT codp FROM Pacientes WHERE nome = 'Ana'));

SELECT nroa, andar
FROM Ambulatorios
WHERE nroa NOT IN (SELECT nroa FROM Medicos);

SELECT nome, CPF, idade
FROM Pacientes
WHERE codp IN (SELECT codp FROM Consultas WHERE data < '2006-06-16');

