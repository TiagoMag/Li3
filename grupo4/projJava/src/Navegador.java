import Views.Pagina;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Navegador implements Serializable {

    int current_page;
    int linhas;
    int colunas;
    int total;
    int totalelems;
    private List<Pagina> paginas;


    public Navegador(List<String> lst,int col,int lin){
        this.current_page = 0;
        this.linhas=lin;
        this.colunas=col;
        this.totalelems=lst.size();
        int i= 0;
        List<Pagina> listP = new ArrayList<>();
        List<String> pageElems  = new ArrayList<>();
        Pagina p;
        while(i<paginasTotal(lst)) {
            for(int j = 0; j < lin; j++) {
                for(int h = 0; h < col; h++) {
                    if(i < lst.size()) {
                        pageElems.add(lst.get(i));
                    }
                    i++;
                }
            }
            p = new Pagina(lin,col,pageElems);
            pageElems = new ArrayList<>();
            listP.add(p);
        }

        this.paginas = listP;
        this.total= this.paginasTotal(lst);
    }

    int paginasTotal(List<String> lst){
        int totalPages=lst.size()/(this.linhas*this.colunas);
        if(totalPages*(this.linhas*this.colunas)< lst.size()) totalPages++;
        return totalPages;
    }
    public void run(){
        int i=0;

         while(i>=0 && i<this.total) {
             System.out.println("\nPagina: " + current_page + 1 + " de " + this.total + "\n");
             System.out.println("Elementos totais:"+this.totalelems);
             this.paginas.get(this.current_page).showPage(this.current_page);
             System.out.println("\n[P] Proxima Pagina");
             System.out.println("[A] Pagina Anterior");
             System.out.println("[S] Atras");
             String op = Input.lerString();

             switch (op) {
                 case "p":
                     if (this.current_page < paginas.size()) {current_page++;i=current_page;}
                     break;
                 case "a":
                     if (current_page > 1) {
                         current_page--;
                         i=current_page;
                     }
                     break;
                 case "s":
                     return;
                 default:
                     break;
             }
         }
    }
}

