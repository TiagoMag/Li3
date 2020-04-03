#ifndef CatProdutos_H
#define CatProdutos_H

#include <stdlib.h>
#include <glib.h>
#include "Produto.h"
#include "Navegador.h"

#define Produtos 26

typedef struct cat_produtos *Cat_Produtos;

Cat_Produtos inicializa_CatProds();
Cat_Produtos insereProd(Cat_Produtos cp,Produto p);
gboolean existeProd(Cat_Produtos cp,Produto p);
Lista produtosLetra(Cat_Produtos cp,Lista lst,char letter);
int totalProd(Cat_Produtos cp);
void removeCatProd(Cat_Produtos cp);
GTree* getTree(Cat_Produtos cp,int index);

#endif