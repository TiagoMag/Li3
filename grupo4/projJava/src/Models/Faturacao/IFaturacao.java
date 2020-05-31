package Models.Faturacao;

import Models.Catalogos.IProduto;
import Models.Queries.ParQuery10;
import Models.Queries.ParQuery5;
import Models.Vendas.Venda;
import java.io.Serializable;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * Interface correspondente a Faturação.
 * Permite operaçoes sobre a Faturação
 *
 * @author Grupo4
 * @version 2020
 */

 public interface IFaturacao extends Serializable {


    /**
     * Compara duas  faturações como Objetos
     * @param o Objeto a comparar
     * @return false, se não forem iguais, true se forem iguais.
     */
     boolean equals(Object o);

    /**
     * Retorna em formato de String.
     * @return Cliente em formato de String.
     */
     String toString();

    /**
     * Cria uma cópia da instância de Cliente que invoca o método.
     * @return model.Faturacao.Faturacao
     */
     List<Map<IProduto, InfoFat>>getFaturacao();

    /**
     * Setter
     * @param f
     *
     */
     void setFaturacao(List<Map<IProduto, InfoFat>> f);

    /**
     *
     * @return
     */
     IFaturacao clone();

    /**
     * Adiciona uma venda à faturacao num determinado mes a um dado produto
     * @param  v
     *
     */
     void insereVenda(Venda v);

    /**
     * Indica o total faturado
     * @return
     */

     float faturacaoTotal();

    /**
     * Indica a faturação por mês
     * @param mes
     * @param filial
     * @return total faturado num determinado mês
     */

     float faturacaoMes(int mes,int filial);

    /**
     * Indica o numero de compras feitas por mês
     * @param mes
     * @return total de compras feitas num determinado mês
     */

     int numComprasMes(int mes);

    /**
     * Indica o numero de produtos comprados
     * @return
     */

     int numeroProdsComprados();

    /**
     * Indica se um produto existe nos registos
     * @param p
     * @return True se sim, False se não
     */

     boolean existeProduto(IProduto p);

    /**
     * Indica o total faturado por um produto num determinado mês
     * @param p
     * @param mes
     * @return faturacao total de produto num mes
     */

     float totalFaturadoProd(IProduto p,int mes);

    /**
     * Indica o numero de vendas de um produto num determinado mês
     * @param p
     * @param mes
     * @return numero de vendas de um produto num mes
     */

     int totalVendasProd(IProduto p,int mes);

    /**
     * Funcao essencial à realizacão da query 5
     * @param limit
     * @return Top delimitado por limit dos produtos mais vendidos
     */

     Set<ParQuery5> mostSelledProds(int limit);

    /**
     * TotalFaturado num produto
     * @param prod
     * @return
     */
     ParQuery10 totalFaturadoProduto(IProduto prod);

    /**
     * Faturação filial por mês
     * @return
     */
    List<Float> faturadoMesFililial();
}
