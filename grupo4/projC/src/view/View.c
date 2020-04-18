#include "../../include/View.h"

static void navega(Lista lst);

/* Função auxiliar para apresentar inicio de alguns output's */
void printInicio(char* string){
   
   printf("\033[1;36m");
   printf("═════════════════════════════════════════════════");
   printf("\033[1;34m");
   printf("%s",string);
   printf("\033[1;36m");
   printf("═════════════════════════════════════════════════\n");
}

/* Menu de apresentção inicial */
void main_menu(){

  system("clear");
  
  printInicio("MENU PRINCIPAL");
  printf("\033[0;31m");
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
  printf("\033[1;33mInformação dos ficheiros lidos.\033[0;31m\n\n");
  printf("14.");
  printf("\033[1;33mFree Structs.\033[1;36m\n\n");
  
  printf("══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n\n");

  printf("\033[1;34m");
  printf("Selecione a opção: \n");

}

/* Navegador */
static void navega(Lista lst){

  if (sizeLst(lst)==0){
    printf("\033[01;33mLista sem Elementos\n");
    printf("PRESS \033[1;34m  ENTER ->  \033[1;36m PARA CONTINUAR\n");
    getchar();
    return ;
  }
  else{
    int totalpages=paginasTotal(lst);
    int pagina=1;
    char c;
    
    while(pagina>0 && pagina<=totalpages){
      
      int x=0;
      int arraybegin=(MAX_LIN*(pagina-1));
      Pagina p=getPageSeguinte(lst,arraybegin);
      
      printInicio("NAVEGADOR");
      
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
      removePagina(p);
      
      while ((c = getchar()) != '\n' && c != EOF) { }
      c=getchar();
      
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

/* Lima input e espera que user presse um tecla */
void clearAndEnter(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  printf("PRESS \033[1;34m  ENTER ->  \033[1;36m PARA CONTINUAR");
  getchar();
}

/*--------------------------------QUERY-2/4/5------------------------*/

void printLst(Lista lst){
  system("clear");
  navega(lst);
  removeLst(lst);
}

/*--------------------------------QUERY-3--------------------------*/

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
 
    char* filial[3];
    filial[0]="FILIAL 1";
    filial[1]="FILIAL 2";
    filial[2]="FILIAL 3";
       
    int h=3; 
    
    for(int j=0;j<3;j++){
        
      printInicio(filial[j]);
        
      printf("Nmr de vendas      (P):%s\n",getStringLst(lst,h++));
      printf("Total Faturado     (P):%s\n",getStringLst(lst,h++));
      printf("Nmr de vendas      (N):%s\n",getStringLst(lst,h++));
      printf("Total Faturado     (N):%s\n",getStringLst(lst,h++));
    }
    clearAndEnter();    
 }
 removeLst(lst);
}

/*--------------------------------QUERY-6--------------------------*/

void printPar(Par p,float time){
   
  system("clear");
  printInicio("QUERY 6");
  printf("\033[1;35m0 -> Voltar \n\n");
  printf("\033[1;34mNÚMERO DE CLIENTES QUE NÃO REALIZARAM COMPRAS:\033[1;35m  %d\n\033[1;34m",getClientsNeverBoughtCount(p));
  printf("NÚMERO DE PRODUTOS NÃO COMPRADOS:\033[1;35m  %d \033[1;34m \n",getProductsNeverBoughtCount(p) );
  printf("\n");
  printf("\033[1;34mTempo da Query:\033[1;35m%f\n",time);
  printf("\n");
  clearAndEnter();
  removePar(p);
}

/*--------------------------------QUERY-7--------------------------*/

void printQuery7(Tabela tbl,float time){
   
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
  printf("\033[1;34mTempo da Query:\033[1;35m%f\n",time);
  clearAndEnter();
}

/*--------------------------------QUERY-8--------------------------*/

void printQuery8(Profit p,int mes1,int mes2,float time){
  
  system("clear");
  
  printf("\033[1;33mO total de vendas entre o intervalo de meses %d e %d foi:\n\n",mes1+1,mes2+1);
    
  printf("\033[1;34mTotal de vendas:\033[1;33m %d\n",getVendas(p));
  printf("\033[1;34mTotal faturado:\033[1;33m %f\n",getFaturado(p));
  printf("\n");
  printf("\033[1;34mTempo da Query:\033[1;35m%f\n",time);
  clearAndEnter();
}

/*--------------------------------QUERY-9--------------------------*/
  
void printQuery9(LstBuyers l,float time){
  
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
  }    
  if (sizeLst(getListaP(l))==0){
    printf("Não há registos nesta filial:\n");
    clearAndEnter();
  }
  else{
    printf("════════════════════════════════════════════════");
    printf("COMPRADORES MODO(P)════════════════════════════════════════════════\n\n");        
    navega(getListaP(l));  
  }
  printf("\033[1;34mTempo da Query:\033[1;35m%f\n",time);
  clearAndEnter();
}

/*--------------------------------QUERY-10--------------------------*/
  
void printLst10(Lista lst,float tempo){
   
  system("clear");
  navega(lst);
  printf("\033[1;34mTempo da Query:\033[1;35m%f\n",tempo);
  clearAndEnter();
  removeLst(lst);
}

/*--------------------------------QUERY-11--------------------------*/

void printQuery11(SelledProd* s,int x,float time){

  system("clear");
  printf("\033[1;35m═════════════════════════════════════════════════\n");
    
  for(int i=0;i<x;i++){
    int total_buyers=0;
    printf("%d)\n",i+1);
    printf("\033[1;34mCódigo Produto:\033[1;33m%s\n",getProdCode(s[i]));
    printf("\n");
    printf("\033[1;34mNr. de unidades vendidas Total:\033[1;33m%d\n",getUnidadesVendidasProd(s[i]));
    
    for(int j=0;j<3;j++)
      total_buyers+=getNumClientes(s[i],j);

    printf("\033[1;34mNr. compradores Total:\033[1;33m%d\n",total_buyers);
    printf("\n");
    
    for(int j=0;j<3;j++)
      printf("\033[1;34mNr. compradores na filial \033[1;33m%d\033[0m--->\033[1;36m%d\n",j+1,getNumClientes(s[i],j));  
    
    printf("\n");
      
    for(int j=0;j<3;j++)
      printf("\033[1;34mNr. unidades vendidas na filial \033[1;33m%d\033[0m--->\033[1;36m%d\n",j+1,getUnidadesVendidasFilial(s[i],j));
      
    printf("\033[1;35m═════════════════════════════════════════════════\n");
  }

  printf("\033[1;34mTempo da Query:\033[1;35m%f\n",time);

  for(int i=0;i<x;i++)
    removeSelledProds(s[i]);
  free(s);
  
  clearAndEnter();
}

/*--------------------------------QUERY-12---------------------------*/

void printQuery12(GList* l,float time){

  system("clear");
  printf("\033[1;36m═════════════════════════\033[1;33mTOP\033[1;36m═════════════════════════\n");
  
  g_list_first(l);

  if(!l) {printf("\033[1;34mCliente não realizou compras.\n");}
  
  while(l){
    TopProds tp=(TopProds)l->data;  
    char* codigo=getCodeTop(tp);
    
    printf("\033[1;34mCódigo:\033[1;33m%s\t\033[1;34mTotal gasto=\033[1;33m%f\n",codigo,getGastoTop(tp));  
    
    GList *_link=l;
    removeTP(tp);
    free (codigo);
    l=g_list_delete_link(l,_link);
  }
  printf("═════════════════════════════════════════════════\n");
  printf("\033[1;34mTempo da Query:\033[1;35m%f\n",time);
    
  g_list_free(l);

  clearAndEnter();
}

/*--------------------------------QUERY-13--------------------------*/

void printQuery13(FileInfo f){
  
  system("clear");

  char* fileType[3];
  fileType[0]="Produtos";
  fileType[1]="Clientes";
  fileType[2]="Vendas";
   
  for(int i=0;i<3;i++){
    printInicio(fileType[i]);
    printf("Nome do ficheiro lido:");
    printf("\033[1;33m");
    printf(" %s \n",getFileNameFI(f,0));
    printf("\033[1;36m");
    printf("Número de linhas lidas:");
    printf("\033[1;33m");
    printf(" %d \n",getNumLinhasLidasFI(f,i));
    printf("\033[1;36m");
    printf("Número de linhas validadas:");
    printf("\033[1;33m");
    printf(" %d \n\n",getNumLinhasValidadasFI(f,i));
    printf("\033[1;32m");
    printf("Tempo: \033[1;34m  %f \n\n",getTempoLeituraFI(f,i));
    printf("\033[1;36m");    
  }
  removeFileInfo(f);
  clearAndEnter();
}