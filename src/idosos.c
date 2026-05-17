// Módulo idosos
// Informações a cerca do tipo Idoso

#include <stdio.h>
#include "include/persistencia.h"
#include "ingresso.h"

#define CABECALHO "Id;Nome;Idade\n"
#define BUFFER_LINHA 512

// Funções

// Validação, se é idoso ou não, 60+
// Retorna 1 para verdadeiro, 0 para falsto
int isIdoso(Ingresso *ing) {
    return (ing->idade >= 60);
}

// Salva uma entrada de ingresso para arquivo idoso.csv
// Retorna 1 para sucesso, 0 para fracasso
int salvarIdoso(Ingresso *ing, const char *diretorio) {
    FILE *arq = fopen(diretorio, "a");
    if (arq == NULL) {
        return -1; // Erro ao abrir arquivo
    }

    if (isIdoso(ing)) {
        fprintf(arq, "%d;%s;%d\n",
            ing->id,
            ing->nome,
            ing->idade
        );
    }

    fclose(arq);
    return 1; // Sucesso
}

// Carrega o idosos na fila apartir do arquivo
// Retorna a quantidade de dados lidos, -1 para fracasso
int carregarIdosos(Ingresso *fila, const char* diretorio) {
    FILE *arq = fopen(diretorio, "r");
    if (arq == NULL) {
        return -1; // Erro ao abrir arquivo 
    }

    char linha[BUFFER_LINHA];
    int qtd;

    fgets(linha, sizeof(linha), arq);

    while (fgets(linha, sizeof(linha), arq) != EOF) {
        Ingresso *ing = &fila[qtd];

        if (!isIdoso(ing)) continue; // Ignora quem não é idoso

        int lidos = sscanf(linha, "%d;%63[^;];%d",
            ing->id,
            ing->nome,
            ing->idade
        );

        if (lidos == 3) qtd++; // Conta cada idoso
    }

    fclose(arq);
    return qtd; // Sucesso
}