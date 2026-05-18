#ifndef FECHAMENTO_FESTA_H
#define FECHAMENTO_FESTA_H

#include "pessoa.h"

// Protótipos das funções de fechamento
Pessoa* carregarParticipantesFechamento(const char* nomeArquivo);
void emitirRelatorioFechamento(Pessoa* lista);
int fechamentoFesta();

#endif // FECHAMENTO_FESTA_H