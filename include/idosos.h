// Include idosos
// Armazenar dados, structs e constantes relacionados ao tipo idoso
// Funções devem conter apenas os headers

// Definição
#ifndef IDOSO_H
#define IDOSO_H

// Bibliotecas
#include "persistencia.h"
// #include "biblioteca" se necessário

int isIdoso(Ingresso *ing);
int salvarIdoso(Ingresso *ing, const char *diretorio);
int carregarIdosos(Ingresso *fila, const char* diretorio);

#endif