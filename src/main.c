<<<<<<< HEAD
// Módulo main:
// O módulo principal onde o programa é executado
=======
>>>>>>> 266fd76 (Arquivos CSV de identificacao)
// Arquivo de incialização do projeto. Ese arquivo deve conter somente o menu inicial do projeto e a chamada dos demais módulos.
// Não insira métodos adicionais ou lógica complexa nesse arquivo.

// bibliotecas padrao
#include <stdio.h>
<<<<<<< HEAD
#include "../include/ingresso.h"
#include "../include/persistencia.h"
#include "../include/vendaIngressos.h"

// Programa principal
int main(){
	printf("Sistema Geral de Festa Junina");

	int escolha;

	do {
        printf("\n====================\n");
        printf("Digite um número para opção:\n");
        printf("[1] --> Venda de ingressos\n");
        printf("        automatizado por .csv\n");
        printf("[2] --> Venda de produtos internos\n");
        printf("[3] --> Gerar relatórios finais\n");
        printf("[0] --> Sair\n");
        printf("======================\n");
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

			case 0:
				printf("Encerrando programa...\n");
                break;

            default:
                printf("Opção inválida!");
                break;
		}
    } while (escolha != 0);

    printf("Programa encerrado.\n");
    return 0;
}
=======

// bibliotecas proprias
#include "../include/vendaIngressos.h"

int main(){
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
>>>>>>> 266fd76 (Arquivos CSV de identificacao)
