// Módulo main:
// O módulo principal onde o programa é executado
<<<<<<< HEAD
// Arquivo de incialização do projeto. Ese arquivo deve conter somente o menu inicial do projeto e a chamada dos demais módulos.
// Não insira métodos adicionais ou lógica complexa nesse arquivo.
=======
// Chama os outros módulos
>>>>>>> 334cf40b6414fdd4635be9e94d18459dd282e394

// Bibliotecas
#include <stdio.h>
#include "../include/ingresso.h"
#include "../include/persistencia.h"
<<<<<<< HEAD
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
=======

// Programa principal
int main() {
    int opcao;

    do {
        printf("\n=== Festa Junina ===\n");
        printf("Digite um número para opção:\n");
        printf("[1] --> Comprar ingresso\n");
        printf("[2] --> Listar ingressos\n");
        printf("[0] --> Sair\n");
        printf("======================\n");
        printf("Opcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Comprar ingresso\n");

                // Lógica de inserção de novo ingresso

                break;

            case 2:
                printf("Listar ingressos\n");    

                // Lógica de listagem dos ingressos
                
                break;

            case 0:
                break;;

            default:
                printf("Opção inválida!");
                break;
        }
    } while (opcao != 0);

>>>>>>> 334cf40b6414fdd4635be9e94d18459dd282e394
    return 0;
}