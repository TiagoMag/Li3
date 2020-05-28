import Common.Constantes;
import Models.Catalogos.Cliente;
import Models.Catalogos.ICliente;
import Models.Catalogos.IProduto;
import Models.Catalogos.Produto;
import Models.Queries.*;

import java.io.IOException;
import java.io.Serializable;
import java.util.List;
import java.util.Set;

public class GereVendasController implements Serializable {

    /* Variáveis de instânvia */
    private GereVendasModel model;
    private GereVendasView view;

    public GereVendasController()
    {
        this.model= new GereVendasModel ();
        this.view= new GereVendasView ();
    }

    public void setModel (GereVendasModel model)
    {
        this.model=model;
    }

    public void setView (GereVendasView view)
    {
        this.view=view;
    }

    public void startController(){
        int x;
        do{
            this.view.run();
            x=Input.lerInt();
            switch(x) {
                case 1:
                    this.readFiles();
                    break;
                case 2:
                    this.guardaEstadoWrapper();
                    break;
                case 3:
                    this.carregaEstadoWrapper();
                    break;
                case 4:
                    this.handlerQueriesEstatisticas();
                    break;
                case 5:
                    this.handlerQueriesInterativas();
                    break;
            }
        }while(x!=0);
    }

    public void readFiles(){
        int x=0;
        do{
           String[] configs = this.model.lerConfigs(); // retira ficheiros do configs.data
            this.view.showMenuFiles();
            x=Input.lerInt();  // lê input do cliente
            switch(x) {
                case 1:
                    this.model.lerFilesProdutos(configs[0]); // carrega o catálogo de produtos
                    this.model.lerFilesClientes(configs[1]); // carrega o catálogo de clientes
                    this.model.lerVendas(configs[2]); // carrega as filiais e a faturação
                    this.view.clickEnter();
                    break;
                case 2:
                    String [] fileNames = new String [3];
                    String path = null;

                    this.view.insertPath("Produtos");
                    path = Input.lerString();
                    fileNames[0] = path;
                    this.view.insertPath("Clientes");
                    path = Input.lerString();
                    fileNames[1] = path;
                    this.view.insertPath("Vendas");
                    path = Input.lerString();
                    fileNames[2] = path;
                    this.view.clearScreen();
                    this.model.lerFilesProdutos(fileNames[0]);
                    this.model.lerFilesClientes(fileNames[1]);
                    this.model.lerVendas(fileNames[2]);

                    this.view.clickEnter();
            }
        }while(x!=0);
    }

    public void carregaEstadoWrapper(){
        GereVendasModel model= null;
        try {
            model = GereVendasModel.carregaEstado("ficheiros/gereVendas.dat");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
            this.view.printError(e.getMessage());
        }
        this.setModel(model);
    }

    public void guardaEstadoWrapper(){
        try {
            this.model.guardaEstado("ficheiros/gereVendas.dat");
        } catch (IOException e) {
            e.printStackTrace();
            this.view.printError(e.getMessage());
        }
    }

    public void handlerQueriesEstatisticas(){
        int x=0;
        do{
            this.view.showQueriesEstatisticas();
            double time;
            x=Input.lerInt();  // lê input do cliente
            switch(x) {
                case 1:
                    Crono.start();
                    List<String> lst =this.model.Querie11();
                    time=Crono.stop();
                    this.view.printQuerie11(lst,time);
                    break;
                case 2:
                    this.handlerdadosGerais();
                    break;
            }
        }while(x!=0);

    }

    public void handlerdadosGerais(){
        int x=0;
        do{
            this.view.showDadosGerais();
            double time;
            x=Input.lerInt();  // lê input do cliente
            switch(x) {
                case 1:
                    Crono.start();
                    List<Integer> lst =this.model.Querie121();
                    time=Crono.stop();
                    this.view.printQuerie121(lst,time);
                    break;
                case 2:
                    break;
            }
        }while(x!=0);

    }

    public void handlerQueriesInterativas(){
        int x=0;
        do{
            this.view.showQueriesInterativas();
            double time;
            String codigoCliente,codigoProduto;
            int limite;
            ICliente c;
            IProduto p;
            x=Input.lerInt();  // lê input do cliente
            switch(x) {
                case 1:
                    Crono.start();
                    Set<IProduto> lst =this.model.produtosNaoComprados();
                    time=Crono.stop();
                    this.view.printQuery1(lst,time);
                    break;
                case 2:
                    int mes=1;
                    while(mes!=0) {
                        this.view.insiraMes();
                        mes=Input.lerInt();
                        if (validaMes(mes)){
                            Crono.start();
                            ParQuery2[] par = this.model.numeroTotalVendasEClientesMes(mes-1);
                            time = Crono.stop();
                            this.view.printQuerie2(par, time);
                        }
                    }
                    break;
                case 3:
                    this.view.insereCliente();
                    codigoCliente=Input.lerString();
                    c = new Cliente(codigoCliente);
                    if (validaCliente (c)){
                        Crono.start();
                        TrioQuery3 triplo=this.model.quantasComprasFezPMes(c);
                        time=Crono.stop();
                        this.view.printQuerie3(triplo,time);
                    }
                    break;
                case 4:
                    this.view.insereProduto();
                    codigoProduto=Input.lerString();
                    p=new Produto(codigoProduto);
                    if(validaProduto(p)){
                        Crono.start();
                        TrioQuery4[] trios = this.model.querie4(p);
                        time=Crono.stop();
                        this.view.printQuerie4(trios,time);
                    }
                    break;
                case 5:
                    this.view.insereCliente();
                    codigoCliente=Input.lerString();
                    c=new Cliente(codigoCliente);
                    if(validaCliente(c)){
                        Crono.start();
                        Set<ParQuery5> set = this.model.query5(c);
                        time=Crono.stop();
                        this.view.printQuery5(set,time);
                    }
                    break;
                case 6:
                    this.view.insereLimite();
                    limite=Input.lerInt();
                    Crono.start();
                    Set<TrioQuery6> trios= this.model.query6(limite);
                    time=Crono.stop();
                    this.view.printQuery6(trios,time);
                    break;
                case 8:
                    this.view.insereLimite();
                    limite=Input.lerInt();
                    Crono.start();
                    List<ParQuery8> pares = this.model.query8(limite);
                    time=Crono.stop();
                    this.view.printQuery8(pares,time);
                    break;
            }
        }while(x!=0);





    }

    public boolean validaMes(int x){
        return (x>=1 && x<Constantes.MESES);
    }

    public boolean validaCliente(ICliente c){
        return (c.validaCliente() && this.model.getCatClientes().existeCliente(c));
    }

    public boolean validaProduto(IProduto p){
        return (p.validaProd() && this.model.getCatProdutos().existeProduto(p));
    }




}
