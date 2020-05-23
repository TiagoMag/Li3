package model;


import java.util.Set;


/**
 * Interface correspondente ao catalogo de clientes.
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
        public Set <ICliente> getClientes();

    /**
     * Define os clientes do catalogo
     * @return void
     *
     */

        public void setClientes (Set <ICliente> clientes);
    /**
     * Método clone
     * @return ICatClientes
     *
     */

        public ICatClientes clone ();
    /**
     * Adiciona quantidade vendida à venda
     * @return int
     *
     */

        public void insereCliente (ICliente p);
    /**
     * Adiciona quantidade vendida à venda
     * @return int
     *
     */

        public int numeroClientes ();
}

