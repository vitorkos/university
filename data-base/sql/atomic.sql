CREATE TABLE produtos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    descricao TEXT,
    preco NUMERIC(10, 2) NOT NULL,
    data_criacao TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE estoque (
    id SERIAL PRIMARY KEY,
    produto_id INT NOT NULL,
    quantidade INT NOT NULL DEFAULT 0,
    ultima_atualizacao TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (produto_id) REFERENCES produtos(id)
);

CREATE TABLE movimentacao_produtos (
    id SERIAL PRIMARY KEY,
    produto_id INT NOT NULL,
    tipo_movimentacao VARCHAR(50) NOT NULL CHECK (tipo_movimentacao IN ('entrada', 'saida')),
    quantidade INT NOT NULL,
    data_movimentacao TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (produto_id) REFERENCES produtos(id)
);

CREATE OR REPLACE FUNCTION atualizar_estoque()
RETURNS TRIGGER AS $$
BEGIN
    IF EXISTS (SELECT 1 FROM estoque WHERE produto_id = NEW.id) THEN
        UPDATE estoque
        SET quantidade = quantidade + NEW.quantidade, 
            ultima_atualizacao = CURRENT_TIMESTAMP
        WHERE produto_id = NEW.id;
    ELSE
        INSERT INTO estoque (produto_id, quantidade, ultima_atualizacao)
        VALUES (NEW.id, NEW.quantidade, CURRENT_TIMESTAMP);
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_atualizar_estoque
AFTER INSERT ON produtos
FOR EACH ROW
EXECUTE FUNCTION atualizar_estoque();


INSERT INTO produtos (nome, descricao, preco)
VALUES ('Produto A', 'Descrição do produto A', 100.00);

SELECT * FROM estoque WHERE produto_id = 1;



