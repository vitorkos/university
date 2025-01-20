SELECT DISTINCT M.nome, M.CPF
FROM Medicos M
JOIN Pacientes P ON M.CPF = P.CPF;

SELECT F.codf, F.nome AS funcionario, M.codm, M.nome AS medico
FROM Funcionarios F
JOIN Medicos M ON F.cidade = M.cidade;

SELECT P.codp, P.nome
FROM Pacientes P
JOIN Consultas C ON P.codp = C.codp
WHERE C.hora > '14:00';

SELECT P.codp, P.nome
FROM Pacientes P
JOIN Consultas C ON P.codp = C.codp
WHERE C.hora > '14:00';

SELECT P.nome, P.CPF
FROM Pacientes P
JOIN Consultas C ON P.codp = C.codp
WHERE C.data BETWEEN '2006-06-14' AND '2006-06-16';

SELECT P.nome, P.CPF
FROM Pacientes P
JOIN Consultas C ON P.codp = C.codp
WHERE C.data BETWEEN '2006-06-14' AND '2006-06-16';

SELECT M.codm, M.nome
FROM Medicos M
JOIN Consultas C ON M.codm = C.codm
WHERE M.nroa = (SELECT nroa FROM Medicos WHERE nome = 'Pedro')
AND C.data = '2006-06-14';

SELECT P.nome, P.CPF, P.idade
FROM Pacientes P
JOIN Consultas C ON P.codp = C.codp
JOIN Medicos M ON C.codm = M.codm
WHERE M.especialidade = 'ortopedia'
AND C.data < '2006-06-16';

SELECT F2.nome, F2.salario
FROM Funcionarios F1
JOIN Funcionarios F2 ON F1.cidade = F2.cidade
WHERE F1.nome = 'Carlos' AND F2.salario > F1.salario;

SELECT A.*, M.codm, M.nome
FROM Ambulatorios A
LEFT JOIN Medicos M ON A.nroa = M.nroa;

SELECT M.CPF AS medico_CPF, M.nome AS medico_nome, P.CPF AS paciente_CPF, P.nome AS paciente_nome, C.data AS data_consulta
FROM Medicos M
LEFT JOIN Consultas C ON M.codm = C.codm
LEFT JOIN Pacientes P ON C.codp = P.codp;

