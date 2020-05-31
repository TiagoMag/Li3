package Views;

import java.util.List;
import java.util.ArrayList;
import java.io.Serializable;

/**
 * Classe Menu
 *
 * @author Grupo 4
 * @version 2020
 */

public class Menu implements Serializable
{
    private List<String>opcoes;

    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_WHITE = "\u001B[37m";

    public Menu(String[] opcoes){
        this.opcoes=new ArrayList<String>();
        for(String op: opcoes)
            this.opcoes.add(op);
    }

    public void showMenu(String title){
        System.out.println(ANSI_CYAN+"═══════════════════════════════════════════════════════════════");
        System.out.println(" "+title+"\n");
        System.out.println(ANSI_BLUE+" "+"0 - Sair");
        for(int i=0;i<this.opcoes.size();i++){
            System.out.print(" ");
            System.out.print(i+1);
            System.out.print(" - ");
            System.out.println(this.opcoes.get(i));
        }
        System.out.println(ANSI_CYAN+"══════════════════════════════════════════════════════════════════\n");
        System.out.print(ANSI_WHITE+" "+"Opcao:");
    }
}