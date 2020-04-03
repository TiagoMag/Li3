#ifndef SGV_H
#define SGV_H

#include <stdlib.h>
#include <glib.h>
#include "CatProdutos.h"
#include "CatClientes.h"
#include "Faturacao.h"
#include "Filial.h"
#include "Queries.h"
#include "Files.h"

#define CAMPOS 7

typedef struct sgv *SGV;

SGV initSGV();
void destroySGV(SGV sgv);
SGV loadFromFiles(char* filepath[3],SGV sgv);
Lista getProductsStartedByLetter(SGV sgv,char letter);
Lista getProductSalesAndProfit(SGV sgv,char* productID,int month);
Lista getProductsNeverBought(SGV,int branchID);
Lista getClientesOfAllBranches(SGV sgv);
Par getClientsAndProductsNeverBoughtCount(SGV sgv);
Tabela getProductBoughtByClient(SGV sgv,char* clientID);
Profit getSalesAndProfit(SGV sgv,int minMonth,int maxMonth);
LstBuyers getProductBuyers(SGV sgv,char* productID,int branchID);
Lista getClientFavoriteProducts(SGV sgv,char* clientID,int month);

#endif