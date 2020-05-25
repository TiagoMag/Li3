import static java.lang.System.exit;

public class GereVendasAppMVC {

    public static void main (String[] args){

        GereVendasModel model = new GereVendasModel();
        GereVendasView view = new GereVendasView();
        GereVendasController control = new GereVendasController();
        control.setView(view);
        control.setModel(model);
        control.startController();
        exit(0);
    }
}
