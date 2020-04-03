#ifndef Venda_H
#define Venda_H

#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "Produto.h"
#include "Cliente.h"
#include "CatProdutos.h"
#include "CatClientes.h"

typedef struct venda *Venda;

Venda inicializaV();
gboolean validaV(Venda venda,Cat_Produtos cp,Cat_Clientes cc);
Venda criaVendas(Venda v,char* p,char* c,float preco,int q,char tipoCompra ,int m,int f);
Produto getProdutoVenda(Venda v);
float getPrecoVenda(Venda v);
int getQntVenda(Venda v);
char getTipo(Venda v);
Cliente getClienteVenda(Venda v);
int getMes(Venda v);
int getFilial(Venda v);
void removeVenda(Venda v); 

#endif