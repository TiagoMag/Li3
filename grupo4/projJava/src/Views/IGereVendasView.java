package Views;

import Models.Catalogos.IProduto;
import Models.Queries.*;



import java.util.List;
import java.util.Set;

/**
 * Interface correspondente á classe Views.GereVendasView
 *
 *
 * @author Grupo4
 * @version 2020
 */


 public interface IGereVendasView {

     void run();

     /**
      * Executa Menu Queries Estatisticas
      */
     void showQueriesEstatisticas();

     /**
      * Executa Menu de escolha de ficheiros para carregamento
      */
     void showMenuFiles();

     /**
      * Executa Menu Queries interativas
      */
     void showQueriesInterativas();

     /**
      * Executa Menu de exposicão de dados gerais
      */
     void showDadosGerais();

     /**
      * Metodo para mostrar erro
      * @param s
      */
     void printError(String s);

     /**
      * Metodo para interação utilizador
      */
     void clickEnter();

     /**
      * Metodo para interação utilizador
      */
      void clearScreen();

     /**
      * Imprime no ecrã o tempo de execução da Querie
      * @param time
      */
     void printTime(double time);

     /**
      * Metodo para interação utilizador
      */
     void insiraMes();

     /**
      * Metodo para interação utilizador
      */
     void insereCliente();

     /**
      * Metodo para interação utilizador
      */
     void insereProduto();

     /**
      * Metodo para interação utilizador
      * @param s
      */
     void insertPath(String s);

     /**
      * Metodo para interação utilizador
      */
     void insereLimite();

     /**
      * Apresenta ao utilizador os dados referentes ao ultimo ficheiro de dados lido
      * @param l
      * @param time
      */
     void printQuerie11 (List<String> l, double time);


     /**
      * Apresenta o numero total de compras por mês
      * @param l
      * @param time
      */
     void printQuerie121 (List <Integer> l,double time);

     /**
      *  Apresenta a Query 1
      * @param lst
      * @param time
      */

     void printQuerie122 (List<Float> lst,double time);

    void printQuerie123 (List<Integer> l,double time);

     void printQuery1(Set<IProduto> lst, double time);


     /**
      * Apresenta a Query 2
      * @param lista
      * @param time
      */
     void printQuerie2(ParQuery2[] lista, double time);

     /**
      * Apresenta a Query 3
      * @param triplo
      * @param time
      */
     void printQuerie3(TrioQuery3 triplo, double time);

     /**
      * Apresenta a Query 4
      * @param trios
      * @param time
      */
     void printQuerie4(TrioQuery4[] trios, double time);

     /**
      * Apresenta a Query 5
      * @param set
      * @param time
      */
     void printQuery5(Set<ParQuery5> set, double time);

     /**
      * Apresenta a Query 6
      * @param trios
      * @param time
      */
     void printQuery6(Set<TrioQuery6> trios, double time);

     /**
      * Apresenta a Query 7
      * @param duo
      * @param time
      */
     void printQuery7(List<Set<ParQuery7>> duo,double time);

     /**
      * Apresenta a Query 8
      * @param pares
      * @param time
      */
     void printQuery8 (List<ParQuery8> pares,double time);


     /**
      * Apresenta a Query 9
      * @param pares
      * @param time
      */
     void printQuery9 (List<ParQuerie9> pares,double time);

     /**
      * Apresenta a Query 10
      * @param pares
      * @param time
      */
     void printQuery10(List<ParQuery10> pares,double time);
}
