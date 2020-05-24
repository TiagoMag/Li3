package Models.Catalogos;

import java.io.Serializable;
import java.util.Objects;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class CatProds implements Serializable {
    private Set<Produto> produtos;

    public CatProds(){
        this.produtos = new TreeSet<Produto>();
    }

    public CatProds(Set<Produto> s){
        setProdutos(s);
    }

    public CatProds(CatProds cp){
        setProdutos(cp.getProdutos());
    }


    public Set <Produto> getProdutos (){
        return this.produtos.stream().map(Produto::clone).collect(Collectors.toSet());
    }


    public void setProdutos (Set <Produto> catp){
        this.produtos=catp.stream().map(Produto::clone).collect(Collectors.toSet());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        CatProds catProds = (CatProds) o;
        return Objects.equals(produtos, catProds.produtos);
    }


    @Override
    public String toString() {
        return "model.Catalogos.CatProds{" +
                "produtos=" + produtos +
                '}';
    }

    public CatProds clone(){
        return new CatProds(this);
    }


    /*metodos*/

    public boolean existeProduto (Produto p){
        return this.produtos.contains(p);
    }

    public void insereProduto (Produto p){
        this.produtos.add(p.clone());
    }

    public int numeroProdutos (){
        return this.produtos.size();
    }

}