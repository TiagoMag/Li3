import Controller.GereVendasController;
import Controller.IGereVendasController;
import Models.GereVendasModel;
import Models.IGereVendasModel;
import Views.GereVendasView;
import Views.IGereVendasView;

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
        IGereVendasView view = new GereVendasView();
        IGereVendasModel model = new GereVendasModel();
        model.loadModel();
        if (model==null){
            view.printError("ERRO");
            System.exit(-1);
        }
        IGereVendasController control = new GereVendasController();
        control.setView(view);
        control.setModel(model);
        control.startController();
        exit(0);
    }
}
