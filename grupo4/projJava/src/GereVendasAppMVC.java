import java.io.Serializable;

import static java.lang.System.exit;

public class GereVendasAppMVC implements Serializable {

    public static void main (String[] args){

        GereVendasModel model = new GereVendasModel();
        GereVendasView view = new GereVendasView();
        GereVendasController control = new GereVendasController();
        control.setView(view);
        control.setModel(model);
        System.out.println("Working Directory = " + System.getProperty("user.dir"));
        control.startController();
        exit(0);
    }
}
