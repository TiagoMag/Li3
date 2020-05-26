package Models.Queries;

import java.util.ArrayList;
import java.util.List;

public class ParQuerie3 {
    private List<Integer> nrVendasPorMes;
    private List<Integer> nrProdutos;
    private List<Float> totalFaturado;

    public ParQuerie3() {
        nrVendasPorMes = new ArrayList<>();
        nrProdutos = new ArrayList<>();
        totalFaturado = new ArrayList<>();
    }

    public ParQuerie3(List<Integer> nrVendasPorMes, List<Integer> nrProdutos, List<Float> totalFaturado) {
        this.nrVendasPorMes = new ArrayList<>(nrVendasPorMes);
        this.nrProdutos = new ArrayList<>(nrProdutos);
        this.totalFaturado = new ArrayList<>(totalFaturado);
    }

    public ParQuerie3(ParQuerie3 p){
        setNrVendasPorMes(p.getNrVendasPorMes());
        setNrProdutos(p.getNrProdutos());
        setTotalFaturado(p.getTotalFaturado());
    }

    public List<Integer> getNrVendasPorMes() {
        return new ArrayList(nrVendasPorMes);
    }

    public void setNrVendasPorMes(List<Integer> nrVendasPorMes) {
        this.nrVendasPorMes = new ArrayList<>(nrVendasPorMes);
    }

    public List<Integer> getNrProdutos() {
        return new ArrayList<>(nrProdutos);
    }

    public void setNrProdutos(List<Integer> nrProdutos) {
        this.nrProdutos = new ArrayList<>(nrProdutos);
    }

    public List<Float> getTotalFaturado() {
        return new ArrayList<>(totalFaturado);
    }

    public void setTotalFaturado(List<Float> totalFaturado) {
        this.totalFaturado = new ArrayList<>(totalFaturado);
    }

    public void setVenda(int mes, int nr ){
        nrVendasPorMes.set(mes, nr);
    }

    public void setProdutos(int mes, int nr ){
        nrProdutos.set(mes, nr);
    }

    public void setFaturado(int mes,float nr){ totalFaturado.set(mes,nr);}
}
