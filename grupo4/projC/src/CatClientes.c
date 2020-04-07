#include "../include/CatClientes.h"

struct cat_clientes{
	GTree* clientes[Clientes];
};

void freeKeyClient(gpointer data){
	char* clienteID=(char*)data;
	free(clienteID);
}

Cat_Clientes inicializa_CatClientes(){
	Cat_Clientes ct=(Cat_Clientes)malloc(sizeof(struct cat_clientes));
	for (int i=0;i<Clientes;i++)
  		ct->clientes[i]=g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)freeKeyClient,NULL); 	
	return ct;
}


Cat_Clientes insereCliente(Cat_Clientes cc,Cliente c){
	int i=getIndexC(c);
	char* code=getCliente(c);
 	g_tree_insert(cc->clientes[i],code,code);
 	return cc;
}

gboolean existeCliente(Cat_Clientes cp, Cliente c){
	int i=getIndexC(c);
	char* code=getCliente(c);
 	if ((g_tree_lookup (cp->clientes[i],code))) {free(code);return TRUE;}
 	free(code);	
 	return FALSE;
}

int totalClientes(Cat_Clientes cc){
	int total=0;
 	for(int i=0;i<26;i++)
  		total+=g_tree_nnodes(cc->clientes[i]);
 	return total;
}

void removeCatCliente(Cat_Clientes cc){
 	for(int i=0;i<Clientes;i++)
  		g_tree_destroy(cc->clientes[i]);  
 	free(cc);
}

GTree* getTreeC(Cat_Clientes cc,int index){
	return cc->clientes[index];
}
