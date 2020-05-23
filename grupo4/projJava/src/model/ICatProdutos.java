package model;


import java.util.Set;


/**
 * Interface correspondente ao catalogo de clientes.
 * Permite operaçoes sobre o catalago
 *
 * @author Grupo4
 * @version 2020
 */


public interface ICatProdutos {

    /**
     *Devolve Catalogo de Produtos
     * @return Set de Produtos
     *
     */
    public Set<IProduto> getProdutos ();

    /**
     * Define Catalogo de Produtos
     * @return void
     *
     */


    public void setProdutos (Set <IProduto> catp);

    /**
     * HashCode
     * @return int
     *
     */


    public int hashCode() ;

    /**
     * Metodo clone, garante encapsulamento
     * @return CatProds
     *
     */

    public CatProds clone();


    /**
     *
     * Verifica se um produto existe no catalogo
     * @return boolean
     *
     */

    public boolean existeProduto (IProduto p);

    /**
     * Insere um produto no catalogo
     * @return void
     *
     */

    public void insereProduto (IProduto p);

    /**
     * calcula o numero de pordutos no catalogo
     * @return void
     *
     */

    public int numeroProdutos ();


}
