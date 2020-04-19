#include "../../include/Produto.h"

/* Estrutura de um produto. */
struct produto{
  char* codigo; /* String com o código do produto correspondente. */
};

/* Função que inicializa a estrutura de um produto. */
Produto inicializa_Prod(){
  Produto p=(Produto)malloc(sizeof(struct produto));
  p->codigo=NULL;
  return p;
}

/* Função que cria um Produto */
Produto criaProduto(Produto p,char* codigo){
  p->codigo=strdup(codigo);
  return p;
}

/* Função que retorna o código de um produto */
char* getProduto(Produto p){
  return strdup(p->codigo);
}

/* Função que retorna o índice do array do Catálogo de Produtos
de onde estará o Produto */
int getIndexP(Produto p){
  return(p->codigo[0]-'A');
}

/* Função que verifica se o código de um Produto
é válido. */
gboolean validaProd(Produto p){
  if (!isalpha(p->codigo[0]) && isalpha(p->codigo[0])) return FALSE;
  if (!(p->codigo[0]>='A' && p->codigo[0]<='Z' && p->codigo[1]>='A' && p->codigo[1]<='Z')) return FALSE;
  if (!(atoi(p->codigo+2)>=1000) && atoi(p->codigo+2)<=9999) return FALSE;
  return TRUE;
}

/* Função que libera a memória alocada pela estrutura
de um Produto */
void removeProduto(Produto p){	
  free(p->codigo);
  free(p);
}
