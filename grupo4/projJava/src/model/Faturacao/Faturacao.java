package model.Faturacao;

import Common.Constantes;
import model.Catalogos.Produto;
import model.Venda;

import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Classe que representa a faturacao e as operaçoes que
 * se podem realizar sobre ela
 *
 * @author Grupo4
 * @version 2020
 */

public class Faturacao implements Serializable{

    /* Variáveis de instância */
    private List<Map<Produto, InfoFat>> faturacao;   /* Lista Meses -> Map( Key : Produto Value : InfoFat ) */

    /**
     * Construtor vazio da classe
     */
    public Faturacao() {
        this.faturacao = new ArrayList<>();
        for (int i = 0; i < Constantes.MESES ; i++) {
            this.faturacao.add(new HashMap<>());
        }
    }

    /**
     * Construtor por cópia
     */
    public Faturacao(Faturacao f){
        this.faturacao = f.getFaturacao();
    }

    /**
     * Construtor parametrizado
     */
    public Faturacao(List<Map<Produto, InfoFat>> f){
        this.setFaturacao(f);
    }

    /**
     * Getters
     */
    public List<Map<Produto, InfoFat>> getFaturacao(){
        return this.faturacao.stream().map(p->p.entrySet().stream().collect(Collectors.toMap(e->e.getKey().clone(),e->e.getValue().clone()))).collect(Collectors.toList());
    }

    /**
     * Setters
     */
    public void setFaturacao(List<Map<Produto, InfoFat>> f){
        this.faturacao = f.stream().map(p->p.entrySet().stream().collect(Collectors.toMap(e->e.getKey().clone(),e->e.getValue().clone()))).collect(Collectors.toList());
    }

    /**
     * Clone
     */
    public Faturacao clone(){
        return new Faturacao(this);
    }

    /**
     * Adiciona uma venda à faturacao num determinado mes a um dado produto
     */
    public void insereVenda(Venda v){
        if(this.faturacao.get(v.getMes()-1).containsKey(v.getProduto())){ // vê se produto já existe
            this.faturacao.get(v.getMes()-1).get(v.getProduto()).insereVenda(v.getFilial(),v.getPreco(),v.getQuantidade());
        } else {  // se não existe cria
            this.faturacao.get(v.getMes()-1).put(v.getProduto().clone(),new InfoFat());
            this.faturacao.get(v.getMes()-1).get(v.getProduto()).insereVenda(v.getFilial(),v.getPreco(),v.getQuantidade());
        }
    }


    /*

    public model.Faturacao.Faturacao(Map<Produto, Venda> vendas) {
        setVendas(vendas);
    }

    public model.Faturacao.Faturacao(model.Faturacao.Faturacao f) {
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
        model.Faturacao.Faturacao a = (model.Faturacao.Faturacao) o;
        return this.vendas.equals(a.getVendas());
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.vendas);
        return sb.toString();
    }

    public model.Faturacao.Faturacao clone(){
        return new model.Faturacao.Faturacao(this);
    }

    public boolean existeProduto(Produto p){
        return this.vendas.containsKey(p);
    }
    */


}
