// definicoes de pessoa.
#ifndef PESSOA_H
#define PESSOA_H

typedef enum {
    ALUNO,
    IDOSO,
    RESTO
} TipoCliente;

// A Struct Genérica
typedef struct Pessoa {
    // Dados de Identificação (Comuns a todos)
    char nome[50];
    int idade;
    TipoCliente tipo; // ALUNO, IDOSO ou RESTO

    // Dados de Venda e Vínculo (Se adaptam conforme as regras)
    int matricula_dono;       // Guarda a matrícula se for ALUNO. Se for IDOSO/RESTO, fica 0.
    int matricula_comprador;  // Se for convidado, guarda a matrícula do Aluno que o comprou.

    // Dados Financeiros (Exclusivo para o sistema de créditos de ALUNOS)
    float saldo;              // Dinheiro disponível para gastar na festa
    float debito;             // Caso ele gaste mais do que tem e fique devendo na saída

    // Ponteiro para a estrutura dinâmica (Lista ou Fila)
    struct Pessoa* proximo;
} Pessoa;

Pessoa* criar_no(char* nome, int idade, TipoCliente tipo, int mat_dono, int mat_comprador, float saldo);

#endif 
