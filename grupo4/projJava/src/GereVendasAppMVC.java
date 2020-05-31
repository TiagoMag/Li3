import java.io.Serializable;

import static java.lang.System.exit;

public class GereVendasAppMVC implements Serializable {

    public static void main (String[] args){

        GereVendasModel model = new GereVendasModel();
        model.loadModel();
        if (model==null){
            System.out.println("ERRO");
            System.exit(-1);
        }
        GereVendasView view = new GereVendasView();
        GereVendasController control = new GereVendasController();
        control.setView(view);
        control.setModel(model);
        control.startController();
        exit(0);
    }
}
