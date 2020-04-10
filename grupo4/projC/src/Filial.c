#include "../include/Filial.h"

struct filial{
  GHashTable* produtos;
  GHashTable* clientes;
};

struct infoCli{
  GHashTable* prods;
  GHashTable* produtos[MES];
};

struct infoProd{
  gboolean modoCompra[2];//0->N 1->P
  int qnt;
};

void freeKeyProductFil(gpointer data){
  char* prodID=(char*)data;
  free(prodID);
}

void freeKeyClientFil(gpointer data){
  char* clientID=(char*)data;
  free(clientID);
}

void freeGasto(gpointer data){
  g_free(data);
 // printf("AHAH%d",i);

}

InfoProd inicializa_InfoProd(){
  InfoProd ip=(InfoProd)malloc(sizeof(struct infoProd));
 
  for(int i=0;i<2;i++)
    ip->modoCompra[i]=FALSE;
 
  ip->qnt=0;

  return ip;
}
int i=0;
void removeInfoProd(gpointer data){
  InfoProd ip=(InfoProd)data;
free(ip);
 //printf("AHAH%d\n",i++);
}

void removeInfoCli(gpointer data){
 
  InfoCli ic=(InfoCli) data;
  g_hash_table_destroy(ic->prods);
 
   for(int i=0;i<MES;i++)
     g_hash_table_destroy(ic->produtos[i]);

   free(ic);
}

InfoCli inicializa_InfoCli(){
  InfoCli ic=(InfoCli)malloc(sizeof(struct infoCli));
  //ic->prods=g_hash_table_new(g_str_hash, g_str_equal);
  //for(int i=0;i<MES;i++)
   // ic->produtos[i]=g_hash_table_new(g_str_hash, g_str_equal);
  ic->prods=g_hash_table_new_full(g_str_hash, g_str_equal,freeKeyProductFil,freeGasto);
  for(int i=0;i<MES;i++){
   ic->produtos[i]=g_hash_table_new_full(g_str_hash, g_str_equal,freeKeyProductFil,removeInfoProd);
  }
   
  return ic;
}

Filial inicializa_Filial(){
  Filial f=(Filial)malloc(sizeof(struct filial));
  f->produtos=g_hash_table_new_full(g_str_hash, g_str_equal,freeKeyProductFil,NULL);
  f->clientes=g_hash_table_new_full(g_str_hash, g_str_equal,freeKeyClientFil,removeInfoCli);
  
  return f;
}

void removeFilial(Filial f){
  g_hash_table_destroy(f->produtos); 
  g_hash_table_destroy(f->clientes);
  free(f);
}




InfoProd setInfoProd(InfoProd ip,int quant,char tipo){
   ip->qnt+=quant;
   if(tipo=='N') ip->modoCompra[0]=TRUE;
   else if(tipo=='P') ip->modoCompra[1]=TRUE;
  
  return ip;
}


Filial insereFilial(Filial f,Venda v){
  
  int mes=getMes(v)-1;
  int quant=getQntVenda(v);
   
  char* codigoProd=getProduto(getProdutoVenda(v));
  char* codigoCli=getCliente(getClienteVenda(v));

  float preco=getPrecoVenda(v)*(float)getQntVenda(v); 
  float* gasto=NULL;

  InfoCli ic=NULL;
  InfoProd ip=NULL;

   //Vê se produto já existe

  if (!g_hash_table_contains(f->produtos,codigoProd)){ 
     g_hash_table_insert(f->produtos,strdup(codigoProd),GINT_TO_POINTER(quant));
   }
   else{
     gpointer unidades_vendidas=g_hash_table_lookup(f->produtos,codigoProd);
     gint unidades=GPOINTER_TO_INT(unidades_vendidas)+quant;
     g_hash_table_insert(f->produtos,strdup(codigoProd),GINT_TO_POINTER(unidades));
   }
    
  ic=g_hash_table_lookup(f->clientes,codigoCli); 
  
  if(!ic){
  
    ic=inicializa_InfoCli();
    g_hash_table_insert(f->clientes,strdup(codigoCli),ic);
  
  }
  
   if (!g_hash_table_contains(ic->prods,codigoProd)){ 
    
    gasto=malloc(sizeof(float*));
    *gasto=preco;
    g_hash_table_insert(ic->prods,strdup(codigoProd),gasto);
   
   }
   else{
   
     gasto=(float*)g_hash_table_lookup(ic->prods,codigoProd);
     
     *gasto+=preco;
   }

  ip=g_hash_table_lookup(ic->produtos[mes],codigoProd);
 
  if(!ip){
   ip=inicializa_InfoProd();
   g_hash_table_insert(ic->produtos[mes],strdup(codigoProd),ip);
  }

  ip=setInfoProd(ip,quant,getTipo(v));

  free(codigoCli);
  free(codigoProd);
 

  return f;
  
}

gboolean existeProdFil(Filial f,char* codigo){
  return g_hash_table_contains(f->produtos,codigo);
}

gboolean existeCliFil(Filial f,char* codigo){
  return g_hash_table_contains(f->clientes,codigo);
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
  //percorre hashtable produtos e somas as suas vendas
  g_hash_table_foreach(ic->produtos[mes], (GHFunc)iterator,&total);

  return total;
}
//--Query 9

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


void removeAux9(Aux9 aux){
  free(aux->productID);
  aux->lst=NULL;
  free(aux);
}

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
  if(g_hash_table_lookup(f->produtos,productID)!=NULL){
    g_hash_table_foreach(f->clientes, (GHFunc)travessia,&aux);
  }
  removeAux9(aux);
  return lst; 
}

//-- Query 10

struct qntProds{
 char* prod;
 int qnt;
};

int getQntQP(QntProds qp){
  return(qp->qnt);
}

char* getCodeQP(QntProds qp){
  return(strdup(qp->prod));
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

void removeQntProds(gpointer data){
  QntProds qp=(QntProds)data;
  free(qp->prod);
  free(qp);

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
 
    g_hash_table_insert(ht,strdup(key),qp); //produto já existe atualiza quantidade
  
  }else{ 

    qp=setQntProds(qp,key,ip->qnt);
 
    g_hash_table_insert(ht,strdup(key),qp); //produtos ñ existe insere
  
  }
}

GHashTable* produtosQueMaisComprou(gpointer ht,Filial f,char* codigoCli,int mes){

  GHashTable* h=(GHashTable*)ht;

  InfoCli ic=g_hash_table_lookup(f->clientes,codigoCli); 

  g_hash_table_foreach(ic->produtos[mes],(GHFunc)travessiaQ10,h);

  return h;
}

//------------------Query11

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

void removeAux11(Aux11 aux){
  free(aux->productID);
  aux->f=NULL;
  free(aux);
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
 
 if(clientHasProduct((*aux)->f,key,(*aux)->productID)) 
  (*aux)->num_clients++;
 
}

int numberClients(Filial f,char* codeProduct){
  int num_clients=0;

  Aux11 aux=setAux11(codeProduct,num_clients,f);

  g_hash_table_foreach(f->clientes,(GHFunc)travessiaQ11,&aux);

  num_clients=(aux)->num_clients;

  removeAux11(aux);

  return num_clients;
}

int getUnidadesFilial (Filial f,char* prodID){

  int x=0;
  // int* unidades_vendidas=g_hash_table_lookup(f->produtos,prodID);
  gpointer unidades_vendidas=g_hash_table_lookup(f->produtos,prodID);

  if(unidades_vendidas==NULL) return 0;
  
  x=GPOINTER_TO_INT(unidades_vendidas);
 
  return x;
 }

//------------------------------------query 12
struct topProds{
 char* prod;
 float gasto;
};


float getGastoTop(TopProds tp){
  return(tp->gasto);
}

char* getCodeTop(TopProds tp){
  return (strdup(tp->prod));
}

TopProds initTopProds(){
  TopProds tp=(TopProds)malloc(sizeof(struct topProds));
  tp->prod=NULL;
  tp->gasto=0.0f;
  return tp;
}

void removeTP(gpointer data){
  TopProds tp=data;
  free(tp->prod);
  free(tp);

}

TopProds setTopProds(TopProds tp,char* prod,float gasto){
  tp->prod=strdup(prod);
  tp->gasto=gasto;
  return tp;
}

void travessiaQ12(gpointer key, gpointer value, gpointer data) {

  TopProds tp=initTopProds();

  GHashTable* ht=(GHashTable*) data;

  float* gasto= value;  

  if(g_hash_table_contains(ht,(char*)key)){

    tp=setTopProds(tp,key,tp->gasto+*gasto);
    
    g_hash_table_insert(ht,strdup(key),tp); //produto já existe atualiza quantidade
  
  }else{ 

    tp=setTopProds(tp,key,*gasto);
 
    g_hash_table_insert(ht,strdup(key),tp); //produtos ñ existe insere
  
  }
}

GHashTable* topProfitProducts(Filial f,gpointer ht,char* clientID){

  GHashTable* h=(GHashTable*)ht;

  InfoCli ic=g_hash_table_lookup(f->clientes,clientID); 

  g_hash_table_foreach(ic->prods,(GHFunc)travessiaQ12,h);

  return h;
}

