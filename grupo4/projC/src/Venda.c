#include "../include/Venda.h"

struct venda{
 Produto produto;
 Cliente cliente;
 float preco;
 int quant;
 char tipoCompra;
 int mes;
 int filial;
};

Venda inicializaV(){
 Venda v=(Venda)malloc(sizeof(struct venda));
 v->produto=inicializa_Prod();
 v->cliente=inicializa_Cliente();
 v->preco=0.0f;
 v->quant=0;
 v->mes=0;
 v->filial=0;
 return v;
}

gboolean validaV(Venda v,Cat_Produtos cp,Cat_Clientes cc){
 if (!((v->preco)>=0.0 && (v->preco)<=999.99))return FALSE;
 if (!((v->quant)>=1 && (v->quant)<=200)) return FALSE;
 if (!((v->tipoCompra=='N') ||(v->tipoCompra=='P'))) return FALSE;
 if (!((v->mes)>=1 && (v->mes)<=12)) return FALSE;
 if (!((v->filial)>=1 && (v->filial)<=3)) return FALSE;
 if (!validaProd(v->produto)) return FALSE;
 if (!validaCliente(v->cliente)) return FALSE;
 if (!existeProd(cp,v->produto)) return FALSE;
 if (!existeCliente(cc,v->cliente)) return FALSE;
 return TRUE;
}

Venda criaVendas(Venda v,char* p,char* c,float preco,int q,char tipoCompra ,int m,int f){
 v->produto = criaProduto(v->produto,p);
 v->cliente = criaCliente(v->cliente,c);
 v->preco = preco;
 v->quant = q;
 v->tipoCompra=tipoCompra;
 v->mes = m;
 v->filial = f;
 return v;
}

Produto getProdutoVenda(Venda v){
 return(v->produto);
}

float getPrecoVenda(Venda v){
 return (v->preco);
}

int getQntVenda(Venda v){
 return(v->quant);
}

char getTipo(Venda v) {
 return (v->tipoCompra);
}

Cliente getClienteVenda(Venda v) {
 return (v->cliente);
}

int getMes (Venda v){
 return (v->mes);
}

int getFilial (Venda v){
 return (v->filial);
}

void removeVenda (Venda v){
 removeCliente(v->cliente);
 removeProduto(v->produto);
 free(v);
}