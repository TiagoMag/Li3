#include "../include/Filial.h"

struct filial{
  GHashTable* produtos;
  GHashTable* clientes;
};

struct infoCli{
  GHashTable* produtos[MES];
};

struct infoProd{
 gboolean modoCompra[2];//0->N 1->P
 float gasto;
 int qnt;
};

InfoProd inicializa_InfoProd(){
  InfoProd ip=(InfoProd)malloc(sizeof(struct infoProd));
  for(int i=0;i<2;i++)
    ip->modoCompra[i]=FALSE;
  ip->gasto=0.0;
  ip->qnt=0;

  return ip;
}

InfoCli inicializa_InfoCli(){
  InfoCli ic=(InfoCli)malloc(sizeof(struct infoCli));
  for(int i=0;i<MES;i++)
  	ic->produtos[i]=g_hash_table_new(g_str_hash, g_str_equal);
  
  return ic;
}

Filial inicializa_Filial(){
   Filial f=(Filial)malloc(sizeof(struct filial));
   f->produtos=g_hash_table_new(g_str_hash, g_str_equal);
   f->clientes=g_hash_table_new(g_str_hash, g_str_equal);

   return f;
}


Filial insereFilial(Filial f,Venda v){
  
   int mes=getMes(v)-1;
   int quant=getQntVenda(v);
   
   char* codigoProd=getProduto(getProdutoVenda(v));
   char* codigoCli=getCliente(getClienteVenda(v));

   float preco=getPrecoVenda(v)*(float)getQntVenda(v);
   
   int* unidades_vendidas=(int*)malloc(sizeof(int*));

   *unidades_vendidas=quant;

   //Vê se produto já existe
   if (!g_hash_table_contains(f->produtos,codigoProd)) 
    g_hash_table_insert(f->produtos,codigoProd,unidades_vendidas);
   else{
    unidades_vendidas=g_hash_table_lookup(f->produtos,codigoProd);
    *unidades_vendidas+=quant;
    g_hash_table_insert(f->produtos,codigoProd,unidades_vendidas);
    
   }
  InfoCli ic=g_hash_table_lookup(f->clientes,codigoCli); 
  
  if(!ic)
    ic=inicializa_InfoCli();
   
  g_hash_table_insert(f->clientes,codigoCli,ic);
   
  InfoProd ip=g_hash_table_lookup(ic->produtos[mes],codigoProd);
   
  if(!ip)
   ip=inicializa_InfoProd();
   
  ip->gasto+=preco;
  ip->qnt+=quant;
  if(getTipo(v)=='N') ip->modoCompra[0]=TRUE;
  if(getTipo(v)=='P') ip->modoCompra[1]=TRUE;
 
  g_hash_table_insert(ic->produtos[mes],codigoProd,ip);
 
  return f;
}

gboolean existeProdFil(Filial f,char* codigo){
 return g_hash_table_contains(f->produtos,codigo);
}

gboolean existeCliFil(Filial f,char* codigo){
 return g_hash_table_contains(f->clientes,codigo);
}


void removeFilial(Filial f){
 g_hash_table_destroy(f->produtos);
 g_hash_table_destroy(f->clientes); 
}

void iterator(gpointer key, gpointer value, gpointer data) {

InfoProd ip=(InfoProd)value;

int x=ip->qnt;

int* l=data;

*l+=x;

}

int produtosCompradosCliente(Filial fil,int mes,char* code){

int total=0;

//procura cliente
InfoCli ic=g_hash_table_lookup(fil->clientes,code);
//percorre hashtable produtos e somas as suas vendar
g_hash_table_foreach(ic->produtos[mes], (GHFunc)iterator,&total);





return total;

}


int mapToIndex(char tipo){

 if (tipo=='N') return 0;
 if (tipo=='P') return 1;
 return -1;
}

gboolean temProduto(InfoCli ic,char* productID,char tipo){
InfoProd ip;

for(int i=0;i<12;i++){
  if (g_hash_table_contains(ic->produtos[i],productID)){
   ip=g_hash_table_lookup(ic->produtos[i],productID);
   if(ip->modoCompra[mapToIndex(tipo)]) return TRUE;
  }
}


return FALSE;

}


typedef struct aux9{
 char* productID;
 char tipo;
 Lista lst;
}*Aux9;


Aux9 setAux9(char* productID,char tipo,Lista lst){
  Aux9 aux=(Aux9)malloc(sizeof(struct aux9));
  aux->lst=lst;
  aux->tipo=tipo;
  aux->productID=strdup(productID);
  return aux;
}


void travessia(gpointer key, gpointer value, gpointer data) {

InfoCli ic=(InfoCli) value;

Aux9 *aux=data;

if(temProduto(ic,(*aux)->productID,(*aux)->tipo))
  insereLista(&(*aux)->lst,key);

}


Lista buyers (Filial f,Lista lst,char* productID,char tipo){ 

 Aux9 aux=setAux9(productID,tipo,lst);

 printf("MODO:%c\n",tipo );
 g_hash_table_foreach(f->clientes, (GHFunc)travessia,&aux);
 

 return lst; 

}








struct qntProds{
 char* prod;
 int qnt;
};


int getQntQP(QntProds qp){

return(qp->qnt);
}

char* getCodeQP(QntProds qp){

return(qp->prod);
}

QntProds initQntProds(){
QntProds qp=(QntProds)malloc(sizeof(struct qntProds));
qp->prod=NULL;
qp->qnt=0;
return qp;
}

QntProds setQntProds(QntProds qp,char* prod,int qnt){
qp->prod=strdup(prod);
qp->qnt=qnt;
return qp;
}


QntProds updateInfo(GHashTable* ht,gpointer value,gpointer key){

InfoProd ip=(InfoProd) value;
QntProds qp=g_hash_table_lookup(ht,key);


qp=setQntProds(qp,key,qp->qnt+ip->qnt);

return qp;


}

void travessiaQ10(gpointer key, gpointer value, gpointer data) {

QntProds qp=initQntProds();

GHashTable* ht=(GHashTable*) data;

InfoProd ip=(InfoProd) value;

if(g_hash_table_contains(ht,(char*)key)){
 
  qp=updateInfo(ht,value,key);
 
  g_hash_table_replace(ht,key,qp); //produto já existe atualiza quantidade
  
}else{ 

  qp=setQntProds(qp,key,ip->qnt);
 
  g_hash_table_insert(ht,key,qp); //produtos ñ existe inseres
  
}
}

GHashTable* produtosQueMaisComprou(gpointer ht,Filial f,char* codigoCli,int mes){

GHashTable* h=(GHashTable*)ht;

InfoCli ic=g_hash_table_lookup(f->clientes,codigoCli); 

g_hash_table_foreach(ic->produtos[mes],(GHFunc)travessiaQ10,h);

return h;
}

//------------------


typedef struct auxNumClients{
 int num_clients;
 char* productID;
 Filial f;
}*Aux11;

Aux11 setAux11(char* productID,int num_clients,Filial f){
  Aux11 aux=(Aux11)malloc(sizeof(struct auxNumClients));
  aux->num_clients=num_clients;
  aux->productID=strdup(productID);
  aux->f=f;
  return aux;
}


gboolean clientHasProduct(Filial fil,char* clientID,char* productID){

 
 InfoCli ic=g_hash_table_lookup(fil->clientes,clientID);
 if(!ic) return FALSE;
 
 for(int i=0;i<12;i++){
  if(g_hash_table_contains(ic->produtos[i],productID)) {return TRUE;break;}
 
 }

return FALSE;

}

void travessiaQ11(gpointer key, gpointer value, gpointer data) {
 
 Aux11 *aux=data;
 
 if(clientHasProduct((*aux)->f,key,(*aux)->productID)) (*aux)->num_clients++;
 
}


int numberClients(Filial f,char* codeProduct){
int num_clients=0;

Aux11 aux=setAux11(codeProduct,num_clients,f);


g_hash_table_foreach(f->clientes,(GHFunc)travessiaQ11,&aux);

num_clients=(aux)->num_clients;

free(aux);

return num_clients;
}

int getUnidadesFilial (Filial f,char* prodID){

  int x=0;
  int* unidades_vendidas=g_hash_table_lookup(f->produtos,prodID);
  if(unidades_vendidas==NULL) return 0;
  
  x=*unidades_vendidas;
 printf("unidades_vendidas:%d\n",x);
  return x;
 

}