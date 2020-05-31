import java.io.Serializable;

import static java.lang.System.exit;

/**
 * Classe GereVendasAppMVC
 *
 * @author Grupo 4
 * @version 2020
 */

public class GereVendasAppMVC implements Serializable {

    public static void main (String[] args){
        System.out.println("Working Directory = " + System.getProperty("user.dir"));
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
