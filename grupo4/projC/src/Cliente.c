#include "headers/Cliente.h"

struct cliente{
 char* codigo;
};

Cliente inicializa_Cliente(){
 Cliente c=(Cliente)malloc(sizeof(struct cliente));
 c->codigo=NULL;
 return c;
}

Cliente criaCliente(Cliente c,char* codigo){
 c->codigo=strdup(codigo);
 return c;
}

char* getCliente(Cliente c){
 return(c->codigo);
}

int getIndexC(Cliente c){
 return (c->codigo[0]-'A');
}

gboolean validaCliente(Cliente c){
  if (!isalpha(c->codigo[0])) return FALSE;
  if (!(c->codigo[0] >='A' && c->codigo[0]<='Z')) return FALSE;
  if (!(atoi(c->codigo+1)>=1000) && atoi(c->codigo+1)<=5000) return FALSE;
 return TRUE;
}

void removeCliente(Cliente c){
 free(c->codigo);
 free(c);
}
