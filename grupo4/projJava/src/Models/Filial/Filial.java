package Models.Filial;

import Models.Catalogos.Cliente;
import Models.Catalogos.ICliente;
import Models.Venda;

import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

public class Filial implements IFilial, Serializable {

    /* Variáveis de instância */
    private Map<ICliente, List<InfoFilial>> filial; // Map de clientes com uma lista das compras do cliente

    /**
     * Construtor vazio da classe
     */
    public Filial(){
        this.filial=new HashMap<>();
    }

    /**
     * Construtor por cópia da classe
     */
    public Filial(IFilial f){
        this.filial=f.getFilial();
    }

    /**
     * Construtor parametrizado da classe
     */
    public Filial(Map<ICliente, List<InfoFilial>> f){
        this.setFilial(f);
    }

    /**
     * Getters
     */
    public Map<ICliente, List<InfoFilial>>  getFilial(){
        return this.filial.entrySet().stream().collect(Collectors.toMap(c -> c.getKey().clone() , l -> l.getValue().stream().map(InfoFilial::clone).collect(Collectors.toList())));
    }

    /**
     * Setters
     */
    public void setFilial(Map<ICliente, List<InfoFilial>> f){
        this.filial = f.entrySet().stream().collect(Collectors.toMap(c -> c.getKey().clone() , l -> l.getValue().stream().map(InfoFilial::clone).collect(Collectors.toList())));
    }

    /**
     * Clone
     * */
    public IFilial clone (){
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

    /**
     * get
     *
     */
    public List<ICliente> filialBuyers(){ return this.filial.keySet().stream().map(ICliente::clone).collect(Collectors.toList());}

}
