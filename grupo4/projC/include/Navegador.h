#ifndef Navegador_H
#define Navegador_H

#include <glib.h>

#define MaxElem 20

typedef struct lst *Lista;
typedef struct pagina *Pagina;

Lista inicializa_lista();
/* @brief Aloca memória para a criação de uma estrutura Lista.
 *
 *  @param 
 *
 *  @return Lista.
 */


void removeLst(Lista lst);
/* @brief Remove a estrutura Lista, libertando memória.
 *
 *  @param Lista a ser removida
 *
 *  @return void.
 */


void insereLista(gpointer lst,gpointer value);
/* @brief Inser um elemento (value) na lista.
 *
 *  @param gpointer da lista onde o valor é inserido, gpointer do valor a ser inserido
 *
 *  @return void.
 */


Pagina initPagina();
/* @brief Aloca memória para a criação de uma estrutura Pagina.
 *
 *  @param 
 *
 *  @return Pagina.
 */


Pagina getPageSeguinte(Lista lst,int sp);
/* @brief Retorna uma determinada pagina.
 *
 *  @param Lista, int com o numero da pagina
 *
 *  @return Pagina.
 */


int paginasTotal(Lista lst);
/* @brief Determina o numero total de paginas .
 *
 *  @param Lista
 *
 *  @return int.
 */


char* getString(Pagina pg,int index);
/* @brief Retorna a String de um index de uma pagina.
 *
 *  @param Pagina, int com o index da pagina
 *
 *  @return char*.
 */


int sizeLst(Lista lst);
/* @brief Indica o tamanho de uma lista.
 *
 *  @param Lista
 *
 *  @return int.
 */


int sizeLstPage(Pagina p);
/* @brief Retorna o tamanho de uma pagina.
 *
 *  @param Pagina
 *
 *  @return int.
 */


char* getStringLst(Lista lst,int index);
/* @brief Retorna a String de um indice de uma lista.
 *
 *  @param Lista, int com o indice da lista
 *
 *  @return char*.
 */


void removePagina(Pagina p);
/* @brief Remove a estrutura Pagina, libertando memória.
 *
 *  @param Pagina
 *
 *  @return void.
 */


#endif