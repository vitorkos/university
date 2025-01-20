SELECT nome, CPF 
FROM Medicos
WHERE idade < 40 OR especialidade != 'traumatologia';

SELECT * 
FROM Consultas
WHERE data > '2006-06-19' AND hora >= '12:00';

SELECT nome, idade 
FROM Pacientes
WHERE cidade != 'Florianopolis';

SELECT hora 
FROM Consultas
WHERE data < '2006-06-14' OR data > '2006-06-20';

SELECT nome, (idade * 12) AS idade_em_meses
FROM Pacientes;

SELECT DISTINCT cidade 
FROM Funcionarios;

SELECT MIN(salario) AS menor_salario, MAX(salario) AS maior_salario
FROM Funcionarios
WHERE cidade = 'Florianopolis';

SELECT MAX(hora) AS ultima_consulta
FROM Consultas
WHERE data = '2006-06-13';

SELECT AVG(idade) AS media_idade, COUNT(DISTINCT nroa) AS total_ambulatorios
FROM Medicos;

SELECT codf, nome, salario - (salario * 0.20) AS salario_liquido
FROM Funcionarios;

SELECT AVG(idade) AS media_idade, COUNT(DISTINCT nroa) AS total_ambulatorios
FROM Medicos;

SELECT codf, nome, salario - (salario * 0.20) AS salario_liquido
FROM Funcionarios;

SELECT nome 
FROM Funcionarios
WHERE nome LIKE '%a';

SELECT nome, CPF
FROM Funcionarios
WHERE CAST(CPF AS VARCHAR) NOT LIKE '%00000%';

SELECT nome, especialidade 
FROM Medicos
WHERE SUBSTRING(nome, 2, 1) = 'o' AND RIGHT(nome, 1) = 'o';

SELECT codp, nome
FROM Pacientes
WHERE idade > 25 AND doenca IN ('tendinite', 'fratura', 'gripe', 'sarampo');












