package Models.Faturacao;

import Models.Queries.ParQuery5;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.AbstractMap.*;
import java.util.stream.Collectors;

/**
 * Classe auxiliar a Faturcao com a informacao que representa os dados de uma venda.
 *
 * @author Grupo4
 * @version 2020
 */

public class InfoFat implements Serializable {

    /* Variáveis de instância */
    private Map<Integer, List<SimpleEntry<Integer, Float>>> fat; /* Map Filial -> Key : NmrFilial Value : unidades,preco  */

    /**
     * Construtor vazio da classe
     */
    public InfoFat() {
        this.fat = new HashMap<>();
    }

    public double faturadoProdutosMes(){
        return this.fat.values().stream().mapToDouble(l -> l.stream().mapToDouble(x-> x.getKey() * x.getValue()).sum()).sum();
    }

    public double faturadoProdutosMesFilial(int filial){
        List<SimpleEntry<Integer, Float>> lst=this.fat.get(filial);
        return lst.stream().mapToDouble(x-> x.getKey() * x.getValue()).sum();
    }

    public int numCompras(){
        return this.fat.values().stream().mapToInt(List::size).sum();
    }


    public float faturado(float preco,int quant){
        return ((float)quant * preco) ;
    }
    /**
     * Construtor por cópia
     */
    public InfoFat(InfoFat fat) {
        this.fat = fat.getFat();
    }

    /**
     * Getters
     */
    public Map<Integer,List<SimpleEntry<Integer,Float>>> getFat(){
        return this.fat.entrySet().stream().collect(Collectors.toMap(p -> p.getKey(), l -> l.getValue().stream().map(x->new SimpleEntry<>(x.getKey(),x.getValue())).collect(Collectors.toList())));
    }

    /**
     * Clone
     */
    public InfoFat clone(){
        return new InfoFat(this);
    }

    /**
     * Equals
     */
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        InfoFat f = (InfoFat) o;
        return (this.fat.equals(f.getFat()));
    }

    /**
     * Adiciona uma venda à fat com o seu preco e quantidade
     */
    public void insereVenda(int filial,float preco,int quantidade){
        if(this.fat.containsKey(filial)){                                     // Se filial tiver info adiciona
            this.fat.get(filial).add(new SimpleEntry<>(quantidade,preco));
        }
        else {
            List<SimpleEntry<Integer,Float>> list = new ArrayList<>();  // Se filial ñ tiver info
            list.add(new SimpleEntry<>(quantidade,preco));              // cria e adiciona
            this.fat.put(filial,list);
        }
    }

    public float totalFaturadoProd(){
        float total=0.0f;
        for(List<SimpleEntry<Integer, Float>> par : this.fat.values() ){
            total+= par.stream().mapToDouble(e->e.getKey()*e.getValue()).sum();
        }
        return (float)total;
    }

    public int totalVendasProd(){
        int total=0;
        for(List<SimpleEntry<Integer, Float>> par : this.fat.values() )
            total += par.size();

        return total;
    }




}









