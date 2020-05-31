package Models.Filial;

import Models.Catalogos.IProduto;
import Models.Catalogos.Produto;

import java.io.Serializable;


/**
 * Classe que representa a venda de um produto numa Filial
 *
 *
 * @author Grupo4
 * @version 2020
 */

public class InfoFilial implements Serializable {

    /* Varáveis de instância */
    private IProduto produto;
    private float preco;
    private int quant;
    private char tipoCompra;
    private int mes;

    /**
    * Construtor vazio da classe
    */
    public InfoFilial(){
        this.produto = new Produto();
        this.preco=0.0f;
        this.quant=0;
        this.tipoCompra='N';
        this.mes=0;
    }

    /**
     * Construtor parametrizado da classe
     */
    public InfoFilial(IProduto p,float preco,int quant,char tipoCompra,int mes){
        this.produto=p.clone();
        this.preco=preco;
        this.quant=quant;
        this.tipoCompra=tipoCompra;
        this.mes=mes;
    }

    /**
     * Construtor por cópia da classe
     */
    public InfoFilial(InfoFilial i){
        this.produto=i.getProduto();
        this.preco=i.getPreco();
        this.quant=i.getQuant();
        this.tipoCompra=i.getTipoCompra();
        this.mes=i.getMes();
    }

    /**
     * Metodo que compara o mes fornecido
     * @param mes
     * @return
     */
    public int correspondeMes(int mes){
        if(this.mes == mes) return 1;
        return 0;
    }

    /**
     * Getters
     */
    public IProduto getProduto() {
        return produto.clone();
    }

    public float getPreco() {
        return preco;
    }

    public int getQuant() {
        return quant;
    }

    public char getTipoCompra() {
        return tipoCompra;
    }

    public int getMes() {
        return mes;
    }

    /**
     * Setters
     */
    public void setProduto(IProduto produto) {
        this.produto = produto;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    public void setQuant(int quant) {
        this.quant = quant;
    }

    public void setTipoCompra(char tipoCompra) {
        this.tipoCompra = tipoCompra;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    /**
     * Clone
     */
    public InfoFilial clone(){
        return new InfoFilial (this);
    }
}