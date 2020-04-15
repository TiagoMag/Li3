/**
 * @file Filial.h
 * @author Grupo 4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros necessárias à manipulação de dados e informação das estruturas filial.
 *  
 */

#ifndef Filial_H
#define Filial_H

#include <glib.h>
#include <stdlib.h>
#include "Venda.h"
#include "Navegador.h"

/**
 * @brief Número de filiais
 */
#define FILIAL 3

/**
 * @brief Número de meses
 */
#define MES 12


/**
 * @brief Declaração do tipo opaco Filial. 
 */
typedef struct filial *Filial;


/**
 * @brief Declaração do tipo opaco InfoCli. 
 */
typedef struct infoCli *InfoCli;


/**
 * @brief Declaração do tipo opaco InfoProd. 
 */
typedef struct infoProd *InfoProd;



/**
 * @brief Declaração do tipo opaco QntProds. 
 */
typedef struct qntProds *QntProds;


/**
 * @brief Declaração do tipo opaco TopProds. 
 */
typedef struct topProds *TopProds;


/* @brief Inicializa a estrutura Filial
 *
 *  @return Filial.
 */
Filial inicializa_Filial();

/* @brief Insere uma venda na Filial
 *
 *  @param f Estrutura de dados
 *  @param v Uma venda
 *
 *  @return Filial.
 */
Filial insereFilial(Filial f,Venda v);

/* @brief Verifica se existe um cliente numa Filial
 *
 *  @param f Estrutura de dados
 *  @param codigo Código de um cliente
 *
 *  @return gboolean
 */
gboolean existeCliFil(Filial f,char* codigo);

/* @brief Verifica se existe um produto numa Filial
 *
 *  @param f Estrutura de dados
 *  @param codigo Código de um produto
 *
 *  @return gboolean
 */
gboolean existeProdFil(Filial f,char* codigo);

/* @brief Remove uma filial, libertando memória no processo.
 *
 *  @param f Estrutura de dados a ser removida
 *
 *  @return void
 */
void removeFilial(Filial f);

/* @brief Retorna o numero de produtos comprados por um cliente, num determinado mês
 *
 *  @param f Estrutura de dados
 *  @param mes Mês escohido
 *  @param code Código do cliente
 *
 *  @return int
 */
int produtosCompradosCliente(Filial fil,int mes,char* code);

/* @brief Retorna os clientes que compraram um determinado produto com um determinado tipo de compra
 *
 *  @param f Estrutura de dados
 *  @param lst 
 *  @param productID Código de produto
 *  @param tipo Modo de compra 
 *
 *  @return Lista
 */
Lista buyers (Filial f,Lista lst,char* productID,char tipo);

/* @brief Retorna os produtos mais comprados por um dado cliente, num mês específico, na filial
 *
 *  @param ht Pointer 
 *  @param f Estrutura de dados
 *  @param codigoCli Código de Cliente
 *  @param mes Mês
 * 
 *  @return GHashTable* 
 */
GHashTable* produtosQueMaisComprou(gpointer ht,Filial f,char* codigoCli,int mes);

/* @brief getter da estrutura QntProds
 *
 *  @param qp Estrutura auxiliar QntProds
 *
 *  @return int
 */
int getQntQP(QntProds qp);

/* @brief getter da estrutura QntProds
 * 
 *  @param qp Estrutura auxiliar QntProds
 *
 *  @return char*
 */
char* getCodeQP(QntProds qp);

/* @brief Remoção e libertação de memória 
 *
 *  @param data A ser removida
 *
 *  @return void
 */
void removeQntProds(gpointer data);

/* @brief Retorna numero de clientes que adquiriram um determinado produto numa determinada filial
 *
 *  @param f Estrutura de dados
 *  @param codeProduct Código de produto
 *
 *  @return int
 */
int numberClients(Filial f,char* codeProduct);

/* @brief Número de unidades compradas de um dado produto, numa filial
 *
 *  @param f Estrutura de dados
 *  @param prodID Código de produto
 *
 *  @return int
 */
int getUnidadesFilial (Filial f,char* prodID);

/* @brief Getter da estrutura gastoTop
 *
 *  @param tp Estrutura auxiliar de dados
 *
 *  @return float
 */
float getGastoTop(TopProds tp);

/* @brief Getter da estrutura getCodeTop
 *
 *  @param tp Estrutura de dados
 *
 *  @return char*
 */
char* getCodeTop(TopProds tp);

/* @brief Inicialização da estrutura de dados TopProd
 *
 *
 *  @return TopProds
 */
TopProds initTopProds();

/* @brief Remoção da estrutura de dados TopProds e libertação de memória
 *
 *  @param data Estrutura a ser removida
 *
 *  @return void 
 */
void removeTP(gpointer data);

/* @brief Setter da estrutura TopProds
 *
 *  @param p Estrutura de dados
 *  @param prod Código de produto
 *  @param gasto Valor gasto nesse produto
 *
 *  @return TopProds
 */
TopProds setTopProds(TopProds tp,char* prod,float gasto);
/* @brief 
 *
 *  @param  f Estrutura de dados
 *  @param  ht Apontador para estrutura
 *  @param  clientID Código de cliente
 *
 *  @return 
 */
GHashTable* topProfitProducts(Filial f,gpointer ht,char* clientID);


#endif