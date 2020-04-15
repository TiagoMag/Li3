#ifndef Faturacao_H
#define Faturacao_H

#include <glib.h>
#include "Venda.h"

/**
 * @brief Declaração do tipo opaco Faturacao. 
 */
typedef struct faturacao *Faturacao;

/**
 * @brief Declaração do tipo opaco Fat. 
 */
typedef struct fat *Fat;


/**
 * @brief Declaração do tipo opaco Data. 
 */
typedef struct data *Data;


/**
 * @brief Número meses
 */
#define MES 12
/**
 * @brief Número de filiais
 */
#define FILIAL 3


/* @brief Inicialização e alocação de memória da estrutura Fatura
 *
 *
 *  @return  Faturacao
 */
Faturacao inicializaFat();

/* @brief Verifica a existencia da venda de um produto na faturaçao
 *
 *  @param f Estrutura de dados 
 *  @param  v Uma venda
 *
 *  @return gboolean
 */
gboolean existeFat(Faturacao f,Venda v);

/* @brief Insere uma venda na Faturacao
 *
 *  @param f Estrutura de dados
 *  @param v Uma venda
 *
 *  @return Faturacao
 */
Faturacao insereFat(Faturacao f,Venda v);
/* @brief Atualiza os parametros de uma venda de um produto já existente
 *
 *  @param f Estrutura de dados
 *  @param v Uma venda
 *
 *  @return Faturacao
 */
Faturacao updateFat(Faturacao f,Venda v);
/* @brief Define a informação correlacionada com o carregamento do ficheiro de vendas
 *
 *  @param f Estrutura de dados
 *  @param num_linhas_validadas Numero de linhas validadas
 *  @param num_linhas_lidas Numero de linhas lidas
 *  @param filename Nome do ficheiro
 *  @param tempo_leitura Tempo de leitura do ficheiro
 *
 *  @return 
 */
Faturacao setFileInfoVendas(Faturacao f,int num_linhas_validadas,int num_linhas_lidas,char* filename,float tempo_leitura);

/* @brief Getter do numero de linhas lidas no ficheiro de vendas
 *
 *  @param f Estrutura de dados
 *
 *  @return int
 */
int getNumLinhasLidasVendas(Faturacao f);

/* @brief Getter do numero de linhas validadas no ficheiro de vendas
 *
 *  @param f Estrutura de dados
 *
 *  @return int
 */
int getNumLinhasValidadasVendas(Faturacao f);


/* @brief Getter do tempo de leitura do ficheiro de vendas
 *
 *  @param f Estrutura de dados
 *
 *  @return float
 */
float getTempoLeituraVendas(Faturacao f);

/* @brief Getter do nome do ficheiro de vendas
 *
 *  @param f Estrutura de dados
 *
 *  @return char*
 */
char* getFileNameVendas(Faturacao f);


/* @brief Getter do numero total de unidades vendidas
 *
 *  @param f Estrutura de dados
 *  @param prodID codigo de produto
 *
 *  @return int
 */
int getUnidadesVendidas(Faturacao f,char* prodID);


/* @brief Getter da informação de vendas de um determinado produto, com um determinado tipo de compra, num determinado mês
 *
 *  @param f Estrutura de dados
 *  @param codigo Código de produto
 *  @param tipo Tipo de compra
 *  @param mes Mês pretendido
 *
 *  @return Data
 */
Data getData(Faturacao f,char* codigo,char tipo,int mes);

/* @brief Getter da informação de vendas de um determinado produto num determinado tipo de compra, num determinado mes numa determinada filial
 *
 *  @param f Estrutura de dados
 *  @param codigo Codigo de produto
 *  @param tipo Tipo de compra
 *  @param mes Mês
 *  @param filial Filial escolhida
 *
 *  @return Data
 */
Data getDataFilial(Faturacao f,char* codigo,char tipo,int mes,int filial);


/* @brief getter do total faturado por um determinado produto
 *
 *  @param d Informação de um produto
 *
 *  @return float
 */
float getPrecoFat(Data d);


/* @brief Getter da quantidade de um produto vendida
 *
 *  @param d Informação de um produto
 *  @param 
 *
 *  @return int
 */
int getQntFat(Data d);

/* @brief Verifica se um produto existe na estrutura da Faturacao 
 *
 *  @param f Estrutura de dados
 *  @param codigo Codigo de produto
 *
 *  @return gboolean
 */
gboolean existeProdFat(Faturacao f,char* codigo);

/* @brief Remove Faturação, libertando memória previamente alocada
 *
 *  @param f Estrutura de dados a ser removida
 *
 *  @return void
 */
void removeFaturacao(Faturacao f);


/* @brief Retorna o total faturado num intevalo de meses
 *
 *  @param f Estrutura de dados
 *  @param minMonth Mes inicial
 *  @param maxMonth Mes final
 *
 *  @return float
 */
float getProfit(Faturacao f,int minMonth,int maxMonth);

/* @brief Retorna o numero total de vendas num intervalo de meses 
 *
 *  @param f Estrutura de dados
 *  @param minMonth Mes inicial
 *  @param maxMonth Mes final
 *
 *  @return gboolean
 */
int getSales(Faturacao f,int minMonth,int maxMonth);


/* @brief Retorna uma lista dos produtos mais vendidos com tamanho <<limit>>
 *
 *  @param lst Lista de retorno
 *  @param f Estrutura de dados
 *  @param maxMonth Mes final
 *
 *  @return Lista
 */
Lista topSelledProductsN(Lista lst,Faturacao f,int limit);

#endif