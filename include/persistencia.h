// Include persistência:
// Armazenar dados fixos da persistência (salvamento, exclusão e carregamento) de arquivo CSV
// Funções devem conter apenas os headers

#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

// Bibliotecas
#include "ingresso.h"

#define CAMINHO_INGRESSOS_CSV "data/ingressos.csv" // Onde será salvo o arquivo de ingressos

// Headers
int salvarIngresso(Ingresso *ing);
int carregarIngressos(Ingresso *fila, int max);

#endif