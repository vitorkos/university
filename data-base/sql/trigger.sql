create table empregrado(
nome varchar(50),
salario numeric(9,2)
);

insert into empregado values ('teste');
insert into empregado values (129.00);

create table empregadoexemplo(
id serial primary key,
primeiroNome varchar(50) not null,
sobrenome varchar(50) not null);

create table empregadoauditoria(
id serial primary key,
idempregado integer not null,3
sobrenomeartigo varchar(50) not null,
sobrenomenovo varchar(50) not null,
mudanca_em timestamp not null
);

insert into empregadoexemplo(primeironome, sobrenome)
values('ana','souza');

insert into empregadoexemplo(primeironome,sobrenome)
values('maria','silva');

create function log_ultimo_nome() returns trigger as $$
begin 
if new, sobrenome <> old, sobrenome then
insert into empregadoauditoria(idempregado, sobrenomeantigo, sobrenomenovo, mudanca_em)
values(old.id, old.sobrenome, new.sobrenome, now());
end if
return new;
end;
$$ Language plgsql;

create treigger log_ultimo_nome
before update
on empregadoexemplo
for each row
execute procedure log_ultimo_nome()

create table venda(
id serial not null primary key,
idvendedor int not null,
total int not null
);

create table vendedorcomissão(
id serial not null primary key,
id vendedor int not null,
valor numeric(7,2) not null,
);

create or replace function atualizacomissao() return trigger as $$
begin 
update vendedorcomissao set valor = valor + (new.total*5/100)
where
new.idvendedor = vendedorcomissao.idvendedor;
return new;
end;
$$ Language plpgsql;

create trigger atualizacomissao
after insert on venda
for each row
execute procedure atualizacomissao();

create table funcionario(
id serial not null rimary key,
nome varchar(30) not null
);

create table dependence(
id serial not null primary key,
nome varchar(30) not null,
idfuncionario int not null,
foreign key(idfuncionario) references funcionario(id)
);

create or replace function removedependente() returns trigger as $$
begin
delete from dependente where old.id = dependente.idfuncionario;
return new;
end;
$$ Language plpgsql;

create trigger removedependente
before delete on function
for each row
execute procedure removedependete();
























































































