#include "../include/Faturacao.h"

static int top=0;

//Estrutura de dados
struct faturacao {
  GHashTable* produtos;
  Data TotaisMes[MES];
  int num_linhas_lidas;
  int num_linhas_validadas;
  char* filename;
  float tempo_leitura;
};     

//Estrutura de dados de uma fatura
struct fat{
  char* code;
  Data infoN[MES][FILIAL];
  Data infoP[MES][FILIAL];
  int vendas;
};

//Dados da fatura
struct data{
  int quant;
  float precofat;	
};

//Alocação de memória
Data initData(){
  Data d=(Data)malloc(sizeof(struct data));
  d->quant=0;
  d->precofat=0.0f;
  return d;
}

//Inserção de valores nos dados da fatura
Data setData(Data d,int quant,float precofat){
  d->quant=quant;
  d->precofat=precofat;
  return d;
}

//Retorna preço da fatura
float getPrecoFat(Data d){
  return(d->precofat);
}

//Retorna quantidade comprada
int getQntFat(Data d){
  return(d->quant);
}


GHashTable* getprodutosFat(Faturacao f){
  return(f->produtos);
}


void freeKeyProductFat(gpointer data){
  char* prodID=(char*)data;
  free(prodID);
}

void removeFat(gpointer data){
 Fat f=(Fat)data;
 free(f->code);
 for(int i=0;i<MES;i++){
    for(int j=0;j<FILIAL;j++){
      free(f->infoN[i][j]);
      free(f->infoP[i][j]);
    }
  }
  free(f);
}


Faturacao inicializaFat(){
  Faturacao fat = (Faturacao)malloc(sizeof(struct faturacao));
  fat->num_linhas_lidas=0;
  fat->num_linhas_validadas=0;
  fat->filename=NULL;
  fat->tempo_leitura=0.0f;
  fat->produtos=g_hash_table_new_full(g_str_hash, g_str_equal,freeKeyProductFat,removeFat);
  for(int i=0;i<MES;i++)
    fat->TotaisMes[i]=initData();
  return fat;
}

Fat initFat(){
  Fat ft = (Fat)malloc(sizeof(struct fat));
  ft->vendas=0;
  ft->code=NULL;
  for(int i=0;i<MES;i++){
    for(int j=0;j<FILIAL;j++){
      ft->infoN[i][j]=initData();
      ft->infoP[i][j]=initData();
    }
  }
  return ft;
}

void removeFaturacao(Faturacao f){
 free(f->filename);
 g_hash_table_destroy(f->produtos);
 for(int i=0;i<MES;i++)
  free(f->TotaisMes[i]);
 free(f);
}


Faturacao setFileInfoVendas(Faturacao f,int num_linhas_validadas,int num_linhas_lidas,char* filename,float tempo_leitura){
 f->num_linhas_lidas=num_linhas_lidas;
 f->num_linhas_validadas=num_linhas_validadas;
 f->tempo_leitura=tempo_leitura;
 f->filename=strdup(filename);
 return f;
}

int getNumLinhasLidasVendas(Faturacao f){
  return(f->num_linhas_lidas);
}

int getNumLinhasValidadasVendas(Faturacao f){
  return(f->num_linhas_validadas);
}

float getTempoLeituraVendas(Faturacao f){
  return(f->tempo_leitura);
}

char* getFileNameVendas(Faturacao f){
  return strdup(f->filename);
}





char* getCodeFat(Fat f){
  return(f->code);
}

Fat setFatCode(Fat f,char* code){
  f->code=strdup(code);
  return f;
}

gboolean existeFat(Faturacao f,Venda v){
  gboolean existe;
  char* codigo=getProduto(getProdutoVenda(v));
  existe=g_hash_table_contains(f->produtos,codigo);
  free(codigo);
  return existe;
}

Faturacao setTotais(Faturacao f,int mes,float preco){

  f->TotaisMes[mes]->quant++;
  f->TotaisMes[mes]->precofat+=preco;
 
  return f;
}

Fat setFatP(Fat f,int mes,int filial,float preco,int quant){

  f->infoP[mes][filial]->quant++;
  f->infoP[mes][filial]->precofat+=preco;
  f->vendas+=quant;
  
  return f;
}

Fat setFatN(Fat f,int mes,int filial,float preco,int quant){

  f->infoN[mes][filial]->quant++;
  f->infoN[mes][filial]->precofat+=preco;
  f->vendas+=quant;
  
  return f;
}

Faturacao insereFat(Faturacao f,Venda v){
   
   char* codigo=getProduto(getProdutoVenda(v));
   int mes=getMes(v)-1;
   int filial=getFilial(v)-1;
   float preco=getPrecoVenda(v)*(float)getQntVenda(v);
   int quant=getQntVenda(v);

   Fat fat=initFat();
   fat=setFatCode(fat,codigo);
   if(getTipo(v)=='P'){
    
    fat=setFatP(fat,mes,filial,preco,quant);
    
    g_hash_table_insert(f->produtos,codigo,fat);
  
    f=setTotais(f,mes,preco);
   
   }
   else if(getTipo(v)=='N'){
    
    fat=setFatN(fat,mes,filial,preco,quant);

    g_hash_table_insert(f->produtos,codigo,fat);
    
    f=setTotais(f,mes,preco); 
   
   }

 return f;
}



Faturacao updateFat(Faturacao f,Venda v){
   
   char* codigo=getProduto(getProdutoVenda(v));
   
   int mes=getMes(v)-1;
   int filial=getFilial(v)-1;
   float preco=getPrecoVenda(v)*(float)getQntVenda(v);
   int quant=getQntVenda(v);

   Fat fat=(Fat)g_hash_table_lookup(f->produtos,codigo);

   if (getTipo(v)=='P'){
   
    fat=setFatP(fat,mes,filial,preco,quant);
    f=setTotais(f,mes,preco);
   
   }else if (getTipo(v)=='N'){
    
    fat=setFatN(fat,mes,filial,preco,quant);
    f=setTotais(f,mes,preco);
   
   }
 free(codigo);
 return f;
}

Data getData(Faturacao f,char* codigo,char tipo,int mes){
  
  Data d=initData();
  Fat fat=g_hash_table_lookup(f->produtos,codigo);
  float preco=0.0;
  int quant=0;
  for(int i=0;i<FILIAL;i++){
   if((tipo=='N')){

    preco+=getPrecoFat(fat->infoN[mes][i]); 
    quant+=getQntFat(fat->infoN[mes][i]);
  
  }else if((tipo=='P')){
  
    preco+=getPrecoFat(fat->infoP[mes][i]);
    quant+=getQntFat(fat->infoP[mes][i]); 
  }
 
 }
 d=setData(d,quant,preco);
 return d;
}

Data getDataFilial(Faturacao f,char* codigo,char tipo,int mes,int filial){
  float preco=0.0;
  int quant=0;
  Data d=initData();
  Fat fat=g_hash_table_lookup(f->produtos,codigo);
  if((tipo=='N')){
  preco=getPrecoFat(fat->infoN[mes][filial]);
  quant=getQntFat(fat->infoN[mes][filial]);
  }else{ 
 preco=getPrecoFat(fat->infoP[mes][filial]);
  quant=getQntFat(fat->infoP[mes][filial]); 
  }
  d=setData(d,quant,preco);
 return d;
}

gboolean existeProdFat(Faturacao f,char* codigo){
 return g_hash_table_contains(f->produtos,codigo);
}


float getProfit(Faturacao f,int minMonth,int maxMonth){

 float faturado=0;
 for(int i=minMonth;i<=maxMonth;i++){
  faturado+=f->TotaisMes[i]->precofat;
 }

 return faturado;
}

int getSales(Faturacao f,int minMonth,int maxMonth){
 int vendas=0;
 for(int i=minMonth;i<=maxMonth;i++){
  vendas+=f->TotaisMes[i]->quant;
 }
 
 return vendas;
  
}

int compare(gpointer a,gpointer b){
  Fat f1=(Fat) a;
  Fat f2=(Fat) b;

  float x=f1->vendas;
  float y=f2->vendas;

return y-x;

}


void percorre11(gpointer data,gpointer user_data){
  
  if(top>0){
  Fat fat=(Fat)data;

  insereLista(user_data,getCodeFat(fat));
  top--;
  }

}

Lista topSelledProductsN(Lista lst,Faturacao f,int limit){

  GList* l=g_hash_table_get_values(f->produtos);
  l=g_list_sort(l,(GCompareFunc)compare);
 
  top=limit;
 
  g_list_foreach(l,(GFunc)percorre11,&lst);
  g_list_free(l);
  
  return lst;
}

int getUnidadesVendidas(Faturacao f,char* prodID){

 Fat fat=g_hash_table_lookup(f->produtos,prodID);
 return(fat->vendas);
}



