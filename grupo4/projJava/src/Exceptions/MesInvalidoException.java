package Exceptions;

public class MesInvalidoException extends Exception {

    public MesInvalidoException (){
        super();
    }

    public MesInvalidoException (String message){
        super(message);
    }
}
