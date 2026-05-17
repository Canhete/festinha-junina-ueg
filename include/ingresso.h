// Include ingresso:
// Armazenar dados, structs e constantes relacionadas ao ingresso aqui
// Funções devem conter apenas os headers

// Definição
#ifndef INGRESSO_H
#define INGRESSO_H

// Bibliotecas
// #include "biblioteca" se necessário

// Constantes
#define TAMANHO_MAX_NOME 128 // Tamanho máximo do nome de uma pessoa
#define TAMANHO_MAX_MATRICULA 16 // Tamanho máximo do código de matrícula

// Struct do ingresso
typedef struct {
    int id;
    char nome[TAMANHO_MAX_NOME];

    // Implementar a diferenciação entre ingresso de idoso, estudante e resto
    int idade; // Usada para saber se é idoso ou não
    char matricula[TAMANHO_MAX_MATRICULA]; // Usada para saber se é estudante ou não

    double saldo; // Guarda quanto a pessoa depositou de saldo antes de entrar na festa
} Ingresso;

#endif