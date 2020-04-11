#include "../../include/CatProdutos.h"
//Estrutura de dados Catalogo de produtos
struct cat_produtos{
	GTree* produtos[Produtos];
	int num_linhas_lidas;
	char* filename;
	float tempo_leitura;
};

//Elimina a chave de um produto
void freeKeyProduct(gpointer data){
	char* prodID=(char*)data;
	free(prodID);
}

//Inicializa a estrutura de dados
Cat_Produtos inicializa_CatProds(){
	Cat_Produtos cp=(Cat_Produtos)malloc(sizeof(struct cat_produtos));
 	cp->num_linhas_lidas=0;
	cp->filename=NULL;
	cp->tempo_leitura=0.0f;
 	for (int i=0;i<Produtos;i++)
  		cp->produtos[i]=g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)freeKeyProduct,NULL);
 	return cp;
}

//Insere um Produto no Catalogo
Cat_Produtos insereProd(Cat_Produtos cp,Produto p){
 	int i=getIndexP(p);
 	char* code=getProduto(p);
 	g_tree_insert(cp->produtos[i],code,code); 
 	return cp;
}


//Retorna a arvore de produtos correspondente a uma determinada letra


gboolean cloneTreeProdutos(gpointer key, gpointer value,gpointer data) {
 	GTree* clone=(GTree*) data;
 	g_tree_insert(clone,strdup(key),strdup(value));
	return FALSE;
}

GTree* getTree(Cat_Produtos cp,int index){
 	GTree* clone=g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)freeKeyProduct,(GDestroyNotify)freeKeyProduct);
    g_tree_foreach(cp->produtos[index],(GTraverseFunc)cloneTreeProdutos,clone);
 	return clone;
}

//Verifica a existencia de um produto no Catalogo
gboolean existeProd (Cat_Produtos cp,Produto p){
 	int i=getIndexP(p);
 	char* code=getProduto(p);
 	if ((g_tree_lookup(cp->produtos[i],code))){free(code);return TRUE;}
 	free(code);
 	return FALSE;
}
//Determina o total de produtos existente no catalogo
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

//Produtos de uma determinada letra (dispostos em arvore) são convertidos numa Lista
Lista produtosLetra(Cat_Produtos cp,Lista lst ,char letter){
	int i=letter-'A';
 	g_tree_foreach(cp->produtos[i],(GTraverseFunc)funcTravessiaQuerie2,&lst);
	return lst;
}
//Desalocação da estrutura de dados
void removeCatProd (Cat_Produtos cp){
	free(cp->filename);
	for(int i=0;i<Produtos;i++)
 		g_tree_destroy(cp->produtos[i]);  
	free(cp);
}

Cat_Produtos setInfoFileProdutos(Cat_Produtos cp,char* filename,int num_linhas_lidas,float tempo){
    cp->num_linhas_lidas=num_linhas_lidas;
    cp->tempo_leitura=tempo;
    cp->filename=strdup(filename);
    return cp;
}

int getNumLinhasLidasProds(Cat_Produtos cp){
	return(cp->num_linhas_lidas);
}

float getTempoLeituraProds(Cat_Produtos cp){
	return(cp->tempo_leitura);
}

char* getFileNameProds(Cat_Produtos cp){
	return strdup(cp->filename);
}