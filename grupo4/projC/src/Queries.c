#include "../include/Queries.h"


//---------------QUERIE 2---------------------------------------

Lista produtosComecadoPelaLetra(Cat_Produtos cp,char letter){
 Lista lst=inicializa_lista();
 lst=produtosLetra(cp,lst,letter);

 return lst;
}

//--------------------------------------------------------------

//----------------QUERIE 3--------------------------------------

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

Lista productSalesAndProfit(Faturacao f,char* productID,int month){

	Data d=initData();
	Lista lst=inicializa_lista();

	d=getData(f,productID,'N',month);
	
    
    int x=getQntFat(d);
    float y=getPrecoFat(d);
  
    insereLista(&lst,intToString(x));
    insereLista(&lst,floatToString(y));
	
	d=getData(f,productID,'P',month);
    
    x=getQntFat(d);
    y=getPrecoFat(d);
    

    insereLista(&lst,intToString(x));
    insereLista(&lst,floatToString(y));
    
    for(int j=0;j<FILIAL;j++){
     for(int i=0;i<2;i++){
    
      if(i==0) d=getDataFilial(f,productID,'P',month,j);
      else if(i==1) d=getDataFilial(f,productID,'N',month,j);
   
      x=getQntFat(d);
      y=getPrecoFat(d);

      insereLista(&lst,intToString(x));
      insereLista(&lst,floatToString(y));
  
     }
    }
 return lst;
}

//--------------------------------------------------------------

//----------------QUERIE 4--------------------------------------

//Estrutura auxiliar Querie4
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
}

Lista productsNeverBought(Filial fil,Faturacao f,Cat_Produtos cp,int branchID){

Lista lst=inicializa_lista();
Aux aux=setAux(f,lst,NULL);
if(branchID==0){ //Valores totais

 for(int i=0;i<26;i++)
  g_tree_foreach(getTree(cp,i),(GTraverseFunc)funcTravessiaQuerie4Fat,&aux);
}

if(branchID>=1){
 printf("%d",branchID);
  aux=setAux(NULL,lst,fil);
  
  for(int i=0;i<26;i++)
  g_tree_foreach(getTree(cp,i),(GTraverseFunc)funcTravessiaQuerie4Fil,&aux);
  
}
removeAux(aux);

return lst;

}

//--------------------------------------------------------------

//----------------QUERIE 5--------------------------------------

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


Lista clientesOfAllBranches(Cat_Clientes cc,Filial fil[3]){

Lista lst = inicializa_lista();
Aux2 aux = setAux2(lst,fil);

for(int i=0;i<26;i++){
  g_tree_foreach(getTreeC(cc,i),(GTraverseFunc)funcTravessiaQuerie5Fil,&aux);
}

return lst;
}


//--------------------------------------------------------------
//----------------QUERIE 6--------------------------------------
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

Par initPar(){
 Par p=(Par)malloc(sizeof(struct par));
  p->countClients=0;
  p->countProducts=0;
  return p;
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
  g_tree_foreach(getTreeC(cc,i),(GTraverseFunc)funcTravessiaQuerie6,&aux);
 }
 return aux->countClients;
} 


Par clientsAndProductsNeverBoughtCount(Par p,Cat_Produtos cp,Cat_Clientes cc,Faturacao f,Filial fil[3]){
  int countProducts;
  int countClients; 
  
  Lista lst=inicializa_lista();
  lst=productsNeverBought(fil[1],f,cp,0);//Lista com os produtnos ñ comprados
  
  countProducts=sizeLst(lst);
  countClients=clientesQueNaoCompraram(fil,cc);
  
  p=setPar(p,countClients,countProducts);

  return p;


 }


//--------------------------------------------------------------
//----------------QUERIE 7--------------------------------------

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

 //--------------------------------------------------------------
//----------------QUERIE 8--------------------------------------

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

//--------------------------------------------------------------
//----------------QUERIE 9--------------------------------------

struct lstbuyers{
 Lista listaN;
 Lista listaP;
};

LstBuyers initLstBuyers(){
  LstBuyers l=(LstBuyers)malloc(sizeof(struct lstbuyers));
  l->listaN=inicializa_lista();
  l->listaP=inicializa_lista();
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


//--------------------------------------------------------------
//----------------QUERIE 10--------------------------------------



int compare_struct(gpointer a,gpointer b){
QntProds qp1=(QntProds) a;
QntProds qp2=(QntProds) b;

int x=getQntQP(qp1);
int y=getQntQP(qp2);

return y-x;

}


void percorre(gpointer data,gpointer user_data){
QntProds qp=(QntProds)data;

insereLista(user_data,getCodeQP(qp));


}

Lista htableToList(GHashTable* ht){

GList* l=g_hash_table_get_values(ht);
GList* s=g_list_sort(l,(GCompareFunc)compare_struct);
Lista lst=inicializa_lista();
g_list_foreach(s,(GFunc)percorre,&lst);
return lst;

}



Lista clientFavoriteProducts(Filial f[3],char* clientID,int month){

GHashTable* ht=g_hash_table_new(g_str_hash,g_str_equal);
printf("SIZE:%d\n",g_hash_table_size(ht));
for(int i=0;i<3;i++)
  produtosQueMaisComprou(ht,f[i],clientID,month);

return(htableToList(ht));
}

