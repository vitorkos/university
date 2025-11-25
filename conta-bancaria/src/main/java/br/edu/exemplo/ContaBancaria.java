package br.edu.exemplo;

import java.math.BigDecimal;

public class ContaBancaria {
    private final String titular;
    private BigDecimal saldo;

    public ContaBancaria(String titular) {
        if (titular == null || titular.isBlank()) {
            throw new IllegalArgumentException("Titular inválido");
        }
        this.titular = titular;
        this.saldo = BigDecimal.ZERO;
    }

    public String getTitular() {
        return titular;
    }

    public BigDecimal getSaldo() {
        return saldo;
    }

    public void depositar(BigDecimal valor) {
        validarValor(valor);
        saldo = saldo.add(valor);
    }

    public void sacar(BigDecimal valor) {
        validarValor(valor);
        if (saldo.compareTo(valor) < 0) {
            throw new IllegalStateException("Saldo insuficiente");
        }
        saldo = saldo.subtract(valor);
    }

    public void transferir(ContaBancaria destino, BigDecimal valor) {
        if (destino == null) {
            throw new IllegalArgumentException("Conta de destino inválida");
        }
        this.sacar(valor);
        destino.depositar(valor);
    }

    private void validarValor(BigDecimal valor) {
        if (valor == null || valor.signum() <= 0) {
            throw new IllegalArgumentException("Valor deve ser positivo");
        }
    }
}
