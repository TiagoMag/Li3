package Models.Filial;

import Models.Catalogos.Cliente;
import Models.Catalogos.ICliente;
import Models.Catalogos.IProduto;
import Models.Queries.TrioQuery6;
import Models.Venda;

import javax.sound.sampled.Line;
import java.io.Serializable;
import java.util.*;
import java.util.stream.Collector;
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
        InfoFilial i = new InfoFilial(v.getProduto(),v.getPreco(),v.getQuantidade(),v.getTipoCompra(),v.getMes()-1); // compra do cliente a adicionar
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

    public List<ICliente> filialbuyersMes(int mes){
        List<ICliente> c = new ArrayList<>();
        for(Map.Entry<ICliente, List<InfoFilial>> f : filial.entrySet()){
            if(f.getValue().stream().anyMatch(e -> e.getMes() == mes)) c.add(f.getKey().clone());
        }
        return  c;
        }

    public boolean fezMCompraEmMes (int mes){
        if( (int)this.filial.values().stream().map(l -> l.stream().filter(e-> e.getMes() == mes)).count() > 0) return true;
        else return false;
    }

    public int distintosPMes(int mes){
        return (int) this.filial.values().stream().filter(e->fezMCompraEmMes(mes)).count();
    }


    public int nrComprasClientePMes(ICliente c,int mes){
        return (int) this.filial.get(c).stream().filter(e->e.getMes()==mes).count();
    }


    public List<IProduto> getProdutosClientePMes(ICliente c,int mes){
        List<IProduto> prods=new ArrayList<>();
        if(this.filial.containsKey(c)){
            return this.filial.get(c).stream().filter(e->e.getMes()==mes).map(InfoFilial::getProduto).map(IProduto::clone).collect(Collectors.toList());
        }else return prods;
    }

    public float getFaturadoClienteMes(ICliente c,int mes){
        return (float) this.filial.get(c).stream().filter(e->e.getMes()==mes).mapToDouble(x->x.getQuant()*x.getPreco()).sum();
    }

    public int numVendas(int mes) {
       int nvendas = 0;
       for (List<InfoFilial> info : this.filial.values()) {
            nvendas += info.stream().filter((e -> e.getMes() == mes)).count();
        }
      return nvendas;
    }

    public List<ICliente> buyersProduct (IProduto p,int mes){
        List<ICliente> c = new ArrayList<>();
        for(Map.Entry<ICliente, List<InfoFilial>> f : filial.entrySet()){
            if(f.getValue().stream().anyMatch(e -> e.getMes()==mes && e.getProduto().equals(p))) c.add(f.getKey().clone());
        }
        return  c;
    }

    public List<InfoFilial> comprasCliente(ICliente c){
        return this.filial.get(c).stream().map(InfoFilial::clone).collect(Collectors.toList());


    }

    public List<InfoFilial> allSells(){
        return this.filial.values().stream().flatMap(List::stream).collect(Collectors.toList());
    }

    public Map<IProduto,Integer> produtosQuantidadeFilial(){

    List<InfoFilial> vendas=this.allSells();
    return vendas.stream().collect(Collectors.groupingBy(x->x.getProduto().clone())).
            entrySet().stream().
            collect(Collectors.toMap(Map.Entry::getKey, e->e.getValue().stream().mapToInt(InfoFilial::getQuant).sum()));
    }

    public List <ICliente> buyersProduct(IProduto p){
        List<ICliente> c = new ArrayList<>();
        for(Map.Entry<ICliente, List<InfoFilial>> f : filial.entrySet()){
            if(f.getValue().stream().anyMatch(e->e.getProduto().equals(p))) c.add(f.getKey().clone());
        }
        return  c;
    }
}