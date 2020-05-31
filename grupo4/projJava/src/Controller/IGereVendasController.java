package Controller;

import Exceptions.ClienteInvalidoException;
import Exceptions.MesInvalidoException;
import Exceptions.ProdutoInvalidoException;
import Models.Catalogos.ICliente;
import Models.Catalogos.IProduto;
import Models.GereVendasModel;
import Models.IGereVendasModel;
import Views.GereVendasView;
import Views.IGereVendasView;

/**
 * Interface correspondente á classe Controller.GereVendasController
 *
 *
 * @author Grupo4
 * @version 2020
 */
 public interface IGereVendasController {
    /**
     * Setter
     * @param model
     */
     void setModel (IGereVendasModel model);

    /**
     * Setter
     * @param view
     */
     void setView (IGereVendasView view);

    /**
     * Inicializa controller
     */
    void startController();

    /**
     * Lê Ficheiros
     */
     void readFiles();

    /**
     * Carrega o Estado
     */
    void carregaEstadoWrapper();


    /**
    * Guarda Estado
    */
     void guardaEstadoWrapper();

    /**
     * Tratamento das Queries estatisticas
     */
    void handlerQueriesEstatisticas();

    /**
     * Tratamento dos dados gerais
     */
     void handlerdadosGerais();

    /**
     * Tratamento das Queries interativas
     */
    void handlerQueriesInterativas();

    /**
     * Verifica a validade de um mes
     * @param x
     * @return
     */
     boolean validaMes(int x) throws MesInvalidoException;

    /**
     * Verifica a validade de um Cliente
     * @param c
     * @return
     */
     boolean validaCliente(ICliente c) throws ClienteInvalidoException;

    /**
     * Verifica a validade de um Produto
     * @param p
     * @return
     */
     boolean validaProduto(IProduto p) throws ProdutoInvalidoException;

}
