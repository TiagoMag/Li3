package Models.Catalogos;

import java.util.Objects;

import static java.lang.Character.isLetter;
import static java.lang.Integer.parseInt;

public class Produto implements Comparable<Produto>{

    private String codigo;

    public Produto(){
        this.codigo= new String();
    }


    public Produto(String codigo) {
        this.codigo = codigo;

    }

    public Produto(Produto a){
        this.setCodigo(a.getCodigo());
    }


    /*getter e setter*/
    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Produto produto = (Produto) o;
        return Objects.equals(codigo, produto.codigo);
    }


    public String toString (){
        StringBuilder sb = new StringBuilder();
        sb.append("Código de model.Catalogos.Produto "); sb.append(this.codigo + "\n");
        return this.codigo;
    }


    public Produto clone(){
        return new Produto(this);
    }


    public boolean validaProd(){
        if (!Character.isLetter((this.codigo.charAt(0))) && Character.isLetter(this.codigo.charAt(0))) return false;
        if (!(this.codigo.charAt(0)>='A' && this.codigo.charAt(0)<='Z' && this.codigo.charAt(1)>='A' && this.codigo.charAt(1)<='Z')) return false;

        try {

            if (!((Integer.parseInt(this.codigo.substring(2))) >= 1000) && (Integer.parseInt(this.codigo.substring(2))) <= 9999) return false;
        }
        catch(NumberFormatException e) {return false;}

        return true;
    }

    public int hashCode (){
        return this.codigo.hashCode();
    }

    @Override
    public int compareTo(Produto p) {
        return this.codigo.compareTo(p.getCodigo());
    }
}
