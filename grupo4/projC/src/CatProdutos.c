#include "headers/CatProdutos.h"

struct cat_produtos{
 GTree* produtos[Produtos];
};

Cat_Produtos inicializa_CatProds(){
 Cat_Produtos cp=(Cat_Produtos)malloc(sizeof(struct cat_produtos));
 for (int i=0;i<Produtos;i++)
  cp->produtos[i]=g_tree_new((GCompareFunc)g_ascii_strcasecmp);
 return cp;
}

Cat_Produtos insereProd(Cat_Produtos cp,Produto p){
 int i=getIndexP(p);
 g_tree_insert(cp->produtos[i],getProduto(p),getProduto(p)); 
 return cp;
}

GTree* getTree(Cat_Produtos cp,int index){
 return cp->produtos[index];
}

gboolean existeProd (Cat_Produtos cp,Produto p){
 int i=getIndexP(p);
 if ((g_tree_lookup(cp->produtos[i],getProduto(p)))==NULL) return FALSE;
 return TRUE;
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


