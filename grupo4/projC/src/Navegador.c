#include "../include/Navegador.h"

struct lst{
 GArray* lista;
};

struct pagina{ 	
 int size;  //nmr elementos da pagina
 GArray* lista; //Strings de uma pagina
};

void removeLst(Lista lst){
 g_array_free(lst->lista,FALSE);
 free(lst);
}

Lista inicializa_lista(){
 Lista lst=(Lista)malloc(sizeof(struct lst));
 lst->lista=g_array_new(FALSE, FALSE, sizeof(char*));
 return lst;
}

void insereLista(gpointer data,gpointer value){
 Lista *lst=data;
 g_array_append_val((*lst)->lista,value);
}


Pagina initPagina(){
 Pagina pag=(Pagina)malloc(sizeof(struct pagina));
 pag->size=0;
 pag->lista=g_array_new(FALSE, FALSE, sizeof(char*));
return pag;
}

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

int paginasTotal(Lista lst){
	int totalPages=(lst->lista->len/MaxElem);
	if(totalPages*MaxElem < lst->lista->len) totalPages++;
	return totalPages;
}

char* getString(Pagina pg,int index){  
	char* elem=g_array_index(pg->lista,char*,index);
	return elem;
}

char* getStringLst(Lista lst,int index){  
	char* elem=g_array_index(lst->lista,char*,index);
	return elem;
}

int sizeLst(Lista lst){

return lst->lista->len;

}


int sizeLstPage(Pagina p){

return p->size;

}