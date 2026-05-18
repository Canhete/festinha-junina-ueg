// bibliotecas padrao
#include <stdio.h>

// bibliotecas proprias
#include "../include/vendaIngressos.h"

// Declarando a variável global do estoque
// Ela fica visível para todas as funções do seu arquivo
ControleEstoque estoque_festa;

int main(){

	estoque_festa.ingressos = 1000;
    	estoque_festa.cervejas = 1000;
    	estoque_festa.refrigerantes = 500;
    	estoque_festa.pasteis = 300;

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
				break;
			case 3:
				// gerar relatórios finais
				break;
			case 4:
				printf("Encerrando programa!");
				return 0;
				break;
		}
	}
}
