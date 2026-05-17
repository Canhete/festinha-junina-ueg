// bibliotecas padrao
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// bibliotecas proprias
#include "../include/pessoa.h"

Pessoa* criar_no(char* nome, int idade, TipoCliente tipo, int mat_dono, int mat_comprador, float saldo) {
    Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));
    if (novo == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->tipo = tipo;
    novo->matricula_dono = mat_dono;
    novo->matricula_comprador = mat_comprador;
    novo->saldo = saldo;
    novo->debito = 0.0;
    novo->proximo = NULL;
    return novo;
}
