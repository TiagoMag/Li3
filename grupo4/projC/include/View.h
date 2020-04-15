/**
 * @file View.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que primitem apresentar output no menu.
 *  
 */

#ifndef menu_H
#define menu_H

#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

/**
 * @brief Máximo de linhas por pagina no navegador. 
 */
#define MAX_LIN 20

/* @brief Apresentação do menu principal.
 *
 *  @return Void.
 */
void main_menu();


/* @brief Voltar atrás do menu.
 *
 *  @return Void.
 */
void voltar();


/* @brief Limpa o input e espera que o utilizador presse alguma tecla.
 *
 *  @return Void.
 */
void clearAndEnter();


/* @brief Apresenta resultado da Query2.
 *
 *  @param lst Lista de Strings.
 *  @return Void.
 */
void printQuery2(Lista lst);


/* @brief Apresenta resultado da Query3.
 *
 *  @param lst Lista de Strings.
 *  @param c Letra pela qual começam os códigos.
 *  @return Void.
 */
void printQuery3(Lista lst,char c);


/* @brief Aprensenta um navegador.
 *
 *  @param lst Lista de Strings.
 *  @return Void.
 */
void printLst(Lista lst);


/* @brief Aprensenta resultado da query 6.
 *
 *  @param p Estrutura que tem os dados necessários à resposta da query.
 *  @param time Tempo de resolução da query.
 *  @return Void.
 */
void printPar(Par p,float time);


/* @brief Aprensenta resultado da query 7.
 *
 *  @param tbl Estrutura que tem os dados necessários à resposta da query.
 *  @param time Tempo de resolução da query.
 *  @return Void.
 */
void printQuery7(Tabela tbl,float time);


/* @brief Aprensenta resultado da query 8.
 *
 *  @param p Estrutura que tem os dados necessários à resposta da query.
 *  @param mes1 Mes inicial.
 *  @param mes2 Mes final.
 *  @param time Tempo de resolução da query.
 *  @return Void.
 */
void printQuery8(Profit p,int mes1,int mes2,float time);


/* @brief Aprensenta resultado da query 9.
 *
 *  @param l Estrutura que tem os dados necessários à resposta da query.
 *  @param time Tempo de resolução da query.
 *  @return Void.
 */
void printQuery9(LstBuyers l,float time);


/* @brief Aprensenta resultado da query 10.
 *
 *  @param lst Lista de strings.
 *  @param tempo Tempo de resolução da query.
 *  @return Void.
 */
void printLst10(Lista lst,float tempo);


/* @brief Aprensenta resultado da query 9.
 *
 *  @param s Estrutura que tem os dados necessários à resposta da query.
 *  @param x Limite do top.
 *  @param time Tempo de resolução da query.
 *  @return Void.
 */
void printQuery11(SelledProd* s,int x,float time);


/* @brief Aprensenta resultado da query 12.
 *
 *  @param l Lista.
 *  @param time Tempo de resolução da query.
 *  @return Void.
 */
void printQuery12(GList* l,float time);


/* @brief Aprensenta resultado da query 13.
 *
 *  @param f Estrutura que tem os dados necessários à resposta da query.
 *  @return Void.
 */
void printQuery13(FileInfo f);

#endif