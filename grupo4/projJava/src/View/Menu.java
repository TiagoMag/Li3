package View;

import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.Serializable;

public class Menu implements Serializable
{
    private List<String>opcoes;

    public Menu(String[] opcoes){
        this.opcoes=new ArrayList<String>();
        for(String op: opcoes)
            this.opcoes.add(op);
    }

    public void showMenu(){
        System.out.println("0 - Sair");
        for(int i=0;i<this.opcoes.size();i++){
            System.out.print(i+1);
            System.out.print(" - ");
            System.out.println(this.opcoes.get(i));
        }
    }

}