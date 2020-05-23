package model.Catalogos;

import java.util.Objects;

import static java.lang.Character.isLetter;
import static java.lang.Integer.parseInt;

public class Cliente {

    private String codigo;

    public Cliente(){
        this.codigo= new String();
    }


    public Cliente(String codigo) {
        this.codigo = codigo;

    }

    public Cliente(Cliente a){
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
        Cliente cliente = (Cliente) o;
        return Objects.equals(codigo, cliente.codigo);
    }

    public int hashCode (){
        return this.codigo.hashCode();
    }

    public String toString (){
        StringBuilder sb = new StringBuilder();
        sb.append("Código de model.Catalogos.Cliente: "); sb.append(this.codigo + "\n");
          return this.codigo;
    }


    public Cliente clone(){
        return new Cliente(this);
    }

    /* metodos */
    /* Verifica se um codigo de cliente é valido tendo em conta os parâmetros */
    public boolean validaCliente(){
        if (!isLetter(this.codigo.charAt(0))) return false;
        if (!(this.codigo.charAt(0) >='A' && this.codigo.charAt(0)<='Z')) return false;
        if (!(parseInt(this.codigo+1)>=1000) && parseInt(this.codigo+1)<=5000) return false;
        return true;
    }

}
