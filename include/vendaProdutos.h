#ifndef VENDAPRODUTO_H
#define VENDAPRODUTO_H

#include "pessoa.h"

// Preços dos produtos
#define PRECO_CERVEJA 8.00
#define PRECO_REFRIGERANTE 5.00
#define PRECO_SUCOS 6.00
#define PRECO_AGUA 2.50
#define PRECO_PAMONHA 10.00
#define PRECO_MILHO 5.00
#define PRECO_SALGADO 3.50
#define PRECO_PASTEL 7.00

// Funções
Pessoa* carregarParticipantes(const char* nomeArquivo);
void vendaProdutos(Pessoa* lista);
// void registrarLogConsumo(const char* nomeCliente, const char* nomeProduto, int quantidade, float preco);

#endif