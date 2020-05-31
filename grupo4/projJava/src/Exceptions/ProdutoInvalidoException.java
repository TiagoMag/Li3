package Exceptions;

public class ProdutoInvalidoException  extends Exception{

    public ProdutoInvalidoException (){
        super();
    }

    public ProdutoInvalidoException (String message){
        super(message);
    }

}

