CC = gcc
CFLAGS = -Wall -ggdb -ansi -std=c99 -O2 -Wno-unused-result -D_GNU_SOURCE

PKGS=glib-2.0
GLIBFLAGC= `pkg-config --cflags $(PKGS)`
GLIBFLAGL= `pkg-config --libs $(PKGS)`

ModelDir=model/
ControllerDir=controller/
ViewDir=view/

_OBJ =  CatProdutos.o Produto.o Cliente.o CatClientes.o Queries.o Files.o SGV.o Navegador.o Input.o View.o Venda.o Faturacao.o Filial.o Controller.o 

program: CatProd Produto Cliente CatCli Queries Files SGV Navegador View Input Venda Faturacao Filial Controller
	$(CC) $(CFLAGS)  -o program main.c $(GLIBFLAGC) $(_OBJ) $(GLIBFLAGL)

CatProd:
	$(CC) $(CFLAGS) -c $(ModelDir)CatProdutos.c $(GLIBFLAGC)  $(GLIBFLAGL)

Produto:
	$(CC) $(CFLAGS) -c $(ModelDir)Produto.c $(GLIBFLAGC) $(GLIBFLAGL)

Cliente:
	$(CC) $(CFLAGS) -c $(ModelDir)Cliente.c $(GLIBFLAGC)  $(GLIBFLAGL)

CatCli:
	$(CC) $(CFLAGS) -c $(ModelDir)CatClientes.c $(GLIBFLAGC) $(GLIBFLAGL) 

Queries:
	$(CC) $(CFLAGS) -c $(ModelDir)Queries.c $(GLIBFLAGC)  $(GLIBFLAGL)

Files:
	$(CC) $(CFLAGS) -c $(ModelDir)Files.c $(GLIBFLAGC)  $(GLIBFLAGL)

SGV:
	$(CC) $(CFLAGS) -c $(ModelDir)SGV.c $(GLIBFLAGC)  $(GLIBFLAGL)

Navegador:
	$(CC) $(CFLAGS) -c $(ModelDir)Navegador.c $(GLIBFLAGC)  $(GLIBFLAGL)

Input:
	$(CC) $(CFLAGS) -c $(ControllerDir)Input.c $(GLIBFLAGC)  $(GLIBFLAGL)

View:
	$(CC) $(CFLAGS) -c $(ViewDir)View.c $(GLIBFLAGC)  $(GLIBFLAGL)

Venda:
	$(CC) $(CFLAGS) -c $(ModelDir)Venda.c $(GLIBFLAGC)  $(GLIBFLAGL)

Faturacao:
	$(CC) $(CFLAGS) -c $(ModelDir)Faturacao.c $(GLIBFLAGC)  $(GLIBFLAGL)

Filial:
	$(CC) $(CFLAGS) -c $(ModelDir)Filial.c $(GLIBFLAGC)  $(GLIBFLAGL)

Controller:
	$(CC) $(CFLAGS) -c $(ControllerDir)Controller.c $(GLIBFLAGC)  $(GLIBFLAGL)

memcheck:
	valgrind --leak-check=yes ./program

clean:
	rm program $(_OBJ)