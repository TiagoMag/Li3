package Models.Queries;

import Models.Catalogos.ICliente;
import java.io.Serializable;


/**
 * Classe auxiliar usada para resolver a Query 9
 *
 * @author Grupo4
 * @version 2020
 */

public class ParQuerie9 implements Serializable {
    private ICliente cliente;
    private float faturado;
    private int total;

    public ParQuerie9(ICliente cl, float f,int t ) {
        this.cliente = cl.clone();
        this.faturado = f;
        this.total = t;

    }

    public ICliente getCliente() {
        return cliente.clone();
    }

    public float getFaturado() {
        return faturado;
    }

    public int getTotal(){
        return this.total;
    }
}
