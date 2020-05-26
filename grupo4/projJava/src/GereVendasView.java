import Common.Constantes;
import Views.Menu;

import java.io.Serializable;
import java.util.List;

public class GereVendasView implements Serializable {

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
    public void showDadosGerais() {
        this.clearScreen();
        this.menuDadosGeraisEstruturas.showMenu("Dados Gerais Estruturas");

    }

        /**
         * Executa menu de queries interativas.
         */
        public void showQueriesInterativas(){
            this.atual = this.menuQueriesInterativas;
        }

        public void printError(String s) {
        System.out.println(s);
    }

        public void insertPath(String s){
        System.out.println("Insira o caminho do ficheiro: "+s);
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


}
