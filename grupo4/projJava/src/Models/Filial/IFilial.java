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

    /**
     * Adiciona uma compra a um cliente
     */
    void insereVenda(Venda v);

}
