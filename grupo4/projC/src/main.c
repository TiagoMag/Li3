#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "headers/SGV.h"
#include "headers/menu.h"
#include "headers/Navegador.h"

int main(){
    
  SGV sgv=initSGV();
  int option=50;
  char c;
  int check=0;
  int a;

 while(option>=0){
  option=main_menu();
    
    if(option==1){
     check=1; 
     char* filenames[3];
  
    if((a=inputQuery1(sgv,filenames))<0)
     voltar();
    
    else{
     sgv=loadFromFiles(filenames,sgv);
     clearAndEnter();
   }
  }
  
  else if(option==2){
    if(check!=1) erro();
    
    else{
        c=inputQuery2();
        Lista rsl=inicializa_lista();
        rsl=getProductsStartedByLetter(sgv,c);
        printQuery2(rsl);
        }
      
  }
  else if(option==3){
    
    if(check!=1)
     erro();
    else{
       char c;
       int mes;
       char* codigo=malloc(sizeof(char*));
          Lista rsl=inicializa_lista();
        c=inputQuery3(codigo,&mes);
         rsl=getProductSalesAndProfit(sgv,codigo,mes);
       printQuery3(rsl,c); 
       }
  }
  else if(option==4){
         if(check!=1) erro();
    else{
         int x;
         x=inputQuery4();
         Lista lst=inicializa_lista();
         lst=getProductsNeverBought(sgv,x);
         printLst(lst);
        }
      }
  else if(option==5){
      if(check!=1) erro();
      else{
         Lista lst=inicializa_lista();
         lst=getClientesOfAllBranches(sgv);
         printLst(lst);
    }

        }
 else if(option==6){
     if(check!=1)erro();
    else{

         Par p=initPar();
         
       
         //begin = clock();
         p=getClientsAndProductsNeverBoughtCount(sgv);
         //end = clock();
         //cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
         //printf("TEMPO:%f\n",cpu_time_used);
         printPar(p);
   
}
        }
  else if(option==7){
    if(check!=1) erro();
    else{
        char* codigo=malloc(sizeof(char*));
        inputQuery7(codigo);
        Tabela tbl=initTabela();
        //begin = clock();
        tbl=getProductBoughtByClient(sgv,codigo);
        //cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
       // printf("TEMPO:%f\n",cpu_time_used);
        printQuery7(tbl);
        free(codigo);
        removeTabela(tbl);
  }
}
    else if(option==8){
      if(check!=1) erro();
    else{
        int mes1;
        int mes2;
        Profit p=initProfit();
        inputQuery8(&mes1,&mes2);
        p=getSalesAndProfit(sgv,mes1,mes2);
        printQuery8(p,mes1,mes2);
        removeProfit(p);
  }
}
   else if(option==9){
 if(check!=1) erro();
    else{
       LstBuyers l=initLstBuyers();
       char* codigo=malloc(sizeof(char*));
       int x=inputQuery9(codigo);
       l=getProductBuyers(sgv,codigo,x);
       printQuery9(l);
       removeLstBuyers(l);
     }
  }
  else if(option==10){
       Lista l=inicializa_lista();
       char* codigo=malloc(sizeof(char*));
       int x=inputQuery10(codigo);
       l=getClientFavoriteProducts(sgv,codigo,x);
       printLst(l);
     

  }

    else if(option==0){
      exit(0);

    }
  }
  return 0;
}


