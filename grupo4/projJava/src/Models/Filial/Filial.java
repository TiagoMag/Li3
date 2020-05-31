package Models.Filial;

import Common.Constantes;
import Models.Catalogos.Cliente;
import Models.Catalogos.ICliente;
import Models.Catalogos.IProduto;

import Models.Faturacao.InfoFat;
import Models.Queries.ParQuery7;

import Models.Queries.ComparatorQuery8;
import Models.Queries.ParQuerie9;
import Models.Queries.ParQuery8;

import Models.Queries.TrioQuery6;
import Models.Venda;




import java.io.Serializable;
import java.util.*;

import java.util.stream.Collectors;

/**
 * Classe Filial
 *
 * @author Grupo 4
 * @version 2020
 */


public class Filial implements IFilial, Serializable {


    private Map<ICliente, List<InfoFilial>> filial; // Map de clientes com uma lista das compras do cliente

    /**
     * Construtor vazio
     */
    public Filial(){
        this.filial=new HashMap<>();
    }

    /**
     * Construtor por cópia
     */
    public Filial(IFilial f){
        this.filial=f.getFilial();
    }

    /**
     * Construtor parametrizado
     */
    public Filial(Map<ICliente, List<InfoFilial>> f){
        this.setFilial(f);
    }


    public Map<ICliente, List<InfoFilial>>  getFilial(){
        return this.filial.entrySet().stream().collect(Collectors.toMap(c -> c.getKey().clone() , l -> l.getValue().stream().map(InfoFilial::clone).collect(Collectors.toList())));
    }


    public void setFilial(Map<ICliente, List<InfoFilial>> f){
        this.filial = f.entrySet().stream().collect(Collectors.toMap(c -> c.getKey().clone() , l -> l.getValue().stream().map(InfoFilial::clone).collect(Collectors.toList())));
    }


    public IFilial clone (){
        return new Filial (this);
    }


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
        if(!this.filial.containsKey(c)) return new ArrayList<>();
        else return this.filial.get(c).stream().map(InfoFilial::clone).collect(Collectors.toList());


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

    public Set<ParQuery7> top3Compradores(){
        return this.filial.entrySet().stream().map(x->new ParQuery7(x.getKey(),getFaturadoCliente(x.getValue()))).collect(Collectors.toCollection(TreeSet::new)).stream().limit(3). collect(Collectors.toCollection(TreeSet::new));

    }


    private float getFaturadoCliente(List<InfoFilial> f){
        return (float) f.stream().mapToDouble(x->x.getQuant()*x.getPreco()).sum();
    }



    public List <IProduto> clientProducts(List<InfoFilial> info){
        return info.stream().map(InfoFilial::getProduto).map(IProduto::clone).collect(Collectors.toList());
    }

    public List<ParQuery8> allClientsProducts() {
       return this.filial.entrySet().stream().map(x -> new ParQuery8(x.getKey(), (int) clientProducts(x.getValue()).stream().distinct().count())).collect(Collectors.toList());
    }


    private int nrTimesBought(ICliente c, IProduto p){

         return  (int) this.filial.get(c).stream().filter(e -> e.getProduto().equals(p)).mapToInt(e->e.getQuant()).sum();
    }

    private float totalFaturadoProdutoCliente(ICliente c, IProduto p){
        return (float) this.filial.get(c).stream().filter(e->e.getProduto().equals(p)).mapToDouble(x->x.getQuant()*x.getPreco()).sum();

    }

    public List<ParQuerie9> nrComprasClienteProduto(IProduto p){
        List<ParQuerie9> pares = new ArrayList<>();

        List<ICliente> lc = buyersProduct(p);

        for(ICliente l : lc){
            pares.add(new ParQuerie9(l, totalFaturadoProdutoCliente(l,p), nrTimesBought(l,p)));
        }

        return pares;
    }

    public List<Integer> clientesDistintosMes(){
               List<Integer> distMes = new ArrayList<>();  // lista com o valor por mes dos clientes distintos
               for(int i = 0; i< Constantes.MESES; i++) {
                        List<ICliente> clientes = new ArrayList<>();    // lista com todos clientes do mês
                      int j=i;
                   for(Map.Entry<ICliente, List<InfoFilial>> e : this.filial.entrySet()){
                                if(this.filial.get(e.getKey()).stream().anyMatch(x -> x.getMes() == j)) clientes.add(e.getKey());
                         }
                       distMes.add((int)clientes.stream().distinct().count());
        }
               return distMes;
    }

}

