#include "../include/CatClientes.h"

//Estrutura de dados do catalogo de clientes
struct cat_clientes{
	GTree* clientes[Clientes];
};

//Elimina a chave de um cliente
void freeKeyClient(gpointer data){
	char* clienteID=(char*)data;
	free(clienteID);
}
//Alocação de memoria da estrutura de dados para sua inicialização
Cat_Clientes inicializa_CatClientes(){
	Cat_Clientes ct=(Cat_Clientes)malloc(sizeof(struct cat_clientes));
	for (int i=0;i<Clientes;i++)
  		ct->clientes[i]=g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)freeKeyClient,NULL); 	
	return ct;
}

//Insere um cliente no catalogo de clientes
Cat_Clientes insereCliente(Cat_Clientes cc,Cliente c){
	int i=getIndexC(c);
	char* code=getCliente(c);
 	g_tree_insert(cc->clientes[i],code,code);
 	return cc;
}
//Verifica a existencia de um cliente no catalogo de clientes
gboolean existeCliente(Cat_Clientes cp, Cliente c){
	int i=getIndexC(c);
	char* code=getCliente(c);
 	if ((g_tree_lookup (cp->clientes[i],code))) {free(code);return TRUE;}
 	free(code);	
 	return FALSE;
}
//Determina o numero total de clientes existentes no catalogo
int totalClientes(Cat_Clientes cc){
	int total=0;
 	for(int i=0;i<26;i++)
  		total+=g_tree_nnodes(cc->clientes[i]);
 	return total;
}
//Desalocação de memória da estrutura de dados
void removeCatCliente(Cat_Clientes cc){
 	for(int i=0;i<Clientes;i++)
  		g_tree_destroy(cc->clientes[i]);  
 	free(cc);
}
//Retorna a árvore correspondente a um determinado cliente a partir da sua chave
GTree* getTreeC(Cat_Clientes cc,int index){
	return cc->clientes[index];
}
