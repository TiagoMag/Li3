import Views.Menu;

public class GereVendasView {

        private Menu menuPrincipal;
        private Menu menuQueriesEstatisticas;
        private Menu menuQueriesInterativas;
        private Menu menuReadFiles;
        private Menu atual;

        /**
         * Construtor vazio da View.
         */
        public GereVendasView(){
            String[] principal = {
                    "Ler ficheiros;",
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

            String[] readFiles = {
                    "Ler ficheiros default(configs)"
            };

            this.menuPrincipal = new Menu(principal);
            this.menuQueriesEstatisticas = new Menu(queriesestatisticas);
            this.menuQueriesInterativas = new Menu(queriesinterativas);
            this.menuReadFiles = new Menu(readFiles);

        }

        /**
         * Executa menu principal.
         */
        public void run(){
            this.atual = this.menuPrincipal;
            this.atual.showMenu();
        }
        /**
         * Executa menu queries estatísticas.
         */
        public void showQueriesEstatisticas() {
            this.atual = this.menuQueriesEstatisticas;
        }

        public void showMenuFiles() {
            this.atual = this.menuReadFiles;
            this.atual.showMenu();
        }

        /**
         * Executa menu de queries interativas.
         */
        public void showQueriesInterativas(){
            this.atual = this.menuQueriesInterativas;
        }


    }
