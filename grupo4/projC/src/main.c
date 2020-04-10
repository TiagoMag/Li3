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
  clock_t begin, end;
  double cpu_time_used;

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
              
               
                Lista rsl=getProductsStartedByLetter(sgv,c);
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
             
             
              c=inputQuery3(codigo,&mes);
          
              if (c=='0') voltar();
          
              else {
                if (c=='-'){
                  puts("\033[1;31mErro");
                  clearAndEnter();
                } 
        
                else{
        
                 Lista rsl=getProductSalesAndProfit(sgv,codigo,mes);
                  printQuery3(rsl,c);
                  free(codigo);

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
                 
                 Lista lst=getProductsNeverBought(sgv,x);
                  printLst(lst);
                }        
              }
          }
        }
  
        else if(option==5){
          if(check!=1) erro();
  
          else{
            
            Lista lst=getClientesOfAllBranches(sgv);
            printLst(lst);
          }

        }
        
        else if(option==6){
      
          if(check!=1)
            erro();

          else{
            begin=clock();
            Par p=getClientsAndProductsNeverBoughtCount(sgv);
            end = clock();
            cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
            printPar(p,cpu_time_used);
   
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
        
              begin=clock();
              Tabela tbl=getProductBoughtByClient(sgv,codigo);
              end=clock();
              cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
              printQuery7(tbl,cpu_time_used);
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
            
            int a=inputQuery8(&mes1,&mes2);
            
            if (a==-2) voltar();
            
            else{
              
              if(a == -1) clearAndEnter();

              else{
              begin=clock();
              Profit p=getSalesAndProfit(sgv,mes1,mes2);
              end=clock();
              cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
              printQuery8(p,mes1,mes2,cpu_time_used);
              removeProfit(p);
              }
            }
          }
        }
  
        else if(option==9){
      
          if(check!=1) erro();
    
          else{

            
            char* codigo=malloc(sizeof(char*));
            int x=inputQuery9(codigo);
      
            if(x==-2) voltar();
            
            else{
              
              if(x==-1) clearAndEnter();
       
              else{

                LstBuyers l;
                begin=clock();
                l=getProductBuyers(sgv,codigo,x);
                end=clock();
                cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
                printQuery9(l,cpu_time_used);
                removeLstBuyers(l);
                free(codigo);
              }
            }
          }
        }

        else if(option==10){

          if(check!=1) erro();
        
          else{
          
            
            char* codigo=malloc(sizeof(char*));
            int x=inputQuery10(codigo);
            
              if(x==-2) voltar();
          
                else{
            
                  if(x==-1) clearAndEnter();
          
                  else{
                   begin=clock();
                   Lista l=getClientFavoriteProducts(sgv,codigo,x-1);
                   end=clock(); 
                   cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
                    printLst10(l,cpu_time_used);
                    free(codigo);
                  }
                } 
              }
          }

        else if(option==11){
          
          if(check!=1) erro();
          
          else{
            SelledProd* s;
            int x;
            if((x=inputQuery11())==-1) voltar();
            else{

            begin=clock();
            s=getTopSelledProducts(sgv,x);
            end=clock();
            cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
            printQuery11(s,x,cpu_time_used);
          }
          }

        }

        else if(option==12){
          if(check!=1) erro();


          else{
            
            GList* s;
            char* codigo=malloc(sizeof(char*));
            int x=inputQuery12(codigo);
              if(x==-2) voltar();
                 
              else{
                if (x==-1) clearAndEnter();
                  
                 else{
                  begin=clock();
                  s=getClientTopProfitProducts(sgv,codigo,x);
                  end=clock();
                  cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
                  printQuery12(s,cpu_time_used);
                  free(codigo);
                  }
              }
          }

        } else if(option==13){
        FileInfo fi=getCurrentFilesInfo(sgv);
        printQuery13(fi);
        }

        else if(option==14){
          if (check!=1) erro();
          
          else{
            destroySGV(sgv);
          }
        }


        else if(option==0){
          destroySGV(sgv);
          system("clear");
          exit(0);

       
        }
 }
return 0;
}


