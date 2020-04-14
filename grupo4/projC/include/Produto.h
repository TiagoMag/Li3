#ifndef Produto_H
#define Produto_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <glib.h>

typedef struct produto *Produto;

Produto inicializa_Prod();
/* @brief Aloca memória para a criação de uma estrutura Produto.
 *
 *  @param 
 *
 *  @return Produto.
 */



Produto criaProduto(Produto p,char* codigo);
/* @brief Cria um produto c/ a informação em si contida devidamente encapsulada.
 *
 *  @param Produto, char* com o codigo a ser introduzido no produto
 *
 *  @return Produto
 */


char* getProduto(Produto p);
/* @brief Retorna o código de um produto
 *
 *  @param Produto
 *
 *  @return char*
 */


int getIndexP(Produto p);
/* @brief Retorna o index -representativo de uma letra- onde o produto se vai encontrar no array do Catalogo de Produtos
 *
 *  @param Produto
 *
 *  @return int
 */


gboolean validaProd(Produto p);
/* @brief Verifica se o código de produto é valido
 *
 *  @param Produto
 *
 *  @return gboolean
 */


void removeProduto(Produto p);
/* @brief Remove a estrutura Produto,libertando memória.
 *
 *  @param Produto
 *
 *  @return void
 */


#endif