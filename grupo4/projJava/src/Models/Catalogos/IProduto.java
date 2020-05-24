package Models.Catalogos;

import static java.lang.Integer.parseInt;

public interface IProduto {

    /**
     * Indica o codigo de produto
     * @return String código de produto
     *
     */
    public String getCodigo();

    /**
     * Define codigo de produto
     * @return void
     *
     */
    public void setCodigo(String codigo);


    public boolean equals(Object o);


    public int hashCode();

    public String toString ();


    public Produto clone();

    public boolean validaProd();

}
