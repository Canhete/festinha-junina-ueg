// Módulo persistência:
// Gerencia a leitura e escrita em arquivo csv
// Apenas lê e escreve em arquivo csv

// Bibliotecas
#include <stdio.h>
#include "include/persistencia.h"
#include "ingresso.h"

#define CABECALHO "Id;Nome;Idade\n"
#define BUFFER_LINHA 512

// Funções

// Validação se é idoso ou não, 60+
// Retorna 1 para verdadeiro, 0 para falso
int isIdoso(Ingresso ing) {
    return (ing.idade >= 60);
}

// Salva uma entrada de idoso no arquivo .csv
// Retorna 1 para sucesso, 0 para fracasso
int salvarIngresso(Ingresso *ing, const char *diretorio) {
    FILE *arq = fopen(diretorio, "a");
    if (arq == NULL) {
        return -1; // Erro ao abrir arquivo
    }

    if (isIdoso(*ing)) {
        fprintf(arq, "%d;%s;%d\n",
            ing->id,
            ing->nome,
            ing->idade
        );
    }

    fclose(arq);
    return 1; // Sucesso
}

// Carrega uma fila de ingressos de idosos a partir do arquivo
// Retorna a quantidade de dados lidos, -1 para fracasso
int carregarIdosos(Ingresso *fila, const char* diretorio) {
    FILE *arq = fopen(diretorio, "r");
    if (arq == NULL) {
        return -1; // Erro ao abrir arquivo 
    }

    char linha[BUFFER_LINHA];
    int qtd;

    // Ignora o cabeçalho
    fgets(linha, sizeof(linha), arq);

    while (fgets(linha, sizeof(linha), arq) != EOF) {
        Ingresso *ing = &fila[qtd];

        if (!isIdoso(*ing)) continue; // Ignora o que não é idoso

        int lidos = sscanf(linha, "%d;%63[^;];%d",
            ing->id,
            ing->nome,
            ing->idade
        );

        // Se leu todos os campos e é idoso, conta
        if (lidos == 3) qtd++;
    }

    fclose(arq);
    return qtd; // Sucesso
}