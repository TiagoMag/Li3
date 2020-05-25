package Models.Catalogos;

import static java.lang.Integer.parseInt;

 public interface IProduto {

    /**
     * Indica o codigo de produto
     * @return String código de produto
     *
     */
     String getCodigo();

    /**
     * Define codigo de produto
     * @return void
     *
     */
     void setCodigo(String codigo);

    /**
     * Funcao que compara a equidade de dois objetos.
     *
     * @param o Objeto que pretendemos comparar
     * @return true no caso de serem iguais, false em caso contrario
     */
     boolean equals(Object o);

    /**
     * Funcao que calcula o hash code de um produto.
     *
     * @return inteiro correspondente ao hashCode
     */
     int hashCode();

    /**
     * Funcao que transforma o produto numa String
     * para que seja possivel visualiza-lo.
     *
     * @return String corresponde ao produto na forma visual
     */
     String toString ();

    /**
     * Funcao que nos permite dar clone a um produto,
     * criando um produto exatamente igual.
     *
     * @return Clone do produto
     */
     IProduto clone();
    /**
     * Funcao que compara produtos tendo em conta o seu codigo.
     *
     * @param p produto a comparar
     * @return >1 caso "p" seja menor que o produto em questao, 0 caso sejam iguais e <1 caso seja maior
     */
     int compareTo (IProduto p);
    /**
     * Funcao que nos verifica se o produto é valido
     *
     * @return false se o produto nao for valido, true caso contrário
     */
     boolean validaProd();



}
