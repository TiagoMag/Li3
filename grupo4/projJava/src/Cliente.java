import java.util.Objects;

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
        sb.append("Código de Cliente: "); sb.append(this.codigo + "\n");
          return this.codigo;
    }


    public Cliente clone(){
        return new Cliente(this);
    }

    /* metodos */

}
