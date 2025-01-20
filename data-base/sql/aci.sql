###acid

begin
update bloqueio set nome = 'joao' where id = 1
update bloqueio set nome = 'kaua' where id = 2
commit;


###rollback

begin
update bloqueio set nome = 'joao' where id = 1
update bloqueio set nome = 'kaua' where id = 2
rollback;


### concorrencia e granularidade

SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
begin TRANSACTION;
update bloqueio set nome = 'kaua' where id = 2
commit;

### bloqueio

BEGIN TRANSACTION;
LOCK TABLE bloqueio IN EXCLUSIVE MODE;
    UPDATE bloqueio SET nome = 'joao' WHERE id = 1;
commit;








