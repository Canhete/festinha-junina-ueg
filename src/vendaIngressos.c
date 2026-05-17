// implementacao do vendaIngressos.h

// bibliotecas padrao
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bibliotecas proprias
#include "../include/vendaIngressos.h"
#include "../include/pessoa.h"

extern ControleEstoque estoque_festa;

int validarMatricula(int matricula_digitada) { // funcao para verificar se a matricula informada e valida
    FILE *file = fopen("./data/ingressos/alunosCadastrados.csv", "r");
    if (file == NULL){
	printf("Algo deu errado ao abrir o arquivo!");
	return 0;
    }

    int matricula_csv;
    char nome[50];
    int idade;

    // Pula o cabeçalho do CSV
    fscanf(file, "%*[^\n]\n"); 

    // Varre o arquivo procurando a matrícula
    while (fscanf(file, "%d,%[^,],%d\n", &matricula_csv, nome, &idade) != EOF) {
        if (matricula_csv == matricula_digitada) {
            fclose(file);
            return 1; // Matricula encontrada
        }
    }

    fclose(file);
    return 0; // Matricula não existe
}

Pessoa* carregar_vendas_antecipadas(char* nome_arquivo, Pessoa* lista, int* resBarrado, int* resSucesso) { // le todas as linhas do CSV, verifica se a matricula e valida e adiciona o aluno na lista se for valida
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return lista;
    }

    char linha[256];
    // Pula a primeira linha (cabeçalho: Matricula,Nome,Idade...)
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        fclose(arquivo);
        return lista;
    }

    int matricula, idade, extras;
    char nome[50];
    float saldo_inicial;
    int cont_sucesso = 0;
    int cont_barrado = 0;

    // Lendo linha por linha do arquivo
    while (fscanf(arquivo, "%d,%[^,],%d,%d,%f\n", &matricula, nome, &idade, &extras, &saldo_inicial) != EOF) {
        
        // verifica se a matricula e valida
        if (validarMatricula(matricula)) {
            
            // cria o novo no
            Pessoa* novo_aluno = criar_no(nome, idade, ALUNO, matricula, matricula, saldo_inicial);
            
            // insere no inicio da lista
            novo_aluno->proximo = lista;
            lista = novo_aluno;
            cont_sucesso++;

	    estoque_festa.ingressos--;

            for (int i = 0; i < extras; i++) {
                char nome_convidado[60];
		snprintf(nome_convidado, sizeof(nome_convidado), "Convidado %d de %s", i + 1, nome);

                Pessoa* novo_convidado = criar_no(nome_convidado, 18, RESTO, 0, 0, 0.0);
                
                // Insere o convidado na lista encadeada também
                novo_convidado->proximo = lista;
                lista = novo_convidado;
                cont_sucesso++;

		estoque_festa.ingressos--;

            }
        } else {
            cont_barrado++;
        }
    }

    fclose(arquivo);

    *resBarrado = cont_barrado;
    *resSucesso = cont_sucesso;

    return lista; // Retorna o novo ponteiro de início da lista
}

int salvarLista(char nomeArquivo[], Pessoa *lista){ // salva a lista encadeada em um arquivo CSV
	FILE *arquivo = fopen(nomeArquivo, "w");

	if (arquivo == NULL){
		printf("Algo deu errado!");
		return -1;
	}
	
	fprintf(arquivo, "Matricula_Dono,Nome_Dono,Tipo_Cliente,Matricula_Comprador,Saldo,Debito\n");
	
	Pessoa *atual = lista;

	while(atual != NULL){
		fprintf(arquivo, "%d,%s,%d,%d,%.2f,%.2f\n", atual->matricula_dono,atual->nome,atual->tipo,atual->matricula_comprador,atual->saldo,atual->debito);
		atual = atual->proximo;
	}
	fclose(arquivo);
	return 1;
}

void esperarEnter(){
	printf("Pressione Enter para continuar\n\n");
	system("stty -echo"); // desliga o eco
	
	int c;

	while (getc(stdin) == '\n'); 

	while ((c = getchar()) != '\n' && c != EOF) { // aguarda o enter
	} 

	system("stty echo"); // religa o eco
}

int vendaIngressos(){
	printf("\033[H\033[J"); // limpando o terminal

	printf("Sistema de venda de ingressos!");

	Pessoa *lista_festa = NULL;
	
	int barrados=0;
	int sucesso=0;
	lista_festa = carregar_vendas_antecipadas("./data/ingressos/listaAlunosAntes28.csv", lista_festa, &barrados, &sucesso);
	salvarLista("./data/ingressos/ingressosVendidos.csv", lista_festa);

	printf("Quantidade de convidados aceitos: %d\nQuantidade de alunos barrados: %d\n", sucesso, barrados);
	printf("Ingressos restantes: %d\nIngressos vendidos: %d\n\n", estoque_festa.ingressos, (MAX_INGRESSOS-estoque_festa.ingressos));

	esperarEnter();

	return 0;
}


