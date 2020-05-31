package Models.Queries;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 * Classe auxiliar usada para resolver a Query 3
 *
 * @author Grupo4
 * @version 2020
 */

public class TrioQuery3 implements Serializable {
    private List<Integer> nrVendasPorMes;
    private List<Integer> nrProdutos;
    private List<Float> totalFaturado;

    public TrioQuery3() {
        nrVendasPorMes = new ArrayList<>();
        nrProdutos = new ArrayList<>();
        totalFaturado = new ArrayList<>();
    }

    public TrioQuery3(List<Integer> nrVendasPorMes, List<Integer> nrProdutos, List<Float> totalFaturado) {
        this.nrVendasPorMes = new ArrayList<>(nrVendasPorMes);
        this.nrProdutos = new ArrayList<>(nrProdutos);
        this.totalFaturado = new ArrayList<>(totalFaturado);
    }

    public TrioQuery3(TrioQuery3 p){
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
        nrVendasPorMes.add(mes, nr);
    }

    public void setProdutos(int mes, int nr ){
        nrProdutos.add(mes, nr);
    }

    public void setFaturado(int mes,float nr){ totalFaturado.add(mes,nr);}
}
