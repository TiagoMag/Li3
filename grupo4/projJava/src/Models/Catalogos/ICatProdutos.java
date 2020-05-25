package Models.Catalogos;


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
    Set<IProduto> getProdutos ();
    /**
     * Define Catalogo de Produtos
     * @param catp Set de Produtos a ser definido no objeto
     * @return void
     *
     */
   void setProdutos (Set <IProduto> catp);

    /**
     * Metodo clone, garante encapsulamento
     * @return CatProds
     *
     */
    ICatProdutos clone ();
    /**
     *
     * Verifica se um produto existe no catalogo
     * @param p produto a ser verificado
     * @return boolean
     *
     */
    boolean existeProduto (IProduto p);
    /**
     * Insere um produto no catalogo
     * @param p produto a ser adicionado
     * @return void
     *
     */
    void insereProduto (IProduto p);
    /**
     * calcula o numero de produtos no catalogo
     * @return int
     *
     */
    int numeroProdutos ();


}
