// Módulo idosos
// Informações a cerca do tipo Idoso

#include <stdio.h>
#include "include/persistencia.h"
#include "ingresso.h"

#define CABECALHO "Prioridade,"

// Funções
// Salva uma entrada de ingresso para arquivo idoso.csv
// Retorna 1 para sucesso, 0 para fracasso
int salvarIdoso(Ingresso *i, const char *diretorio) {
    FILE *arq = fopen(diretorio, "a");
    if (arq == NULL) {
        return -1; // Erro ao abrir arquivo
    }

    fprintf(arq, "%s,%s,%d,%d,%.2f\n",
        i->matricula,
        i->nome,
        i->idade,
        i->ingressosExtras,
        i->saldoInicial
    );

    fclose(arq);
    return 1; // Sucesso
}

// Carrega o ingresso na fila apartir do arquivo
// Retorna a quantidade de dados lidos, -1 para fracasso
int carregarIngressos(Ingresso *fila, const char* diretorio, int max) {
    FILE *arq = fopen(diretorio, "r");
    if (arq == NULL) {
        return -1; // Erro ao abrir arquivo 
    }

    char linha[BUFFER_LINHA];
    int qtd;

    fgets(linha, sizeof(linha), arq);

    while (fgets(linha, sizeof(linha, arq)) != EOF && qtd < max) {
        Ingresso *i = &fila[qtd];

        int lidos = sscanf(linha, "%15[^,],%63[^,],%d,%d,%f",
            i->matricula,
            i->nome,
            &i->idade,
            &i->ingressosExtras,
            &i->saldoInicial
        );

        if (lidos == 5) qtd++;
    }

    fclose(arq);
    return qtd; // Sucesso
}

int ehIdoso