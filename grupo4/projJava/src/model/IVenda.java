package model;


public interface IVenda {

    /**
     * Retorna o Produto da venda
     * @return Produto
     *
     */

    public Produto getProduto();

    /**
     * Insere Produto numa venda
     * @param produto
     * @return void
     *
     */

    public void setProduto(Produto produto);

    /**
     * Retorna Cliente da venda
     * @return Cliente
     *
     */

    public Cliente getCliente();

    /**
     * Insere cliente na venda
     * @param cliente
     * @return void
     *
     */

    public void setCliente(Cliente cliente);

    /**
     * Retorna valor da venda
     * @return float
     *
     */
    public float getPreco();

    /**
     * Adiciona valor à venda
     * @param  preco
     * @return void
     *
     */
    public void setPreco(float preco);


    /**
     * Retorna quantidade vendida na venda
     * @return int
     *
     */
    public int getQuantidade();

    /**
     * Adiciona quantidade vendida à venda
     * @param quantidade
     * @return void
     *
     */

    public void setQuantidade(int quantidade);


    /**
     * Retorna tipo de compra
     * @return char
     *
     */
    public char getTipoCompra();


    /**
     * Define tipo de compra de uma venda
     * @return void
     *
     */
    public void setTipoCompra(char tipoCompra);

    /**
     * Indica mes da venda
     * @return int
     *
     */
    public int getMes();


    /**
     * Define mes da venda
     * @return void
     *
     */
    public void setMes(int mes);


    /**
     * Retorna a filial da venda
     * @return int
     *
     */
    public int getFilial();


    /**
     * Define a filial da venda
     * @return int
     *
     */
    public void setFilial(int filial);


    /**
     * Cria uma cópia da instância de Venda que invoca o método.
     * @return Cópia da Venda.
     */
    public Venda clone();


    /**
     * Valida uma venda
     * @param v,cp,cc
     * @return boolean
     *
     */
    public boolean validaV(Venda v,CatProds cp,CatClientes cc);


}
