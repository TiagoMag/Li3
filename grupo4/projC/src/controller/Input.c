#include "../../include/Input.h"

/* Verifica se carater é o correto */
static int scanning(char buffer[100],char*filenames[3]){
 
  if (buffer[0]=='S'){
    filenames[0]=strdup("D");
    memset(buffer,0,100);
    
    return 0;
  }
 
  else if (buffer[0]=='N'){
    printf("\033[1;34mPaths ficheiro cliente: ");
    scanf("%s",buffer);
    filenames[0]=strdup(buffer);
  
    printf("\033[1;34mPath ficheiro produtos: ");
    scanf("%s",buffer);
    filenames[1]=strdup(buffer);
  
    printf("\033[1;34mPath ficheiro vendas: ");
    scanf("%s",buffer);
    filenames[2]=strdup(buffer);
  
    memset(buffer,0,100);
    
    return 0;
  }
 
 return 1;
}

/*--------------------------------QUERY-1------------------------*/

int inputQuery1(SGV sgv,char* filenames[3]){
  
  int b; 
  char buffer[100];

  system("clear");
  printf("\033[1;36m");
  printInicio("QUERY 1");
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

/*--------------------------------QUERY-2------------------------*/

char inputQuery2(){
  
  char c;
  system("clear");
  printInicio("QUERY 2");
  printf("\033[1;35m0 -> Voltar\033[1;36m\n");
  printf("Qual a letra do produto que pretende procurar [A-Z] ?\n");
  printf("══════════════════════════════════════════════════════════════════════════════════════════\n");
   
  scanf(" %c",&c);
  
  if (c=='0') return '0';
  else {
    if (!(c>='A' && c<='Z')){
      puts("\033[1;31mLetra inválida");
      clearAndEnter();
      return '0';
    }
  }
  return c;
}

/*--------------------------------QUERY-3------------------------*/

char inputQuery3(char* code,int* mes){
  
  char mes_str[100];
  char c;
  
  system("clear");
  printInicio("QUERY 3");
  printf("\033[1;35m0 -> Voltar \n\n"); 
  printf("\033[1;33mIndique um mês (1-12)?\033[0;32m\n");
 
  scanf(" %s",mes_str);
  
  if ((atoi(mes_str))==0) return c='0'; 
    
  if ((atoi(mes_str))>12){
    puts("\033[1;31mMês inválido");clearAndEnter();
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
      clearAndEnter();
      return c='-';
    }

    if (!isalpha(code[0]) && isalpha(code[0])){
      printf("\033[1;31m Primeiros 2 caracteres não são letras\n");
      clearAndEnter();
      return c='-';
    }

    if (!(code[0]>='A' && code[0]<='Z' && code[1]>='A' && code[1]<='Z')){
      printf("\033[1;31m Primeiros 2 caracteres não são letras MAÍUSCULAS\n");
      clearAndEnter();
      return c='-';
    }

    if (!(atoi(code+2)>=1000) && atoi(code+2)<=9999){
      printf("\033[1;31m Últimos 4 caracteres têm de ser numéricos\n");
      clearAndEnter();
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

/*--------------------------------QUERY-4------------------------*/

int inputQuery4(){
 
  char c;
  int f;
  int res=-1;
  int flag=0;
 
  while(flag==0){
 
    system("clear");
  
    printInicio("QUERY 4"); 
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
          clearAndEnter();
          return -1;
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

/*--------------------------------QUERY-7------------------------*/

int inputQuery7(char* code){

  int flag=0;
  while(!flag){

  system("clear");
  printf("\033[1;35m0 -> para voltar\n");
  printf("\033[1;34mInsira o código de cliente:\n");

  scanf(" %s",code);
  
  if (code[0]=='0') return -2;
  else if (strlen(code)!=5){
    printf("\033[1;31mCódigo de cliente inválido\n");
    clearAndEnter();
  }
  else if (!isalpha(code[0])) {
    printf ("\033[1;31mPrimeiro caracter é uma letra\n");
    clearAndEnter();
  }
  else if (!(code[0] >='A' && code[0]<='Z')){
    printf("\033[1;31mLetra tem que ser maiúscula\n");
    clearAndEnter();
  }
  else if (!(atoi(code+1)>=1000) && atoi(code+1)<=5000){
    printf("\033[1;31mRestantes caracteres têm que ser numéricos\n");
    clearAndEnter();  
  }
  else {flag=1;}
  }
  
  return 0;
}

/*--------------------------------QUERY-8------------------------*/

int inputQuery8(int* mes1,int* mes2){
  
  system("clear");
  printInicio("QUERY 8");
  printf("\033[1;34m0 -> Voltar \033[1;36m\n\n");
  printf("\033[1;35mIndique o intervalo de meses no qual quer ver o numero de vendas e o total faturado nesse periodo.\n");
  printf("\033[1;36m══════════════════════════════════════════════════════════════════════════════════════════════════════════\n\n");
  
  printf("\033[0;34mIndique o mês 1\033[0;32m\n");
  scanf("%d",mes1);
    
  if(*mes1==0)
    return -2;
    
  if (*mes1>12 || *mes1 <0){
    puts("\033[0;31mMês inválido"); 
    clearAndEnter();
    return -1;
  }
  
  printf("\033[0;34mIndique o mês 2\033[0;32m\n");
  scanf("%d",mes2);
  if (*mes2==0)
    return -2;
  if (*mes2>12 || *mes2<0 || *mes2<*mes1){
    puts ("\033[0;31mMês inválido");
    clearAndEnter();
    return -1;
  }

  *mes1-=1;
  *mes2-=1;

  return 0;
}

/*--------------------------------QUERY-9------------------------*/

int inputQuery9(char* productID){
  
  system("clear");
  printInicio("QUERY 9"); 
  printf("\033[1;34m0 -> Voltar \033[1;36m\n\n");

  int x;
  printf("\033[1;33mIndique o produto:\n");
  scanf("%s",productID);
    
  if (*productID=='0')
    return -2;
    
  if (strlen(productID)!=6){
    printf("\033[1;31mCódigo de produto inválido\n");
    clearAndEnter();
    return -1;
  }
  
  if (!isalpha(productID[0]) && isalpha(productID[0])){
    printf("\033[1;31m Primeiros 2 caracteres não são letras\n");
    clearAndEnter();
    return -1;
  }
    
  if (!(productID[0]>='A' && productID[0]<='Z' && productID[1]>='A' && productID[1]<='Z')){
    printf("\033[1;31m Primeiros 2 caracteres não são letras maíusculas\n");
    clearAndEnter();
    return -1;
  }
    
  if (!(atoi(productID+2)>=1000) && atoi(productID+2)<=9999){
    printf("\033[1;31m Últimos 4 caracteres têm de ser numéricos\n");
    clearAndEnter();
    return -1;
  }
    
  printf("Indique a filial:\n");
  scanf("%d",&x);

  if(x==0)
    return -2;
    
  if(x>3 || x<0){
    printf ("\033[1;31Filial assume os valores de 1 a 3.");
    clearAndEnter();
    return -1;
  }
  
  x--;
  return x;
}

/*--------------------------------QUERY-10------------------------*/

int inputQuery10(char* clientID){
  
  int x;
  system("clear");
  printInicio("QUERY 10");
  printf("\033[1;34m0 -> Voltar \033[1;36m\n\n");

  printf("\033[1;33mIndique um cliente:\n");
  scanf("%s",clientID);
  
  if (*clientID=='0') 
    return -2;
  
  if (strlen(clientID)!=5){
    printf("\033[1;31mCódigo de cliente inválido\n");
    clearAndEnter();
    return -1;}

  
  if (!isalpha(clientID[0])) {
    printf ("\033[1;31mPrimeiro caracter é uma letra\n");
    clearAndEnter();
    return -1;}
  
  if (!(clientID[0] >='A' && clientID[0]<='Z')){
    printf("\033[1;31mPrimeira letra tem que ser maiúscula\n");
    clearAndEnter();
    return -1;}
  
  if (!(atoi(clientID+1)>=1000) && atoi(clientID+1)<=5000){
    printf("\033[1;31mRestantes caracteres têm que ser numéricos\n");
    clearAndEnter();
    return -1;}
  
 
  printf("\033[1;33mIndique o mês:\n");
  scanf("%d",&x);

  if(x==0) return -2;
  if (x>12 || x<0){
    printf("\033[1;31mMês inválido\n");
    clearAndEnter();
    return -1;
  }
  
  return x;
}

/*--------------------------------QUERY-11------------------------*/

int inputQuery11(){
  
  int x;
  system("clear");
  printInicio("QUERY 11");
  printf("\033[1;34m0 -> Voltar \033[1;36m\n\n");

  printf("\033[1;33mIndique o limite do top:\n");
 
  scanf("%d",&x);

  if (x==0) return -1;
 
  return x;
}

/*--------------------------------QUERY-12------------------------*/

int inputQuery12(char* clientID){
  
  int x;
  system("clear");
  printInicio("QUERY 12");
  printf("\033[1;34m0 -> Voltar \033[1;36m\n\n");

  printf("\033[1;33mIndique um cliente:\n");
  scanf("%s",clientID);
  if (clientID[0]=='0') return -2;
  if (strlen(clientID)!=5){
    printf("\033[1;31mCódigo de cliente inválido\n");
    clearAndEnter();
    return -1;
  }
  if (!isalpha(clientID[0])) {
    printf ("\033[1;31mPrimeiro caracter é uma letra\n");
    clearAndEnter();
    return -1;
  }
  if (!(clientID[0] >='A' && clientID[0]<='Z')){
    printf("\033[1;31mLetra tem que ser maiúscula\n");
    clearAndEnter();
    return -1;
  }
  if (!(atoi(clientID+1)>=1000) && atoi(clientID+1)<=5000){
    printf("\033[1;31mRestantes caracteres têm que ser numéricos\n");
    clearAndEnter();
    return -1;
  }

  printf("\033[1;33mIndique o limite do top:\n");
 
  scanf("%d",&x);
  if (x==0) return -2;
 
  return x;
}
