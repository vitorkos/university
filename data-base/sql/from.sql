SELECT *
FROM Consultas C
JOIN (SELECT codm FROM Medicos WHERE nome = 'Maria') M
ON C.codm = M.codm;

SELECT P.codp, P.nome
FROM Pacientes P
JOIN (SELECT codp FROM Consultas WHERE hora > '14:00') C
ON P.codp = C.codp;

SELECT P.nome, P.cidade
FROM Pacientes P
JOIN (SELECT codp FROM Consultas WHERE codm IN (SELECT codm FROM Medicos WHERE especialidade = 'ortopedia')) C
ON P.codp = C.codp;

SELECT P.nome, P.CPF
FROM Pacientes P
WHERE cidade = 'Florianopolis'
AND codp NOT IN (SELECT codp FROM Consultas WHERE codm = (SELECT codm FROM Medicos WHERE nome = 'Joao'));

