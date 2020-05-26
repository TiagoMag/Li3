package Models.Faturacao;

import Models.Catalogos.IProduto;
import Models.Catalogos.Produto;
import Models.Venda;
import java.io.Serializable;
import java.util.List;
import java.util.Map;


public interface IFaturacao extends Serializable {


    /**
     * Compara duas  faturações como Objetos
     * @param o Objeto a comparar
     * @return false, se não forem iguais, true se forem iguais.
     */
    public boolean equals(Object o);

    /**
     * Retorna   em formato de String.
     * @return Cliente em formato de String.
     */
    public String toString();

    /**
     * Cria uma cópia da instância de Cliente que invoca o método.
     * @return model.Faturacao.Faturacao
     */
    public List<Map<IProduto, InfoFat>> getFaturacao();

    /**
     * @param f
     *
     */
    public void setFaturacao(List<Map<Produto, InfoFat>> f);

    /**
     * Clone
     */
    public IFaturacao clone();

    /**
     * Adiciona uma venda à faturacao num determinado mes a um dado produto
     * @param  v
     *
     */
    public void insereVenda(Venda v);

    public float faturacaoTotal();

    public float faturacaoMes(int mes,int filial);

    public int numComprasMes(int mes);

    public int numeroProdsComprados();

}
