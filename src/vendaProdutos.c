#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vendaProdutos.h"
#include "../include/vendaIngressos.h"


extern ControleEstoque estoque_festa;

// Função para carregar as pessoas que compraram ingresso
Pessoa* carregarParticipantes(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return NULL; 
    }

    char linha[256];
    
    // Pula o cabeçalho do CSV
    fscanf(file, "%*[^\n]\n"); 

    Pessoa* lista = NULL;
    int mat_dono, tipo_int, mat_comprador;
    char nome[50];
    float saldo, debito;

    // Lendo o formato salvo,  tem que ser editado ainda os titulos (mat_dono ...)
    while (fscanf(arquivo, "%d,%[^,],%d,%d,%f,%f\n", &mat_dono, nome, &tipo_int, &mat_comprador, &saldo, &debito) != EOF) {
        Pessoa* novo = criar_no(nome, idade, (TipoCliente)tipo_int, mat_dono, mat_comprador, saldo);
        novo->debito = debito;
        
        // Insere na lista
        novo->proximo = lista;
        lista = novo;
    }

    fclose(arquivo);
    return lista;
}

// Função para registrar a venda física no CSV de histórico


// Módulo de Vendas Internas
void vendaProdutos(Pessoa* lista) { 

    if (lista == NULL) {
        printf("Nenhum participante na festa ainda. Processe a venda de ingressos primeiro!\n\n");
        return;
    }

    printf("\033[H\033[J"); // Limpa terminal

    printf(" VENDA DE PRODUTOS INTERNOS \n");
    
    char nomeBusca[50];
    printf("Digite o nome do comprador: ");
    scanf(" %[^\n]", nomeBusca);

    // Busca a pessoa na lista de presença e definindo o tipo 
    Pessoa* atual = lista;
    while (atual != NULL && strcmp(atual->nome, nomeBusca) != 0) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Participante não encontrado na lista de ingressos da festa\n\n");
        return;
    }

   const char* tipoTexto; //ajudar a observar o tipo

   //Usando o tipoTexto para 
switch (atual->tipo) {
    case ALUNO:
        tipoTexto = "Aluno";
        break;
    case IDOSO:
        tipoTexto = "Idoso";
        break;
    default:
        tipoTexto = "Convidado/Resto";
        break;
}

printf("\nCliente encontrado: %s (%s)\n", atual->nome, tipoTexto);

// Exibindo os produtos da festa 

    printf("1 - Cerveja (R$ %.2f)\n", PRECO_CERVEJA);
    printf("2 - Refrigerante (R$ %.2f)\n", PRECO_REFRIGERANTE);
    printf("3 - Sucos (R$ %.2f) \n", PRECO_SUCOS);
    printf("4 - Água (R$ %.2f) \n", PRECO_AGUA);
    printf("5 - Pamonha (R$ %.2f) \n", PRECO_PAMONHA);
    printf("6 - Milho (R$ %.2f) \n", PRECO_MILHO);
    printf("7 - Salgado (R$ %.2f) \n", PRECO_SALGADO);
    printf("8 - Pastel (R$ %.2f)\n", PRECO_PASTEL);
    printf("Sua escolha: ");
    int opcao;
    scanf("%d", &opcao);

    float precoItem = 0;
    char nomeProduto[30];

    switch(opcao) {
        case 1:
            // Bebida alcoólica apenas para maiores de 18 anos
            
            //Verifica o estoque 
            if (estoque_festa.cervejas <= 0) {
                printf("Estoque de Cerveja esgotado!\n\n");
                return;
            }
            precoItem = PRECO_CERVEJA;
            strcpy(nomeProduto, "Cerveja");
            estoque_festa.cervejas--;
            break;

        case 2:

            //Verifica o estoque 
            if (estoque_festa.refrigerantes <= 0) {
                printf("Estoque de Refrigerante esgotado!\n\n");
                return;
            }
            precoItem = PRECO_REFRIGERANTE;
            strcpy(nomeProduto, "Refrigerante");
            estoque_festa.refrigerantes--;
            break;

        case 3:
            //Verifica o estoque 
            if (estoque_festa.sucos <= 0) {
                printf("Estoque de sucos esgotado!\n\n");
                return;
            }
            precoItem = PRECO_SUCOS;
            strcpy(nomeProduto, "Sucos");
            estoque_festa.sucos--;
            break;


        case 4:
        //Verifica o estoque 
        if (estoque_festa.aguas <= 0) {
            printf("Estoque de água esgotado!\n\n");
            return;
        }

        precoItem = PRECO_AGUA;
        strcpy(nomeProduto, "Agua");
        estoque_festa.aguas--;
        break;

        //Casos para comidas:



        default:
            printf("Opção inválida!\n\n");
            return;
    }

    // Pagamento


    if (atual->tipo == ALUNO) {
        // Aluno usa sistema de créditos
        if (atual->saldo >= precoItem) {
            atual->saldo -= precoItem;
            printf("Pago com crédito com sucesso! Saldo restante: R$ %.2f\n", atual->saldo);
        } else {
            // Se o saldo não for suficiente, o restante vira débito
            float excedente = precoItem - atual->saldo;
            atual->saldo = 0.0;
            atual->debito += excedente;
            printf("Saldo insuficiente. R$ %.2f adicionados ao seu débito pendente!\n", excedente);
        }
    } else {
        // Idosos e Resto pagam em dinheiro/cartão na hora (não entram em débito)
        printf("Pagamento de R$ %.2f efetuado via Dinheiro/Cartão.\n", precoItem);
    }

    // Registrar no histórico de vendas global
    registrarLogConsumo(atual->nome, nomeProduto, 1, precoItem);
    printf("Venda realizada com sucesso!\n\n");
}

    

