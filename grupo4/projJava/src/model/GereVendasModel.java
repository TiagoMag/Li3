package model;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

public class GereVendasModel {
    private Faturacao vendas;
    private CatProds produtos;
    private CatClientes clientes;

    public GereVendasModel() {
        this.vendas = new Faturacao();
        this.produtos = new CatProds();
        this.clientes = new CatClientes();
    }

    public GereVendasModel(Faturacao vendas, CatProds produtos, CatClientes clientes) {
        this.vendas = new Faturacao(vendas.clone());
        this.produtos = new CatProds(produtos);
        this.clientes = new CatClientes(clientes);
    }

    public GereVendasModel(GereVendasModel g){
        setVendas(g.getVendas());
        setProdutos(g.getProdutos());
        setClientes(g.getClientes());
    }

    public Faturacao getVendas() {
        return vendas.clone();
    }

    public void setVendas(Faturacao vendas) {
        this.vendas = vendas.clone();
    }

    public CatProds getProdutos() {
        return produtos.clone();
    }

    public void setProdutos(CatProds produtos) {
        this.produtos = produtos.clone();
    }

    public CatClientes getClientes() {
        return clientes.clone();
    }

    public void setClientes(CatClientes clientes) {
        this.clientes = clientes.clone();
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        GereVendasModel a = (GereVendasModel) o;
        return this.vendas.equals(a.getVendas())
                && this.clientes.equals(a.getClientes())
                && this.produtos.equals(a.getProdutos());
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.vendas).append(this.clientes).append(this.produtos);
        return sb.toString();
    }

    public GereVendasModel clone(){
        return new GereVendasModel(this);
    }


    //Consultas estatisticas
    /**
     * 1.1
     */



    /**
     * 1.2
     */

    public int numeroComprasMes(int mes){
        return (int) this.vendas.getVendas().values().stream().filter(e->e.getMes()==(mes)).count();
    }



    //Consultas interativas

    //1)
    public List<Produto> produtosNaoComprados(){
        return this.produtos.getProdutos().stream().filter(e-> !(vendas.existeProduto(e))).collect(Collectors.toList());
    }

    //2) FALTA FILIAL A FILIAL(o que isso quer dizer eu nao sei :P)
    public ParQuerie2 numeroTotalVendasEClientesMes(int mes){
        ParQuerie2 p = new ParQuerie2();
        List<Cliente> c = Collections.singletonList((Cliente) this.vendas.getVendas().values().stream().filter(e -> e.getMes() == (mes)).collect(Collectors.toList()));

        p.setNrVendas(numeroComprasMes(mes));
        p.setNrClientes((int) c.stream().distinct().count());
        return p;
    }

    //3)
    public int quantasComprasFezPMes(String cod){
        float faturado = 0;
        List<Venda> vendas = this.vendas.getVendas().values().stream().filter(e->e.getCliente().equals(cod)).collect(Collectors.toList());
        ParQuerie3 p = new ParQuerie3();
        for (int i=0;i<12;i++){
            int aux = i;
            p.setVenda(aux,(int)vendas.stream().filter(e->e.getMes()==(aux+1)).count());
            p.setProdutos(aux,(int)vendas.stream().filter(e->e.getMes()==(aux+1)).distinct().count());
            vendas.stream().filter(e->e.getMes()==(aux+1)).map(c->c.getPreco()); // da a lista com o faturado de todas as vendas de determinado mes
        }

    }
}
