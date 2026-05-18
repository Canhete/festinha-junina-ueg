// bibliotecas padrao
#include <stdio.h>

// bibliotecas proprias
#include "../include/vendaIngressos.h" 
#include "../include/pessoa.h"
// Declarando a variável global do estoque
// Ela fica visível para todas as funções do seu arquivo

ControleEstoque estoque_festa;

int main(){

	estoque_festa.ingressos = 1000;
    	estoque_festa.cervejas = 1000;
    	estoque_festa.refrigerantes = 500;
		estoque_festa.sucos = 500;
		estoque_festa.aguas = 500;
    	
	Pessoa* lista_participantes = carregarParticipantes("./data/ingressos/ingressosVendidos.csv");

		//Comida possui estoque indefinido, pois ao decorrer das vendas mais comida é preparada

	printf("Sistema Geral de Festa Junina\n");

	int escolha;

	while (1){
		printf("1 - Venda de ingressos(automatizado por CSV)\n2 - Venda de produtos internos(Interativo)\n3 - Gerar relatórios finais\n4 - Encerrar programa\n");
		printf("Sua escolha: ");
		scanf("%d", &escolha);
		
		printf("\n");

		switch(escolha){
			case 1:
				// chamar módulo venda de ingressos
				vendaIngressos();
				break;
			case 2:
				// chamar módulo venda de produtos
				vendaProdutos(lista_participantes);
				break;
			case 3:
				// gerar relatórios finais
				fechamentoFesta(lista_participantes);
                break;
				break;
			case 4:
				printf("Encerrando programa!");
				return 0;
				break;
		}
	}
}
