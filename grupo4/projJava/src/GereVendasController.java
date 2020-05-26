import java.io.IOException;
import java.io.Serializable;
import java.util.List;

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




}
