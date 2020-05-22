package model;


import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class Faturacao {
    private Map<Produto,Venda> vendas;

    public Faturacao() {
        this.vendas = new HashMap<>();
    }

    public Faturacao(Map<Produto, Venda> vendas) {
        setVendas(vendas);
    }

    public Faturacao(Faturacao f) {
        setVendas(f.getVendas());
    }

    public Map<Produto, Venda> getVendas() {
        Map<Produto,Venda> ret = new HashMap<Produto,Venda>();
        vendas.forEach((a,b)->ret.put(a.clone(),b.clone()));
        return ret;
    }

    public void setVendas(Map<Produto, Venda> vendas) {
        this.vendas = new HashMap<>();
        vendas.entrySet().forEach(e->this.vendas.put(e.getKey(),e.getValue().clone()));
    }

    public void insereVenda(Venda v){
        this.vendas.put(v.getProduto(),v.clone());
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Faturacao a = (Faturacao) o;
        return this.vendas.equals(a.getVendas());
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.vendas);
        return sb.toString();
    }

    public Faturacao clone(){
        return new Faturacao(this);
    }

    public boolean existeProduto(Produto p){
        return this.vendas.containsKey(p);
    }

}
