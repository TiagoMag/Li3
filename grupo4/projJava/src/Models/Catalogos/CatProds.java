package Models.Catalogos;

import java.io.Serializable;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class CatProds implements ICatProdutos,Serializable {

    private Set<IProduto> produtos;

    /**
     * Construtor por omissão da classe CatProds
     *
     * @return um objeto produto vazio
     */
    public CatProds(){
        this.produtos = new TreeSet<IProduto>();
    }

    /**
     * Construtor parâmeterizado da classe CatProds
     * @param s Set de produtos
     * @return novo CatProds vazio
     */
    public CatProds(Set<IProduto> s){
        setProdutos(s);
    }
    /**
     * Construtor por objetos da classe Catprods
     * @param cp objeto a copiar
     * @return novo produto vazio
     */
    public CatProds(ICatProdutos cp){
        setProdutos(cp.getProdutos());
    }

    public Set <IProduto> getProdutos (){
        return this.produtos.stream().map(IProduto::clone).collect(Collectors.toSet());
    }

    public void setProdutos (Set <IProduto> catp){
        this.produtos=catp.stream().map(IProduto::clone).collect(Collectors.toSet());
    }

    public ICatProdutos clone(){
        return new CatProds(this);
    }

    public boolean existeProduto (IProduto p){
        return this.produtos.contains(p);
    }

    public void insereProduto (IProduto p){
        this.produtos.add(p.clone());
    }

    public int numeroProdutos (){
        return this.produtos.size();
    }

}