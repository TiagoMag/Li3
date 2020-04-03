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
   
   //Vê se produto já existe
   if (!g_hash_table_contains(f->produtos,codigoProd)) 
    g_hash_table_insert(f->produtos,codigoProd,codigoProd);
   
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
puts("4");
QntProds qp=initQntProds();
puts("5");
GHashTable* ht=(GHashTable*) data;
printf("SIZE3:%d\n",g_hash_table_size(ht));
InfoProd ip=(InfoProd) value;
puts("6");
printf("KEY:%s\n",(char*)key);
if(g_hash_table_contains(ht,(char*)key)){
  puts("7");
  qp=updateInfo(ht,value,key);
  puts("8");
  g_hash_table_replace(ht,key,qp); //produto já existe atualiza quantidade
  puts("9");
}else{ 
  puts("10");
  qp=setQntProds(qp,key,ip->qnt);
  puts("11");
  g_hash_table_insert(ht,key,qp); //produtos ñ existe inseres
  puts("12");
}
}

GHashTable* produtosQueMaisComprou(gpointer ht,Filial f,char* codigoCli,int mes){
puts("1");
GHashTable* h=(GHashTable*)ht;
printf("SIZE2:%d\n",g_hash_table_size(h));
InfoCli ic=g_hash_table_lookup(f->clientes,codigoCli); 
puts("2");
g_hash_table_foreach(ic->produtos[mes],(GHFunc)travessiaQ10,h);
puts("3");
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