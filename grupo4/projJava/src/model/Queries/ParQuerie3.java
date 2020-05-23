package model.Queries;

import java.util.ArrayList;
import java.util.List;

public class ParQuerie3 {
    private List<Integer> nrVendasPorMes;
    private List<Integer> nrProdutos;
    private float totalFaturado;

    public ParQuerie3() {
        nrVendasPorMes = new ArrayList<>();
        nrProdutos = new ArrayList<>();
        totalFaturado = 0;
    }

    public ParQuerie3(List<Integer> nrVendasPorMes, List<Integer> nrProdutos, float totalFaturado) {
        this.nrVendasPorMes = new ArrayList<>(nrVendasPorMes);
        this.nrProdutos = new ArrayList<>(nrProdutos);
        this.totalFaturado = totalFaturado;
    }

    public ParQuerie3(ParQuerie3 p){
        setNrVendasPorMes(p.getNrVendasPorMes());
        setNrProdutos(p.getNrProdutos());
        this.totalFaturado = p.getTotalFaturado();
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

    public float getTotalFaturado() {
        return totalFaturado;
    }

    public void setTotalFaturado(float totalFaturado) {
        this.totalFaturado = totalFaturado;
    }

    public void setVenda(int mes, int nr ){
        nrVendasPorMes.set(mes, nr);
    }

    public void setProdutos(int mes, int nr ){
        nrProdutos.set(mes, nr);
    }
}
