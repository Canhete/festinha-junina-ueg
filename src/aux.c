// implementacao aux.h
#include "../include/aux.h"


// bibliotecas padrao
#include <stdio.h>
#include <stdlib.h>



void esperarEnter(){
	printf("Pressione Enter para continuar\n\n");
	system("stty -echo"); // desliga o eco
	
	int c;

	while (getc(stdin) == '\n'); 

	while ((c = getchar()) != '\n' && c != EOF) { // aguarda o enter
	} 

	system("stty echo"); // religa o eco
}


