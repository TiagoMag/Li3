package Models.Filial;

import Models.Catalogos.ICliente;
import Models.Catalogos.IProduto;


import Models.Queries.ParQuery7;

import Models.Queries.ParQuery8;

import Models.Venda;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public interface IFilial {

    Map<ICliente, List<InfoFilial>> getFilial();

    /**
     * Setters
     */
    void setFilial(Map<ICliente, List<InfoFilial>> f);

    /**
     * Clone
     * */
    IFilial clone ();

    List<ICliente> filialBuyers();
    /**
     * Adiciona uma compra a um cliente
     */
   void insereVenda(Venda v);

   List<ICliente> filialbuyersMes(int mes);

    int nrComprasClientePMes(ICliente c,int mes);

    List<IProduto> getProdutosClientePMes(ICliente c,int mes);

    float getFaturadoClienteMes(ICliente c,int mes);

    int numVendas(int mes);

    List<ICliente> buyersProduct (IProduto p,int mes);

    List<InfoFilial> comprasCliente(ICliente c);


    List<InfoFilial> allSells();



    Set<ParQuery7> top3Compradores();

    List <ICliente> buyersProduct(IProduto p);


    List<ParQuery8> allClientsProducts();

    List <IProduto> clientProducts(List<InfoFilial> info);

}
