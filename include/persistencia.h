// Include persistência:
// Armazenar dados fixos da persistência (salvamento, exclusão e carregamento) de arquivo CSV
// Funções devem conter apenas os headers

#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

// Bibliotecas
#include "ingresso.h"

<<<<<<< HEAD
#define CAMINHO_INGRESSOS "data/ingressos/" // Onde será salvo o arquivo de ingressos
#define ALUNOS_ANTES_28_CSV "listaAlunosAntes28.csv" // Nome do arquivo de alunos antes do dia 28
#define ALUNOS_DEPOIS_28_CSV "listaAlunosDepois28.csv" // Nome do arquivo de alunos antes do dia 28

// Headers
int salvarIngresso(Ingresso *ing);
int carregarIngressos(Ingresso *fila, const char* diretorio, int max);
=======
#define CAMINHO_INGRESSOS_CSV "data/ingressos.csv" // Onde será salvo o arquivo de ingressos

// Headers
int salvarIngresso(Ingresso *ing);
int carregarIngressos(Ingresso *fila, int max);
>>>>>>> 334cf40b6414fdd4635be9e94d18459dd282e394

#endif