#include "../../include/Navegador.h"

/* Estrutura de uma Lista */
struct lst{
  GArray* lista; // Array dinamico de strings
};

/* Estrutua de uma pagina */
struct pagina{ 	
  int size;  //nmr elementos da pagina
  GArray* lista; //Strings de uma pagina
};

/* Libera memoria alocada por uma lista */
void removeLst(Lista lst){
  char* elem=NULL;
  for(int i=0;i<lst->lista->len;i++){
  	elem=g_array_index(lst->lista,char*,i);
  	free(elem);
  }
  g_array_free(lst->lista,TRUE);
  free(lst);
}

/* Inicializa a estrutura lista */
Lista inicializa_lista(){
  Lista lst=(Lista)malloc(sizeof(struct lst));
  lst->lista=g_array_new(FALSE, FALSE, sizeof(char*));
  return lst;
}

/* Insere uma elemento numa Lista */
void insereLista(gpointer data,gpointer value){
  Lista *lst=data;
  char* elem=strdup((char*)value);
  g_array_append_val((*lst)->lista,elem);
}

/* Inicializa uma página */
Pagina initPagina(){
  Pagina pag=(Pagina)malloc(sizeof(struct pagina));
  pag->size=0;
  pag->lista=g_array_new(FALSE, FALSE, sizeof(char*));
  return pag;
}

/* Retorna uma determinada pagina */
Pagina getPageSeguinte(Lista lst,int sp){
  int j=sp;
  Pagina pag=initPagina();
  int l=0;
  for(int i=0;i<MaxElem;i++,j++){
  	if(j>=lst->lista->len) break;
  	g_array_append_val(pag->lista,g_array_index(lst->lista,char*,j));
  	l++;
}
  pag->size=l;
  return pag;
}

/* Retorna o numero total de paginas */
int paginasTotal(Lista lst){
  int totalPages=(lst->lista->len/MaxElem);
  if(totalPages*MaxElem < lst->lista->len) totalPages++;
  return totalPages;
}

/* Retorna a String de um indice de uma Pagina */
char* getString(Pagina pg,int index){  
  char* elem=g_array_index(pg->lista,char*,index);
  return elem;
}

/* Retorna a String de um indice de uma lista */
char* getStringLst(Lista lst,int index){  
  char* elem=g_array_index(lst->lista,char*,index);
  return elem;
}

/* Retorna o tamanho de uma lista */
int sizeLst(Lista lst){
  if (lst==NULL) return 0; 
  return lst->lista->len;
}

/* Retorna o tamanho de uma pagina */
int sizeLstPage(Pagina p){
 return p->size;
}

/* Libera a memoria alocada por uma esturuta pagina */
void removePagina(Pagina p){
  g_array_free(p->lista,TRUE);
  free(p);
}
