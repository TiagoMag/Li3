/**
 * @file CatClientes.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que primitem manipular o Catalogo de Clientes.
 *  
 */

#ifndef CatClientes_H
#define CatClientes_H

#include <stdlib.h>
#include <glib.h>
#include "Cliente.h"

/**
 * @brief Tamanho do abecedario.
 */
#define Clientes 26

/**
 * @brief Declaração do tipo opaco Cat_Clientes. 
 */
typedef struct cat_clientes *Cat_Clientes;


/* @brief Inicializa a o tipo Cat_Clientes,alocando memoria da estrutura de dados para sua inicialização.
 *
 *  @return Catalogo de Clientes.
 */
Cat_Clientes inicializa_CatClientes();


/* @brief Insere um cliente no catalogo de clientes.
 *  
 *  @param cc Catalogo de Clientes.
 *  @param c Cliente.
 *  @return Catalogo de Clientes.
 */
Cat_Clientes insereCliente(Cat_Clientes cc,Cliente c);


/* @brief Verifica a existencia de um cliente no catalogo de clientes.
 *  
 *  @param cc Catalogo de Clientes.
 *  @param c Cliente.
 *  @return True or False.
 */
gboolean existeCliente(Cat_Clientes cc,Cliente c);


/* @brief Determina o numero total de clientes existentes no catalogo.
 *  
 *  @param cc Catalogo de Clientes.
 *  @return Total de clientes.
 */
int totalClientes(Cat_Clientes cc);


/* @brief Desalocação de memória do Catalogo de Clientes.
 *  
 *  @param cc Catalogo de Clientes.
 *  @return Void.
 */
void removeCatCliente(Cat_Clientes cc);


/* @brief Desalocação de memória do Catalogo de Clientes.
 *  
 *  @param cc Catalogo de Clientes.
 *  @param index Indice correspondente á primeira letra dos codigos de cliente.
 *  @return Arvóre de clientes começados por uma determinada Letra.
 */
GTree* getTreeC(Cat_Clientes cc,int index);


/* @brief Coloca informação sobre o ficheiro lido.
 *  
 *  @param cc Catalogo de Clientes.
 *  @param filename nome do ficheiro lido.
 *  @param num_linhas_lidas Numero de linha lidas do ficheiro.
 *  @param tempo Tempo de leitura do ficheiro.
 *  @return Catalogo de Clientes.
 */
Cat_Clientes setInfoFileClientes(Cat_Clientes cc,char* filename,int num_linhas_lidas,float tempo);


/* @brief Retorna o numero de linhas lidas pelo ficheiro que carregou o Catalogo.
 *  
 *  @param cc Catalogo de Clientes.
 *  @return Numero de linhas lidas.
 */
int getNumLinhasLidasClientes(Cat_Clientes cc);


/* @brief Retorna o tempo de leitura do ficheiro que carregou o Catalogo.
 *  
 *  @param cc Catalogo de Clientes.
 *  @return Tempo de leitura.
 */
float getTempoLeituraClientes(Cat_Clientes cc);


/* @brief Retorna o nome do ficheiro que carregou o Catalogo.
 *  
 *  @param cc Catalogo de Clientes.
 *  @return Nome do ficheiro.
 */
char* getFileNameClientes(Cat_Clientes cc);

#endif