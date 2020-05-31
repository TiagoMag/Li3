package Models.Queries;

import Models.Catalogos.ICliente;

import java.io.Serializable;

/**
 * Classe auxiliar usada para resolver a Query 8
 *
 * @author Grupo4
 * @version 2020
 */


public class ParQuery8 implements Serializable {
    private ICliente cliente;
    private int quantidade;


    public ParQuery8(ICliente cl, int quantidade) {
        this.cliente = cl.clone();
        this.quantidade = quantidade;
    }


    public int getQuant(){
        return this.quantidade;
    }


    public ICliente getCliente(){
        return this.cliente.clone();
    }
}