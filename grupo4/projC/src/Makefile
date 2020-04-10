CC = gcc
CFLAGS = -Wall -ggdb -ansi -std=c99 -O2 -Wno-unused-result -D_GNU_SOURCE
GLIBFLAG = `pkg-config --cflags --libs glib-2.0`
GLIBFLAGC= `pkg-config --cflags glib-2.0`
GLIBFLAGL= `pkg-config --libs glib-2.0`

program: CatProd Produto Cliente CatCli Queries Files SGV Navegador Menu Venda Faturacao Filial
	$(CC) $(CFLAGS)  -o program main.c $(GLIBFLAGC)   CatProdutos.o Produto.o Cliente.o CatClientes.o Queries.o Files.o SGV.o Navegador.o menu.o Venda.o Faturacao.o Filial.o $(GLIBFLAGL)

CatProd:
	$(CC) $(CFLAGS) -c CatProdutos.c $(GLIBFLAGC)  $(GLIBFLAGL)

Produto:
	$(CC) $(CFLAGS) -c Produto.c $(GLIBFLAGC) $(GLIBFLAGL)

Cliente:
	$(CC) $(CFLAGS) -c Cliente.c $(GLIBFLAGC)  $(GLIBFLAGL)

CatCli:
	$(CC) $(CFLAGS) -c CatClientes.c $(GLIBFLAGC) $(GLIBFLAGL) 

Queries:
	$(CC) $(CFLAGS) -c Queries.c $(GLIBFLAGC)  $(GLIBFLAGL)

Files:
	$(CC) $(CFLAGS) -c Files.c $(GLIBFLAGC)  $(GLIBFLAGL)

SGV:
	$(CC) $(CFLAGS) -c SGV.c $(GLIBFLAGC)  $(GLIBFLAGL)

Navegador:
	$(CC) $(CFLAGS) -c Navegador.c $(GLIBFLAGC)  $(GLIBFLAGL)

Menu:
	$(CC) $(CFLAGS) -c menu.c $(GLIBFLAGC)  $(GLIBFLAGL)

Venda:
	$(CC) $(CFLAGS) -c Venda.c $(GLIBFLAGC)  $(GLIBFLAGL)

Faturacao:
	$(CC) $(CFLAGS) -c Faturacao.c $(GLIBFLAGC)  $(GLIBFLAGL)

Filial:
	$(CC) $(CFLAGS) -c Filial.c $(GLIBFLAGC)  $(GLIBFLAGL)


clean:
	rm program CatProdutos.o Produto.o CatClientes.o Cliente.o Queries.o Files.o SGV.o Navegador.o menu.o Venda.o Faturacao.o Filial.o