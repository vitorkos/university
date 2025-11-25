# Conta Bancária (Projeto Maven)
Projeto simples em Java para praticar testes com JUnit 5 e cobertura com JaCoCo.

## Regras
- Depósito: valor > 0
- Saque: valor > 0 e saldo suficiente
- Transferência: saca da origem e deposita no destino
- Titular não pode ser vazio

## Estrutura
- `src/main/java/br/edu/exemplo/ContaBancaria.java` (código de produção)
- `src/test/java/br/edu/exemplo/ContaBancariaTest.java` (exemplos de testes)

## Como importar no Eclipse
1. **File > Import… > Existing Maven Projects**
2. Selecione a pasta deste projeto (onde está o `pom.xml`)
3. Finish

## Como rodar testes e cobertura
No terminal, dentro da pasta do projeto:
```bash
mvn clean verify
```
Abra o relatório de cobertura em:
`target/site/jacoco/index.html`

## Versões
- Java 17
- JUnit 5 (Jupiter)
- Maven Surefire 3.2.5
- JaCoCo 0.8.12
