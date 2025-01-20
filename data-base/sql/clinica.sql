-- Tabela Ambulatorios
CREATE TABLE Ambulatorios (
    nroa INT PRIMARY KEY,
    andar NUMERIC(3) NOT NULL,
    capacidade SMALLINT
);

-- Tabela Medicos
CREATE TABLE Medicos (
    codm INT PRIMARY KEY,
    nome VARCHAR(40) NOT NULL,
    idade SMALLINT NOT NULL,
    especialidade CHAR(20),
    CPF NUMERIC(11) UNIQUE,
    cidade VARCHAR(30),
    nroa INT,
    FOREIGN KEY (nroa) REFERENCES Ambulatorios(nroa)
);

-- Tabela Pacientes
CREATE TABLE Pacientes (
    codp INT PRIMARY KEY,
    nome VARCHAR(40) NOT NULL,
    idade SMALLINT NOT NULL,
    cidade CHAR(30),
    CPF NUMERIC(11) UNIQUE,
    doenca VARCHAR(40) NOT NULL
);

-- Tabela Funcionarios
CREATE TABLE Funcionarios (
    codf INT PRIMARY KEY,
    nome VARCHAR(40) NOT NULL,
    idade SMALLINT,
    CPF NUMERIC(11) UNIQUE,
    cidade VARCHAR(30),
    salario NUMERIC(10),
    cargo VARCHAR(20)
);

-- Tabela Consultas
CREATE TABLE Consultas (
    codm INT,
    codp INT,
    data DATE,
    hora TIME,
    PRIMARY KEY (codm, codp, data, hora),
    FOREIGN KEY (codm) REFERENCES Medicos(codm),
    FOREIGN KEY (codp) REFERENCES Pacientes(codp)
);

ALTER TABLE Funcionarios
ADD COLUMN nroa INT;

-- Índice único para CPF na tabela Medicos
CREATE UNIQUE INDEX idx_Medicos_CPF ON Medicos (CPF);

-- Índice para a coluna doenca na tabela Pacientes
CREATE INDEX idx_Pacientes_doenca ON Pacientes (doenca);

DROP INDEX idx_Pacientes_doenca;


ALTER TABLE Funcionarios
DROP COLUMN cargo,
DROP COLUMN nroa;

