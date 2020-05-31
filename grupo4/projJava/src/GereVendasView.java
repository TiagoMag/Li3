import Common.Constantes;
import Models.Catalogos.IProduto;
import Models.Queries.*;
import Views.Menu;
import Views.Navegador;


import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Classe GereVendasView
 *
 * @author Grupo 4
 * @version 2020
 */

public class GereVendasView implements IGereVendasView, Serializable {

    private Menu menuPrincipal;
    private Menu menuQueriesEstatisticas;
    private Menu menuQueriesInterativas;
    private Menu menuReadFiles;
    private Menu atual;
    private Menu menuDadosGeraisEstruturas;

    /**
     * Construtor vazio da View.
     */
    public GereVendasView(){
        String[] principal = {
                "Ler ficheiros;",
                "Guardar Estado",
                "Carregar Estado",
                "Consultas estatísticas;",
                "Consultas interativas.",
        };
        String[] queriesinterativas = {
                "Lista ordenada alfabeticamente com os códigos dos produtos nunca comprados e o seu respetivo total.",
                "Número total - global e por filial - de vendas e clientes que realizaram compras num determinado mês.",
                "Número de compras feitas, número de produtos comprados e total gasto por um determinado cliente, por mês.",
                "Número de vezes que um determinado produto foi comprado, quanta faturação foi por ele gerada e por quantos distintos clientes foi comprado.",
                "Lista discriminada de códigos de produtos mais comprados por ordem decrescente de quantidade, por cliente.",
                "Top personalizado de quantidade de produtos mais vendidos em todo ano",
                "Os três maiores compradores de cada filial",
                "Top personalizado de clientes que compraram uma maior variedade de produtos",
                "Top personalizado de clientes que mais compraram um determinado produto",
                "Faturação total de cada produto, mês a mês, filial a filial."
        };
        String[] queriesestatisticas = {
                "Dados gerais do ficheiro de vendas;",
                "Dados gerais das estruturas."
        };
        String[] dadosgeraisestruturas = {
                "Totais compras por mês;",
                        "Total faturado por mês e filial",
                "Numero de distintos clientes que compraram em cada mês e filial"
        };



        String[] readFiles = {
                "Ler ficheiros default(configs)",
                "Inserir os caminhos"
        };

        this.menuPrincipal = new Menu(principal);
        this.menuQueriesEstatisticas = new Menu(queriesestatisticas);
        this.menuQueriesInterativas = new Menu(queriesinterativas);
        this.menuReadFiles = new Menu(readFiles);
        this.menuDadosGeraisEstruturas = new Menu(dadosgeraisestruturas);

    }

    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLACK = "\u001B[30m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_WHITE = "\u001B[37m";

    /**
     * Executa menu principal.
     */
    public void run(){
        this.clearScreen();
         this.menuPrincipal.showMenu("Menu Principal");
    }
    /**
     * Executa menu queries estatísticas.
     */
    public void showQueriesEstatisticas() {
        this.clearScreen();
         this.menuQueriesEstatisticas.showMenu("Queries Estatisticas");
    }

    public void showMenuFiles() {
        this.clearScreen();
        this.menuReadFiles.showMenu("Leitura de Ficheiros de Carregamento");
    }

    public void showQueriesInterativas(){
        this.clearScreen();
        this.menuQueriesInterativas.showMenu("Queries Interativas");
    }

     public void showDadosGerais() {
        this.clearScreen();
        this.menuDadosGeraisEstruturas.showMenu("Dados Gerais Estruturas");
    }

    /**
     * Executa menu de queries interativas.
     */

    public void printError(String s) {
    System.out.println(s);
}

    public void clickEnter(){
        System.out.println("\nClique ENTER para prosseguir.");
        try{
            System.in.read();
        }catch(Exception e){e.printStackTrace();}
    }

    public  void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public void printTime(double time){
        System.out.println("\nTempo da querie: " + time + " s");
    }

    //-------------------------------------- Print Pedidos de input  ----------------------------------------

    public void insiraMes(){ System.out.println("Insira mês (1-12) | 0->Sair:"); }

    public void insereCliente(){ System.out.println("Insira código de um cliente"); }

    public void insereProduto(){ System.out.println("Insira código de um produto"); }

    public void insertPath(String s){
    System.out.println("Insira o caminho do ficheiro: "+s);
}

    public void insereLimite(){
        System.out.println("Insira o limite:");
    }

    //-------------------------------------- Print Queries ----------------------------------------
    public void printQuerie11 (List<String> l,double time){
        this.clearScreen();
        System.out.println(ANSI_BLUE +"\nNome do Ficheiro: " +ANSI_WHITE+ l.get(0));
        System.out.println(ANSI_BLUE +"Registos de venda erradas: "+ANSI_WHITE+l.get(1));
        System.out.println(ANSI_BLUE +"\nNumero total de produtos: "+ANSI_WHITE+l.get(2));
        System.out.println(ANSI_BLUE +"Produtos diferentes comprados: "+ANSI_WHITE+l.get(3));
        System.out.println(ANSI_BLUE +"Produtos nao comprados: "+ANSI_WHITE+l.get(4));
        System.out.println(ANSI_BLUE +"\nNumero total de clientes: "+ANSI_WHITE+l.get(5));
        System.out.println(ANSI_BLUE +"Clientes diferentes que realizaram compras: "+ANSI_WHITE+l.get(6));
        System.out.println(ANSI_BLUE +"Clientes que nao compraram: "+ANSI_WHITE+l.get(7));
        System.out.println(ANSI_BLUE +"\nCompras com valor 0 € : "+ANSI_WHITE+l.get(8));
        System.out.println(ANSI_BLUE +"Total faturado: "+ANSI_WHITE+l.get(9) + " €");
        this.printTime(time);
        this.clickEnter();

        clearScreen();
    }

    public void printQuerie121 (List <Integer> l,double time){
       this.clearScreen();
        System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            for(int j = 0; j < Constantes.MESES; j++){
                System.out.println("Mês:"+(j+1)+"\t"+l.get(j));
            }
        System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
        this.printTime(time);
        this.clickEnter();
    }

       public void printQuerie122 (List<Float> lst,double time){
              this.clearScreen();
               System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
               int h=0;
               for(int i=0;i<Constantes.FILIAIS;i++) {
                       System.out.println("Filial:"+(i+1));
                       for (int j = 0; j < Constantes.MESES; j++) {
                               System.out.printf("Mês:%d %08f \n",(j+1) ,lst.get(h++));
                            }
                        System.out.println();
                    }
                System.out.println("Total faturado:"+lst.get(h));
                System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                this.printTime(time);
                this.clickEnter();
            }

            public void printQuerie123 (List<Integer> l,double time){
               this.clearScreen();
               System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
               for(int i=0;i<Constantes.FILIAIS;i++) {
                      System.out.println("Filial:"+(i+1));
                       for (int j = 0; j < Constantes.MESES; j++) {
                              System.out.printf("Mês:%d %d",(j + 1) ,l.get(j));
                          }
                        System.out.println();
                   }
                System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                this.printTime(time);
                this.clickEnter();

                   }

    public void printQuery1(Set<IProduto> lst, double time){
        if(lst.size()==0) {
            System.out.println("Não há nenhum produto.");
            return;
        }
        List<String> lista = lst.stream().map(IProduto::getCodigo).collect(Collectors.toList());
        System.out.println("tam listta"+lista.size());
        Navegador nav = new Navegador(lista,Constantes.LINHAS,Constantes.COLUNAS);
        nav.run();
        this.printTime(time);
        this.clickEnter();
    }

    public void printQuerie2(ParQuery2[] lista, double time){
        this.clearScreen();
        int i=0;
        for (i=0;i<lista.length-1;i++){
            System.out.println("\nFilial " + (i+1) + ":");
            System.out.println("Numero total de vendas: " + lista[i].getNrVendas());
            System.out.println("Numero total de clientes: " + lista[i].getNrClientes());
        }
        System.out.println("\nGlobal:");
        System.out.println("Numero total de vendas: " + lista[i].getNrVendas());
        System.out.println("Numero total de clientes: " + lista[i].getNrClientes());
        this.printTime(time);
        clickEnter();
    }

    public void printQuerie3(TrioQuery3 triplo, double time){
        this.clearScreen();
        System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
        for(int j = 0; j < Constantes.MESES; j++){
            System.out.printf("Mês:%d ",(j+1));
            System.out.printf("Nmr compras total:%d ",triplo.getNrVendasPorMes().get(j));
            System.out.printf("Produtos distintos comprados:%d ",triplo.getNrProdutos().get(j));
            System.out.printf("Total gasto:%f \n",triplo.getTotalFaturado().get(j));
        }
        System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
        this.printTime(time);
        this.clickEnter();
    }

    public void printQuerie4(TrioQuery4[] trios, double time){
        this.clearScreen();
        System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
        for(int i = 0; i < trios.length; i++){
            System.out.printf("Mês:%d ",(i+1));
            System.out.printf("Nmr de vezes que foi camprado:%d ",trios[i].getNum_compras());
            System.out.printf("Nmr de clientes que compraram o produto :%d ",trios[i].getNum_clientes());
            System.out.printf("Total gasto:%f \n",trios[i].getTotal_faturado());
        }
        System.out.println("══════════════════════════════════════════════════════════════════════════════════════════════════\n");
        this.printTime(time);
        this.clickEnter();
    }

    public void printQuery5(Set<ParQuery5> set, double time) {
        if(set.size()==0) {
            System.out.println("Não há nenhum elemento.");
            return;
        }
        List<String> lista = new ArrayList<>();
        for(ParQuery5 par : set){
            lista.add(par.getProduto().getCodigo() + ": " + par.getQuantidade() + "\t");
        }
        Navegador nav = new Navegador(lista,10,10);
        nav.run();
        this.printTime(time);
        this.clickEnter();
    }

    public void printQuery6(Set<TrioQuery6> trios,double time){
        if(trios.size()==0) {
            System.out.println("Não há nenhum elemento.");
            return;
        }
        List<String> lista = new ArrayList<>();
        int i=0;
        for(TrioQuery6 trio : trios){
            System.out.println((i+1)+": "+trio.getProduto().getCodigo() + ": " + trio.getCompras() + ": "+trio.getNmr_clientes() + "\t");
            i++;
        }

        this.printTime(time);
        this.clickEnter();

    }



    public void printQuery7(List<Set<ParQuery7>> duo,double time) {
        if (duo.size() == 0) {
            System.out.println("Não há nenhum elemento.");
            return;
        }

        int i = 0;
        int y = 0;

        for (Set<ParQuery7> duos : duo) {
            System.out.println("Filial " + (y + 1));
            for (ParQuery7 p : duos) {
                System.out.println((i + 1) + ": " + p.getCliente().getCodigo() + ": " + p.getGasto() + "\t");
                i++;
            }
            i = 0;
            y++;
        }

        this.printTime(time);
        this.clickEnter();

    }

    public void printQuery8 (List<ParQuery8> pares,double time){
        if(pares.size()==0) {
            System.out.println("Não há nenhum elemento.");
            return;
        }
        List<String> lista = new ArrayList<>();
        int i=0;
        for(ParQuery8 par : pares){
            lista.add((i+1)+": "+"Cliente:"+ par.getCliente().getCodigo() +" Produtos: "+ par.getQuant());
            i++;
        }

        Navegador nav = new Navegador(lista,1,10);
        nav.run();

        this.printTime(time);
        this.clickEnter();

    }


    public void printQuery9 (List<ParQuerie9> pares,double time){
        if(pares.size()==0) {
            System.out.println("Não há nenhum elemento.");
            return;
        }
        List<String> lista = new ArrayList<>();
        int i=0;
        for(ParQuerie9 par : pares){
            lista.add((i+1)+": "+"Cliente:"+ par.getCliente().getCodigo() +" Total Faturado: "+ par.getFaturado()+" Compras totais: "+par.getTotal());
            i++;
        }

        Navegador nav = new Navegador(lista,1,10);
        nav.run();
        this.printTime(time);
        this.clickEnter();

    }

    public void printQuery10(List<ParQuery10> pares,double time){
        if(pares.size()==0) {
            System.out.println("Não há nenhum elemento.");
            return;
        }
        List<String> lista = new ArrayList<>();
        for(ParQuery10 par : pares){
            lista.add(par.toString());
        }
        Navegador nav = new Navegador(lista,5,1);
        nav.run();
        this.printTime(time);
        this.clickEnter();


    }

}
