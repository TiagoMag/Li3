CC = gcc
CFLAGS = -Wall -ggdb -ansi -std=c99 -O2 -D_GNU_SOURCE
GLIBFLAG = `pkg-config --cflags --libs glib-2.0`

program: CatProd Produto Cliente CatCli Queries Files SGV Navegador Menu Venda Faturacao Filial
	$(CC) $(GLIBFLAG) $(CFLAGS) -o program main.c CatProdutos.o Produto.o Cliente.o CatClientes.o Queries.o Files.o SGV.o Navegador.o menu.o Venda.o Faturacao.o Filial.o

CatProd:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c CatProdutos.c

Produto:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c Produto.c

Cliente:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c Cliente.c

CatCli:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c CatClientes.c

Queries:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c Queries.c

Files:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c Files.c

SGV:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c SGV.c

Navegador:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c Navegador.c

Menu:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c menu.c

Venda:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c Venda.c

Faturacao:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c Faturacao.c

Filial:
	$(CC) $(GLIBFLAG) $(CFLAGS) -c Filial.c


clean:
	rm program CatProdutos.o Produto.o CatClientes.o Cliente.o Queries.o Files.o SGV.o Navegador.o menu.o Venda.o Faturacao.o Filial.o