package Comparator;

import Models.Queries.ParQuerie9;

import java.io.Serializable;
import java.util.Comparator;

/**
 * Comparator destinado à realização do método da Query 8
 *
 * @author Grupo4
 * @version 2020
 */

public class ComparatorQuery9 implements Comparator<ParQuerie9>, Serializable {
    public int compare (ParQuerie9 s1 , ParQuerie9 s2){
        if (s1.getTotal() > s2.getTotal())
            return -1;
        else if (s2.getTotal() > s1.getTotal())
            return 1;
        return s1.getCliente().compareTo(s2.getCliente());
    }
}
