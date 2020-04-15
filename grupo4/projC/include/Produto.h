/**
 * @file Produto.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que permitem manipular um Produto.
 */

#ifndef Produto_H
#define Produto_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <glib.h>

/**
 * @brief Declaração do tipo opaco Produto. 
 */
typedef struct produto *Produto;


/** @brief Aloca memória para a criação de uma estrutura Produto.
 *
 * @return Produto.
 */
Produto inicializa_Prod();


/**  @brief Cria um produto c/ a informação em si contida devidamente encapsulada.
 *
 *  @param Produto 
 *  @param codigo Código a ser introduzido no produto
 *
 *  @return Produto
 */
Produto criaProduto(Produto p,char* codigo);


/**  @brief Retorna o código de um produto
 *
 *  @param Produto
 *
 *  @return char*
 */
char* getProduto(Produto p);


/** @brief Retorna o index -representativo de uma letra- onde o produto se vai encontrar no array do Catalogo de Produtos
 *
 *  @param Produto
 *
 *  @return int
 */
int getIndexP(Produto p);


/** @brief Verifica se o código de produto é valido
 *
 *  @param Produto
 *
 *  @return gboolean
 */
gboolean validaProd(Produto p);


/** @brief Remove a estrutura Produto,libertando memória.
 *
 *  @param Produto
 *
 *  @return void
 */
void removeProduto(Produto p);


#endif