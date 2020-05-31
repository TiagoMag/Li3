package Models.Queries;

import java.io.Serializable;

/**
 * Classe InfoVendasFile
 * Representa informações àcerca do ficheiro de vendas
 *
 * @author Grupo4
 * @version 2020
 */

public class InfoVendasFile implements Serializable {

    int num_compras_preco_0;
    String file_name;
    int linhas_erradas;

    public InfoVendasFile(){
        this.num_compras_preco_0 = 0;
        this.file_name = "";
        this.linhas_erradas=0;
    }

    public InfoVendasFile(InfoVendasFile ivf){
        this.num_compras_preco_0 = ivf.getNum_compras_preco_0();
        this.file_name = ivf.getFile_name();
        this.linhas_erradas= ivf.getLinhas_erradas();
    }


    public InfoVendasFile(int num_compras_preco_0, String file_name, int linhas_erradas) {
        this.num_compras_preco_0 = num_compras_preco_0;
        this.file_name = file_name;
        this.linhas_erradas = linhas_erradas;
    }

    public void setNum_compras_preco_0(int num_compras_preco_0) {
        this.num_compras_preco_0 = num_compras_preco_0;
    }

    public int getNum_compras_preco_0() {
        return num_compras_preco_0;
    }

    public String getFile_name() {
        return file_name;
    }

    public void setFile_name(String file_name) {
        this.file_name = file_name;
    }

    public void setLinhas_erradas(int linhas_erradas) {
        this.linhas_erradas = linhas_erradas;
    }

    public int getLinhas_erradas() {
        return linhas_erradas;
    }

    public InfoVendasFile clone(){
        return new InfoVendasFile (this);
    }
}
