/**
 * @file Cliente.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que primitem manipular um Cliente.
 *  
 */

#ifndef Cliente_H
#define Cliente_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <glib.h>

/**
 * @brief Declaração do tipo opaco Cliente. 
 */
typedef struct cliente *Cliente;


/* @brief Aloca memória para a criação de uma estrutura Cliente.
 *
 *  @return Cliente.
 */
Cliente inicializa_Cliente();


/* @brief Cria um cliente c/ a informação em si contida devidamente encapsulada.
 *
 *  @param c Cliente
 *  @param codigo char* com o codigo a ser introduzido no cliente.
 *  @return Cliente.
 */
Cliente criaCliente(Cliente c,char* codigo);


/* @brief Retorna o código de um cliente.
 *
 *  @param c Cliente.
 *
 *  @return Letra inicial do código do cliente.
 */
char* getCliente(Cliente c);


/* @brief Retorna o index -representativo de uma letra- onde o cliente se vai encontrar no array do Catalogo de Clientes.
 *  Map de uma letra para index.
 *  @param c Cliente.
 *
 *  @return Index.
 */
int getIndexC(Cliente c);


/* @brief Verifica se o código de cliente é valido.
 *
 *  @param c Cliente.
 *
 *  @return True ou False.
 */
gboolean validaCliente(Cliente c);


/* @brief Remove a estrutura Cliente,libertando memória alocada por este.
 *
 *  @param c Cliente.
 *
 *  @return Void.
 */
void removeCliente(Cliente c);

#endif
