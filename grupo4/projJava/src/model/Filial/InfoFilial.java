package model.Filial;

import model.Catalogos.Produto;

public class InfoFilial {

    /* Varáveis de instância */
    private Produto produto;
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
    public InfoFilial(Produto p,float preco,int quant,char tipoCompra,int mes){
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
     * Getters
     */
    public Produto getProduto() {
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
    public void setProduto(Produto produto) {
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