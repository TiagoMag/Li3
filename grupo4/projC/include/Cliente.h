#ifndef Cliente_H
#define Cliente_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <glib.h>

typedef struct cliente *Cliente;

Cliente inicializa_Cliente();
Cliente criaCliente(Cliente c,char* codigo);
char* getCliente(Cliente c);
int getIndexC(Cliente c);
gboolean validaCliente(Cliente c);
void removeCliente(Cliente c);

#endif
