package Models.Catalogos;

import java.io.Serializable;
import java.util.Comparator;
import java.util.Objects;

import static java.lang.Character.isLetter;
import static java.lang.Integer.parseInt;

/**
 * Classe representativa de um Cliente
 *
 * @author Grupo4
 * @version 2020
 */

public class Cliente implements Serializable, ICliente, Comparable<ICliente> {

    private String codigo;

    /**
     * Construtor vazio
     *
     */
    public Cliente(){
        this.codigo= new String();
    }

    /**
     * Construtor parâmeterizado
     * @param codigo codigo de cliente
     */
    public Cliente(String codigo) {
        this.codigo = codigo;
    }
    /**
     * Construtor por objeto
     * @param a objeto a
     */
    public Cliente(Cliente a){
        this.setCodigo(a.getCodigo());
    }


    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Cliente cliente = (Cliente) o;
        return Objects.equals(codigo, cliente.codigo);
    }

    public int hashCode (){
        return this.codigo.hashCode();
    }

    public int compareTo(ICliente c) {
        return this.codigo.compareTo(c.getCodigo());
    }

    public String toString (){
        StringBuilder sb = new StringBuilder();
        sb.append("Código de model.Catalogos.Cliente: "); sb.append(this.codigo + "\n");
          return this.codigo;
    }

    public Cliente clone(){
        return new Cliente(this);
    }

    public boolean validaCliente(){
        if (!isLetter(this.codigo.charAt(0))) return false;
        if (!(this.codigo.charAt(0) >='A' && this.codigo.charAt(0)<='Z')) return false;

        try{
            if (!((Integer.parseInt(this.codigo.substring(1)))>=1000) && (Integer.parseInt(this.codigo.substring(1)))<=5000) return false;
        } catch(NumberFormatException e) {return false;}

        return true;
    }

}
