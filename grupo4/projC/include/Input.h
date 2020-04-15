/**
 * @file Input.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que primitem validar e receber Input's .
 *  
 */

#ifndef Input_H
#define Input_H

#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "View.h"


/** @brief Recebe o input do utilizador deste programa, (o qual pode conter, ou não os paths para os ficheiros de vendas,produtos e clientes) e imprime o resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param estrutra SGV, char** contendo paths personalizados do cliente
 *
 *  @return Lista.
 */
int inputQuery1(SGV sgv,char* filenames[3]);


/** @brief Gere a interação sistema-user, requisitando a letra necessaria à impressao do resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param 
 *
 *  @return char
 */
char inputQuery2();


/** @brief Requisita um mês e um código de um produto essencial para a querie funcionar imprime o resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param estrutura SGV, char* com o codigo de cliente, int com o mes
 *
 *  @return char.
 */
char inputQuery3(char* codigo,int* mes);


/** @brief Questiona o tipo de procura: por filial ou total imprime o resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param 
 *
 *  @return int.
 */
int inputQuery4();


/** @brief Requisita o codigo de cliente imprime o resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param char* onde o utilizador irá inserir o codigo de um cliente.
 *
 *  @return int.
 */
int inputQuery7(char* code);

/** @brief Recebe por parte do cliente os inteiros representativos do intervalo de meses imprime o resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param int onde o utilizador irá inserir o primeiro e segundo mes
 *
 *  @return int.
 */
int inputQuery8(int* mes1,int* mes2);


/** @brief Requisita o codigo de produto e a filial ao utilizador imprime o resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param 
 *
 *  @return int.
 */
int inputQuery9(char* productID);


/** @brief Recebe o codigo de um cliente e um mes por parte de um utilizador imprime o resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param  char* onde o codigo de cliente vai ser introduzido
 *
 *  @return int.
 */
int inputQuery10(char* clientID);

/** @brief Recebe o limite do top e imprime o resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param 
 *
 *  @return int.
 */
int inputQuery11();

/** @brief Recebe um codigo de cliente, um limite para o top e imprime o resultado da querie. Valor devolvido é essencial ao funcionamento da querie em si.
 *
 *  @param char* onde o codigo de cliente vai ser introduzido
 *
 *  @return int.
 */
int inputQuery12(char* clientID);

#endif