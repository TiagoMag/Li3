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
                    this.handlerQueriesEstatisticas();
                    break;
                case 2:
                    this.handlerQueriesInterativas();
                    break;

            }
        }while(x!=0);
    }

}
