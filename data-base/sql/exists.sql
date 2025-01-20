SELECT nome, CPF
FROM Medicos M
WHERE EXISTS (SELECT 1 FROM Pacientes P WHERE M.CPF = P.CPF);

SELECT nome, idade
FROM Medicos M
WHERE EXISTS (SELECT 1 FROM Consultas C WHERE C.codm = M.codm AND C.codp = (SELECT codp FROM Pacientes WHERE nome = 'Ana'));

SELECT nroa
FROM Ambulatorios A
WHERE NOT EXISTS (SELECT 1 FROM Ambulatorios B WHERE B.capacidade > A.capacidade);

SELECT nome, CPF
FROM Medicos M
WHERE NOT EXISTS (SELECT 1 FROM Pacientes P WHERE NOT EXISTS (SELECT 1 FROM Consultas C WHERE C.codm = M.codm AND C.codp = P.codp));

SELECT nome, CPF
FROM Medicos M
WHERE especialidade = 'ortopedia'
AND EXISTS (SELECT 1 FROM Consultas C, Pacientes P WHERE C.codm = M.codm AND C.codp = P.codp AND P.cidade = 'Florianopolis');

