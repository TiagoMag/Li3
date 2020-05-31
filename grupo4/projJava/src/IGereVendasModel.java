
import Models.Catalogos.*;
import Models.Faturacao.Faturacao;
import Models.Faturacao.IFaturacao;
import Models.Filial.Filial;
import Models.Filial.IFilial;

import Models.Queries.*;
import Models.Venda;

import java.io.*;
import java.util.*;

/**
 * Interface correspondente á classe GereVendasModel
 *
 *
 * @author Grupo4
 * @version 2020
 */


public interface IGereVendasModel {
    /**
     * Getter
     * @return
     */
    ICatProdutos getCatProdutos();

    /**
     * Getter
     * @return
     */
    ICatClientes getCatClientes();

    /**
     * Getter
     * @return
     */
    IFaturacao getFaturacao();

    /**
     * Getter
     * @return
     */
    List<IFilial> getFiliais();

    /**
     * Getter
     * @return
     */
    InfoVendasFile getIv();


    /**
     * Setter
     * @param catprodutos
     */
    void setCatprodutos(CatProds catprodutos);

    /**
     * Setter
     * @param catclientes
     */
    void setCatclientes(CatClientes catclientes);

    /**
     *
     * @param faturacao
     */
    void setFaturacao(Faturacao faturacao);

    /**
     * Setter
     * @param filiais
     */
    void setFiliais(List<Filial> filiais);

    /**
     * Método clone
     * @return
     */
    GereVendasModel clone();


    /**
     * leitura do ficheiro de produto
     * @param filename
     */
    void lerFilesProdutos (String filename);


    /**
     * leitura do ficheiro de clientes
     * @param nomeFich
     */
    void lerFilesClientes (String nomeFich);


    /**
     * Transforma uma linha do ficheiro venda numa Venda
     * @param linha
     * @return
     */
    Venda linhaToVenda (String linha);

    /**
     * Leitura do ficheiro de vendas
     * @param filename
     */
    void lerVendas(String filename);

    /**
     * Leitura da config
     * @return
     */
    String [] lerConfigs();

    /**
     * Save dos dados carregados
     * @param fileName
     * @throws FileNotFoundException
     * @throws IOException
     */
    void guardaEstado(String fileName) throws FileNotFoundException,IOException;

    /**
     * Carrega estado previamente guardado
     * @param fileName
     * @return
     * @throws FileNotFoundException
     * @throws IOException
     * @throws ClassNotFoundException
     */




    /**
     * Numero total de compradores numa filial
     */
    int totalBuyers();

    /**
     * Querie Estatistica 1.1
     * @return
     */
    List<String> Querie11();

    /**
     * Querie Estatica 1.2.1
     * @return
     */

    List<Integer> Querie121();




    /**
     * Método que procede à realizacao da query 1
     * @return
     */
    Set<IProduto> produtosNaoComprados();

    /**
     * Método que procede à realizacao da query 2
     * @param mes
     * @return
     */
    ParQuery2[] numeroTotalVendasEClientesMes(int mes);

    /**
     * Método que procede à realizacao da query 3
     * @param c
     * @return
     */
    TrioQuery3 quantasComprasFezPMes(ICliente c);


    /**
     * Método que procede à realizacao da query 4
     * @param p
     * @return
     */
    TrioQuery4[] querie4 (IProduto p);

    /**
     * Método que procede à realizacao da query 5
     * @param c
     * @return
     */
    Set<ParQuery5> query5(ICliente c);

    /**
     * Numero total de compradores de um produto
     * @param p
     * @return
     */
    int buyersProduct(IProduto p);

    /**
     * Método que procede à realizacao da query 6
     * @param limit
     * @return
     */
    Set<TrioQuery6> query6 (int limit);

    /**
     * Método que procede à realizacao da query 7
     * @return
     */
    List<Set<ParQuery7>> query7 ();

    /**
     * Método que procede à realizacao da query 8
     * @param limit
     * @return
     */
    List<ParQuery8> query8(int limit);

    /**
     * Método que procede à realizacao da query 9
     * @param p
     * @param limit
     * @return
     */
    List<ParQuerie9> query9(IProduto p,int limit);


    /**
     * Método que procede à realizacao da query 10
     * @return
     */
    List<ParQuery10> query10();

    public void loadModel();
}
