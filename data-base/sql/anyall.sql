SELECT nroa, andar
FROM Ambulatorios
WHERE capacidade > ALL (SELECT capacidade FROM Ambulatorios);

SELECT nome, idade
FROM Medicos
WHERE codm = ANY (SELECT codm FROM Consultas WHERE codp = (SELECT codp FROM Pacientes WHERE nome = 'Ana'));

SELECT nome, idade
FROM Medicos
WHERE idade <= ALL (SELECT idade FROM Medicos);

SELECT nome, CPF
FROM Pacientes
WHERE codp IN (SELECT codp FROM Consultas WHERE hora < ALL (SELECT hora FROM Consultas WHERE data = '2006-11-12'));

SELECT nome, CPF
FROM Medicos
WHERE nroa NOT IN (SELECT nroa FROM Ambulatorios WHERE capacidade > ANY (SELECT capacidade FROM Ambulatorios WHERE andar = 2));

