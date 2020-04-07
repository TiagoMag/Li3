#ifndef Navegador_H
#define Navegador_H

#include <glib.h>
#include <stdio.h>

#define MaxElem 20

typedef struct lst *Lista;
typedef struct pagina *Pagina;

Lista inicializa_lista();
void removeLst(Lista lst);
void insereLista(gpointer lst,gpointer value);
Pagina initPagina();
Pagina getPageSeguinte(Lista lst,int sp);
int paginasTotal(Lista lst);
char* getString(Pagina pg,int index);
int sizeLst(Lista lst);
int sizeLstPage(Pagina p);
char* getStringLst(Lista lst,int index);
void removePagina(Pagina p);



#endif