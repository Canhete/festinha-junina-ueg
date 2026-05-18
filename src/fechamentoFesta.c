#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bibliotecas próprias baseadas na árvore de arquivos
#include "../include/fechamentoFesta.h"
#include "../include/vendaIngressos.h"
#include "../include/vendaProdutos.h"
#include "../include/pessoa.h"

extern ControleEstoque estoque_festa;

// Protótipo local ou externo para garantir que o compilador conheça a função
void esperarEnter(void);

// Função auxiliar para carregar os participantes para o fechamento
Pessoa* carregarParticipantesFechamento(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return NULL;
    }

    char linha[256];

    // Pula o cabeçalho do CSV
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        fclose(arquivo);
        return NULL;
    }

    Pessoa* lista = NULL;

    int mat_dono, tipo_int, mat_comprador;
    char nome[50];
    float saldo, debito;

    // Lendo o formato salvo no arquivo de ingressos vendidos
    while (fscanf(arquivo, "%d,%[^,],%d,%d,%f,%f\n",
                  &mat_dono,
                  nome,
                  &tipo_int,
                  &mat_comprador,
                  &saldo,
                  &debito) != EOF) {

        // Criando o nó (usando 18 como idade padrão)
        Pessoa* novo = criar_no(
            nome,
            18,
            (TipoCliente)tipo_int,
            mat_dono,
            mat_comprador,
            saldo
        );

        if (novo != NULL) {
            novo->debito = debito;

            // Insere na lista encadeada local
            novo->proximo = lista;
            lista = novo;
        }
    }

    fclose(arquivo);
    return lista;
}

void emitirRelatorioFechamento(Pessoa* lista) {

    printf("\033[H\033[J"); // Limpa o terminal

    printf("==================================================\n");
    printf("         FECHAMENTO FINANCEIRO - FESTA JUNINA     \n");
    printf("==================================================\n\n");

    int total_pessoas = 0;
    int qtd_alunos = 0;
    int qtd_idosos = 0;
    int qtd_convidados = 0;

    float total_saldos_retidos = 0.0;
    float total_debitos_alunos = 0.0;

    Pessoa* atual = lista;

    // Contabiliza os dados dos clientes que consumiram
    while (atual != NULL) {

        total_pessoas++;

        if (atual->tipo == ALUNO) {

            qtd_alunos++;

            total_saldos_retidos += atual->saldo;
            total_debitos_alunos += atual->debito;

        } else if (atual->tipo == IDOSO) {

            qtd_idosos++;

        } else {

            qtd_convidados++;
        }

        atual = atual->proximo;
    }

    // Relatório de Público
    printf("--- ESTATISTICAS DE PUBLICO ---\n");

    printf("Total de participantes na festa: %d\n", total_pessoas);
    printf("  - Alunos cadastrados: %d\n", qtd_alunos);
    printf("  - Idosos (Prioritarios): %d\n", qtd_idosos);
    printf("  - Convidados / Outros: %d\n\n", qtd_convidados);

    // Relatório de Bilheteria
    int ingressos_vendidos = MAX_INGRESSOS - estoque_festa.ingressos;

    float preco_base_ingresso = 20.0;
    float receita_ingressos = ingressos_vendidos * preco_base_ingresso;

    printf("--- CAIXA E BILHETERIA ---\n");

    printf("Ingressos Vendidos: %d / %d\n",
           ingressos_vendidos,
           MAX_INGRESSOS);

    printf("Faturamento Estimado de Ingressos: R$ %.2f\n\n",
           receita_ingressos);

    // Relatório de Consumo Interno
    printf("--- SALDOS E DEBITOS PENDENTES (ALUNOS) ---\n");

    printf("Total de saldos nao utilizados: R$ %.2f\n",
           total_saldos_retidos);

    printf("Total de debitos a receber: R$ %.2f\n",
           total_debitos_alunos);

    printf("--------------------------------------------------\n");

    printf("Saldo Liquido de devedores: R$ %.2f\n\n",
           total_debitos_alunos);

    // Relatório de Sobras de Estoque
    printf("--- ESTOQUE RESIDUAL DE PRODUTOS ---\n");

    printf("Cervejas restantes: %d\n",
           estoque_festa.cervejas);

    printf("Refrigerantes restantes: %d\n",
           estoque_festa.refrigerantes);

    printf("Sucos restantes: %d\n",
           estoque_festa.sucos);

    printf("Aguas restantes: %d\n",
           estoque_festa.aguas);

    printf("==================================================\n\n");

    // Salva o estado final de volta no arquivo
    salvarLista("./data/ingressos/ingressosVendidos.csv", lista);

    printf("Relatorio gerado e 'ingressosVendidos.csv' atualizado com sucesso!\n");

    esperarEnter();
}

int fechamentoFesta() {

    // Carrega a lista final gerada no ingressosVendidos.csv
    Pessoa* lista_final =
        carregarParticipantesFechamento(
            "./data/ingressos/ingressosVendidos.csv"
        );

    if (lista_final == NULL) {

        printf("\033[H\033[J");

        printf("Erro: Nao foi possivel carregar os dados de vendas para o fechamento.\n");

        printf("Certifique-se de que a venda de ingressos ou produtos ja foi iniciada.\n\n");

        esperarEnter();

        return -1;
    }

    emitirRelatorioFechamento(lista_final);

    // Libera memória
    Pessoa* atual = lista_final;

    while (atual != NULL) {

        Pessoa* proximo = atual->proximo;

        free(atual);

        atual = proximo;
    }

    return 0;
}