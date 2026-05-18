#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vendaProdutos.h"
#include "../include/vendaIngressos.h"
#include "../include/pessoa.h"


extern ControleEstoque estoque_festa;

// Função para carregar as pessoas que compraram ingresso
Pessoa* carregarParticipantes(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return NULL; 
    }

    char linha[256];
    
    // Pula o cabeçalho do CSV
    fscanf(arquivo, "%*[^\n]\n"); 

    Pessoa* lista = NULL;

    // Declaração das variáveis locais antes do while:
int mat_dono, tipo_int, mat_comprador, idade;
char nome[50];
float saldo, debito;

// Lendo o formato salvo
while (fscanf(arquivo, "%d,%[^,],%d,%d,%d,%f,%f\n", &mat_dono, nome, &idade, &tipo_int, &mat_comprador, &saldo, &debito) != EOF) {
    Pessoa* novo = criar_no(nome, idade, (TipoCliente)tipo_int, mat_dono, mat_comprador, saldo);
        novo->debito = debito;
        
        // Insere na lista
        novo->proximo = lista;
        lista = novo;
    }

    fclose(arquivo);
    return lista;
}

// Função para registrar a venda física no CSV de históricoll 

void registrarLogConsumo(const char* comprador, const char* produto, int qtd, float valorTotal) {
    FILE* arquivo = fopen("./data/vendas_produtos.csv", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir vendas de produtos!\n");
        return;
    }
    // Formato: Produto, Quantidade, Comprador, ValorTotal
    fprintf(arquivo, "%s,%d,%s,%.2f\n", produto, qtd, comprador, valorTotal);
    fclose(arquivo);
}

// Módulo de Vendas Internas
void vendaProdutos(Pessoa* lista) { 

    if (lista == NULL) {
        printf("Nenhum participante na festa ainda. Processe a venda de ingressos primeiro!\n\n");
        return;
    }

    printf("\033[H\033[J"); // Limpa terminalsas

     printf(" VENDA DE PRODUTOS INTERNOS \n");

    int c;
    while((c = getchar()) != '\n' && c != EOF); // Limpa o buffer de entrada
  
    
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

    printf("\033[H\033[J"); // Limpa terminal
      

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
        if (atual->idade < 18) {
            printf("Venda proibida, cliente menor de 18 anos.\n\n");
            return;
        } // <-- Chave de fechamento adicionada aqui

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

        case 5:

        precoItem = PRECO_PAMONHA;
        strcpy(nomeProduto, "Pamonha");
        break;

        case 6: 

        precoItem = PRECO_MILHO;
        strcpy(nomeProduto, "Milho");
        break;

        case 7:

        precoItem = PRECO_SALGADO;
        strcpy(nomeProduto, "Salgado");
        break;


        case 8: 

        precoItem = PRECO_PASTEL;
        strcpy(nomeProduto, "Pastel");
        break;

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
    // registrarLogConsumo(atual->nome, nomeProduto, 1, precoItem);
    printf("Venda realizada com sucesso!\n\n");    
}



    

