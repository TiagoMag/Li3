#ifndef INTERFACE_H
#define INTERFACE_H

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
/* @brief Remove a estrutura SGV, libertando memória.
 *
 *  @param 
 *
 *  @return void.
 */


SGV loadFromFiles(char* filepath[3],SGV sgv);
/* @brief Faz a leitura dos ficheiros pré-definidos ou personalizados.
 *
 *  @param char** com os paths dos ficheiros, estrutura SGV
 *
 *  @return SGV.
 */


Lista getProductsStartedByLetter(SGV sgv,char letter);
/* @brief Apresenta a lista de produtos começados por uma determinada letra
 *
 *  @param estrutura SGV, char com a letra em questão
 *
 *  @return Lista.
 */


Lista getProductSalesAndProfit(SGV sgv,char* productID,int month);
/* @brief Apresenta a lista de registos e do total de vendas de um determinado produto, num determinado mês 
 *
 *  @param estrutura SGV, char* com o codigo de produto, int que representa o mês
 *
 *  @return Lista.
 */


Lista getProductsNeverBought(SGV,int branchID);
/* @brief Lista ordenada de códigos de produtos que ninguém comprou (Total ou por filial).
 *
 *  @param estrutura SGV, int com o numero da filial 
 *
 *  @return Lista.
 */


Lista getClientesOfAllBranches(SGV sgv);
/* @brief Lista de códigos de clientes que realizaram compras em todas as filiais.
 *
 *  @param estrutura SGV
 *
 *  @return Lista.
 */


Par getClientsAndProductsNeverBoughtCount(SGV sgv);
/* @brief Clientes que não realizaram compras e número de produtos nunca comprados.
 *
 *  @param estrutura SGV
 *
 *  @return Par.
 */


Tabela getProductBoughtByClient(SGV sgv,char* clientID);
/* @brief Tabela de produtos comprados por mês e filial.
 *
 *  @param estrutura SGV, codigo cliente
 *
 *  @return Tabela.
 */


Profit getSalesAndProfit(SGV sgv,int minMonth,int maxMonth);
/* @brief Determinar total de vendas num determinado intervalo.
 *
 *  @param estrutura SGV, int com o mês inicial, int com o mês final
 *
 *  @return void.
 */


LstBuyers getProductBuyers(SGV sgv,char* productID,int branchID);
/* @brief Determinar os códigos e o número total dos clientes que compraram um produto numa filial.
 *
 *  @param estrutura SGV, int com o codigo de produto , int com a filial
 *
 *  @return LstBuyers.
 */


Lista getClientFavoriteProducts(SGV sgv,char* clientID,int month);
/* @brief Determinar a lista de produtos que um cliente mais comprou por quantidade, num determinado mês.
 *
 *  @param estrutura SGV, char* com o codigo de cliente, int com o mes
 *
 *  @return Lista.
 */


SelledProd* getTopSelledProducts(SGV sgv,int limit);
/* @brief Top personalizado de vendas,por número de cliente e quantidade vendida, filial a filial.
 *
 *  @param estrutura SGV, int com o limite do top
 *
 *  @return SelledProd*.
 */


GList* getClientTopProfitProducts(SGV sgv,char* clientID,int limit);
/* @brief Top personalizado de gasto em compras individualizado por cliente.
 *
 *  @param estrutura SGV, char* com o codigo de cliente, int com o limite do top
 *
 *  @return GList*.
 */


FileInfo getCurrentFilesInfo(SGV sgv);
/* @brief Informação dos ficheiros lidos.
 *
 *  @param estrutura SGV
 *
 *  @return FileInfo.
 */

#endif