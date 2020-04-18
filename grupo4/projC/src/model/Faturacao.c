#include "../../include/Faturacao.h"

static int top=0; /* inteiro utilizado na função topSelledProductsN */

/* Estrutura da faturação */
struct faturacao {
  GHashTable* produtos; /* HashTable com código de produtos */
  Data TotaisMes[MES]; /* Informações globais acerca dos meses */
  int num_linhas_lidas; /* numero de linhas lidas do ficheiro que contém a informação a armazenar na faturação e filial */
  int num_linhas_validadas; /* numero de linhas validadas do ficheiro que contém a informação a armazenar na faturação e filial */
  char* filename; /* nome do ficheiro que contém a informação a armazenar na faturação e filial */
  float tempo_leitura; /* tempo de leitura */
};     

/* Value da HashTable produtos */
struct fat{
  char* code; /* Código do produto */ 
  Data infoN[MES][FILIAL]; /* Informação mês a mês e filial a filial acerca do produto no modo Normal */
  Data infoP[MES][FILIAL]; /* Informação mês a mês e filial a filial acerca do produto no modo Promoção */
  int vendas; /* Número de unidades vendidas global do produto */
};

/* Estrutura Data */
struct data{
  int quant; /* Número de vendas do produto */
  float precofat;	 /* Total faturado pelo produto */
};

/* Função que inicializa a estrutura Data */
Data initData(){
  Data d=(Data)malloc(sizeof(struct data));
  d->quant=0;
  d->precofat=0.0f;
  return d;
}

/* Função que coloca informação na estrutura Data */
static Data setData(Data d,int quant,float precofat){
  d->quant=quant;
  d->precofat=precofat;
  return d;
}

/* Get's */
float getPrecoFat(Data d){
  return(d->precofat);
}

int getQntFat(Data d){
  return(d->quant);
}

/* Função que libera da memória a chave da HashTable produtos */
static void freeKeyProductFat(gpointer data){
  char* prodID=(char*)data;
  free(prodID);
}

/* Função que libera da memória a estrutura Fat */
static void removeFat(gpointer data){
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

/* Função que inicializa a estrutura Faturacao*/
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

/* Função que inicializa a estrutura Fat */
static Fat initFat(){
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

/* Função que libera da memória a esturuta Faturacao */
void removeFaturacao(Faturacao f){
 free(f->filename);
 g_hash_table_destroy(f->produtos);
 for(int i=0;i<MES;i++)
  free(f->TotaisMes[i]);
 free(f);
}

/* Função que coloca informação acerca do ficheiro de onde se carrega a faturação */
Faturacao setFileInfoVendas(Faturacao f,int num_linhas_validadas,int num_linhas_lidas,char* filename,float tempo_leitura){
 f->num_linhas_lidas=num_linhas_lidas;
 f->num_linhas_validadas=num_linhas_validadas;
 f->tempo_leitura=tempo_leitura;
 f->filename=strdup(filename);
 return f;
}

/* Get's */
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

static char* getCodeFat(Fat f){
  return(f->code);
}

/* Função que retorna o numero de unidades vendidas de um determinado produto */
int getUnidadesVendidas(Faturacao f,char* prodID){
 Fat fat=g_hash_table_lookup(f->produtos,prodID);
 return(fat->vendas);
}

/* Função que verifica se produto já está na Faturação */
gboolean existeFat(Faturacao f,Venda v){
  gboolean existe;
  char* codigo=getProduto(getProdutoVenda(v));
  existe=g_hash_table_contains(f->produtos,codigo);
  free(codigo);
  return existe;
}

/* Set's */
static Fat setFatCode(Fat f,char* code){
  f->code=strdup(code);
  return f;
}

static Faturacao setTotais(Faturacao f,int mes,float preco){

  f->TotaisMes[mes]->quant++;
  f->TotaisMes[mes]->precofat+=preco;
 
  return f;
}

static Fat setFatP(Fat f,int mes,int filial,float preco,int quant){

  f->infoP[mes][filial]->quant++;
  f->infoP[mes][filial]->precofat+=preco;
  f->vendas+=quant;
  
  return f;
}

static Fat setFatN(Fat f,int mes,int filial,float preco,int quant){

  f->infoN[mes][filial]->quant++;
  f->infoN[mes][filial]->precofat+=preco;
  f->vendas+=quant;
  
  return f;
}

/* Função que insere uma venda na Faturação */
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

/* Caso um produto já existe na faturção a função irá atualizar o seu valor */
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

/* Get's */
Data getData(Faturacao f,char* codigo,char tipo,int mes){
  
  Data d=initData();
  Fat fat=g_hash_table_lookup(f->produtos,codigo);
  if(fat){
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
 }else {d=setData(d,0,0.0);}

 return d;
}

Data getDataFilial(Faturacao f,char* codigo,char tipo,int mes,int filial){
  float preco=0.0;
  int quant=0;
  Data d=initData();
  Fat fat=g_hash_table_lookup(f->produtos,codigo);
  if(fat){
    if((tipo=='N')){
      preco=getPrecoFat(fat->infoN[mes][filial]);
      quant=getQntFat(fat->infoN[mes][filial]);
    }else{ 
      preco=getPrecoFat(fat->infoP[mes][filial]);
      quant=getQntFat(fat->infoP[mes][filial]); 
    }
    d=setData(d,quant,preco);
  }else{d=setData(d,0,0.0);}
  
  return d;
}

/* Verifica se existe um produto na hashtable produtos */
gboolean existeProdFat(Faturacao f,char* codigo){
 return g_hash_table_contains(f->produtos,codigo);
}

/* Função que retorna o total faturado num intervalo de meses */
float getProfit(Faturacao f,int minMonth,int maxMonth){

 float faturado=0;
 for(int i=minMonth;i<=maxMonth;i++){
  faturado+=f->TotaisMes[i]->precofat;
 }
 return faturado;
}

/* Função que retorna o total de vendas num intervalo de meses */
int getSales(Faturacao f,int minMonth,int maxMonth){
 int vendas=0;
 for(int i=minMonth;i<=maxMonth;i++){
  vendas+=f->TotaisMes[i]->quant;
 }
 
 return vendas;  
}

/* Funções que ajudam na realização da querie 11 */

/* Compara duas Fat's a que tiver maior numero de unidades vendidas é a maior */
static int compare(gpointer a,gpointer b){
  Fat f1=(Fat) a;
  Fat f2=(Fat) b;

  float x=f1->vendas;
  float y=f2->vendas;

  return y-x;

}

/* Função que percorre uma lista */
static void percorre11(gpointer data,gpointer user_data){
  
  if(top>0){
    Fat fat=(Fat)data;
    insereLista(user_data,getCodeFat(fat));
    top--;
  }

}

/* Função que retorna uma lista com tamanho "limit" com os produtos mais vendidos */
Lista topSelledProductsN(Lista lst,Faturacao f,int limit){

  GList* l=g_hash_table_get_values(f->produtos);
  l=g_list_sort(l,(GCompareFunc)compare);
 
  top=limit;
 
  g_list_foreach(l,(GFunc)percorre11,&lst);
  g_list_free(l);
  
  return lst;
}
