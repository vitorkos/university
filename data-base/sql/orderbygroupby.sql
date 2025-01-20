SELECT *
FROM Funcionarios
ORDER BY salario DESC, idade ASC
LIMIT 3;

SELECT M.nome, A.nroa, A.andar
FROM Medicos M
JOIN Ambulatorios A ON M.nroa = A.nroa
ORDER BY A.nroa;

SELECT M.nome, A.nroa, A.andar
FROM Medicos M
JOIN Ambulatorios A ON M.nroa = A.nroa
ORDER BY A.nroa;

SELECT idade, COUNT(*) AS total_medicos
FROM Medicos
GROUP BY idade;

SELECT idade, COUNT(*) AS total_medicos
FROM Medicos
GROUP BY idade;

SELECT andar, AVG(capacidade) AS media_capacidade
FROM Ambulatorios
GROUP BY andar;

SELECT andar, AVG(capacidade) AS media_capacidade
FROM Ambulatorios
GROUP BY andar
HAVING AVG(capacidade) >= 40;

SELECT M.nome
FROM Medicos M
JOIN Consultas C ON M.codm = C.codm
GROUP BY M.nome
HAVING COUNT(C.codp) > 1;

