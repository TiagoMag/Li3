import java.util.Objects;

public class Produto {

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

    @Override
    public int hashCode() {
        return Objects.hash(codigo);
    }

    public String toString (){
        StringBuilder sb = new StringBuilder();
        sb.append("Código de Produto "); sb.append(this.codigo + "\n");
        return this.codigo;
    }


    public Produto clone(){
        return new Produto(this);
    }




}
