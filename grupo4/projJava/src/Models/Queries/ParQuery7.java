package Models.Queries;

import Models.Catalogos.Cliente;
import Models.Catalogos.ICliente;

import java.io.Serializable;

    public class ParQuery7 implements Comparable <ParQuery7>, Serializable
    {
        private ICliente cliente;
        private float gasto;

        public ParQuery7()
        {
            this.cliente= new Cliente() ;

            this.gasto=0;
        }

        public ParQuery7(ICliente cli, float g)
        {
            this.cliente=cli.clone();
            this.gasto=g;
        }

        public ParQuery7(ParQuery7 p)
        {
            this.cliente=p.getCliente();
            this.gasto=p.getGasto();
        }

        public ICliente getCliente (){
            return this.cliente.clone();
        }

        public void setCliente (ICliente c){
            this.cliente=c;
        }

        public float getGasto (){
            return this.gasto;
        }

        public void setGasto (float gasto){
            this.gasto=gasto;
        }

        public ParQuery7 clone (){
            return new ParQuery7 (this);
        }

        public int compareTo (ParQuery7 p){
            return Float.compare(p.getGasto(),this.gasto);
        }

        @Override
        public String toString() {
            return "ParQuery7{" +
                    "cliente=" + cliente +
                    ", gasto=" + gasto +
                    '}';
        }
    }

