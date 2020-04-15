/**
 * @file Navegador.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declração de funções e macros que permitem manipular Listas com string's e Navegadores.
 *  
 */

#ifndef Navegador_H
#define Navegador_H

#include <glib.h>


/**
 * @brief Número de elementos por página
 */
#define MaxElem 20


/**
 * @brief Declaração do tipo opaco Lista. 
 */
typedef struct lst *Lista;


/**
 * @brief Declaração do tipo opaco Pagina. 
 */
typedef struct pagina *Pagina;



/* @brief Aloca memória para a criação de uma estrutura Lista.
 *
 *  @param 
 *
 *  @return Lista.
 */
Lista inicializa_lista();


/* @brief Remove a estrutura Lista, libertando memória.
 *
 *  @param Lista a ser removida
 *
 *  @return void.
 */
void removeLst(Lista lst);


/* @brief Inser um elemento (value) na lista.
 *
 *  @param gpointer da lista onde o valor é inserido, gpointer do valor a ser inserido
 *
 *  @return void.
 */
void insereLista(gpointer lst,gpointer value);


/* @brief Aloca memória para a criação de uma estrutura Pagina.
 *
 *  @param 
 *
 *  @return Pagina.
 */
Pagina initPagina();


/* @brief Retorna uma determinada pagina.
 *
 *  @param Lista, int com o numero da pagina
 *
 *  @return Pagina.
 */
Pagina getPageSeguinte(Lista lst,int sp);


/* @brief Determina o numero total de paginas .
 *
 *  @param Lista
 *
 *  @return int.
 */
int paginasTotal(Lista lst);


/* @brief Retorna a String de um index de uma pagina.
 *
 *  @param Pagina, int com o index da pagina
 *
 *  @return char*.
 */
char* getString(Pagina pg,int index);


/* @brief Indica o tamanho de uma lista.
 *
 *  @param Lista
 *
 *  @return int.
 */
int sizeLst(Lista lst);


/* @brief Retorna o tamanho de uma pagina.
 *
 *  @param Pagina
 *
 *  @return int.
 */
int sizeLstPage(Pagina p);



/* @brief Retorna a String de um indice de uma lista.
 *
 *  @param Lista, int com o indice da lista
 *
 *  @return char*.
 */
char* getStringLst(Lista lst,int index);


/* @brief Remove a estrutura Pagina, libertando memória.
 *
 *  @param Pagina
 *
 *  @return void.
 */
void removePagina(Pagina p);


#endif