#ifndef menu_H
#define menu_H


#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include "SGV.h"


#define MAX_COL 5
#define MAX_LIN 20


//int init_menu(SGV sgv);



int main_menu();
void voltar();
void clearAndEnter();
void erro();
int inputQuery1(SGV sgv,char* filenames[3]);
char inputQuery2();
void printQuery2(Lista lst);
void printQuery3(Lista lst,char c);
char inputQuery3(char* codigo,int* mes);
int inputQuery4();
void printLst(Lista lst);
void printPar(Par p);
void inputQuery7(char* code);
void printQuery7(Tabela tbl);
void inputQuery8(int* mes1,int* mes2);
void printQuery8(Profit p,int mes1,int mes2);
int inputQuery9(char* productID);
void printQuery9(LstBuyers l);
int inputQuery10(char* clientID);

#endif