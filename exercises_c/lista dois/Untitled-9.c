As estruturas a seguir representam os dados de uma loja de produtos eletrˆonicos. Crie um
programa para cadastrar lojas usando a estrutura definida. O programa deve ler um vetor
de struct lojas com N registros alocados dinamicamente, sendo N informado pelo usu ́ario.
Al ́em disso, o programa deve mostrar a m ́edia dos pre ̧cos dos produtos cadastrados e uma
rela ̧c ̃ao contendo o nome, endere ̧co e telefone das lojas cujo pre ̧co est ̃ao abaixo da m ́edia
calculada.
1 struct e n d e r e c o {
2 char rua [ 5 0 ] ;
3 char b a i r r o [ 5 0 ] ;
4 } ;
1 struct l o j a {
2 char nome [ 5 0 ] ;
3 struct e n d e r e c o ende r ;
4 char t e l e f o n e [ 2 0 ] ;
5 f l o a t p re c o ;
6 } ;