/**
 * @file Files.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que primitem manipular um Produto.
 *  
 */

#ifndef Files_H
#define Files_H

#include <stdlib.h>
#include <glib.h>
#include <stdio.h>
#include "CatProdutos.h"
#include "CatClientes.h"
#include "Produto.h"
#include "Cliente.h"
#include "Venda.h"
#include "Faturacao.h"
#include "Filial.h"

/**
 * @brief Número de campos de uma venda. 
 */
#define CAMPOS 7

/**
 * @brief Tamanho do BUFFER. 
 */
#define BUFFER 64


/* @brief Carrega os produtos de um ficheiro para o Catalogo de Produtos.
 *
 *  @param file Nome do ficheiro.
 *  @param cp Catalogo de Produtos.
 *  @return Void.
 */
void loadFilesProduto(char* file,Cat_Produtos cp);


/* @brief Carrega os clientes de um ficheiro para o Catalogo de Clientes.
 *
 *  @param file Nome do ficheiro.
 *  @param cp Catalogo de Produtos.
 *  @return Void.
 */
void loadFilesCliente(char* file,Cat_Clientes cc);


/* @brief Carrega e valida as vendas de um ficheiro para a Filial e Faturacao.
 *
 *  @param file Nome do ficheiro.
 *  @param fil Array de Filiais.
 *  @param f Faturacao.
 *  @param cp Catalogo de Produtos
 *  @param cc Catalogo de Clientes
 *  @return Void.
 */
void leVendas(Filial fil[3],Faturacao f,char* file,Cat_Produtos cp,Cat_Clientes cc);

#endif