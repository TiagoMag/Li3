#ifndef menu_H
#define menu_H

#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

#define MAX_LIN 20

void main_menu();
void voltar();
void clearAndEnter();
void printQuery2(Lista lst);
void printQuery3(Lista lst,char c);
void printLst(Lista lst);
void printPar(Par p,float time);
void printQuery7(Tabela tbl,float time);
void printQuery8(Profit p,int mes1,int mes2,float time);
void printQuery9(LstBuyers l,float time);
void printLst10(Lista lst,float tempo);
void printQuery11(SelledProd* s,int x,float time);
void printQuery12(GList* l,float time);
void printQuery13(FileInfo f);

#endif