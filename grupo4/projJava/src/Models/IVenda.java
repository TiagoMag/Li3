package Models;


import Models.Catalogos.ICatClientes;
import Models.Catalogos.ICatProdutos;
import Models.Catalogos.ICliente;
import Models.Catalogos.IProduto;

/**
 * Interface correspondente a Venda.
 * Permite operaçoes sobre uma Venda.
 *
 * @author Grupo4
 * @version 2020
 */

public interface IVenda {

    /**
     * Retorna o Produto da venda
     * @return Produto
     *
     */

    IProduto getProduto();

    /**
     * Insere Produto numa venda
     * @param produto
     * @return void
     *
     */

    void setProduto(IProduto produto);

    /**
     * Retorna Cliente da venda
     * @return Cliente
     *
     */

    ICliente getCliente();

    /**
     * Insere cliente na venda
     * @param cliente
     * @return void
     *
     */

    void setCliente(ICliente cliente);

    /**
     * Retorna valor da venda
     * @return float
     *
     */
    float getPreco();

    /**
     * Adiciona valor à venda
     * @param  preco
     * @return void
     *
     */
    void setPreco(float preco);


    /**
     * Retorna quantidade vendida na venda
     * @return int
     *
     */
    int getQuantidade();

    /**
     * Adiciona quantidade vendida à venda
     * @param quantidade
     * @return void
     *
     */

    void setQuantidade(int quantidade);


    /**
     * Retorna tipo de compra
     * @return char
     *
     */
    char getTipoCompra();


    /**
     * Define tipo de compra de uma venda
     * @return void
     *
     */
    void setTipoCompra(char tipoCompra);

    /**
     * Indica mes da venda
     * @return int
     *
     */
    int getMes();


    /**
     * Define mes da venda
     * @return void
     *
     */
    void setMes(int mes);


    /**
     * Retorna a filial da venda
     * @return int
     *
     */
    int getFilial();


    /**
     * Define a filial da venda
     * @return int
     *
     */
    void setFilial(int filial);


    /**
     * Cria uma cópia da instância de Venda que invoca o método.
     * @return Cópia da Venda.
     */
    IVenda clone();


    /**
     * Valida uma venda
     * @param v,cp,cc
     * @return boolean
     *
     */
    boolean validaV(ICatProdutos cp, ICatClientes cc);


}
