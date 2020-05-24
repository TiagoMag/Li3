package Models;

import Models.Catalogos.Produto;
import Common.Constantes;
import Models.Catalogos.CatClientes;
import Models.Catalogos.CatProds;
import Models.Catalogos.Cliente;

import java.util.Objects;

public class Venda {
    private Produto produto;
    private Cliente cliente;
    private float preco;
    private int quantidade;
    private char tipoCompra;
    private int mes;
    private int filial;


    public Venda() {
        this.produto = new Produto();
        this.cliente = new Cliente();
        this.preco = 0.0f;
        this.quantidade = 0;
        this.tipoCompra = 'N';
        this.mes = 0;
        this.filial = 0;
    }

    public Venda(Produto produto, Cliente cliente, float preco, int quantidade, char tipoCompra, int mes, int filial) {
        this.produto = new Produto(produto);
        this.cliente = new Cliente(cliente);
        this.preco = preco;
        this.quantidade = quantidade;
        this.tipoCompra = tipoCompra;
        this.mes = mes;
        this.filial = filial;
    }

    public Venda(Venda v){
        this.produto = v.getProduto();
        this.cliente = v.getCliente();
        this.preco = v.getPreco();
        this.quantidade = v.getQuantidade();
        this.tipoCompra = v.getTipoCompra();
        this.mes = v.getMes();
        this.filial = v.getFilial();
    }

    public Produto getProduto() {
        return produto.clone();
    }

    public void setProduto(Produto produto) {
        this.produto = new Produto(produto);
    }

    public Cliente getCliente() {
        return cliente.clone();
    }

    public void setCliente(Cliente cliente) {
        this.cliente = new Cliente(cliente);
    }

    public float getPreco() {
        return preco;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public char getTipoCompra() {
        return tipoCompra;
    }

    public void setTipoCompra(char tipoCompra) {
        this.tipoCompra = tipoCompra;
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getFilial() {
        return filial;
    }

    public void setFilial(int filial) {
        this.filial = filial;
    }

    public boolean equals(Object o){
        if (o == this) return true;
        if (o == null || o.getClass() != this.getClass()) return false;
        Venda a = (Venda) o;
        return this.produto.equals(a.getProduto())
                && this.cliente.equals(a.getCliente())
                && this.preco == (a.getPreco())
                && this.quantidade == (a.getQuantidade())
                && this.tipoCompra == (a.getTipoCompra())
                && this.mes == (a.getMes())
                && this.filial == (a.getFilial());
    }

    public String toString (){
        StringBuilder sb = new StringBuilder();
        sb.append("Código de model.Catalogos.Produto ").append(this.produto)
        .append("\nCódigo de model.Catalogos.Cliente:").append(this.cliente)
        .append("\nPreco:").append(this.preco)
        .append("\nQuantidade:").append(this.quantidade)
        .append("\nTipo de Compra:").append(this.tipoCompra)
        .append("\nMes:").append(this.mes)
        .append("\nFilial:").append(this.filial).append("\n");
        return sb.toString();
    }

    public Venda clone(){
        return new Venda(this);
    }

    public int hashCode() {
        return Objects.hash(produto);
    }

    /* Valida uma venda */
    public boolean validaV(CatProds cp, CatClientes cc){
       if (!((this.preco)>=0.0 && (this.preco)<=999.99))return false;
       if (!((this.quantidade)>=1 && (this.quantidade)<=200)) return false;
       if (!((this.tipoCompra=='N') ||(this.tipoCompra=='P'))) return false;
       if (!((this.mes)>=1 && (this.mes)<= Constantes.MESES)) return false;
       if (!((this.filial)>=1 && (this.filial)<=Constantes.FILIAIS)) return false;
       if (!this.produto.validaProd()) return false;
       if (!this.cliente.validaCliente()) return false;
       if (!cp.existeProduto(this.produto)) return false;
       if (!cc.existeCliente(this.cliente)) return false;

        return true;
    }


}
