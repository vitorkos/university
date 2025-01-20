CREATE TABLE Ambulatorios (
    nroa INTEGER,
    andar NUMERIC(3) NOT NULL,
    capacidade SMALLINT,
    PRIMARY KEY(nroa)
);

CREATE TABLE Pacientes (
    codp INTEGER,
    nome VARCHAR(40) NOT NULL,
    CPF CHAR(11) UNIQUE,
    idade SMALLINT,
    doenca VARCHAR(50),
    cidade VARCHAR(30),
    PRIMARY KEY(codp)
);

CREATE TABLE Funcionarios (
    codf INTEGER,
    nome VARCHAR(40) NOT NULL,
    nroa INTEGER,
    PRIMARY KEY(codf)
);



CREATE TABLE Medicos (
    codm INTEGER,
    nome VARCHAR(40) NOT NULL,
    idade SMALLINT NOT NULL,
    especialidade VARCHAR(20),
    CPF CHAR(11) UNIQUE,
    cidade VARCHAR(30),
    nroa INTEGER,
    PRIMARY KEY(codm),
    FOREIGN KEY (nroa) REFERENCES Ambulatorios(nroa) ON DELETE SET NULL ON UPDATE CASCADE
);

ALTER TABLE Ambulatorios
ADD COLUMN nome VARCHAR(30);

ALTER TABLE Medicos
DROP CONSTRAINT medicos_pkey;

ALTER TABLE Pacientes
DROP COLUMN doenca,
DROP COLUMN cidade;

ALTER TABLE Funcionarios
ADD CONSTRAINT fk_nroa
FOREIGN KEY(nroa) REFERENCES Ambulatorios(nroa);

CREATE UNIQUE INDEX indPac_CPF ON Pacientes (CPF);

DROP INDEX indPac_CPF;

