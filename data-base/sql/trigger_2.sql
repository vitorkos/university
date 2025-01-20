CREATE TABLE empregadoExemplo(
	id serial primary key, 
	nome varchar(40) NOT NULL, 
	salario numeric(10,2) NOT NULL
);
CREATE TABLE salarioMudanca (
	id serial primary key, 
	idEmpregado int4 NOT NULL, 
	salarioAntigo numeric(10,2)NOT NULL, 
	salarioNovo numeric(10,2) NOT NULL, 
	mudanca_em timestamp(6) NOT NULL,
	foreign key(idEmpregado) references empregadoExemplo(id)
);

insert into empregadoExemplo(id, nome, salario)values
(1 ,joao, 1000.00 ),
(2 ,jose, 2000.00 ),
(3 ,ana, 3500.00 );

create function log_mudanca_salario() returns trigger as $$
	begin
	if new.salario <> old.salario then
		insert into salarioMudanca ( idEmpregado, salarioAntigo, SalarioNovo, mudanca_em)
		values (old.id, old.salario, new.salario, now());
		end if return new;
	end;
$$ Language plsql;
		
