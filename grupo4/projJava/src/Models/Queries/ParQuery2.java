package Models.Queries;

public class ParQuery2 {
    private int nrVendas;
    private int nrClientes;

    public ParQuery2() {
        this.nrVendas = 0;
        this.nrClientes = 0;
    }

    public ParQuery2(int nrVendas, int nrClientes) {
        this.nrVendas = nrVendas;
        this.nrClientes = nrClientes;
    }

    public ParQuery2(ParQuery2 p){
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
        ParQuery2 a = (ParQuery2) o;
        return this.nrVendas==(a.getNrVendas())
                && this.nrClientes==(a.getNrClientes());
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.nrVendas).append("\n").append(this.nrClientes);
        return sb.toString();
    }

    public ParQuery2 clone(){
        return new ParQuery2(this);
    }
}
