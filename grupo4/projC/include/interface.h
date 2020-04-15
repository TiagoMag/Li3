/**
 * @file Interface.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros necessárias ao funcionamento do programa e à interação com o utilizador.
 *  
 */
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

/**
 * @brief Declaração do tipo opaco SGV. 
 */
typedef struct sgv *SGV;


/** @brief Aloca memória para a inicialização da estrutura SGV.
 *
 * @return void.
 */
SGV initSGV();


/** @brief Remove a estrutura SGV, libertando memória.
 *
 * @param sgv Estrutura a ser removida
 *
 * @return void.
 */
void destroySGV(SGV sgv);


/** @brief Faz a leitura dos ficheiros pré-definidos ou personalizados.
 *
 *  @param filepath[3] Path dos ficheiros a serem lidos
 *  @param sgv Estrutura de dados  
 *
 *  @return SGV.
 */
SGV loadFromFiles(char* filepath[3],SGV sgv);


/** @brief Apresenta a lista de produtos começados por uma determinada letra
 *
 *  @param sgv Estrutura de dados
 *  @param letter Contém a letra selecionada pelo utilizador
 *
 *  @return Lista.
 */
Lista getProductsStartedByLetter(SGV sgv,char letter);


/** @brief Apresenta a lista de registos e do total de vendas de um determinado produto, num determinado mês 
 *
 *  @param sgv Estrutura de dados
 *  @param produtctID Contém o codigo de produto 
 *  @param month Representa o mês
 *
 *  @return Lista.
 */
Lista getProductSalesAndProfit(SGV sgv,char* productID,int month);


/** @brief Lista ordenada de códigos de produtos que ninguém comprou (Total ou por filial).
 *
 * @param sgv Estrutura de dados
 * @param branchID Número da filial
 * 
 * @return Lista.
 */
Lista getProductsNeverBought(SGV sgv,int branchID);


/** @brief Lista de códigos de clientes que realizaram compras em todas as filiais.
 *
 *  @param sgv Estrutura de dados
 *
 *  @return Lista.
 */
Lista getClientesOfAllBranches(SGV sgv);


/** @brief Clientes que não realizaram compras e número de produtos nunca comprados.
 *
 *  @param sgv Estrutura de dados
 *
 *  @return Par.
 */
Par getClientsAndProductsNeverBoughtCount(SGV sgv);


/** @brief Tabela de produtos comprados por mês e filial.
 *
 *  @param sgv Estrutura de dados 
 *  @param clientID Codigo de cliente
 *
 *  @return Tabela.
 */
Tabela getProductBoughtByClient(SGV sgv,char* clientID);


/** @brief Determinar total de vendas num determinado intervalo.
 *
 *  @param sgv Estrutura de dados 
 *  @param minMonth Mês inicial 
 *  @param maxMonth Mês final
 *
 *  @return void.
 */
Profit getSalesAndProfit(SGV sgv,int minMonth,int maxMonth);


/** @brief Determinar os códigos e o número total dos clientes que compraram um produto numa filial.
 *
 *  @param sgv Estrutura de dados 
 *  @param productID Código de produto 
 *  @param branchID Valor correspondente à filial
 *
 *  @return LstBuyers.
 */
LstBuyers getProductBuyers(SGV sgv,char* productID,int branchID);


/** @brief Determinar a lista de produtos que um cliente mais comprou por quantidade, num determinado mês.
 *
 *  @param sgv Estrutura de dados 
 *  @param clientID Código de cliente 
 *  @param month Mês escolhido 
 *
 *  @return Lista.
 */
Lista getClientFavoriteProducts(SGV sgv,char* clientID,int month);


/** @brief Top personalizado de vendas,por número de cliente e quantidade vendida, filial a filial.
 *
 *  @param sgv Estrutura SGV 
 *  @param limit Limite do top
 *
 *  @return SelledProd*.
 */
SelledProd* getTopSelledProducts(SGV sgv,int limit);


/** @brief Top personalizado de gasto em compras individualizado por cliente.
 *
 *  @param sgv Estrutura de dados 
 *  @param clientID Código de cliente 
 *  @param limit Limite do top
 *
 *  @return GList*.
 */
GList* getClientTopProfitProducts(SGV sgv,char* clientID,int limit);


/** @brief Informação de performance àcerca dos ficheiros lidos.
 *
 *  @param sgv Estrutura de dados
 *
 *  @return FileInfo.
 */
FileInfo getCurrentFilesInfo(SGV sgv);


#endif