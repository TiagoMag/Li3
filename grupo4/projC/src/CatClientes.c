#include "../include/CatClientes.h"

//Estrutura de dados do catalogo de clientes
struct cat_clientes{
	GTree* clientes[Clientes];
	int num_linhas_lidas;
	char* filename;
	float tempo_leitura;
};

//Elimina a chave de um cliente
void freeKeyClient(gpointer data){
	char* clienteID=(char*)data;
	free(clienteID);
}
//Alocação de memoria da estrutura de dados para sua inicialização
Cat_Clientes inicializa_CatClientes(){
	Cat_Clientes cc=(Cat_Clientes)malloc(sizeof(struct cat_clientes));
	cc->num_linhas_lidas=0;
	cc->filename=NULL;
	cc->tempo_leitura=0.0f;
	for (int i=0;i<Clientes;i++)
  		cc->clientes[i]=g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)freeKeyClient,NULL); 	
	return cc;
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
 	free(cc->filename);
 	for(int i=0;i<Clientes;i++)
  		g_tree_destroy(cc->clientes[i]);  
 	free(cc);
}

//Retorna a árvore de clientes correspondente a uma determinada letra



gboolean cloneTreeClientes(gpointer key, gpointer value,gpointer data) {
 	GTree* clone=(GTree*) data;
 	g_tree_insert(clone,strdup((char*)key),strdup((char*)value));
	return FALSE;
}

GTree* getTreeC(Cat_Clientes cc,int index){
	GTree* clone=g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)freeKeyClient,(GDestroyNotify)freeKeyClient);
    g_tree_foreach(cc->clientes[index],(GTraverseFunc)cloneTreeClientes,clone);
	return clone;
}

Cat_Clientes setInfoFileClientes(Cat_Clientes cc,char* filename,int num_linhas_lidas,float tempo){
  cc->num_linhas_lidas=num_linhas_lidas;
  cc->tempo_leitura=tempo;
  cc->filename=strdup(filename);
  return cc;
}

int getNumLinhasLidasClientes(Cat_Clientes cc){
	return(cc->num_linhas_lidas);
}

float getTempoLeituraClientes(Cat_Clientes cc){
	return(cc->tempo_leitura);
}

char* getFileNameClientes(Cat_Clientes cc){
	return strdup(cc->filename);
}