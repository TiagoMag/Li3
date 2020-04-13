#ifndef Queries_h
#define Queries_h

#include <stdio.h>
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
typedef struct selledprod *SelledProd;
typedef struct fileinfo *FileInfo;


Lista produtosComecadoPelaLetra(Cat_Produtos cp,Lista lst,char letter);

Lista productSalesAndProfit(Faturacao f,Lista lst,char* productID,int month);

Lista productsNeverBought(Filial fil,Lista lst,Faturacao f,Cat_Produtos cp,int branchID);

Lista clientesOfAllBranches(Cat_Clientes cc,Lista lst,Filial fil[3]);

Par initPar();
void removePar(Par p);
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

Lista clientFavoriteProducts(Filial f[3],Lista lst,char* clientID,int month);

SelledProd initSelledProd();
int getUnidadesVendidasProd(SelledProd s);
int* getNumClientes(SelledProd s);
char* getProdCode(SelledProd s);
int* getUnidadesVendidasFilial(SelledProd s);
void removeSelledProds(SelledProd s);
SelledProd* topSelledProducts(SelledProd* top,Faturacao fat,Filial f[3],int limit);

GList* topProducts(Filial f[3],char* clientID,int limit);

FileInfo initFileInfo();
int getNumLinhasLidasFI(FileInfo fi,int index);
int getNumLinhasValidadasFI(FileInfo fi,int index);
float getTempoLeituraFI(FileInfo fi,int index);
char* getFileNameFI(FileInfo fi,int index);
void removeFileInfo(FileInfo fi);
FileInfo currentFilesInfo(FileInfo fi,Cat_Produtos cp,Cat_Clientes cc,Faturacao f);

#endif