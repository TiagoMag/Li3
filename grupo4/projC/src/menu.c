#include "../include/menu.h"


static void navega(Lista lst);


int main_menu(){

  system("clear");
  
  printf("\033[1;36m════════════════════════════════════════════════════\033[1;34m");
  printf("MENU PRINCIPAL");
  printf("\033[1;36m════════════════════════════════════════════════════\033[0;31m\n\n");
  printf(" 0.");
  printf("\033[1;33mSAIR.\033[0;31m\n\n");
  printf(" 1.");
  printf("\033[1;33mLeitura dos ficheiros.\033[0;31m\n\n");
  printf(" 2.");
  printf("\033[1;33mListar produtos por uma determinada letra.\033[0;31m\n\n");
  printf(" 3.");
  printf("\033[1;33mTotal e registos de vendas de um determinado produto num determinado mês.\033[0;31m\n\n");
  printf(" 4.");
  printf("\033[1;33mLista ordenada de códigos de produtos que ninguém comprou (Total ou por filial).\033[0;31m\n\n");
  printf(" 5.");
  printf("\033[1;33mLista de códigos de clientes que realizaram compras em todas as filiais.\033[0;31m\n\n");
  printf(" 6.");
  printf("\033[1;33mClientes que não realizaram compras e número de produtos nunca comprados.\033[0;31m\n\n");
  printf(" 7.");
  printf("\033[1;33mTabela de produtos comprados por mês e filial.\033[0;31m\n\n");
  printf(" 8.");
  printf("\033[1;33mDeterminar total de vendas num determinado intervalo [MÊS 1; MÊS 2].\033[0;31m\n\n");
  printf(" 9.");
  printf("\033[1;33mDeterminar os códigos e o número total dos clientes que compraram um produto numa filial.\033[0;31m\n\n");
  printf("10.");
  printf("\033[1;33mDeterminar a lista de produtos que um cliente mais comprou por quantidade, num determinado mês.\033[0;31m\n\n");
  printf("11.");
  printf("\033[1;33mTop personalizado de vendas,por número de cliente e quantidade vendida, filial a filial.\033[0;31m\n\n");
  printf("12.");
  printf("\033[1;33mTop personalizado de gasto em compras individualizado por cliente.\033[0;31m\n\n");
  printf("13.");
  printf("\033[1;33m<<<Não definido>>>.\033[0;31m\n\n");
  printf("14.");
  printf("\033[1;33mFree Structs.\033[1;36m\n\n");
  
  printf("══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n\n");

  char buffer[10];
  int option;
  
  printf("\033[1;34m");
  printf("Selecione a opção: \n");
  
  scanf("%s",buffer);
  option=atoi(buffer);

  return option;

}

static void navega(Lista lst){


if (sizeLst(lst)==0){
  printf("\033[01;33mLista sem Elementos\n");
  clearAndEnter();

  return ;
}
  else{
    int totalpages=paginasTotal(lst);
    int pagina=1;
    char c;
    Pagina p=initPagina();
    
    
    while(pagina>0 && pagina<=totalpages){
      int arraybegin=(MAX_LIN*(pagina-1));
      p=getPageSeguinte(lst,arraybegin);
      int x=0;
    
    
      printf("\033[1;34m");
      printf("═════════════════════════════════════════════════");
      printf("NAVEGADOR");
      printf("═════════════════════════════════════════════════\n");
      printf("\033[1;36m");
      printf("Nmr total de elementos  ->\033[1;35m  %d\n\033[1;36m",sizeLst(lst));  
      printf("Nmr elementos na página ->\033[1;35m %d\n\n\033[1;36m",sizeLstPage(p));  
      printf("\033[1;35m Página %d de %d\n\n\033[1;36m",pagina,totalpages);

        while(x<sizeLstPage(p)){
          char *produto=getString(p,x);
          printf("Código: \033[0;34m%s\n\033[1;36m",produto);
          x++;    
        }  

      printf("═════════════════════════════════════════════════\n");
      printf("\033[01;33m n -- avançar        x--sair             a -- recuar\n");
      
        while ((c = getchar()) != '\n' && c != EOF) { }
          c=getchar();
          removePagina(p);
            
            if(c=='n')
            pagina++;
            
            if(c=='a')
            pagina--;
            
            if(c=='x'){
            return ; }
            
            system("clear");
    


    }
  }
}

void clearAndEnter(){

  int c;
    while ((c = getchar()) != '\n' && c != EOF);
  printf("PRESS \033[1;34m  ENTER ->  \033[1;36m PARA CONTINUAR");
  getchar();

}

void voltar(){
  int c=0;
  
    while(c!=4) c++;
}


void erro(){

  int c;
  system("clear");
  printf("\033[1;31m");
  while ((c= getchar()) != '\n' && c != EOF);
  
  puts("AVISO! \033[1;31m É NECESSÁRIA A LEITURA DOS FICHEIROS.\n\n\033[0;33mENTER para voltar atrás\n");
  getchar();
}





//--------------------------------------------------QUERY-1



int scanning(char buffer[100],char*filenames[3]){
 
  if (buffer[0]=='S'){
    filenames[0]=strdup("D");
    memset(buffer,0,100);
 
    return 0;
  }
 
  else if (buffer[0]=='N'){
    printf("Paths ficheiro cliente: ");
    scanf("%s",buffer);
    filenames[0]=strdup(buffer);
  
    printf("Path ficheiro produtos: ");
    scanf("%s",buffer);
    filenames[1]=strdup(buffer);
  
    printf("Path ficheiro vendas: ");
    scanf("%s",buffer);
    filenames[2]=strdup(buffer);
  
    memset(buffer,0,100);
    
    return 0;
  }
 
 return 1;
}

int inputQuery1(SGV sgv,char* filenames[3]){
  
int b; 
char buffer[100];

  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 1");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n\n");
  printf("\033[1;34m");
  printf("\033[1;35m0 -> Voltar\033[1;36m \n");
  printf("Usar ficheiros default(S/N)?\n");
  printf("\033[1;36m");
  printf("══════════════════════════════════════════════════════════════════════════════════════════\n");
  scanf("%s",buffer);

  if((b=scanning(buffer,filenames))==0)
    return 0;

  else if (buffer[0]=='0'){
    memset(buffer,0,100);
    return -1;
  }

  else{

  int a=1;
 
    while(a!=0){
      printf("Responder com (S/N)\nUsar ficheiros default(S/N)?\n");
      scanf("%s",buffer);
      a=scanning(buffer,filenames);
    }

  }

  return 0;
}


//--------------------------------------------------QUERY-2
char inputQuery2(){
  
  char c;
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 2");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n");
  printf("\033[1;35m0 -> Voltar\033[1;36m\n");
  printf("Qual a letra do produto que pretende procurar [A-Z] ?\n");
  printf("══════════════════════════════════════════════════════════════════════════════════════════\n");
   
  scanf(" %c",&c);
  
    if (c=='0') 
      return '0';
  
      else {
        
        if (!(c>='A' && c<='Z')){
          puts("\033[1;31mLetra inválida");
          return '-';
        }
      }
    

  return c;
}

void printQuery2(Lista lst){
  system("clear");
  navega(lst);
  removeLst(lst);
}

//--------------------------------------------------QUERY-3
char inputQuery3(char* code,int* mes){
  
char mes_str[100];
char c;
  
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 3");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n");
  printf("\033[1;35m0 -> Voltar \n\n"); 
  printf("\033[1;33mIndique um mês (1-12)?\033[0;32m\n");
 
  scanf(" %s",mes_str);
  
    if ((atoi(mes_str))==0)
      return c='0'; 
    
    if ((atoi(mes_str))>12){
      puts("\033[1;31mMês inválido");
      return c='-';
    }
  
  else{

    *mes=atoi(mes_str)-1;

    
    printf("\033[1;33mIndique um código de um produto?\033[0;32m\n");  
    scanf(" %s",code);
      
      if (*code == '0')
        return c='0';
      
      if (strlen(code)!=6){
        printf("\033[1;31mCódigo de produto inválido\n");
        return -1;
      }

      if (!isalpha(code[0]) && isalpha(code[0])){
        printf("\033[1;31m Primeiros 2 caracteres não são letras\n");
        return c='-';
      }

      if (!(code[0]>='A' && code[0]<='Z' && code[1]>='A' && code[1]<='Z')){
        printf("\033[1;31m Primeiros 2 caracteres não são letras MAÍUSCULAS\n"); return c='-';
      }

      if (!(atoi(code+2)>=1000) && atoi(code+2)<=9999){
        printf("\033[1;31m Últimos 4 caracteres têm de ser numéricos\n");
        return c='-';
      }
  
    
    printf("\033[1;33mTotal ou por Filial(T/F)?\n"); 
    scanf(" %c",&c); 

      if (!(c=='T' || c=='F')){
        puts("\033[1;31m Utilize a letra (T)otal ou (F)ilial");
        return c='-';
      }
  }

return c;
}  




void printQuery3(Lista lst,char c){

  if(c=='T'){
  
    system("clear");  
  
    printf("Nmr de vendas      (N):%s\n",getStringLst(lst,0));
    printf("Total faturado     (N):%s\n",getStringLst(lst,1));
    printf("Nme de vendas      (P):%s\n",getStringLst(lst,2));
    printf("Total faturado     (P):%s\n",getStringLst(lst,3));

    clearAndEnter();
    
  }
  
  else if(c=='F'){
   
    system("clear");
   
    printf("\033[1;36m");
    printf("═════════════════════════════════════════════════");
    printf("\033[1;34m");
    printf("FILIAL 1");
    printf("\033[1;36m");
    printf("═════════════════════════════════════════════════\n");
 
    printf("Nmr de vendas      (P):%s\n",getStringLst(lst,4));
    printf("Total Faturado     (P):%s\n",getStringLst(lst,5));
    printf("Nmr de vendas      (N):%s\n",getStringLst(lst,6));
    printf("Total Faturado     (N):%s\n",getStringLst(lst,7));
    printf("\033[1;36m");

    printf("═════════════════════════════════════════════════");
    printf("\033[1;34m");
    printf("FILIAL 2");
    printf("\033[1;36m");
    printf("═════════════════════════════════════════════════\n");
 
    printf("Nmr de vendas      (P):%s\n",getStringLst(lst,8));
    printf("Total faturado     (P):%s\n",getStringLst(lst,9));
    printf("Nmr de vendas      (N):%s\n",getStringLst(lst,10));
    printf("Total faturado     (N):%s\n",getStringLst(lst,11));
 
    printf("\033[1;36m");
    printf("═════════════════════════════════════════════════");
    printf("\033[1;34m");
    printf("FILIAL 3");
    printf("\033[1;36m");
    printf("═════════════════════════════════════════════════\n");
   
    printf("Nmr de vendas      (P):%s\n",getStringLst(lst,12));
    printf("Total faturado     (P):%s\n",getStringLst(lst,13));
    printf("Nmr de vendas      (N):%s\n",getStringLst(lst,14));
    printf("Total faturado     (N):%s\n",getStringLst(lst,15));
    
    clearAndEnter();
  }

  removeLst(lst);

}



//--------------------------------------------------QUERY-4
int inputQuery4(){
 
 char c;
 int f;
 int res=-1;
 int flag=0;
 
  while(flag==0){
 
    system("clear");
  
    printf("\033[1;36m");
    printf("═════════════════════════════════════════════════");
    printf("\033[1;34m");
    printf("QUERY 4");
    printf("\033[1;36m");
    printf("═════════════════════════════════════════════════\n");
    printf("\033[1;35m0 -> Voltar \n");
    printf("\033[1;35m Ver codigos por Filial ou Totais(F/T) ?\033[1;36m\n");
    printf("══════════════════════════════════════════════════════════════════════════════════════════\n");
   
    scanf(" %c",&c);
    if(c=='0') return -1;
    else{

    if (!(c=='T' || c=='F')){
     puts("\033[1;31mLetra inválida");
     clearAndEnter();
    }
     
  
    if (c=='T'){
     res=0;
     flag=1;
    }   
    else if (c=='F'){ 

    printf("\033[1;34mEscolha a filial |1|2|3|?\n");
    scanf(" %d",&f);
    if(f==0) return -1;
    if(f>3){
      printf("\033[1;31mValor inválido\n");
      return -2;
    }
    else{
    res=f;
    flag=1;
    }
    }
 
  }
} 
return res;


}
/*
printf(“\033[0;31m”); --> vermelho
[1;31m vermelho escuro
[0;32m verde
[1;32m verde escuro
[0;33m amarelo
[1;33m amarelo escuro
[0;34m azul
[1;34m azul escuro
[0;35m magenta
[1;35m magenta escuro
[0;36m cyan
[1;36m cyan escuro
[0m reset
printf("\033[1;36m ");
*/

//---Output Query 4 e 5
void printLst(Lista lst){
 
  system("clear");
  navega(lst);
  removeLst(lst);
}

//--------------------------------------------------QUERY-6

void printPar(Par p){
 
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 6");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n");
  printf("\033[1;35m0 -> Voltar \n\n");
  printf("\033[1;34mNÚMERO DE CLIENTES QUE NÃO REALIZARAM COMPRAS:\033[1;35m  %d\n\033[1;34m",getClientsNeverBoughtCount(p));
  printf("NÚMERO DE PRODUTOS NÃO COMPRADOS:\033[1;35m  %d\n\n\033[1;34m ",getProductsNeverBoughtCount(p) );
  clearAndEnter();
}

//--------------------------------------------------QUERY-7

int inputQuery7(char* code){
 
system("clear");
printf("\033[1;35m0 -> para voltar\n");
printf("\033[1;34mInsira o código de cliente:\n");

scanf(" %s",code);
  if (code[0]=='0') return -2;
  if (strlen(code)!=5){
    printf("\033[1;31mCódigo de cliente inválido\n");
    return -1;
  }
  if (!isalpha(code[0])) {
    printf ("\033[1;31mPrimeiro caracter é uma letra\n");
    return -1;
  }
  if (!(code[0] >='A' && code[0]<='Z')){
    printf("\033[1;31mLetra tem que ser maiúscula\n");
    return -1;
  }
  if (!(atoi(code+1)>=1000) && atoi(code+1)<=5000){
    printf("\033[1;31mRestantes caracteres têm que ser numéricos\n");
    return -1;
  }
 
return 0;

}


void printQuery7(Tabela tbl){
 
  system("clear");
  printf("\n");
  printf("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
  printf("\033[1;33m      | Jan | Feb | Mar | Apr | May | Jun | Jul | Aug | Sep | Oct | Nov | Dec |\n");
  printf("\033[1;32m------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|\n");
    
    for(int i = 0; i < 3; i++){
      if(i == 0)printf("\033[0;33mOne   ");
      if(i == 1)printf("\033[0;33mTwo   ");
      if(i == 2)printf("\033[0;33mThree ");
      
        for(int j = 0; j < 12; j++){
          printf("|\033[0;34m %3d\033[1;32m ",getComprado(tbl,j,i));            
        }

      printf("|\n");
    }

  printf("\n");
  printf("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
  clearAndEnter();
}

//--------------------------------------------------QUERY-8

int inputQuery8(int* mes1,int* mes2){
  
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 8");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n");
  printf("\033[1;34m0 -> Voltar \033[1;36m\n\n");
  printf("\033[1;35mIndique o intervalo de meses no qual quer ver o numero de vendas e o total faturado nesse periodo.\n");
  printf("\033[1;36m══════════════════════════════════════════════════════════════════════════════════════════════════════════\n\n");
  
  printf("\033[0;34mIndique o mês 1\033[0;32m\n");
  scanf("%d",mes1);
    
    if(*mes1==0)
      return -2;
    
    if (*mes1>12 || *mes1 <0){
      puts("\033[0;31mMês inválido"); 
      return -1;
    }
  
  printf("\033[0;34mIndique o mês 2\033[0;32m\n");
  scanf("%d",mes2);
    if (*mes2==0)
      return -2;
    if (*mes2>12 || *mes2<0 || *mes2<*mes1){
      puts ("\033[0;31mMês inválido");
      return -1;
    }

  *mes1-=1;
  *mes2-=1;

  return 0;
}



void printQuery8(Profit p,int mes1,int mes2){
 
  printf("\033[1;33mO total de vendas entre o intervalo de meses %d e %d foi:\n\n",mes1+1,mes2+1);
 
  printf("\033[1;34mTotal de vendas:\033[1;33m %d\n",getVendas(p));
  printf("\033[1;34mTotal faturado:\033[1;33m %f\n",getFaturado(p));
  printf("\n");
  clearAndEnter();
}

//--------------------------------------------------QUERY-9

int inputQuery9(char* productID){
  
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 9");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n"); 
  
  int x;
  printf("Indique o produto:\n");
  scanf("%s",productID);
    
    if (*productID=='0')
      return -2;
    
    if (strlen(productID)!=6){
      printf("\033[1;31mCódigo de produto inválido\n");
      return -1;
    }
  
    if (!isalpha(productID[0]) && isalpha(productID[0])){
      printf("\033[1;31m Primeiros 2 caracteres não são letras\n");
      return -1;
    }
    
    if (!(productID[0]>='A' && productID[0]<='Z' && productID[1]>='A' && productID[1]<='Z')){
      printf("\033[1;31m Primeiros 2 caracteres não são letras maíusculas\n");
      return -1;
    }
    
    if (!(atoi(productID+2)>=1000) && atoi(productID+2)<=9999){
      printf("\033[1;31m Últimos 4 caracteres têm de ser numéricos\n");
      return -1;
    }
    
    printf("Indique a filial:\n");
    scanf("%d",&x);

    if(x==0)
      return -2;
    
    if(x>3 || x<0){
      printf ("\033[1;31Filial assume os valores de 1 a 3.");
      return -1;
    }
  
  x--;
  return x;


}


void printQuery9(LstBuyers l){
  system("clear");
    if (sizeLst(getListaN(l))==0){
      printf("Não há registos nesta filial.\n\n");
      clearAndEnter();
    }
    else{
      printf("\033[1;33m════════════════════════════════════════════════"); 
      printf("COMPRADORES MODO(N)════════════════════════════════════════════════\n\n");
      navega(getListaN(l));
      system("clear");
        
        if (sizeLst(getListaP(l))==0){
          printf("Não há registos nesta filial:\n");
          clearAndEnter();
    }
        else{
  printf("════════════════════════════════════════════════");
  printf("COMPRADORES MODO(P)════════════════════════════════════════════════\n\n");
  

  navega(getListaP(l));
 }
 } 

}


int inputQuery10(char* clientID){
  
  int x;
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 10");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n");


  printf("\033[1;33mIndique um cliente:\n");
  scanf("%s",clientID);
  
  if (*clientID=='0') 
    return -2;
  
  if (strlen(clientID)!=5){printf("\033[1;31mCódigo de cliente inválido\n");
    return -1;}

  
  if (!isalpha(clientID[0])) {
    printf ("\033[1;31mPrimeiro caracter é uma letra\n");
    return -1;}
  
  if (!(clientID[0] >='A' && clientID[0]<='Z')){
    printf("\033[1;31mPrimeira letra tem que ser maiúscula\n");
    return -1;}
  
  if (!(atoi(clientID+1)>=1000) && atoi(clientID+1)<=5000){
    printf("\033[1;31mRestantes caracteres têm que ser numéricos\n");
    return -1;}
  
 
  printf("\033[1;33mIndique o mês:\n");
  scanf("%d",&x);
    if(x==0) return -2;
    if (x>12 || x<0){
     printf("\033[1;31mMês inválido\n");
     return -1;
    }
  
  return x;

}


int inputQuery11(){
  
  int x;
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 11");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n");


  printf("\033[1;33mIndique o limite do top:\n");
 
  scanf("%d",&x);
 

  return x;

}

void printQuery11(SelledProd* s,int x){


  system("clear");
  printf("\033[1;35m═════════════════════════════════════════════════\n");
  
  for(int i=0;i<x;i++){
    
    printf("%d)\n",i+1);
    printf("\033[1;34mCódigo Produto:\033[1;33m%s\n",getProdCode(s[i]));
    printf("\n");
    
    int* num_clientes=getNumClientes(s[i]);
    int* unidades_vendidas_filial=getUnidadesVendidasFilial(s[i]);
    
    printf("\033[1;34mNr. de unidades vendidas:\033[1;33m%d\n",getUnidadesVendidasProd(s[i]));
    printf("\n");
  
    for(int i=0;i<3;i++)
      
      printf("\033[1;34mNr. compradores na filial \033[1;33m%d\033[0m--->\033[1;36m%d\n",i+1,num_clientes[i] );  
    
    printf("\n");
  
    for(int i=0;i<3;i++)
    
      printf("\033[1;34mNr. unidades vendidas na filial \033[1;33m%d\033[0m--->\033[1;36m%d\n",i+1,unidades_vendidas_filial[i] );
    
    printf("\033[1;35m═════════════════════════════════════════════════\n");

  }

  clearAndEnter();
}

//---Query 12

int inputQuery12(char* clientID){
  
  int x;
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n");
  printf("\033[1;34m");
  printf("QUERY 12");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n");

  printf("Indique um cliente:\n");
  scanf("%s",clientID);

  printf("Indique o limite do top:\n");
 
  scanf("%d",&x);
 

  return x;

}

void printQuery12(GList* l){


  system("clear");
  printf("═════════════════════════════════════════════════\n");
  g_list_first(l);
    
    while(l){
     
    TopProds tp=(TopProds)l->data;  
     
    printf("Código:%s,total gasto=%f\n",getCodeTop(tp),getGastoTop(tp));  
    l=g_list_next(l); 
   
    }
    printf("═════════════════════════════════════════════════\n");
  

  clearAndEnter();
}

