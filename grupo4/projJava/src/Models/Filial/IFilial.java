package Models.Filial;

import Models.Catalogos.ICliente;
import Models.Catalogos.IProduto;
import Models.Queries.ParQuerie9;


import Models.Queries.ParQuery7;

import Models.Queries.ParQuery8;

import Models.Vendas.Venda;

import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * Interface correspondente a Filial.
 * Permite operaçoes sobre uma Filial
 *
 * @author Grupo4
 * @version 2020
 */


public interface IFilial {

    Map<ICliente, List<InfoFilial>> getFilial();

    /**
     * Setter
     * @param f
     */
    void setFilial(Map<ICliente, List<InfoFilial>> f);

    /**
     * Clone
     * @return copia do objeto
     */
    IFilial clone ();

    /**
     * Lista de clientes que fizeram compras numa filial
     * @return Lista de clientes
     */
    List<ICliente> filialBuyers();

    /**
     * Adiciona uma venda a um cliente
     * @param v
     */
   void insereVenda(Venda v);

    /**
     * Lista de clientes que realizaram compras num determinado mes, numa filial
     * @param mes
     * @return
     */

   List<ICliente> filialbuyersMes(int mes);

    /**
     * Numero de compras de um cliente num determinado mes, numa determinada filial
     * @param c
     * @param mes
     * @return Total de compras feitas por um cliente num mes à escolha
     */

    int nrComprasClientePMes(ICliente c,int mes);

    /**
     * Infere o numero de produtos comprados por um cliente, num mes escolhido numa determinada filial
     * @param c
     * @param mes
     * @return Lista de produtos comprados num determinado mes por um determinado cliente
     */

    List<IProduto> getProdutosClientePMes(ICliente c,int mes);

    /**
     * Infere o total de dinheiro que um cliente gastou num determinado mes numa determinada filial
     * @param c
     * @param mes
     * @return total de dinheiro gasto por um cliente
     */

    float getFaturadoClienteMes(ICliente c,int mes);

    /**
     * Numero de vendas feitas num determinado mes, numa determinada filial
     * @param mes
     * @return total de vendas feitas mes à escolha
     */

    int numVendas(int mes);

    /**
     * Infere todos os clientes que compraram um determinado produto, num determinado mes, numa determinada filial
     * @param p
     * @param mes
     * @return Lista de clientes que compraram um produto em especifico num determinado mes
     */

    List<ICliente> buyersProduct (IProduto p,int mes);

    /**
     * Compras de um determinado cliente numa determinada filial
     * @param c
     * @return Lista com as especificações - InfoFilial - de todas as compras que um cliente efetuou
     */

    List<InfoFilial> comprasCliente(ICliente c);

    /**
     * Todas as vendas de uma determinada filial
     * @return Retorna a lista de vendas de um cliente
     */

    List<InfoFilial> allSells();


    /**
     * Auxilia a realização da Query 7
     * @return Retorna os 3 clientes que mais dinheiro gastaram numa determinada filial
     */
    Set<ParQuery7> top3Compradores();

    /**
     * Infere todos os clientes que compraram um determinado produto numa determinada filial
     * @param p
     * @return Lista de clientes que compraram um produto em especifico
     */

    List <ICliente> buyersProduct(IProduto p);

    /**
     * Auxilia a realizacao da Query 8
     * @return Lista de clientes que realizaram compras numa filial
     */
    List<ParQuery8> allClientsProducts();

    /**
     *
     * @param info
     * @return
     */
    List <IProduto> clientProducts(List<InfoFilial> info);

    /**
     * Auxilia a realizacao da Query9
     * @param p
     * @return Lista de clientes, cada um com, com especificações da compra de um determinado produto
     */

    List<ParQuerie9> nrComprasClienteProduto(IProduto p);


    /**
     * Lista de clientes diferentes num determinado mes
     * @return
     */
    public List<Integer> clientesDistintosMes();


}
