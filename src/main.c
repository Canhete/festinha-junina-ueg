// Módulo main:
// O módulo principal onde o programa é executado
// Chama os outros módulos

// Bibliotecas
#include <stdio.h>
#include "../include/ingresso.h"
#include "../include/persistencia.h"

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

    return 0;
}