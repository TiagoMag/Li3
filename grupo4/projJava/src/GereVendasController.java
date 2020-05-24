public class GereVendasController {

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
                    break;
            }
        }while(x!=0);
    }


}
