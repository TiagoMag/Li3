#include "../include/SGV.h"

static char file1[]="ficheiros/Clientes.txt";
static char file2[]="ficheiros/Produtos.txt";
static char file3[]="ficheiros/Vendas_1M.txt";
char* arr_token[CAMPOS];

struct sgv{
 Cat_Clientes cc;
 Cat_Produtos cp;
 Faturacao f;
 Filial fil[3];
};


SGV initSGV(){

 SGV sgv=(SGV)malloc(sizeof(struct sgv));
 sgv->cc=inicializa_CatClientes();
 sgv->cp=inicializa_CatProds();
 sgv->f=inicializaFat();
 for(int i=0;i<FILIAL;i++)
  sgv->fil[i]=inicializa_Filial();
 
 return sgv;
}

void destroySGV(SGV sgv){
 removeCatCliente(sgv->cc);
 removeCatProd(sgv->cp);
 removeFaturacao(sgv->f);
  for(int i=0;i<3;i++)
   removeFilial(sgv->fil[i]); 
 
}


SGV loadFromFiles(char* filesPath[3],SGV sgv){
 
 if(totalClientes(sgv->cc)>0) {destroySGV(sgv);sgv=initSGV();}

 if(strcmp(filesPath[0],"D")!=0){
  strcpy(file1,filesPath[0]);
  strcpy(file2,filesPath[1]);
  strcpy(file3,filesPath[2]);
 }

 loadFilesCliente(file1,sgv->cc);
 loadFilesProduto(file2,sgv->cp);
 leVendas(sgv->fil,sgv->f,file3,arr_token,sgv->cp,sgv->cc);

 return sgv;
}

Lista getProductsStartedByLetter(SGV sgv,char letter){
 Lista lst=inicializa_lista();
 lst=produtosComecadoPelaLetra(sgv->cp,letter);

 return lst;
}

Lista getProductSalesAndProfit(SGV sgv,char* productID,int month){
 Lista lst=inicializa_lista();
 lst=productSalesAndProfit(sgv->f,productID,month);

 return lst;
}

Lista getProductsNeverBought(SGV sgv,int branchID){
 Lista lst=inicializa_lista();
 lst=productsNeverBought(sgv->fil[branchID-1],sgv->f,sgv->cp,branchID);

return lst;
}

Lista getClientesOfAllBranches(SGV sgv){
 Lista lst=inicializa_lista();
 lst=clientesOfAllBranches(sgv->cc,sgv->fil);
return lst;
}

Par getClientsAndProductsNeverBoughtCount(SGV sgv){
  Par p=initPar();
  p=clientsAndProductsNeverBoughtCount(p,sgv->cp,sgv->cc,sgv->f,sgv->fil);
  return p;

}

Tabela getProductBoughtByClient(SGV sgv,char* clientID){

  Tabela t=initTabela();
  t=productBoughtByClient(t,sgv->fil,clientID);
  return t;


}

Profit getSalesAndProfit(SGV sgv,int minMonth,int maxMonth){
  Profit p=initProfit();
  p=salesAndProfit(sgv->f,p,minMonth,maxMonth);
  return p;

}


LstBuyers getProductBuyers(SGV sgv,char* productID,int branchID){
 LstBuyers l=initLstBuyers();
 l=productBuyers(l,sgv->fil[branchID],productID);
 return l;


}

Lista getClientFavoriteProducts(SGV sgv,char* clientID,int month){
 Lista lst=inicializa_lista();
 lst=clientFavoriteProducts(sgv->fil,clientID,month);
  return lst;
}