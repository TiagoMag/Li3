#include "headers/menu.h"


static void navega(Lista lst);

/*
printf(“\033[0;31m”); --> vermelho
[1;31m vermelho escuro
[0;32m verde
[1;32m verde escuro
[0;33m amarelo
[01;33m amarelo escuro
[0;34m azul
[1;34m azul escuro
[0;35m magenta
[1;35m magenta escuro
[0;36m cyan
[1;36m cyan escuro
[0m reset
printf("\033[1;36m ");

*/



int main_menu(){
system("clear");
printf("\033[1;36m");
printf("════════════════════════════════════════════════════");
printf("\033[1;34m");
printf("MENU PRINCIPAL");
printf("\033[1;36m");
printf("════════════════════════════════════════════════════\n\n");
printf("\033[0;31m");
printf(" 0.");
printf("\033[1;33m");
printf("SAIR.\n\n");
printf("\033[0;31m");
printf(" 1.");
printf("\033[1;33m");
printf("Leitura dos ficheiros.\n\n");
printf("\033[0;31m");
printf(" 2.");
printf("\033[1;33m");
printf("Listar produtos por uma determinada letra.\n\n");
printf("\033[0;31m");
printf(" 3.");
printf("\033[1;33m");
printf("Total e registos de vendas de um determinado produto num determinado mês.\n\n");
printf("\033[0;31m");
printf(" 4.");
printf("\033[1;33m");
printf("Lista ordenada de códigos de produtos que ninguém comprou (Total ou por filial).\n\n");
printf("\033[0;31m");
printf(" 5.");
printf("\033[1;33m");
printf("Lista de códigos de clientes que realizaram compras em todas as filiais.\n\n");
printf("\033[0;31m");
printf(" 6.");
printf("\033[1;33m");
printf("Clientes que não realizaram compras e número de produtos nunca comprados.\n\n");
printf("\033[0;31m");
printf(" 7.");
printf("\033[1;33m");
printf("Tabela de produtos comprados por mês e filial.\n\n");
printf("\033[0;31m");
printf(" 8.");
printf("\033[1;33m");
printf("Determinar total de vendas num determinado intervalo [MÊS 1; MÊS 2].\n\n");
printf("\033[0;31m");
printf(" 9.");
printf("\033[1;33m");
printf("Determinar os códigos e o número total dos clientes que compraram um produto numa filial.\n\n");
printf("\033[0;31m");
printf("10.");
printf("\033[1;33m");
printf("Determinar a lista de produtos que um cliente mais comprou por quantidade, num determinado mês.\n\n");
printf("\033[0;31m");
printf("11.");
printf("\033[1;33m");
printf("Top personalizado de vendas,por número de cliente e quantidade vendida, filial a filial.\n\n");
printf("\033[0;31m");
printf("12.");
printf("\033[1;33m");
printf("Top personalizado de gasto em compras individualizado por cliente.\n\n");
printf("\033[1;36m");
printf("══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n\n");


 char buffer[10];
 int option;
 printf("\033[1;34m");
 printf("Selecione a opção: ");
 scanf("%s",buffer);
 option=atoi(buffer);



return option;
}



static void navega(Lista lst){

   
   int totalpages=paginasTotal(lst);
   int pagina=1;
   char c;
   Pagina p=initPagina();
    while(pagina>0 && pagina<=totalpages){
 
     

     int arraybegin=(MAX_LIN*(pagina-1));
     
     p=getPageSeguinte(lst,arraybegin);
    
    // int per_line=MAX_LIN/MAX_COL;
   int x=0;
    printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("NAVEGADOR");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════\n");
    printf("Nmr total de elementos  -> %d\n",sizeLst(lst));  
    printf("Nmr elementos na página -> %d\n\n",sizeLstPage(p));  
    printf("Página %d de %d\n\n",pagina,totalpages);

    while(x<sizeLstPage(p)){
    
      char *produto=getString(p,x);
    
      printf("Código:%s\n",produto);
         x++;    
   }
    printf("═════════════════════════════════════════════════\n");
    printf("n -- avançar        x--sair             a -- recuar\n");
    while ((c = getchar()) != '\n' && c != EOF) { }
    c=getchar();
    if(c=='n')
    pagina++;
    if(c=='a')
    pagina--;
    if(c=='x')
    return ;
    system("clear");
    }

  
}

void clearAndEnter(){

 int c;
 while ((c = getchar()) != '\n' && c != EOF) { }
 printf("PRESS \033[1;34m  ENTER ->  \033[1;36m PARA CONTINUAR");
 getchar();

}

void voltar(){
  int c=0;
  while(c!=4){c++;}
}


void erro(){

 int c;
 system("clear");
 printf("\033[1;31m");
 while ((c= getchar()) != '\n' && c != EOF) { }
 puts("AVISO! É NECESSARIO A LEITURA DOS FICHEIROS.\n\nENTER para voltar atrás\n");
 printf("\033[1;34m");
 getchar();
}





//--------------------------------------------------QUERY-1


//adiciona-se ao .h?
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
printf("0 -> Voltar \n");
printf("Usar ficheiros default(S/N)?\n");
printf("\033[1;36m");
printf("══════════════════════════════════════════════════════════════════════════════════════════\n");

scanf("%s",buffer);
if((b=scanning(buffer,filenames))==0) return 0;

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
    printf("═════════════════════════════════════════════════");
    printf("0 -> Voltar \n");
    printf("Qual a letra do produto que pretende procurar [A-Z] ?\n");
    printf("══════════════════════════════════════════════════════════════════════════════════════════\n");
   
 scanf(" %c",&c);
    if (c=='0') voltar();
    else {
    if (!(c>='A' && c<='Z'))
     {puts("Letra inválida");exit(0);}
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
    printf("═════════════════════════════════════════════════");
  printf("0 -> Voltar \n");
    
  printf("Indique um mês ?\n");
  scanf(" %s",mes_str);
 
  *mes=atoi(mes_str)-1;
    
  printf("Indique um código de um produto?\n");  
  scanf(" %s",code);
    
  printf("Total ou por Filial(T/F)?\n"); 
  scanf(" %c",&c);    
    
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
    
  }else if(c=='F'){
   
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
  printf("═════════════════════════════════════════════════");
  printf("0 -> Voltar \n");
  printf("Ver codigos por Filial ou Totais(F/T) ?\n");
  printf("══════════════════════════════════════════════════════════════════════════════════════════\n");
   
  scanf(" %c",&c);
    
  if (!(c=='T' || c=='F')){
  puts("Letra inválida");
  clearAndEnter();
  }
  else if (c=='0') exit(0);
  
 if (c=='T') {res=0;flag=1;}   
 else if (c=='F'){ 

  printf("Escolha a filial ?\n");
  scanf(" %d",&f);
  res=f;
  flag=1;
 }
 
 }
 
 return res;

}
//---Output Query 4 e 5
void printLst(Lista lst){
 system("clear");
 navega(lst);
 removeLst(lst);
}

//--------------------------------------------------QUERY-6

void printPar(Par p){
  
  printf("Numero de clientes que não realizaram compras:%d\n",getClientsNeverBoughtCount(p));
  printf("Numero de produtos não comprado:%d\n",getProductsNeverBoughtCount(p) );
  clearAndEnter();
}

//--------------------------------------------------QUERY-7

void inputQuery7(char* code){
 system("clear");
 printf("Insira o código de cliente:\n");
 scanf(" %s",code);
}


void printQuery7(Tabela tbl){
system("clear");
printf("\n");
printf("      | Jan | Feb | Mar | Apr | May | Jun | Jul | Aug | Sep | Oct | Nov | Dec |\n");
    printf("------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|\n");
    for(int i = 0; i < 3; i++){
        if(i == 0)printf("One   ");
        if(i == 1)printf("Two   ");
        if(i == 2)printf("Three ");
        for(int j = 0; j < 12; j++){
            printf("| %3d ",getComprado(tbl,j,i));            
        }
        printf("|\n");
    }

  printf("\n");
  clearAndEnter();


}

//--------------------------------------------------QUERY-8

void inputQuery8(int* mes1,int* mes2){
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 8");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("0 -> Voltar \n");
  printf("Indique o intervalo de meses que quer ver o numero de vendas\n");
  printf("e o total faturado\n");
  printf("══════════════════════════════════════════════════════════════════════════════════════════\n");
  
  printf("Indique o mês 1\n");
  scanf("%d",mes1);
  printf("Indique o mês 2\n");
  scanf("%d",mes2);

  *mes1-=1;
  *mes2-=1;

}

void printQuery8(Profit p,int mes1,int mes2){

 printf("O total de vendas entre o intervalo de meses,%d e %d foi:\n",mes1,mes2);
 printf("Total de vendas:%d\n",getVendas(p));
 printf("Total faturado:%f\n",getFaturado(p));
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
 
  printf("Indique a filial:\n");
  scanf("%d",&x);

  return x;


}

void printQuery9(LstBuyers l){
   system("clear");
  printf("═════════════════════════════════════════════════\n"); 
  printf("COMPRADORES MODO(N)\n\n");
  navega(getListaN(l));
  system("clear");
 
  printf("COMPRADORES MODO(P)\n\n");
  printf("═════════════════════════════════════════════════\n");

  navega(getListaP(l));
  

}


int inputQuery10(char* clientID){
  
  int x;
  system("clear");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");
  printf("\033[1;34m");
  printf("QUERY 10");
  printf("\033[1;36m");
  printf("═════════════════════════════════════════════════");


  printf("Indique um cliente:\n");
  scanf("%s",clientID);
 
  printf("Indique o mês:\n");
  scanf("%d",&x);
  if (x>12 || x<0){
    printf("Mês inválido");
    exit(0);}

  return x;

}

