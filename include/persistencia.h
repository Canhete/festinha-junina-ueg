// Include persistência:
// Armazenar dados fixos da persistência (salvamento, exclusão e carregamento) de arquivo CSV
// Funções devem conter apenas os headers

#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

// Bibliotecas
#include "ingresso.h"

#define CAMINHO_INGRESSOS "data/ingressos/" // Onde será salvo o arquivo de ingressos
#define ALUNOS_ANTES_28_CSV "listaAlunosAntes28.csv" // Nome do arquivo de alunos antes do dia 28
#define ALUNOS_DEPOIS_28_CSV "listaAlunosDepois28.csv" // Nome do arquivo de alunos antes do dia 28

// Headers
int salvarIngresso(Ingresso *ing);
int carregarIngressos(Ingresso *fila, const char* diretorio, int max);

#endif