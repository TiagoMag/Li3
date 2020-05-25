package Models.Catalogos;

import java.io.Serializable;

public interface ICliente extends Serializable {

    /**
     * Retorna o código de cliente.
     * @return Código de cliente
     */
    String getCodigo();
    /**
     * Altera o código da instância de cliente que invoca o método.
     * @param codigo Novo código de cliente.
     */
    void setCodigo(String codigo);
    /**
     * Compara dois objetos, em concreto, deverá ser usado para comparar dois Clientes.
     * @param o Objeto para comparar ao Cliente.
     * @return false, se não forem iguais, true se forem iguais.
     */
    boolean equals(Object o);
    /**
     * Método de hashing para estruturas que o exigem.
     * @return Inteiro que representa o resultado do hashing.
     */
    int hashCode();
    /**
     * Funcao que compara clientes pelo seu codigo.
     *
     * @param p cliente a comparar
     * @return >1 caso o p seja menor que o cliente em questao, 0 caso sejam iguais e <1 caso seja maior
     */
    int compareTo (ICliente p);
    /**
     * Retorna o Cliente em formato de String.
     * @return Cliente em formato de String.
     */
    String toString();
    /**
     * Cria uma cópia da instância de Cliente que invoca o método.
     * @return Cópia do Cliente.
     */
    Cliente clone();
    /**
     * Método de validação de um cliente
     * @return Bool que diz se um codigo é valido ou nao
     */
    boolean validaCliente();








}

