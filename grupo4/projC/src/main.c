#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "../include/SGV.h"
#include "../include/menu.h"
#include "../include/Navegador.h"

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
            if ((c=inputQuery2())=='0')
              voltar();
       

            else{
              
              if(c=='-')
                clearAndEnter();
              
              else{
              
                Lista rsl=inicializa_lista();
                rsl=getProductsStartedByLetter(sgv,c);
                printQuery2(rsl);
              
              }
            }
          }

        }
        
        else if(option==3){
    
            if(check!=1) erro();
    
            else{
      
              char c;
              int mes;
              char* codigo=malloc(sizeof(char*));
             
              Lista rsl=inicializa_lista();
              c=inputQuery3(codigo,&mes);
          
              if (c=='0') voltar();
          
              else {
                if (c=='-'){
                  puts("\033[1;31mErro");
                  clearAndEnter();
                } 
        
                else{
        
                  rsl=getProductSalesAndProfit(sgv,codigo,mes);
                  printQuery3(rsl,c);

                }
              }
            }
        }
  
        else if(option==4){
      
          if(check!=1) erro();
    
          else{
            
            int x;
              
              if((x=inputQuery4())==-1) 
                voltar();

              else{
                if (x==-2) clearAndEnter();

                else{
                  Lista lst=inicializa_lista();
                  lst=getProductsNeverBought(sgv,x);
                  printLst(lst);
                }        
              }
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
      
          if(check!=1)
            erro();

          else{
            Par p=initPar();
            p=getClientsAndProductsNeverBoughtCount(sgv);
            printPar(p);
   
          }
        }

        else if(option==7){
      
          if(check!=1)
            erro();
    
          else{
            char* codigo=malloc(sizeof(char*));
            int a=inputQuery7(codigo);
       
            if(a==-2) voltar(); 
            
            else{
              if(a==-1){
                puts("Erro de input");
                clearAndEnter();
              }

              else{
        
              Tabela tbl=initTabela();
              tbl=getProductBoughtByClient(sgv,codigo);
              printQuery7(tbl);
              free(codigo);
              removeTabela(tbl);
              }
            }
          }
        }

        else if(option==8){
  
          if(check!=1) erro();
     
          else{
            int mes1;
            int mes2;
            Profit p=initProfit();
            int a=inputQuery8(&mes1,&mes2);
            
            if (a==-2) voltar();
            
            else{
              
              if(a == -1) clearAndEnter();

              else{
              p=getSalesAndProfit(sgv,mes1,mes2);
              printQuery8(p,mes1,mes2);
              removeProfit(p);
              }
            }
          }
        }
  
        else if(option==9){
      
          if(check!=1) erro();
    
          else{

            LstBuyers l=initLstBuyers();
            char* codigo=malloc(sizeof(char*));
            int x=inputQuery9(codigo);
      
            if(x==-2) voltar();
            
            else{
              
              if(x==-1) clearAndEnter();
       
              else{
                printQuery9(l=getProductBuyers(sgv,codigo,x));
                removeLstBuyers(l);
              }
            }
          }
        }

        else if(option==10){

          if(check!=1) erro();
        
          else{
          
            Lista l=inicializa_lista();
            char* codigo=malloc(sizeof(char*));
            int x=inputQuery10(codigo);
            
              if(x==-2) voltar();
          
                else{
            
                  if(x==-1) clearAndEnter();
          
                  else{
                  
                    l=getClientFavoriteProducts(sgv,codigo,x-1);
                    printLst(l);
                  }
                } 
              }
          }

        else if(option==11){
          
          if(check!=1) erro();
          
          else{
            SelledProd* s;
            int x=inputQuery11();
            s=getTopSelledProducts(sgv,x);
            printQuery11(s,x);
          }

        }

        else if(option==12){
          if(check!=1) erro();
          GList* s;
          char* codigo=malloc(sizeof(char*));
          int x=inputQuery12(codigo);
          s=getClientTopProfitProducts(sgv,codigo,x);
          printQuery12(s);
     

        }
        else if(option==14){

        destroySGV(sgv);
        }

        else if(option==0){
          destroySGV(sgv);
          system("clear");
          exit(0);

       
        }
 }
return 0;
}


