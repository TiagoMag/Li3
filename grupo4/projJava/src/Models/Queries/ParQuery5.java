package Models.Queries;

import Models.Catalogos.IProduto;
import Models.Catalogos.Produto;

public class ParQuery5 implements Comparable<ParQuery5>{
    private IProduto produto;
    private int quantidade;

    public ParQuery5()
    {
        this.produto= new Produto();
        this.quantidade=0;
    }

    public ParQuery5(IProduto prod, int quant)
    {
        this.produto=prod.clone();
        this.quantidade=quant;
    }

    public ParQuery5(ParQuery5 t)
    {
        this.produto=t.getProduto();
        this.quantidade=t.getQuantidade();
    }

    public IProduto getProduto (){
        return this.produto.clone();
    }

    public int getQuantidade (){
        return this.quantidade;
    }

    public void setProduto (IProduto prod){
        this.produto=prod.clone();
    }

    public void addQuantidade (int quantidade){
        this.quantidade+=quantidade;
    }

    public ParQuery5 clone (){
        return new ParQuery5(this);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder ();
        sb.append("[").append(this.getProduto()).append("]:").append(this.getQuantidade()).append(" ");
        return sb.toString();
    }

    @Override
    public int compareTo(ParQuery5 par) {
        if (this.quantidade==par.getQuantidade()) return this.produto.compareTo(par.getProduto());
        else return Integer.compare(par.getQuantidade(),this.quantidade);
    }
}



