package br.edu.exemplo;

import static org.junit.jupiter.api.Assertions.*;

import java.math.BigDecimal;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Nested;

class ContaBancariaTest {

    private ContaBancaria conta;

    @BeforeEach
    void setup() {
        conta = new ContaBancaria("João");
    }

    @Nested
    @DisplayName("Testes do Construtor")
    class TestesConstitutor {
        
        @Test
        @DisplayName("Deve criar conta com titular válido")
        void devecriarContaComTitularValido() {
            ContaBancaria novaConta = new ContaBancaria("Pedro");
            assertEquals("Pedro", novaConta.getTitular());
            assertEquals(BigDecimal.ZERO, novaConta.getSaldo());
        }

        @Test
        @DisplayName("Não deve permitir titular nulo")
        void naoDevePermitirTitularNulo() {
            assertThrows(IllegalArgumentException.class,
                () -> new ContaBancaria(null));
        }

        @Test
        @DisplayName("Não deve permitir titular vazio")
        void naoDevePermitirTitularVazio() {
            assertThrows(IllegalArgumentException.class,
                () -> new ContaBancaria(""));
        }

        @Test
        @DisplayName("Não deve permitir titular com apenas espaços")
        void naoDevePermitirTitularComApenasEspacos() {
            assertThrows(IllegalArgumentException.class,
                () -> new ContaBancaria("   "));
        }
    }

    @Nested
    @DisplayName("Testes de Depósito")
    class TestesDeposito {
        
        @Test
        @DisplayName("Depósito válido deve aumentar o saldo")
        void depositoValidoDeveAumentarSaldo() {
            conta.depositar(BigDecimal.valueOf(100));
            assertEquals(BigDecimal.valueOf(100), conta.getSaldo());
        }

        @Test
        @DisplayName("Múltiplos depósitos devem somar ao saldo")
        void multiplosDepositosDevemSomarAoSaldo() {
            conta.depositar(BigDecimal.valueOf(50));
            conta.depositar(BigDecimal.valueOf(30));
            conta.depositar(BigDecimal.valueOf(20));
            assertEquals(BigDecimal.valueOf(100), conta.getSaldo());
        }

        @Test
        @DisplayName("Não deve permitir depósito com valor zero")
        void naoDevePermitirDepositoComValorZero() {
            assertThrows(IllegalArgumentException.class,
                () -> conta.depositar(BigDecimal.ZERO));
        }

        @Test
        @DisplayName("Não deve permitir depósito com valor negativo")
        void naoDevePermitirDepositoComValorNegativo() {
            assertThrows(IllegalArgumentException.class,
                () -> conta.depositar(BigDecimal.valueOf(-10)));
        }

        @Test
        @DisplayName("Não deve permitir depósito com valor nulo")
        void naoDevePermitirDepositoComValorNulo() {
            assertThrows(IllegalArgumentException.class,
                () -> conta.depositar(null));
        }
    }

    @Nested
    @DisplayName("Testes de Saque")
    class TestesSaque {
        
        @Test
        @DisplayName("Saque válido deve diminuir o saldo")
        void saqueValidoDeveDiminuirSaldo() {
            conta.depositar(BigDecimal.valueOf(200));
            conta.sacar(BigDecimal.valueOf(50));
            assertEquals(BigDecimal.valueOf(150), conta.getSaldo());
        }

        @Test
        @DisplayName("Saque do valor total deve zerar o saldo")
        void saqueDoValorTotalDeveZerarSaldo() {
            conta.depositar(BigDecimal.valueOf(100));
            conta.sacar(BigDecimal.valueOf(100));
            assertEquals(BigDecimal.ZERO, conta.getSaldo());
        }

        @Test
        @DisplayName("Não deve permitir saque maior que o saldo")
        void naoDevePermitirSaqueMaiorQueSaldo() {
            conta.depositar(BigDecimal.valueOf(50));
            assertThrows(IllegalStateException.class,
                () -> conta.sacar(BigDecimal.valueOf(100)));
        }

        @Test
        @DisplayName("Não deve permitir saque com saldo zerado")
        void naoDevePermitirSaqueComSaldoZerado() {
            assertThrows(IllegalStateException.class,
                () -> conta.sacar(BigDecimal.valueOf(10)));
        }

        @Test
        @DisplayName("Não deve permitir saque com valor zero")
        void naoDevePermitirSaqueComValorZero() {
            conta.depositar(BigDecimal.valueOf(100));
            assertThrows(IllegalArgumentException.class,
                () -> conta.sacar(BigDecimal.ZERO));
        }

        @Test
        @DisplayName("Não deve permitir saque com valor negativo")
        void naoDevePermitirSaqueComValorNegativo() {
            conta.depositar(BigDecimal.valueOf(100));
            assertThrows(IllegalArgumentException.class,
                () -> conta.sacar(BigDecimal.valueOf(-10)));
        }

        @Test
        @DisplayName("Não deve permitir saque com valor nulo")
        void naoDevePermitirSaqueComValorNulo() {
            conta.depositar(BigDecimal.valueOf(100));
            assertThrows(IllegalArgumentException.class,
                () -> conta.sacar(null));
        }
    }

    @Nested
    @DisplayName("Testes de Transferência")
    class TestesTransferencia {
        
        private ContaBancaria contaDestino;

        @BeforeEach
        void setupTransferencia() {
            contaDestino = new ContaBancaria("Maria");
        }

        @Test
        @DisplayName("Transferência válida deve alterar saldos corretamente")
        void transferenciaValidaDeveAlterarSaldosCorretamente() {
            conta.depositar(BigDecimal.valueOf(300));
            conta.transferir(contaDestino, BigDecimal.valueOf(100));
            
            assertEquals(BigDecimal.valueOf(200), conta.getSaldo());
            assertEquals(BigDecimal.valueOf(100), contaDestino.getSaldo());
        }

        @Test
        @DisplayName("Transferência do valor total deve zerar conta origem")
        void transferenciaDoValorTotalDeveZerarContaOrigem() {
            conta.depositar(BigDecimal.valueOf(150));
            conta.transferir(contaDestino, BigDecimal.valueOf(150));
            
            assertEquals(BigDecimal.ZERO, conta.getSaldo());
            assertEquals(BigDecimal.valueOf(150), contaDestino.getSaldo());
        }

        @Test
        @DisplayName("Não deve permitir transferência maior que o saldo")
        void naoDevePermitirTransferenciaMaiorQueSaldo() {
            conta.depositar(BigDecimal.valueOf(50));
            assertThrows(IllegalStateException.class,
                () -> conta.transferir(contaDestino, BigDecimal.valueOf(100)));
        }

        @Test
        @DisplayName("Não deve permitir transferência com saldo zerado")
        void naoDevePermitirTransferenciaComSaldoZerado() {
            assertThrows(IllegalStateException.class,
                () -> conta.transferir(contaDestino, BigDecimal.valueOf(10)));
        }

        @Test
        @DisplayName("Não deve permitir transferência com valor zero")
        void naoDevePermitirTransferenciaComValorZero() {
            conta.depositar(BigDecimal.valueOf(100));
            assertThrows(IllegalArgumentException.class,
                () -> conta.transferir(contaDestino, BigDecimal.ZERO));
        }

        @Test
        @DisplayName("Não deve permitir transferência com valor negativo")
        void naoDevePermitirTransferenciaComValorNegativo() {
            conta.depositar(BigDecimal.valueOf(100));
            assertThrows(IllegalArgumentException.class,
                () -> conta.transferir(contaDestino, BigDecimal.valueOf(-10)));
        }

        @Test
        @DisplayName("Não deve permitir transferência com valor nulo")
        void naoDevePermitirTransferenciaComValorNulo() {
            conta.depositar(BigDecimal.valueOf(100));
            assertThrows(IllegalArgumentException.class,
                () -> conta.transferir(contaDestino, null));
        }

        @Test
        @DisplayName("Não deve permitir transferência para conta nula")
        void naoDevePermitirTransferenciaParaContaNula() {
            conta.depositar(BigDecimal.valueOf(100));
            assertThrows(IllegalArgumentException.class,
                () -> conta.transferir(null, BigDecimal.valueOf(50)));
        }

        @Test
        @DisplayName("Transferência falha não deve alterar saldos se não há saldo suficiente")
        void transferenciaFalhaNaoDeveAlterarSaldos() {
            BigDecimal saldoOriginalOrigem = conta.getSaldo();
            BigDecimal saldoOriginalDestino = contaDestino.getSaldo();
            
            assertThrows(IllegalStateException.class,
                () -> conta.transferir(contaDestino, BigDecimal.valueOf(100)));
            
            assertEquals(saldoOriginalOrigem, conta.getSaldo());
            assertEquals(saldoOriginalDestino, contaDestino.getSaldo());
        }
    }

    @Nested
    @DisplayName("Testes dos Getters")
    class TestesGetters {
        
        @Test
        @DisplayName("Deve retornar o titular correto")
        void deveRetornarTitularCorreto() {
            assertEquals("João", conta.getTitular());
        }

        @Test
        @DisplayName("Deve retornar saldo inicial zero")
        void deveRetornarSaldoInicialZero() {
            assertEquals(BigDecimal.ZERO, conta.getSaldo());
        }
    }
}
