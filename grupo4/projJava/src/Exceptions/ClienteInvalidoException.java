package Exceptions;

public class ClienteInvalidoException  extends Exception{

    public ClienteInvalidoException (){
        super();
    }

    public ClienteInvalidoException (String message){
        super(message);
    }

}
