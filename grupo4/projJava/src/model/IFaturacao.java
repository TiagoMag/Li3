package model;

import java.io.Serializable;
import java.util.HashMap;
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
     * @return Faturacao
     */
    public Faturacao clone();






}
