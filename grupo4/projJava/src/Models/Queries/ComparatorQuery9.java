package Models.Queries;

import java.io.Serializable;
import java.util.Comparator;

public class ComparatorQuery9 implements Comparator<ParQuerie9>, Serializable {
    public int compare (ParQuerie9 s1 , ParQuerie9 s2){
        if (s1.getTotal() > s2.getTotal())
            return -1;
        else if (s2.getTotal() > s1.getTotal())
            return 1;
        return s1.getCliente().compareTo(s2.getCliente());
    }
}
