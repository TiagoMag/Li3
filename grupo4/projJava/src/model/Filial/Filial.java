package model.Filial;

import model.Catalogos.Cliente;
import model.Venda;

import java.util.*;
import java.util.stream.Collectors;

public class Filial {

    /* Variáveis de instância */
    private Map<Cliente, List<InfoFilial>> filial; // Map de clientes com uma lista das compras do cliente

    /**
     * Construtor vazio da classe
     */
    public Filial(){
        this.filial=new HashMap<>();
    }

    /**
     * Construtor por cópia da classe
     */
    public Filial(Filial f){
        this.filial=f.getFilial();
    }

    /**
     * Construtor parametrizado da classe
     */
    public Filial(Map<Cliente, List<InfoFilial>> f){
        this.setFilial(f);
    }

    /**
     * Getters
     */
    public Map<Cliente, List<InfoFilial>>  getFilial(){
        return this.filial.entrySet().stream().collect(Collectors.toMap(c -> c.getKey().clone() , l -> l.getValue().stream().map(InfoFilial::clone).collect(Collectors.toList())));
    }

    /**
     * Setters
     */
    public void setFilial(Map<Cliente, List<InfoFilial>> f){
        this.filial = f.entrySet().stream().collect(Collectors.toMap(c -> c.getKey().clone() , l -> l.getValue().stream().map(InfoFilial::clone).collect(Collectors.toList())));
    }

    /**
     * Clone
     * */
    public Filial clone (){
        return new Filial (this);
    }

    /**
     * Adiciona uma compra a um cliente
     */
    public void insereVenda(Venda v){
        InfoFilial i = new InfoFilial(v.getProduto(),v.getPreco(),v.getQuantidade(),v.getTipoCompra(),v.getMes()); // compra do cliente a adicionar
        if(this.filial.containsKey(v.getCliente())){  // se exister só tem de adicionar à lista
            this.filial.get(v.getCliente()).add(i);
        }
        else {  // se cliente ainda não tiver registado na filial
            List<InfoFilial> list = new ArrayList<>();
            list.add(i);
            this.filial.put(v.getCliente(),list);
        }
    }

}
