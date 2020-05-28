package Models.Queries;

import Models.Catalogos.ICliente;

import java.util.Map;

public class ParQuerie9 {
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
