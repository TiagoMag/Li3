/**
 * @file Venda.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que primitem manipular uma Venda.
 *  
 */

#ifndef Venda_H
#define Venda_H

#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "Produto.h"
#include "Cliente.h"
#include "CatProdutos.h"
#include "CatClientes.h"

/**
 * @brief Declaração do tipo opaco Venda. 
 */
typedef struct venda *Venda;


/** @brief Inicializa o tipo Venda,alocando memoria da estrutura de dados para sua inicialização.
 *
 *  @return Venda.
 */
Venda inicializaV();


/** @brief Verifica se uma venda é válida.
 *
 *  @param venda Venda.
 *  @param cp Catalogo de Produtos.
 *  @param cc Catalogo de Clientes.
 *  @return Venda.
 */
gboolean validaV(Venda venda,Cat_Produtos cp,Cat_Clientes cc);

/** @brief Cria uma venda.
 * Cria uma venda a partir de uma linha de um ficheiro já dividida.
 *
 *  @param v Venda.
 *  @param p Codigo de um produto.
 *  @param c Codigo de um cliente.
 *  @param preco Preco unitario do produto.
 *  @param q Quantidade comprada.
 *  @param tipoCompra mode do Compra(Normal(N)/Promocao(P)).
 *  @param m Mes da venda.
 *  @param f Filial onde ocorreu a venda.
 *  @return Venda.
 */
Venda criaVendas(Venda v,char* p,char* c,float preco,int q,char tipoCompra ,int m,int f);


/** @brief Retorna o produto de uma venda.
 * 
 *  @param v Venda.
 *  @return Produto.
 */
Produto getProdutoVenda(Venda v);


/** @brief Retorna o preco de uma venda.
 * 
 *  @param v Venda.
 *  @return Preco da venda.
 */
float getPrecoVenda(Venda v);


/** @brief Retorna a quantidade de uma venda.
 * 
 *  @param v Venda.
 *  @return Quantidade da venda.
 */
int getQntVenda(Venda v);


/** @brief Retorna o modo de compra de uma venda.
 * 
 *  @param v Venda.
 *  @return Modo de compra(N/P).
 */
char getTipo(Venda v);


/** @brief Retorna o Cliente de uma venda.
 * 
 *  @param v Venda.
 *  @return Cliente.
 */
Cliente getClienteVenda(Venda v);


/** @brief Retorna o mes de uma venda.
 * 
 *  @param v Venda.
 *  @return Mes.
 */
int getMes(Venda v);


/** @brief Retorna a filial de uma venda.
 * 
 *  @param v Venda.
 *  @return Filial.
 */
int getFilial(Venda v);


/** @brief Liberta a memória alocada pelo tipo Venda.
 * 
 *  @param v Venda.
 *  @return Void.
 */
void removeVenda(Venda v); 

#endif