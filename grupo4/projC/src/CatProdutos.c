#include "../include/CatProdutos.h"
//Estrutura de dados Catalogo de produtos
struct cat_produtos{
	GTree* produtos[Produtos];
};

////Elimina a chave de um produto
void freeKeyProduct(gpointer data){
	char* prodID=(char*)data;
	free(prodID);
}

Cat_Produtos inicializa_CatProds(){
	Cat_Produtos cp=(Cat_Produtos)malloc(sizeof(struct cat_produtos));
 	for (int i=0;i<Produtos;i++)
  		cp->produtos[i]=g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)freeKeyProduct,NULL);
 	return cp;
}

Cat_Produtos insereProd(Cat_Produtos cp,Produto p){
 	int i=getIndexP(p);
 	char* code=getProduto(p);
 	g_tree_insert(cp->produtos[i],code,code); 
 	return cp;
}

GTree* getTree(Cat_Produtos cp,int index){
 	return cp->produtos[index];
}

gboolean existeProd (Cat_Produtos cp,Produto p){
 	int i=getIndexP(p);
 	char* code=getProduto(p);
 	if ((g_tree_lookup(cp->produtos[i],code))){free(code);return TRUE;}
 	free(code);
 	return FALSE;
}

int totalProd (Cat_Produtos cp){ 
 	int total=0;
 	for(int i=0;i<26;i++)
 		total+=g_tree_nnodes(cp->produtos[i]);

 	return total;
}

gboolean funcTravessiaQuerie2(gpointer key, gpointer value,gpointer data) {
 	insereLista(data,value);
	return FALSE;
}

Lista produtosLetra(Cat_Produtos cp,Lista lst ,char letter){
	int i=letter-'A';
 	g_tree_foreach(cp->produtos[i],(GTraverseFunc)funcTravessiaQuerie2,&lst);
	return lst;
}

void removeCatProd (Cat_Produtos cp){
	for(int i=0;i<Produtos;i++)
 		g_tree_destroy(cp->produtos[i]);  
	free(cp);
}


