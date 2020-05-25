package Models.Catalogos;

import java.io.Serializable;
import java.util.Objects;


public class Produto implements Serializable,Comparable<IProduto>,IProduto {

    private String codigo;

    /**
     * Construtor por omissão da classe Produto
     *
     * @return um objeto produto vazio
     */
    public Produto(){
        this.codigo = "";
    }
    /**
     * Construtor parâmeterizado da classe produto
     * @param codigo Codigo de Produto
     * @return novo objeto produto definido com os parametros
     */
    public Produto(String codigo) {
        this.codigo = codigo;

    }
    /**
     * Construtor por objetos da classe produto
     * @param a objeto a copiar
     * @return novo produto vazio
     */
    public Produto(IProduto a){
        this.setCodigo(a.getCodigo());
    }

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

    @Override
    public String toString (){
        StringBuilder sb = new StringBuilder();
        sb.append("Código de model.Catalogos.Produto "); sb.append(this.codigo + "\n");
        return this.codigo;
    }


    public IProduto clone(){
        return new Produto(this);
    }




    public int hashCode (){
        return this.codigo.hashCode();
    }

    @Override
    public int compareTo(IProduto p) {
        return this.codigo.compareTo(p.getCodigo());
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
}
