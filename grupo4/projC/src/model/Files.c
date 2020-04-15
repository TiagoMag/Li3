#include "../../include/Files.h"

#define BUFFER 64

static void resultadosVenda(char *file,int validadas,int total,float tempo);
static void resultadosCliente(char *file,Cat_Clientes cc,int total,float tempo);
static void resultadosProd(char *file,Cat_Produtos cp,int total,float tempo);

/* Carrega Produtos para o Catálogo de Produtos */
void loadFilesProduto(char* file,Cat_Produtos cp){

  clock_t begin,end;
  double cpu_time_used;

  begin = clock();

  FILE *fp;

  int count=0;
  char str[BUFFER];
  char *token;

  fp=fopen (file,"r");

  if (fp==NULL) {

    printf("Erro no ficheiro %s \n",file);
    exit (1);
  }

  while (fgets(str,BUFFER,fp)!=NULL){

    count++;
    token=strtok(str,"\n\r"); 
    Produto p=inicializa_Prod();
    p=criaProduto(p,token);

    if (validaProd(p))
      cp=insereProd(cp,p);
    removeProduto(p);
  }
  
  fclose (fp);

  end = clock();
  cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
  resultadosProd(file,cp,count,cpu_time_used);
  
  cp=setInfoFileProdutos(cp,file,count,cpu_time_used);
}

/* Carrega Clientes para o Catálogo de Clientes */
void loadFilesCliente(char* file,Cat_Clientes cc){

  clock_t begin, end;
  double cpu_time_used;
  begin=clock();

  FILE *fp;

  int count=0;

  char str[BUFFER];
  char *token;

  fp=fopen (file,"r");



  if (fp==NULL) {
    printf("Erro no ficheiro %s \n",file);
    exit (1);
  }

  while (fgets(str,BUFFER,fp)!=NULL){

    count++;

    token= strtok(str,"\n\r"); 
    Cliente c=inicializa_Cliente();
    c=criaCliente(c,token);

    if (validaCliente(c)) 
     cc=insereCliente(cc,c);
   removeCliente(c);
 }
 
 fclose (fp);
 
 end = clock();
 cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
 
 resultadosCliente(file,cc,count,cpu_time_used);
 cc=setInfoFileClientes(cc,file,count,cpu_time_used);
}

/* Divide linha vendas em campos */
void dividetoken(char* str,char* arr_token[]){

  int j=0;
  char* token;

  token = strtok (str," ");

  while (token != NULL){

    arr_token[j]=strdup(token);
    token = strtok (NULL, " ");
    j++;
  }

}

/* Carrega Filial e Faturacao com vendas */
void leVendas(Filial fil[3],Faturacao f,char* file,Cat_Produtos cp,Cat_Clientes cc){

  clock_t begin, end;
  double cpu_time_used;
  begin=clock();

  char* token;

  FILE *fp;

  char str[64];
  int lidas=0;
  int validadas=0;
  char* arr_token[CAMPOS];


  fp=fopen (file,"r");

  if (fp==NULL) {
    printf("Erro no ficheiro");
    exit (1);
  }

  while (fgets(str,BUFFER,fp)!=NULL){

    token=strtok(str,"\n\r");
    lidas+=1;
    
    
    dividetoken(token,arr_token);

    float preco=atof(arr_token[1]);
    int qnt=atoi(arr_token[2]);
    int mes= atoi(arr_token[5]);
    int filial= atoi(arr_token[6]);
    char tipo=*(arr_token[3]);
    
    Venda v= inicializaV(); 
    v=criaVendas(v,arr_token[0],arr_token[4],preco,qnt,tipo,mes,filial);

    if (validaV(v,cp,cc)){ 

      if (existeFat(f,v))
        f=updateFat(f,v);
      else f=insereFat(f,v);

      fil[getFilial(v)-1]=insereFilial(fil[getFilial(v)-1],v);
      validadas++;
    }
    for(int i=0;i<CAMPOS;free(arr_token[i++]));
    
    removeVenda(v); 
 }

 fclose(fp);
 
 end = clock();
 cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
 f=setFileInfoVendas(f,validadas,lidas,file,cpu_time_used);
 resultadosVenda(file,validadas,lidas,cpu_time_used);
}



static void resultadosProd(char *file,Cat_Produtos cp,int total,float tempo){

  int nmr_linhas_lidas=0;
  int nmr_linhas_validadas=0;

  nmr_linhas_lidas=total;
  nmr_linhas_validadas=totalProd(cp);


  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("PRODUTOS");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n\n");
  printf("Nome do ficheiro lido:");
  printf("\033[1;33m");
  printf(" %s \n",file);
  printf("\033[1;36m");
  printf("Número de linhas lidas:");
  printf("\033[1;33m");
  printf(" %d \n",nmr_linhas_lidas);
  printf("\033[1;36m");
  printf("Número de linhas validadas:");
  printf("\033[1;33m");
  printf(" %d \n\n",nmr_linhas_validadas);
  printf("\033[1;32m");
  printf("Tempo: \033[1;34m  %f \n\n",tempo);
  printf("\033[1;36m");
}

static void resultadosCliente(char *file,Cat_Clientes cc,int total,float tempo){

 int nmr_linhas_lidas=0;
 int nmr_linhas_validadas=0;

 nmr_linhas_lidas=total;
 nmr_linhas_validadas=totalClientes(cc);

 system("clear");
 printf("═════════════════════════════════════════════════");
 printf("\033[1;34m");
 printf("CLIENTES");
 printf("\033[1;36m");
 printf("═════════════════════════════════════════════════\n\n");
 printf("Nome do ficheiro lido:");
 printf("\033[1;33m");
 printf(" %s \n",file);
 printf("\033[1;36m");
 printf("Número de linhas lidas:");
 printf("\033[1;33m");
 printf(" %d \n",nmr_linhas_lidas);
 printf("\033[1;36m");
 printf("Número de linhas validadas:");
 printf("\033[1;33m");
 printf(" %d \n\n",nmr_linhas_validadas);
 printf("\033[1;32m");
 printf("Tempo: \033[1;34m  %f \n\n",tempo);
 printf("\033[1;36m");
}

static void resultadosVenda(char *file,int validadas,int total,float tempo){

 int nmr_linhas_lidas=0;
 int nmr_linhas_validadas=0;

 nmr_linhas_lidas=total;
 nmr_linhas_validadas=validadas;

 printf("══════════════════════════════════════════════════");
 printf("\033[1;34m");
 printf("VENDAS");
 printf("\033[1;36m");
 printf("══════════════════════════════════════════════════\n\n");
 printf("Nome do ficheiro lido:");
 printf("\033[1;33m");
 printf(" %s \n",file);
 printf("\033[1;36m");
 printf("Número de linhas lidas:");
 printf("\033[1;33m");
 printf(" %d \n",nmr_linhas_lidas);
 printf("\033[1;36m");
 printf("Número de linhas validadas:");
 printf("\033[1;33m");
 printf(" %d \n\n",nmr_linhas_validadas);
 printf("\033[1;32m");
 printf("Tempo: \033[1;34m  %f \n\n",tempo);
 printf("\033[1;36m");

}