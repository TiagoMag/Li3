#ifndef Queries_h
#define Queries_h

#include "CatProdutos.h"
#include "CatClientes.h"
#include "Files.h"
#include "Navegador.h"
#include "Faturacao.h"
#include "Venda.h"

typedef struct par *Par;
typedef struct tabela *Tabela;
typedef struct profit *Profit;
typedef struct lstbuyers *LstBuyers;


Lista produtosComecadoPelaLetra(Cat_Produtos cp,char letter);

Lista productSalesAndProfit(Faturacao f,char* productID,int month);

Lista productsNeverBought(Filial fil,Faturacao f,Cat_Produtos cp,int branchID);

Lista clientesOfAllBranches(Cat_Clientes cc,Filial fil[3]);

Par initPar();
int getClientsNeverBoughtCount(Par p);
int getProductsNeverBoughtCount(Par p);
Par clientsAndProductsNeverBoughtCount(Par p,Cat_Produtos cp,Cat_Clientes cc,Faturacao f,Filial fil[3]);

Tabela initTabela();
void removeTabela(Tabela tbl);
int getComprado(Tabela tbl,int linha,int coluna);
Tabela productBoughtByClient(Tabela tbl,Filial fil[3],char* clientID);

Profit initProfit();
float getFaturado(Profit p);
int getVendas(Profit p);
void removeProfit(Profit p);
Profit salesAndProfit(Faturacao f,Profit p,int minMonth,int maxMonth);


LstBuyers initLstBuyers();
Lista getListaN(LstBuyers l);
Lista getListaP(LstBuyers l);
void removeLstBuyers(LstBuyers l);
LstBuyers productBuyers(LstBuyers l,Filial f,char* productID);

Lista clientFavoriteProducts(Filial f[3],char* clientID,int month);

#endif