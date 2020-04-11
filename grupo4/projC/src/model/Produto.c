#include "../../include/Produto.h"

struct produto{
	char* codigo;
};

Produto inicializa_Prod(){
	Produto p=(Produto)malloc(sizeof(struct produto));
	p->codigo=NULL;
	return p;
}

Produto criaProduto(Produto p,char* codigo){
	p->codigo=strdup(codigo);
	return p;
}

char* getProduto(Produto p){
	return strdup(p->codigo);
}

int getIndexP(Produto p){
	return(p->codigo[0]-'A');
}

gboolean validaProd(Produto p){
	if (!isalpha(p->codigo[0]) && isalpha(p->codigo[0])) return FALSE;
 	if (!(p->codigo[0]>='A' && p->codigo[0]<='Z' && p->codigo[1]>='A' && p->codigo[1]<='Z')) return FALSE;
 	if (!(atoi(p->codigo+2)>=1000) && atoi(p->codigo+2)<=9999) return FALSE;
 	return TRUE;
}

void removeProduto(Produto p){
	
 	free(p->codigo);
 	free(p);
}
