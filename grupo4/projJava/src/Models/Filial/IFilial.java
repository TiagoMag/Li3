package Models.Filial;

import Models.Catalogos.ICliente;
import Models.Catalogos.IProduto;
import Models.Catalogos.Produto;
import Models.Venda;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
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

    public List<ICliente> filialBuyers();
    /**
     * Adiciona uma compra a um cliente
     */
   void insereVenda(Venda v);

   public List<ICliente> filialbuyersMes(int mes);

    public int nrComprasClientePMes(ICliente c,int mes);

    public List<IProduto> getProdutosClientePMes(ICliente c,int mes);

    public float getFaturadoClienteMes(ICliente c,int mes);
}
