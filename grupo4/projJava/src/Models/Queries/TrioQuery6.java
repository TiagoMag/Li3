package Models.Queries;

import Models.Catalogos.IProduto;

import java.io.Serializable;


/**
 * Classe auxiliar usada para resolver a Query 6
 *
 * @author Grupo4
 * @version 2020
 */

public class TrioQuery6 implements Comparable<TrioQuery6>, Serializable {
    private IProduto produto;
    private int compras;
    private int nmr_clientes;


    public TrioQuery6(TrioQuery6 t){
        this.produto=t.getProduto().clone();
        this.compras=t.getCompras();
        this.nmr_clientes=t.getNmr_clientes();
    }
    public TrioQuery6(IProduto produto, int compras, int nmr_clientes) {
        this.produto = produto;
        this.compras = compras;
        this.nmr_clientes = nmr_clientes;
    }

    public IProduto getProduto() {
        return produto;
    }

    public int getCompras() {
        return compras;
    }

    public int getNmr_clientes() {
        return nmr_clientes;
    }

    public TrioQuery6 clone(){
        return new TrioQuery6(this);
    }

    @Override
    public int compareTo (TrioQuery6 p){
        return Integer.compare(p.getCompras(),this.compras);
    }
}
