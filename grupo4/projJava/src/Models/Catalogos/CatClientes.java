package Models.Catalogos;

import java.io.Serializable;
import java.util.Objects;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class CatClientes implements Serializable {


        private Set<Cliente> clientes;

        public CatClientes(){
            this.clientes = new TreeSet<Cliente>();
        }

        public CatClientes(Set<Cliente> clientes){
            setClientes(clientes);
        }

        public CatClientes(CatClientes cc){
            setClientes(cc.getClientes());
        }

        public Set <Cliente> getClientes(){
            return this.clientes.stream().map(Cliente::clone).collect(Collectors.toSet());
        }

        public void setClientes (Set <Cliente> catp){
            this.clientes=catp.stream().map(Cliente::clone).collect(Collectors.toSet());
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            CatClientes catCli = (CatClientes) o;
            return Objects.equals(clientes, catCli.clientes);
        }

        @Override
        public int hashCode() {
            return Objects.hash(clientes);
        }

        @Override
        public String toString() {
            return "model.Catalogos.CatClientes{" +
                    "clientes=" + clientes +
                    '}';
        }

    public CatClientes clone(){
        return new CatClientes(this);
    }


    /*metodos*/

        public boolean existeCliente (Cliente p){
            return this.clientes.contains(p);
        }

        public void insereCliente (Cliente p){
            this.clientes.add(p.clone());
        }

        public int numeroProdutos (){
            return this.clientes.size();
        }
    }




