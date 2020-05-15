CC = gcc
CFLAGS = -Wall -ggdb -ansi -std=c99 -O2 -Wno-unused-result -D_GNU_SOURCE

PKGS=glib-2.0
GLIBFLAGC= `pkg-config --cflags $(PKGS)`
GLIBFLAGL= `pkg-config --libs $(PKGS)`

ModelDir=model/
ControllerDir=controller/
ViewDir=view/

_OBJ =  CatProdutos.o model.Produto.o model.Cliente.o model.CatClientes.o Queries.o Files.o SGV.o Navegador.o Input.o View.o model.Venda.o Faturacao.o Filial.o Controller.o

program: CatProd model.Produto model.Cliente CatCli Queries Files SGV Navegador View Input model.Venda Faturacao Filial Controller
	$(CC) $(CFLAGS)  -o program main.c $(GLIBFLAGC) $(_OBJ) $(GLIBFLAGL)

CatProd:
	$(CC) $(CFLAGS) -c $(ModelDir)CatProdutos.c $(GLIBFLAGC)  $(GLIBFLAGL)

model.Produto:
	$(CC) $(CFLAGS) -c $(ModelDir)model.Produto.c $(GLIBFLAGC) $(GLIBFLAGL)

model.Cliente:
	$(CC) $(CFLAGS) -c $(ModelDir)model.Cliente.c $(GLIBFLAGC)  $(GLIBFLAGL)

CatCli:
	$(CC) $(CFLAGS) -c $(ModelDir)model.CatClientes.c $(GLIBFLAGC) $(GLIBFLAGL)

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

model.Venda:
	$(CC) $(CFLAGS) -c $(ModelDir)model.Venda.c $(GLIBFLAGC)  $(GLIBFLAGL)

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