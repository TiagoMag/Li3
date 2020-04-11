#include "../../include/Cliente.h"
//Estrutura de um cliente
struct cliente{
	char* codigo;
};

//Alocação de memoria de um cliente
Cliente inicializa_Cliente(){
 	Cliente c=(Cliente)malloc(sizeof(struct cliente));
 	c->codigo=NULL;
 	return c;
}
//Criação/definição um cliente
Cliente criaCliente(Cliente c,char* codigo){
 	c->codigo=strdup(codigo);
 	return c;
}
//Obter codigo de um cliente
char* getCliente(Cliente c){
 	return strdup(c->codigo);
}
//Determinar index ao qual cliente irá pertencer no CatClientes
int getIndexC(Cliente c){
 	return (c->codigo[0]-'A');
}

//Verifica se um codigo de cliente é valido tendo em conta os parâmetros
gboolean validaCliente(Cliente c){
  	if (!isalpha(c->codigo[0])) return FALSE;
  	if (!(c->codigo[0] >='A' && c->codigo[0]<='Z')) return FALSE;
  	if (!(atoi(c->codigo+1)>=1000) && atoi(c->codigo+1)<=5000) return FALSE;
 	return TRUE;
}

//Desalocação na memória de um cliente
void removeCliente(Cliente c){
 	
 	free(c->codigo);
 	free(c);
}
