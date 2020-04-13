#include "../../include/Controller.h"

/* Funções privadas ao módulo */
static void erro();

static void erro(){

  int c;
  system("clear");
  printf("\033[1;31m");
  while ((c= getchar()) != '\n' && c != EOF);
  
  puts("AVISO! \033[1;31m É NECESSÁRIA A LEITURA DOS FICHEIROS.\n\n\033[0;33mENTER para voltar atrás\n");
  getchar();
}

int runController(){

	SGV sgv=initSGV();
  
  int exit=0;
  int check=0;

  char c;
 
  clock_t begin, end;
  double cpu_time_used;

	while(!exit) {

    	  main_menu();
      	int option;
      	scanf(" %d",&option);

       	switch(option){
        case 0:
          	destroySGV(sgv);
          	system("clear");
          	exit=1;
          	break;
        case 1:
            if (check==1){destroySGV(sgv);sgv=initSGV();}
            char* filenames[3];
            for(int i=0;i<3;filenames[i++]=NULL);
            inputQuery1(sgv,filenames);
            sgv=loadFromFiles(filenames,sgv);
            for(int i=0;i<3;free(filenames[i++]));
            check=1; 
            clearAndEnter();
            break;
        case 2:
         	if(check!=1) erro();
            while((c=inputQuery2())!='0'){  	
            	Lista rsl=getProductsStartedByLetter(sgv,c);
            	printQuery2(rsl);
            }
            break;
        case 3:
            if(check!=1) erro();
            else{
            	char c;
            	int mes;
            	char* codigo=malloc(sizeof(char*));
            	while((c=inputQuery3(codigo,&mes))!='0'){
                	Lista rsl=getProductSalesAndProfit(sgv,codigo,mes);
                 	printQuery3(rsl,c);
              }
              free(codigo);
            }
            break;
        case 4:
            if(check!=1) erro();
            else{
            	int x;
              	while((x=inputQuery4())!=-1){ 
               	    Lista lst=getProductsNeverBought(sgv,x);
        	          printLst(lst);
                }
          	}
         	break;
        case 5:
            if(check!=1) erro();
            else{
          		Lista lst=getClientesOfAllBranches(sgv);
             	printLst(lst);
            }
            break; 
        case 6:
            if(check!=1) erro();
            else{
            	begin=clock();
            	Par p=getClientsAndProductsNeverBoughtCount(sgv);
            	end = clock();
            	cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
            	printPar(p,cpu_time_used);
   			    }
            break;
        case 7:
            if(check!=1)
            erro();
            else{
            	char* codigo=malloc(sizeof(char*));
            	int a;
            	while((a=inputQuery7(codigo))!=-2){
        			    	begin=clock();
              			Tabela tbl=getProductBoughtByClient(sgv,codigo);
              			end=clock();
              			cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
              			printQuery7(tbl,cpu_time_used);
              			removeTabela(tbl); 
              	}
              free(codigo);
            }
            break;
        case 8:
  			if(check!=1) erro();
     		else{
            	int mes1;
            	int mes2;
            	int a;
            while((a=inputQuery8(&mes1,&mes2))!=-2){
              if(a != -1){ 
              	begin=clock();
              	Profit p=getSalesAndProfit(sgv,mes1,mes2);
              	end=clock();
              	cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
              	printQuery8(p,mes1,mes2,cpu_time_used);
              	removeProfit(p);
              }
            }
          }
          break;
        case 9:
      		if(check!=1) erro();
    		else{
				char* codigo=malloc(sizeof(char*));
            	int x=inputQuery9(codigo);
                while((x=inputQuery9(codigo))!=-2){
              		if(x!=-1){
              			LstBuyers l;
                		begin=clock();
                		l=getProductBuyers(sgv,codigo,x);
                		end=clock();
                		cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
                		printQuery9(l,cpu_time_used);
                		removeLstBuyers(l);                		
              	    }
              	}
              	free(codigo);
            }
          break;
        case 10:
            if(check!=1) erro();
            else{
            	char* codigo=malloc(sizeof(char*));
            	int x;
            	while((x=inputQuery10(codigo))!=-2){
                	if(x!=-1){
                		  begin=clock();
                   		Lista l=getClientFavoriteProducts(sgv,codigo,x-1);
                   		end=clock(); 
                    	cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
                    	printLst10(l,cpu_time_used);
                  }
              }
              free(codigo);
            }
            break;
        case 11:
            if(check!=1) erro();
            else{
            	SelledProd* s;
            	int x;
            	while((x=inputQuery11())!=-1){
					      begin=clock();
           			s=getTopSelledProducts(sgv,x);
            		end=clock();
            		cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
            		printQuery11(s,x,cpu_time_used);
          	  }
          	}
          	break;
        case 12:
            if(check!=1) erro();
            else{
            	GList* s;
            	char* codigo=malloc(sizeof(char*));
            	int x;
              	while((x=inputQuery12(codigo))!=-2){
                	if (x!=-1){
                  		begin=clock();
                  		s=getClientTopProfitProducts(sgv,codigo,x);
                  		end=clock();
                  		cpu_time_used = (float)(end - begin) / CLOCKS_PER_SEC;
                  		printQuery12(s,cpu_time_used);
                  		free(codigo);
                  }
                }
            }
            break;
        case 13: ;
            FileInfo fi=getCurrentFilesInfo(sgv);
            printQuery13(fi);
            break;
        case 14:
            if (check!=1) erro();
            else{
            	destroySGV(sgv);
          	}
            check=0;
          	break;
		}
	}
	return 0;
}
