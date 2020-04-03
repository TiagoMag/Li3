#ifndef Produto_H
#define Produto_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <glib.h>

typedef struct produto *Produto;

Produto inicializa_Prod();
Produto criaProduto(Produto p,char* codigo);
char* getProduto(Produto p);
int getIndexP(Produto p);
gboolean validaProd(Produto p);
void removeProduto(Produto p);

#endif