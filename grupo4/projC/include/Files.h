#ifndef Files_H
#define Files_H

#include <stdlib.h>
#include <glib.h>
#include <stdio.h>
#include "CatProdutos.h"
#include "CatClientes.h"
#include "Produto.h"
#include "Cliente.h"
#include "Venda.h"
#include "Faturacao.h"
#include "Filial.h"

#define CAMPOS 7
#define BUFFER 64

void loadFilesProduto(char* file,Cat_Produtos cp);
void loadFilesCliente(char* file,Cat_Clientes cc);
void leVendas(Filial fil[3],Faturacao f,char* file,Cat_Produtos cp,Cat_Clientes cc);

#endif