// vendaIngressos.h

#ifndef VENDAINGRESSOS_H
#define VENDAINGRESSOS_H

#define MAX_INGRESSOS 1000

typedef struct {
    int ingressos;
    int cervejas;
    int refrigerantes;
    int pasteis;
} ControleEstoque;

int vendaIngressos();

#endif


