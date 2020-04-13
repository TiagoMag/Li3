#include "../../include/Queries.h"

/*
 * Query 2
 */

Lista produtosComecadoPelaLetra(Cat_Produtos cp,Lista lst,char letter){
 
  lst=produtosLetra(cp,lst,letter);

  return lst;
}

/*
 * Query 3
 */

//Passar int para string

char* intToString(int x){
  int length = snprintf( NULL, 0, "%d", x );
  char* str = malloc( length + 1 );
  snprintf( str, length + 1, "%d", x );
  return str;
}

//Passar Float para string

char* floatToString(float y){
  int length = snprintf( NULL, 0, "%f", y );
  char* str = malloc( length + 1 );
  snprintf( str, length + 1, "%f", y );
  return str;
}

Lista productSalesAndProfit(Faturacao f,Lista lst,char* productID,int month){

	Data d;

	d=getData(f,productID,'N',month);
	
    
  int x=getQntFat(d);
  float y=getPrecoFat(d);
    
  char* xx=intToString(x);
  char* yy=floatToString(y);
    
  insereLista(&lst,xx);
  insereLista(&lst,yy);
    
  free(yy);
  free(xx);
	free(d);
	
  d=getData(f,productID,'P',month);
    
  x=getQntFat(d);
  y=getPrecoFat(d);
    
  xx=intToString(x);
  yy=floatToString(y);

  insereLista(&lst,xx);
  insereLista(&lst,yy);
    
  free(yy);
  free(xx);
  free(d);

  for(int j=0;j<FILIAL;j++){
    for(int i=0;i<2;i++){
    
      if(i==0) d=getDataFilial(f,productID,'P',month,j);
      else if(i==1) d=getDataFilial(f,productID,'N',month,j);
   
      x=getQntFat(d);
      y=getPrecoFat(d);
 
      char* xx=intToString(x);
      char* yy=floatToString(y);

      insereLista(&lst,xx);
      insereLista(&lst,yy);
      
      free(yy);
      free(xx);
      free(d);
    }
  }
 return lst;
}

/*
 * Query 4
 */

//Estrutura auxiliar Query4
typedef struct aux{
  Faturacao f;
  Filial fil;
  Lista lst;
}*Aux;


Aux setAux(Faturacao f,Lista lst,Filial fil){
  Aux aux=(Aux)malloc(sizeof(struct aux));
  aux->f=f;
  aux->lst=lst;
  aux->fil=fil;
  return aux;
}

gboolean funcTravessiaQuerie4Fat(gpointer key, gpointer value,gpointer data) {
  Aux* aux=data;
  if (!existeProdFat((*aux)->f,(char*)key))
    insereLista(&(*aux)->lst,value);
 
  return FALSE;
}

gboolean funcTravessiaQuerie4Fil(gpointer key, gpointer value,gpointer data) {
  Aux* aux=data;
  if (!existeProdFil((*aux)->fil,(char*)key))
    insereLista(&(*aux)->lst,value);
 
  return FALSE;
}

void removeAux(Aux aux){
  aux->f=NULL;
  aux->fil=NULL;
  aux->lst=NULL;
  free(aux);
}

Lista productsNeverBought(Filial fil,Lista lst,Faturacao f,Cat_Produtos cp,int branchID){

  Aux aux=NULL;
  
  if(branchID==0){ //Valores totais

  aux=setAux(f,lst,NULL);
  for(int i=0;i<26;i++){ 
    GTree* avl=getTree(cp,i);
    g_tree_foreach(avl,(GTraverseFunc)funcTravessiaQuerie4Fat,&aux);
    g_tree_destroy(avl);
  } 
  
  }

  if(branchID>=1){
  
    aux=setAux(NULL,lst,fil);
   
    for(int i=0;i<26;i++){
      GTree* avl=getTree(cp,i);
      g_tree_foreach(getTree(cp,i),(GTraverseFunc)funcTravessiaQuerie4Fil,&aux);
      g_tree_destroy(avl); 
    }
   
  }

  removeAux(aux);

  return lst;
}

/*
 * Query 5
 */

//Estrutura auxiliar Querie 5
typedef struct aux2{
  Filial fil[3];
  Lista lst;
}*Aux2;


Aux2 setAux2(Lista lst,Filial fil[3]){
  Aux2 aux=(Aux2)malloc(sizeof(struct aux2));
  aux->lst=lst;
  for(int i=0;i<3;i++)
  aux->fil[i]=fil[i];

  return aux;
}

void removeAux2(Aux2 aux){
  aux->lst=NULL;
  for(int i=0;i<3;i++)
    aux->fil[i]=NULL;

  free(aux);
}

gboolean funcTravessiaQuerie5Fil(gpointer key, gpointer value,gpointer data) {
  Aux2 *aux=data;
  int flag=0;
  for(int i=0;i<3;i++){
    if (!existeCliFil((*aux)->fil[i] ,(char*)key )) {flag++;break;}
  }
  if (flag==0)
    insereLista(&(*aux)->lst,value);

return FALSE;
}

Lista clientesOfAllBranches(Cat_Clientes cc,Lista lst,Filial fil[3]){

  Aux2 aux = setAux2(lst,fil);
  
  for(int i=0;i<26;i++){
    GTree* avl=getTreeC(cc,i);
    g_tree_foreach(avl,(GTraverseFunc)funcTravessiaQuerie5Fil,&aux);
    g_tree_destroy(avl);
  }

  removeAux2(aux);
  return lst;
}

/*
 * Query 6
 */

struct par{
  int countClients;
  int countProducts;
};

typedef struct aux6{
  Filial fil[3];
  int countClients;
}*Aux6;

Aux6 setAux6(Filial fil[3]){
  Aux6 aux=(Aux6)malloc(sizeof(struct aux6));
  aux->countClients=0;
  for(int i=0;i<3;i++)
  aux->fil[i]=fil[i];

  return aux;
}

void removeAux6(Aux6 aux){
  for(int i=0;i<3;i++){
    aux->fil[i]=NULL;
}
  free(aux);
}

Par initPar(){
  Par p=(Par)malloc(sizeof(struct par));
  p->countClients=0;
  p->countProducts=0;
  return p;
}

void removePar(Par p){
  free(p);
}

Par setPar(Par p,int x,int y){
  p->countClients=x;
  p->countProducts=y;
  return p;
}

int getClientsNeverBoughtCount(Par p){
  return p->countClients;
}

int getProductsNeverBoughtCount(Par p){
  return p->countProducts;
}

 
gboolean funcTravessiaQuerie6(gpointer key, gpointer value,gpointer data) {
  Aux6 *aux=data;
  int flag=0;
  for(int i=0;i<3;i++){
   if (existeCliFil((*aux)->fil[i] ,(char*)key )) {flag++;break;}
  }
   if (flag==0)
     (*aux)->countClients++;

  return FALSE;
}

int clientesQueNaoCompraram(Filial fil[3],Cat_Clientes cc){
  Aux6 aux;
  aux=setAux6(fil);
 
  for(int i=0;i<26;i++){
  GTree* avl=getTreeC(cc,i);
   g_tree_foreach(avl,(GTraverseFunc)funcTravessiaQuerie6,&aux);
   g_tree_destroy(avl);
  }
  removeAux6(aux);
  
  return aux->countClients;
} 


Par clientsAndProductsNeverBoughtCount(Par p,Cat_Produtos cp,Cat_Clientes cc,Faturacao f,Filial fil[3]){
  int countProducts;
  int countClients; 
  
  Lista lst=inicializa_lista();
  lst=productsNeverBought(fil[1],lst,f,cp,0);//Lista com os produtnos ñ comprados
  
  countProducts=sizeLst(lst);
  countClients=clientesQueNaoCompraram(fil,cc);
  
  p=setPar(p,countClients,countProducts);
  removeLst(lst);
  return p;
}

/*
 * Query 7
 */

 //MES   :   1 2 3 4 5
 //FILIAL 1 
 //FILIAL 2
 //FILIAL 3
struct tabela{
  int tabela[12][3];	
};

Tabela initTabela(){
  Tabela tbl=(Tabela)malloc(sizeof(struct tabela));
  for(int i=0;i<12;i++)
 	  for(int j=0;j<3;j++)
      tbl->tabela[i][j]=0;
  return tbl;
}

Tabela setTabela(Tabela tbl,int linha,int coluna,int res){
  tbl->tabela[linha][coluna]=res;
  return tbl;
}

void removeTabela(Tabela tbl){
  free(tbl);
}

int getComprado(Tabela tbl,int linha,int coluna){
  return(tbl->tabela[linha][coluna]);
}

Tabela productBoughtByClient(Tabela tbl,Filial fil[3],char* clientID){
  int nmr_produtos_comprados=0;
  for(int j=0;j<12;j++){
    for(int i=0;i<3;i++){
     nmr_produtos_comprados=produtosCompradosCliente(fil[i],j,clientID);
     tbl=setTabela(tbl,j,i,nmr_produtos_comprados); 
    }
  }
 
  return tbl;
}

/*
 * Query 8
 */

struct profit{
  int total_vendas;
  float total_faturado;
};

Profit initProfit(){
  Profit p=(Profit)malloc(sizeof(struct profit));
  p->total_vendas=0;
  p->total_faturado=0.0;
  return p;
}

Profit setProfit(Profit p,int vendas,float faturado){
  p->total_vendas=vendas;
  p->total_faturado=faturado;
  return p; 
}

float getFaturado(Profit p){
  return(p->total_faturado);	
}

int getVendas(Profit p){
  return p->total_vendas;
}


void removeProfit(Profit p){
  free(p);	
}

Profit salesAndProfit(Faturacao f,Profit p,int minMonth,int maxMonth){
  int vendas=getSales(f,minMonth,maxMonth);
  float faturado=getProfit(f,minMonth,maxMonth);
  p=setProfit(p,vendas,faturado);
  return p;
}

/*
 * Query 9
 */

struct lstbuyers{
  Lista listaN;
  Lista listaP;
};

LstBuyers initLstBuyers(){
  LstBuyers l=(LstBuyers)malloc(sizeof(struct lstbuyers));
  l->listaN=NULL;
  l->listaP=NULL;
  return l;
}

LstBuyers setLstBuyers(LstBuyers l,Lista l1,Lista l2){
  l->listaN=l1;
  l->listaP=l2;
  return l;
}

Lista getListaN(LstBuyers l){
 return(l->listaN);
}

Lista getListaP(LstBuyers l){
 return(l->listaP);
}

void removeLstBuyers(LstBuyers l){
 removeLst(l->listaN);
 removeLst(l->listaP);
 free(l);
}

LstBuyers productBuyers(LstBuyers l,Filial f,char* productID){
 Lista l1=inicializa_lista();
 Lista l2=inicializa_lista();

 l1=buyers(f,l1,productID,'N');
 l2=buyers(f,l2,productID,'P');

 l=setLstBuyers(l,l1,l2);

return l;

}

/*
 * Query 10
 */

int compare_struct(gpointer a,gpointer b){
  QntProds qp1=(QntProds) a;
  QntProds qp2=(QntProds) b;

  int x=getQntQP(qp1);
  int y=getQntQP(qp2);

  return y-x;
}


void percorre(gpointer data,gpointer user_data){
  
  QntProds qp=(QntProds)data;
  char* code=getCodeQP(qp);
  insereLista(user_data,code);
  free(code);
}

Lista htableToList(Lista lst,GHashTable* ht){

  GList* l=g_hash_table_get_values(ht);
  l=g_list_sort(l,(GCompareFunc)compare_struct);

  g_list_foreach(l,(GFunc)percorre,&lst);

  g_list_free(l);
  return lst;

}

void freeKeyProdQ(gpointer data){
  char* clientID=(char*)data;
  free(clientID);
}

Lista clientFavoriteProducts(Filial f[3],Lista lst,char* clientID,int month){

  GHashTable* ht=g_hash_table_new_full(g_str_hash,g_str_equal,freeKeyProdQ,removeQntProds);

  for(int i=0;i<3;i++)
    produtosQueMaisComprou(ht,f[i],clientID,month);

  lst=htableToList(lst,ht),

  g_hash_table_destroy(ht);

  return lst;
}

/*
 * Query 11
 */

struct selledprod{
  char* prodID;
  int num_clientes[3];
  int unidades_vendidas; 
  int unidades_vendidas_filial[3];
};

SelledProd initSelledProd(){
  SelledProd s=(SelledProd)malloc(sizeof(struct selledprod));
  s->prodID=NULL;
  for(int i=0;i<3;s->num_clientes[i++]=0);
  s->unidades_vendidas=0;
  for(int i=0;i<3;s->unidades_vendidas_filial[i++]=0);

return s;
}

SelledProd setSelledProd(SelledProd s,char* code,int* num_clientes,int unidades_vendidas,int* unidades_vendidas_filial){
  s->prodID=strdup(code);
  for(int i=0;i<3;i++)
   s->num_clientes[i]=num_clientes[i];
  s->unidades_vendidas=unidades_vendidas;
  for(int i=0;i<3;i++)
   s->unidades_vendidas_filial[i]=unidades_vendidas_filial[i];
return s;
}

int getUnidadesVendidasProd(SelledProd s){
  return(s->unidades_vendidas);
}

int* getNumClientes(SelledProd s){
  return(s->num_clientes);
}

int* getUnidadesVendidasFilial(SelledProd s){
  return(s->unidades_vendidas_filial);
}


char* getProdCode(SelledProd s){
  return(s->prodID);
}


void removeSelledProds(SelledProd s){
  free(s->prodID);
  free(s);
}


SelledProd* topSelledProducts(SelledProd* top,Faturacao fat,Filial f[3],int limit){

  char* code=NULL;
  int num_clientes[3];
  int unidades_vendidas_filial[3];
  int unidades_vendidas=0;

  for(int i=0;i<3;num_clientes[i++]=0);

  Lista l=inicializa_lista();

  l=topSelledProductsN(l,fat,limit);

  for(int i=0;i<limit;top[i++]=initSelledProd());

  for(int i=0;i<limit;i++){
    code=strdup(getStringLst(l,i));
    for(int j=0;j<3;j++){
      num_clientes[j]=numberClients(f[j],code);
      unidades_vendidas_filial[j]=getUnidadesFilial(f[j],code);
    }  
 
    unidades_vendidas=getUnidadesVendidas(fat,code);
    top[i]=setSelledProd(top[i],code,num_clientes,unidades_vendidas,unidades_vendidas_filial);

    free(code); 
  }

  removeLst(l);
  return top;
}

/*
 * Query 12
 */

int compareTop(gpointer a,gpointer b){
  TopProds tp1=(TopProds) a;
  TopProds tp2=(TopProds) b;

  int x=getGastoTop(tp1);
  int y=getGastoTop(tp2);

  return y-x;
}

gpointer cloneTopProds(gconstpointer src,gpointer data){
  TopProds tp=(TopProds) src;
  TopProds clone=initTopProds();
  float gasto=getGastoTop(tp);
  char *code=getCodeTop(tp);
  clone=setTopProds(clone,code,gasto);
  free(code);
  return clone;
}

GList* topProducts(Filial f[3],char* clientID,int limit){

  GHashTable* ht=g_hash_table_new_full(g_str_hash,g_str_equal,freeKeyProdQ ,removeTP);

  for(int i=0;i<3;i++){
    ht=topProfitProducts(f[i],ht,clientID);
  }

  GList* l=g_hash_table_get_values(ht);

  l=g_list_sort(l,(GCompareFunc)compareTop);

  GList* clone=g_list_copy_deep(l,cloneTopProds,NULL);

  GList* fst=g_list_first(clone);

  for(int i=g_list_length(clone)-1;i>=limit;i--){
    clone=g_list_nth(clone,i);
    TopProds tp=(TopProds)clone->data;
    removeTP(tp);
    clone=g_list_delete_link(fst,clone);
  }
  
  g_list_free(l);
  g_hash_table_destroy(ht);

  return clone;
}

/*
 * Query 13
 */

struct fileinfo{
 char* filenames[3];
 int num_linhas_lidas[3];
 int num_linhas_validadas[3];
 float tempo_leitura[3];
};

FileInfo initFileInfo(){
  FileInfo fi=(FileInfo)malloc(sizeof(struct fileinfo));
  for(int i=0;i<3;fi->filenames[i++]=NULL);
  for(int i=0;i<3;fi->num_linhas_lidas[i++]=0);
  for(int i=0;i<3;fi->num_linhas_validadas[i++]=0);  
  for(int i=0;i<3;fi->tempo_leitura[i++]=0.0f);
  return fi;
}

void removeFileInfo(FileInfo fi){
 for(int i=0;i<3;free(fi->filenames[i++]));
 free(fi);
}

FileInfo currentFilesInfo(FileInfo fi,Cat_Produtos cp,Cat_Clientes cc,Faturacao f){

  fi->filenames[0]=getFileNameProds(cp);
  fi->filenames[1]=getFileNameClientes(cc);
  fi->filenames[2]=getFileNameVendas(f);

  fi->num_linhas_lidas[0]=getNumLinhasLidasProds(cp);
  fi->num_linhas_lidas[1]=getNumLinhasLidasClientes(cc);
  fi->num_linhas_lidas[2]=getNumLinhasLidasVendas(f);

  fi->num_linhas_validadas[0]=totalProd(cp);
  fi->num_linhas_validadas[1]=totalClientes(cc);
  fi->num_linhas_validadas[2]=getNumLinhasValidadasVendas(f);

  fi->tempo_leitura[0]=getTempoLeituraProds(cp);
  fi->tempo_leitura[1]=getTempoLeituraClientes(cc);
  fi->tempo_leitura[2]=getTempoLeituraVendas(f);

  return fi;
}

int getNumLinhasLidasFI(FileInfo fi,int index){
  return (fi->num_linhas_lidas[index]);
}

int getNumLinhasValidadasFI(FileInfo fi,int index){
  return (fi->num_linhas_validadas[index]);
}

float getTempoLeituraFI(FileInfo fi,int index){
  return (fi->tempo_leitura[index]);
}

char* getFileNameFI(FileInfo fi,int index){
  return (fi->filenames[index]);
}