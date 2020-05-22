package model;

import java.util.ArrayList;
import java.util.List;

public class ParQuerie2 {
    private int nrVendas;
    private int nrClientes;

    public ParQuerie2() {
        this.nrVendas = 0;
        this.nrClientes = 0;
    }

    public ParQuerie2(int nrVendas, int nrClientes) {
        this.nrVendas = nrVendas;
        this.nrClientes = nrClientes;
    }

    public ParQuerie2(ParQuerie2 p){
        this.nrClientes=p.getNrClientes();
        this.nrVendas=p.getNrVendas();
    }

    public int getNrVendas() {
        return nrVendas;
    }

    public void setNrVendas(int nrVendas) {
        this.nrVendas = nrVendas;
    }

    public int getNrClientes() {
        return nrClientes;
    }

    public void setNrClientes(int nrClientes) {
        this.nrClientes = nrClientes;
    }
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ParQuerie2 a = (ParQuerie2) o;
        return this.nrVendas==(a.getNrVendas())
                && this.nrClientes==(a.getNrClientes());
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.nrVendas).append("\n").append(this.nrClientes);
        return sb.toString();
    }

    public ParQuerie2 clone(){
        return new ParQuerie2(this);
    }
}
