package Models.Catalogos;


import java.util.Set;


/**
 * Interface correspondente ao Catalogo de clientes.
 * Permite operaçoes sobre o catalago
 *
 * @author Grupo4
 * @version 2020
 */

public interface ICatClientes {
     /**
     * Retorna os clientes do catalogo
     * @return Set<ICliente>
     *
     */
      Set <ICliente> getClientes();

    /**
     * Define os clientes do catalogo
     * @return void
     *
     */

      void setClientes (Set <ICliente> clientes);
    /**
     * Método clone
     * @return ICatClientes
     *
     */
      ICatClientes clone ();
    /**
     * Verifica se um determinado Cliente existe no catalogo
     *
     * @param  c cliente a ser procurado
     * @return  true ou false consoante a existencia do cliente
     */
     boolean existeCliente (ICliente c);
    /**
     * Adiciona Cliente ao Catalogo
     * @param p Cliente a ser adicionado
     * @return void
     *
     */
     void insereCliente (ICliente p);
    /**
     * Indica o numero de clientes existentes no catalogo
     * @return numero de clientes existentes no catalogo
     *
     */
     int numeroClientes();
}

