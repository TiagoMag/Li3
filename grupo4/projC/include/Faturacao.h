#ifndef Faturacao_H
#define Faturacao_H

#include <glib.h>
#include "Venda.h"


typedef struct faturacao *Faturacao;
typedef struct fat *Fat;
typedef struct data *Data;

#define MES 12
#define FILIAL 3

Data initData();
Faturacao inicializaFat();
Fat initFat();
gboolean existeFat(Faturacao f,Venda v);
Faturacao insereFat(Faturacao f,Venda v);
Faturacao updateFat(Faturacao f,Venda v);
int getUnidadesVendidas(Faturacao f,char* prodID);
Data getData(Faturacao f,char* codigo,char tipo,int mes);
Data getDataFilial(Faturacao f,char* codigo,char tipo,int mes,int filial);
float getPrecoFat(Data d);
int getQntFat(Data d);
gboolean existeProdFat(Faturacao f,char* codigo);
void removeFaturacao(Faturacao f);
float getProfit(Faturacao f,int minMonth,int maxMonth);
int getSales(Faturacao f,int minMonth,int maxMonth);
Lista topSelledProductsN(Lista lst,Faturacao f,int limit);

#endif