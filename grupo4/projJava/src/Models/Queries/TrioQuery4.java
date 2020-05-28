package Models.Queries;

public class TrioQuery4 {

    float total_faturado;
    int num_compras;
    int num_clientes;

    public TrioQuery4(){
        this.total_faturado=0.0f;
        this.num_compras=0;
        this.num_clientes=0;
    }

    public TrioQuery4(TrioQuery4 trio)
    {
        // initialise instance variables
        this.total_faturado=trio.getTotal_faturado();
        this.num_compras=trio.getNum_compras();
        this.num_clientes=trio.getNum_clientes();
    }

    public TrioQuery4(float total_faturado, int num_compras, int num_clientes) {
        this.total_faturado = total_faturado;
        this.num_compras = num_compras;
        this.num_clientes = num_clientes;
    }

    public float getTotal_faturado() {
        return total_faturado;
    }

    public int getNum_compras() {
        return num_compras;
    }

    public int getNum_clientes() {
        return num_clientes;
    }

    public void setTotal_faturado(float total_faturado) {
        this.total_faturado = total_faturado;
    }

    public void setNum_compras(int num_compras) {
        this.num_compras = num_compras;
    }

    public void setNum_clientes(int num_clientes) {
        this.num_clientes = num_clientes;
    }

    public TrioQuery4 clone (){
        return new TrioQuery4(this);
    }
}
