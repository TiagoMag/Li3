#ifndef CatClientes_H
#define CatClientes_H

#include <stdlib.h>
#include <glib.h>
#include "Cliente.h"

#define Clientes 26

typedef struct cat_clientes *Cat_Clientes;

Cat_Clientes inicializa_CatClientes();
Cat_Clientes insereCliente(Cat_Clientes cc,Cliente c);
gboolean existeCliente(Cat_Clientes cp,Cliente c);
int totalClientes(Cat_Clientes cc);
void removeCatCliente(Cat_Clientes cc);
GTree* getTreeC(Cat_Clientes cc,int index);
Cat_Clientes setInfoFileClientes(Cat_Clientes cc,char* filename,int num_linhas_lidas,float tempo);
int getNumLinhasLidasClientes(Cat_Clientes cc);
float getTempoLeituraClientes(Cat_Clientes cc);
char* getFileNameClientes(Cat_Clientes cc);
#endif