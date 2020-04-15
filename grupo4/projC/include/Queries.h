/**
 * @file Queries.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que permitem reponder às queries.
 *  Funções e estruturas que permitem guardar as informações das queries.
 */

#ifndef Queries_h
#define Queries_h

#include <stdio.h>
#include "CatProdutos.h"
#include "CatClientes.h"
#include "Files.h"
#include "Navegador.h"
#include "Faturacao.h"
#include "Venda.h"

/**
 * @brief Declaração do tipo opaco Par. 
 */
typedef struct par *Par;
/**
 * @brief Declaração do tipo opaco Tabela. 
 */
typedef struct tabela *Tabela;
/**
 * @brief Declaração do tipo opaco Profit. 
 */
typedef struct profit *Profit;
/**
 * @brief Declaração do tipo opaco LstBuyers. 
 */
typedef struct lstbuyers *LstBuyers;
/**
 * @brief Declaração do tipo opaco SelledProd. 
 */
typedef struct selledprod *SelledProd;
/**
 * @brief Declaração do tipo opaco FileInfo. 
 */
typedef struct fileinfo *FileInfo;


/*  @brief Retorna a lista de produtos começados por uma determinada letra.
 *
 *  @param cp Estrutura Catalogo de Produtos 
 *  @param lst Lista onde se insere o resultado da função 
 *  @param letra pretendida.
 *
 *  @return Lista.
 */
Lista produtosComecadoPelaLetra(Cat_Produtos cp,Lista lst,char letter);


/*  @brief Retorna a lista do valor e numero de vendas de um produtopor uma determinada letra.
 *
 *  @param f Estrutura Faturacao 
 *  @param lst Lista onde se insere o resultado da função
 *  @param productID Código de produto
 *  @param month Identifica o mês.
 *
 *  @return Lista.
 */
Lista productSalesAndProfit(Faturacao f,Lista lst,char* productID,int month);


/*  @brief Retorna a lista de produtos começados por uma determinada letra.
 *
 *  @param fil Estrutura Filial 
 *  @param lst Lista onde se insere o resultado da função 
 *  @param f Estrutura Faturação
 *  @param cp Estrutura Catalogo produtos 
 *  @param branchID Identifica a filial.
 *
 *  @return Lista.
 */
Lista productsNeverBought(Filial fil,Lista lst,Faturacao f,Cat_Produtos cp,int branchID);


/* @brief Retorna a lista de clientes de todas as filiais.
 *
 *  @param cc Estrutura Catalogo de clientes 
 *  @param lst Lista onde se insere o resultado da função 
 *  @param fil[3] Informação contida nas 3 filiais
 *
 *  @return Lista.
 */
Lista clientesOfAllBranches(Cat_Clientes cc,Lista lst,Filial fil[3]);


/* @brief Aloca memória para a criação de uma estrutura par.
 *
 *  @return Par.
 */
Par initPar();


/* @brief Remove a estrutura par, libertando a memória.
 *
 *  @param p Estrutura Par a ser removida.
 *
 *  @return void.
 */
void removePar(Par p);


/* @brief Retorna o número de clientes que não realizaram quaisquer compras.
 *
 *  @param p Estrutura Par.
 *
 *  @return int.
 */
int getClientsNeverBoughtCount(Par p);


/* @brief Retorna o número de produtos que nunca foram comprados.
 *
 *  @param p Estrutura Par.
 *
 *  @return int.
 */
int getProductsNeverBoughtCount(Par p);


/* @brief Retorna o numero de clientes que nunca realizaram compras e o numero de produtos nunca comprados.
 *
 *  @param p Estrutura Par 
 *  @param cp Catalogo de produtos 
 *  @param cc Catalogo de clientes  
 *  @param f Faturacao 
 *  @param fil[3] Informação contida nas 3 filiais
 *
 *  @return Par.
 */
Par clientsAndProductsNeverBoughtCount(Par p,Cat_Produtos cp,Cat_Clientes cc,Faturacao f,Filial fil[3]);


/*  @brief Aloca memória para a criação de uma estrutura Tabela.
 *
 *  @return Tabela
 */
Tabela initTabela();


/*  @brief Remove a estrutura tabela, libertando memória.
 *
 *  @param tbl Tabela a ser removida
 *
 *  @return void
 */
void removeTabela(Tabela tbl);


/* @brief Determina o numero de produtos comprados numa determinada filial (linha) num determinado mês (coluna).
 *
 *  @param tbl Tabela  
 *  @param linha Número da linha 
 *  @param coluna Número da coluna
 *
 *  @return int
 */
int getComprado(Tabela tbl,int linha,int coluna);


/* @brief Retorna a tabela com a informação dos produtos comprados por um determinado cliente
 *
 *  @param tbl Tabela 
 *  @param fil[3] Informação das 3 filiais 
 *  @param clientID Código de cliente
 *
 *  @return Tabela
 */
Tabela productBoughtByClient(Tabela tbl,Filial fil[3],char* clientID);


/* @brief Aloca memória para a criação de uma estrutura Profit.
 *
 *  @return Profit
 */
Profit initProfit();


/* @brief Retorna o total faturado.
 *
 *  @param p Estrutura de dados
 *
 *  @return float
 */
float getFaturado(Profit p);


/* @brief Retorna o total de vendas.
 *
 *  @param p Estrutura Profit
 *
 *  @return int
 */
int getVendas(Profit p);


/* @brief Remove a estrutura profit, libertando memória.
 *
 *  @param p Estrutura de dados
 *
 *  @return void
 */
void removeProfit(Profit p);


/* @brief Retorna as vendas e o total faturado num intervalo de meses 
 *
 *  @param f Estrutura Faturacao 
 *  @param p Profit 
 *  @param minMonth Mês onde o intervalo se inicia 
 *  @param maxMonth Mês onde o intervalo finda
 *
 *  @return Profit
 */
Profit salesAndProfit(Faturacao f,Profit p,int minMonth,int maxMonth);


/* @brief Aloca memória para a criação de uma estrutura LstBuyers.
 *
 *  @return LstBuyers
 */
LstBuyers initLstBuyers();


/* @brief Retorna a lista de clientes que realizaram compras em modo Normal.
 *
 *  @param l Estrutura de dados
 *
 *  @return Lista
 */
Lista getListaN(LstBuyers l);


/* @brief Retorna a lista de clientes que realizaram compras em modo Promocional.
 *
 *  @param  l Estrutura de dados
 *
 *  @return Lista
 */
Lista getListaP(LstBuyers l);


/* @brief Remove a estrutura LstBuyers, libertando memória.
 *
 *  @param l Estrutura de dados a ser removida
 *
 *  @return void
 */
void removeLstBuyers(LstBuyers l);


/* @brief Retorna as listas (N e P) c/ os clientes que compraram um determinado produto num tipo de compra Normal ou Promocional
 *
 *  @param l Estrutura de dados 
 *  @param f Estrutura de dados 
 *  @param productID Código do produto
 *
 *  @return LstBuyers
 */
LstBuyers productBuyers(LstBuyers l,Filial f,char* productID);



/* @brief Retorna a lista c/ os produtos  mais comprados por um cliente num determinado mês, em todas as filiais.
 *
 *  @param f[3] Informação das tres filiais
 *  @param lst Lista onde se insere o resultado da função
 *  @param clientID Código de cliente 
 *  @param month Mês
 *
 *  @return Lista
 */
Lista clientFavoriteProducts(Filial f[3],Lista lst,char* clientID,int month);


/* @brief Aloca memória para a criação de uma estrutura SelledProd.
 *
 *  @return SelledProd
 */
SelledProd initSelledProd();


/* @brief Retorna o numero de unidades vendidas
 *
 *  @param s Estrutura de dados
 *
 *  @return int
 */
int getUnidadesVendidasProd(SelledProd s);


/* @brief Retorna o número de clientes
 *
 *  @param s Estrutura SelledProd
 *
 *  @return int*
 */
int* getNumClientes(SelledProd s);


/* @brief Retorna o código do produto
 *
 *  @param s Estrutura de dados 
 *
 *  @return char*
 */
char* getProdCode(SelledProd s);


/* @brief Retorna o número de unidades de um produto vendidas por filial
 *
 *  @param s Estrutura de dados
 *
 *  @return int*
 */
int* getUnidadesVendidasFilial(SelledProd s);


/* @brief Remove a estrutura SelledProd, libertando memória.
 *
 *  @param s Estrutura de dados a ser removida
 *
 *  @return void
 */
void removeSelledProds(SelledProd s);


/* @brief Retorna a lista de produtos mais vendidos na empresa
 *
 *  @param top Apontador
 *  @param fat Estrutura de dados 
 *  @param f[3] Informação àcerca das filiais 
 *  @param limit Limite do top
 *
 *  @return void
 */
SelledProd* topSelledProducts(SelledProd* top,Faturacao fat,Filial f[3],int limit);


/* @brief Retorna a lista de produtos mais comprados por um cliente, com um determinado limite
 *
 *  @param f[3]Filial Informação das filiais
 *  @param clientID Código cliente 
 *  @param limit Limite do top
 *
 *  @return GList*
 */
GList* topProducts(Filial f[3],char* clientID,int limit);


/* @brief Aloca memória para a criação da uma estrutura FileInfo.
 *
 *  @return FileInfo
 */
FileInfo initFileInfo();


/* @brief Indica o número de linhas lidas de um ficheiro cujo path é identificado pelo index.
 *
 *  @param fi Estrutura de dados 
 *  @param index Index para o path pretendido;
 *
 *  @return int
 */
int getNumLinhasLidasFI(FileInfo fi,int index);


/* @brief Indica o número de linhas validadas num ficheiro cujo path é identificado pelo index. 
 *
 *  @param fi Estrutura de dados 
 *  @param index Index para o path pretendido;
 *
 *  @return int
 */
int getNumLinhasValidadasFI(FileInfo fi,int index);


/* @brief Indica o tempo que demorou a ler um ficheiro cujo path é identificado pelo index. 
 *
 *  @param fi Estrutura de dados 
 *  @param index Index para o path pretendido;
 *
 *  @return int
 */
float getTempoLeituraFI(FileInfo fi,int index);


/* @brief Indica o nome do ficheiro cujo path é identificado pelo index
 *
 *  @param fi Estrutura de dados 
 *  @param index Index para o path pretendido;
 *
 *  @return char*
 */
char* getFileNameFI(FileInfo fi,int index);


/* @brief Remove a estrutura FileInfo, libertando memória.
 *
 *  @param fi Estrutura a ser removida
 *
 *  @return void
 */
void removeFileInfo(FileInfo fi);


/* @brief Define os parâmetros da estrutura FileInfo com informação dos ficheiros, de leitura e de validação sobre as diversas estruturas que constam no argumento
 *
 *  @param fi Estrutura de dados 
 *  @param cp Estrutura de dados Catalogo de Produtos
 *  @param cc Estrutura de dados Catalogo de clientes
 *  @param f  Estrutura de dados Faturação
 *
 *  @return FileInfo
 */
FileInfo currentFilesInfo(FileInfo fi,Cat_Produtos cp,Cat_Clientes cc,Faturacao f);

#endif