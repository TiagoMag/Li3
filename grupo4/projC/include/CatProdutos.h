/**
 * @file CatProdutos.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que primitem manipular o Catalogo de Produtos.
 *  
 */

#ifndef CatProdutos_H
#define CatProdutos_H

#include <stdlib.h>
#include <glib.h>
#include "Produto.h"
#include "Navegador.h"

/**
 * @brief Tamanho do abecedario.
 */
#define Produtos 26

/**
 * @brief Declaração do tipo opaco Cat_Produtos. 
 */
typedef struct cat_produtos *Cat_Produtos;


/** @brief Inicializa a o tipo CatProds,alocando memoria da estrutura de dados para sua inicialização.
 *
 *  @return Catalogo de Produtos.
 */
Cat_Produtos inicializa_CatProds();


/** @brief Insere um produto no catalogo de produtos.
 *  
 *  @param cp Catalogo de Produtos.
 *  @param p Produto.
 *  @return Catalogo de Produtos.
 */
Cat_Produtos insereProd(Cat_Produtos cp,Produto p);

/** @brief Verifica a existencia de um produto no catalogo de produtos.
 *  
 *  @param cp Catalogo de Produtos.
 *  @param p Produto.
 *  @return True or False.
 */
gboolean existeProd(Cat_Produtos cp,Produto p);


/** @brief Produtos de uma determinada letra (dispostos em arvore) são convertidos numa Lista.
 *  
 *  @param cp Catalogo de Produtos.
 *  @lst Lista de Strings(Códigos Produto).
 *  @letter Letra inicial dos código de um produto.
 *  @return Lista com códigos de produtos começados pela letra.
 */
Lista produtosLetra(Cat_Produtos cp,Lista lst,char letter);


/** @brief Determina o numero total de clientes existentes no catalogo.
 *  
 *  @param cp Catalogo de Produtos.
 *  @return Total de produtos.
 */
int totalProd(Cat_Produtos cp);


/** @brief Desalocação de memória do Catalogo de Produtos.
 *  
 *  @param cp Catalogo de Produtos.
 *  @return Void.
 */
void removeCatProd(Cat_Produtos cp);


/** @brief Desalocação de memória do Catalogo de Produtos.
 *  
 *  @param cp Catalogo de Produtos.
 *  @param index Indice correspondente á primeira letra dos codigos de produtos.
 *  @return Árvore de produtos começados por uma determinada Letra.
 */
GTree* getTree(Cat_Produtos cp,int index);


/** @brief Coloca informação sobre o ficheiro lido.
 *  
 *  @param cp Catalogo de Produtos.
 *  @param filename nome do ficheiro lido.
 *  @param num_linhas_lidas Numero de linha lidas do ficheiro.
 *  @param tempo Tempo de leitura do ficheiro.
 *  @return Catalogo de Clientes.
 */
Cat_Produtos setInfoFileProdutos(Cat_Produtos cp,char* filename,int num_linhas_lidas,float tempo);


/** @brief Retorna o numero de linhas lidas pelo ficheiro que carregou o Catalogo.
 *  
 *  @param cp Catalogo de Produtos.
 *  @return Numero de linhas lidas.
 */
int getNumLinhasLidasProds(Cat_Produtos cp);

/** @brief Retorna o tempo de leitura do ficheiro que carregou o Catalogo.
 *  
 *  @param cp Catalogo de Produtos.
 *  @return Tempo de leitura.
 */
float getTempoLeituraProds(Cat_Produtos cp);


/** @brief Retorna o nome do ficheiro que carregou o Catalogo.
 *  
 *  @param cp Catalogo de Produtos.
 *  @return Nome do ficheiro.
 */
char* getFileNameProds(Cat_Produtos cp);

#endif