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
/*  @brief Retorna a lista de produtos começados por uma determinada letra.
 *
 *  @param estrutura Catalogo de produtos, Lista, char c/ letra pretendida.
 *
 *  @return Lista.
 */


Lista productSalesAndProfit(Faturacao f,Lista lst,char* productID,int month);
/*  @brief Retorna a lista do valor e numero de vendas de um produtopor uma determinada letra.
 *
 *  @param Faturacao, uma lista, char* c/ o código de produto, int que identifica o mes.
 *
 *  @return Lista.
 */

Lista productsNeverBought(Filial fil,Lista lst,Faturacao f,Cat_Produtos cp,int branchID);

/*  @brief Retorna a lista de produtos começados por uma determinada letra.
 *
 *  @param estrutura Filial, Lista, Faturação, Catalogo produtos, int que identifica a filial.
 *
 *  @return Lista.
 */


Lista clientesOfAllBranches(Cat_Clientes cc,Lista lst,Filial fil[3]);
/* @brief Retorna a lista de clientes de todas as filiais.
 *
 *  @param Catalogo de clientes, uma lista e a filial[3] (c/ a informação contida nas 3 filiais).
 *
 *  @return Lista.
 */

Par initPar();
/* @brief Aloca memória para a criação de uma estrutura par.
 *
 *  @param 
 *
 *  @return Par.
 */


void removePar(Par p);
/* @brief Remove a estrutura par, libertando a memória.
 *
 *  @param estrutura Par.
 *
 *  @return void.
 */


int getClientsNeverBoughtCount(Par p);
/* @brief Retorna o número de clientes que não realizaram quaisquer compras.
 *
 *  @param estrutura Par.
 *
 *  @return int.
 */


int getProductsNeverBoughtCount(Par p);
/* @brief Retorna o número de produtos que nunca foram comprados.
 *
 *  @param estrutura Par.
 *
 *  @return int.
 */


Par clientsAndProductsNeverBoughtCount(Par p,Cat_Produtos cp,Cat_Clientes cc,Faturacao f,Filial fil[3]);
/* @brief Retorna o numero de clientes que nunca realizaram compras e o numero de produtos nunca comprados.
 *
 *  @param estrutura Par, Catalogo de produtos, Catalogo de clientes, Faturacao e filial[3] (c/ a informação contida nas 3 filiais).
 *
 *  @return Par.
 */


Tabela initTabela();
/* @brief Aloca memória para a criação de uma estrutura Tabela.
 *
 *  @param 
 *
 *  @return Tabela
 */


void removeTabela(Tabela tbl);
/* @brief Remove a estrutura tabela, libertando memória.
 *
 *  @param Tabela
 *
 *  @return void
 */



int getComprado(Tabela tbl,int linha,int coluna);
/* @brief Determina o numero de produtos comprados numa determinada filial (linha) num determinado mês (coluna).
 *
 *  @param Tabela, int com o número da linha, int com o número da coluna
 *
 *  @return int
 */


Tabela productBoughtByClient(Tabela tbl,Filial fil[3],char* clientID);
/* @brief Retorna a tabela com a informação dos produtos comprados por um determinado cliente
 *
 *  @param estrutura Tabela, Filial com a informação das 3 filiais, char* c/ o código de cliente
 *
 *  @return Tabela
 */


Profit initProfit();
/* @brief Aloca memória para a criação de uma estrutura Profit.
 *
 *  @param 
 *
 *  @return Profit
 */

float getFaturado(Profit p);
/* @brief Retorna o parâmetro (float)total_faturado da estrutura profit.
 *
 *  @param estrutura Profit
 *
 *  @return float
 */


int getVendas(Profit p);
/* @brief Retorna o parâmetro (int)total_vendas da estrutura profit.
 *
 *  @param estrutura Profit
 *
 *  @return int
 */


void removeProfit(Profit p);
/* @brief Remove a estrutura profit, libertando memória.
 *
 *  @param Profit
 *
 *  @return void
 */


Profit salesAndProfit(Faturacao f,Profit p,int minMonth,int maxMonth);
/* @brief Retorna as vendas e o total faturado num intervalo de meses 
 *
 *  @param estrutura Faturacao, Profit, int com o mês onde o intervalo se inicia, int com o mês onde o intervalo finda
 *
 *  @return Profit
 */



LstBuyers initLstBuyers();
/* @brief Aloca memória para a criação de uma estrutura LstBuyers.
 *
 *  @param 
 *
 *  @return LstBuyers
 */


Lista getListaN(LstBuyers l);
/* @brief Retorna a lista de clientes que realizaram compras em modo Normal.
 *
 *  @param  LstBuyers
 *
 *  @return Lista
 */


Lista getListaP(LstBuyers l);
/* @brief Retorna a lista de clientes que realizaram compras em modo Promocional.
 *
 *  @param  LstBuyers
 *
 *  @return Lista
 */


void removeLstBuyers(LstBuyers l);
/* @brief Remove a estrutura LstBuyers, libertando memória.
 *
 *  @param LstBuyers a ser removida
 *
 *  @return void
 */


LstBuyers productBuyers(LstBuyers l,Filial f,char* productID);
/* @brief Retorna as listas (N e P) c/ os clientes que compraram um determinado produto num tipo de compra Normal ou Promocional
 *
 *  @param estrutura LstBuyers, Filial f , codigo do produto
 *
 *  @return LstBuyers
 */


Lista clientFavoriteProducts(Filial f[3],Lista lst,char* clientID,int month);
/* @brief Retorna a lista c/ os produtos  mais comprados por um cliente num determinado mês, em todas as filiais.
 *
 *  @param estrutra Filial, Lista,  o codigo de cliente e um mês
 *
 *  @return Lista
 */


SelledProd initSelledProd();
/* @brief Aloca memória para a criação de uma estrutura SelledProd.
 *
 *  @param 
 *
 *  @return SelledProd
 */


int getUnidadesVendidasProd(SelledProd s);
/* @brief Retorna o numero de unidades vendidas
 *
 *  @param estrutura SelledProd
 *
 *  @return int
 */


int* getNumClientes(SelledProd s);
/* @brief Retorna o numero de clientes
 *
 *  @param estrutura SelledProd
 *
 *  @return int*
 */


char* getProdCode(SelledProd s);
/* @brief Retorna o codigo do produto
 *
 *  @param estrutura SelledProd
 *
 *  @return char*
 */


int* getUnidadesVendidasFilial(SelledProd s);
/* @brief Retorna o numero de unidades de um produto vendidas por filial
 *
 *  @param estrutura SelledProd
 *
 *  @return int*
 */


void removeSelledProds(SelledProd s);
/* @brief Remove a estrutura SelledProd, libertando memória.
 *
 *  @param SelledProd a ser removida
 *
 *  @return void
 */


SelledProd* topSelledProducts(SelledProd* top,Faturacao fat,Filial f[3],int limit);
/* @brief Retorna a lista de produtos mais vendidos na empresa
 *
 *  @param apontador de SelledProd, faturacao, filial f[3] c/ info das 3 filiais, limite do top
 *
 *  @return void
 */


GList* topProducts(Filial f[3],char* clientID,int limit);
/* @brief Retorna a lista de produtos mais comprados por um cliente, com um determinado limite
 *
 *  @param Filial, codigo cliente, limite do top
 *
 *  @return GList*
 */


FileInfo initFileInfo();
/* @brief Aloca memória para a criação da uma estrutura FileInfo.
 *
 *  @param 
 *
 *  @return FileInfo
 */


int getNumLinhasLidasFI(FileInfo fi,int index);
/* @brief Indica o numero de linhas (em cada linha há 1 código) lidos de um ficheiro cujo path é identificado pelo index.
 *
 *  @param FileInfo, (int) index;
 *
 *  @return int
 */


int getNumLinhasValidadasFI(FileInfo fi,int index);
/* @brief Indica o numero de linhas (em cada linha há 1 código) validados num ficheiro cujo path é identificado pelo index. 
 *
 *  @param FileInfo, (int) index;
 *
 *  @return int
 */


float getTempoLeituraFI(FileInfo fi,int index);
/* @brief Indica o tempo que demorou a ler um ficheiro cujo path é identificado pelo index. 
 *
 *  @param FileInfo, (int) index;
 *
 *  @return int
 */


char* getFileNameFI(FileInfo fi,int index);
/* @brief Indica o nome do ficheiro cujo path é identificado pelo index
 *
 *  @param FileInfo, (int) index;
 *
 *  @return char*
 */


void removeFileInfo(FileInfo fi);
/* @brief Remove a estrutura FileInfo, libertando memória.
 *
 *  @param FileInfo a ser removida
 *
 *  @return void
 */



FileInfo currentFilesInfo(FileInfo fi,Cat_Produtos cp,Cat_Clientes cc,Faturacao f);
/* @brief Define os parâmetros da estrutura FileInfo com informação dos ficheiros, de leitura e de validação sobre as diversas estruturas que constam no argumento
 *
 *  @param estrutura FileInfo, Catalogo de produtos, Catalogo de clientes, Faturação
 *
 *  @return FileInfo
 */

#endif