package Models.Faturacao;

import Common.Constantes;
import Models.Catalogos.IProduto;
import Models.Catalogos.Produto;
import Models.Queries.ParQuery10;
import Models.Queries.ParQuery5;
import Models.Queries.TrioQuery6;
import Models.Venda;
import java.util.AbstractMap.*;
import java.io.Serializable;
import java.util.*;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.stream.Collectors;

/**
 * Classe que representa a faturacao e as operaçoes que
 * se podem realizar sobre ela
 *
 * @author Grupo4
 * @version 2020
 */

public class Faturacao implements IFaturacao,Serializable {

    /* Variáveis de instância */
    private List<Map<IProduto, InfoFat>> faturacao;   /* Lista Meses -> Map( Key : Produto Value : InfoFat ) */

    /**
     * Construtor vazio da classe
     */
    public Faturacao() {
        this.faturacao = new ArrayList<>();
        for (int i = 0; i < Constantes.MESES; i++) {
            this.faturacao.add(new HashMap<>());
        }
    }

    /**
     * Construtor por cópia
     */
    public Faturacao(IFaturacao f) {
        this.faturacao = f.getFaturacao();
    }

    /**
     * Construtor parametrizado
     */
    public Faturacao(List<Map<IProduto, InfoFat>> f) {
        this.setFaturacao(f);
    }


    public List<Map<IProduto, InfoFat>> getFaturacao() {
        return this.faturacao.stream().map(p -> p.entrySet().stream().collect(Collectors.toMap(e -> e.getKey().clone(), e -> e.getValue().clone()))).collect(Collectors.toList());
    }


    public void setFaturacao(List<Map<IProduto, InfoFat>> f) {
        this.faturacao = f.stream().map(p -> p.entrySet().stream().collect(Collectors.toMap(e -> e.getKey().clone(), e -> e.getValue().clone()))).collect(Collectors.toList());
    }


    public IFaturacao clone() {
        return new Faturacao(this);
    }


    public void insereVenda(Venda v) {
        if (this.faturacao.get(v.getMes() - 1).containsKey(v.getProduto())) { // vê se produto já existe
        } else {  // se não existe cria
            this.faturacao.get(v.getMes() - 1).put(v.getProduto().clone(), new InfoFat());
        }
        this.faturacao.get(v.getMes() - 1).get(v.getProduto()).insereVenda((v.getFilial()-1), v.getPreco(), v.getQuantidade());
    }


    public int numeroProdsComprados() {

        List<IProduto> aux = new ArrayList<>();

        this.faturacao.forEach(a -> a.forEach((key, value) -> aux.add(key)));

        return (int) aux.stream().distinct().count();
    }

    public float faturacaoTotal() {

        double total = 0.0d;
        for (Map<IProduto, InfoFat> x : this.faturacao) {
            total += x.values().stream().mapToDouble(InfoFat::faturadoProdutosMes).sum();
        }
        return (float) total;
    }

    public float faturacaoMes(int mes, int filial) {

        double total = 0.0d;
        Map<IProduto, InfoFat> x = this.faturacao.get(mes); // obtem map do mês
        for (InfoFat f : x.values())
            total += f.faturadoProdutosMesFilial(filial);

        return (float) total;
    }

    public int numComprasMes(int mes) {
        Map<IProduto, InfoFat> res = this.faturacao.get(mes); // obtem map do mês
        return (int) res.values().stream().mapToInt(InfoFat::numCompras).sum();
    }

    public boolean existeProduto(IProduto p) {

        for (int i = 0; i < Constantes.MESES; i++) {
            if (this.faturacao.get(i).containsKey(p)) return true;
        }
        return false;
    }

    public float totalFaturadoProd(IProduto p, int mes) {
        Map<IProduto, InfoFat> info = this.faturacao.get(mes); // retira o mês
        if (info.containsKey(p)) {   // verifica se o produto foi comprado
            InfoFat fat = info.get(p); // retira InfoFat do produto
            return fat.totalFaturadoProd();
        }
        return 0.0f;
    }

    public int totalVendasProd(IProduto p, int mes) {
        Map<IProduto, InfoFat> info = this.faturacao.get(mes); // retira o mês
        if (info.containsKey(p)) {   // verifica se o produto foi comprado
            InfoFat fat = info.get(p); // retira InfoFat do produto
            return fat.totalVendasProd();
        }
        return 0;
    }

    public Set<ParQuery5> mostSelledProds(int limit){
         ConcurrentLinkedQueue<ParQuery5> l = new ConcurrentLinkedQueue<>();
            //Set<ParQuery5> l = new TreeSet<>();
              //       List<ParQuery5> l = Collections.synchronizedList(new ArrayList<>());
               Crono.start();

               this.faturacao.parallelStream().forEach(x-> x.entrySet().parallelStream()
                       .forEach(e -> l.add(new ParQuery5(e.getKey(),e.getValue()
                           .getFat().values().stream()
                       .flatMap(List::stream)
                               .mapToInt(SimpleEntry::getKey).sum())))); //.forEachOrdered(l::add));


               System.out.println("terminou: "+Crono.stop());
               Crono.start();
               Set<ParQuery5> s= l.stream().collect(Collectors.groupingBy(ParQuery5::getProduto)).entrySet().stream()
                             .map(p -> new ParQuery5 (p.getKey(),p.getValue().stream().mapToInt(ParQuery5::getQuantidade).sum()))
                               .collect(Collectors.toCollection(TreeSet::new)).stream().limit(limit).collect(Collectors.toSet());
               System.out.println("terminou: "+Crono.stop());
               return s;

    }


    public ParQuery10 totalFaturadoProduto(IProduto prod){
        double[][] tabela = new double[Constantes.MESES][Constantes.FILIAIS];
        for (int i = 0; i < Constantes.MESES; i++) {
              for (int j = 0; j < Constantes.FILIAIS; j++) {
                  if (!this.faturacao.get(i).containsKey(prod)) tabela[i][j] = 0.0;
                  else tabela[i][j] = this.faturacao.get(i).get(prod).faturadoProdutosMesFilial(j);
              }
          }
        return new ParQuery10(prod.clone(),tabela);
    }

        public List<Float> faturadoMesFililial(){
               float total=0.0f;
        List<Float> faturados = new ArrayList<>();
              for(int i=0;i<Constantes.FILIAIS;i++){
            int j=i;
                               for( Map<IProduto, InfoFat> f :this.faturacao){
                float fat=(float) f.values().stream().mapToDouble(e->e.faturadoProdutosMesFilial(j)).sum();
                faturados.add(fat);
                total+= fat;
            }
                  }
               faturados.add(total);
               return faturados;
    }


}
