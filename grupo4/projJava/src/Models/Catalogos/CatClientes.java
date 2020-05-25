package Models.Catalogos;

import java.io.Serializable;
import java.util.Objects;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

/**
 * Classe representativa do cátalogo de clientes
 *
 * @author Grupo4
 * @version 2020
 */


public class CatClientes implements Serializable, ICatClientes {


        private Set<ICliente> clientes;

        /**
        * Construtor vazio da classe CatClientes
        * @return novo objeto com todas as variaveis vazias
        */

        public CatClientes(){
            this.clientes = new TreeSet<ICliente>();
        }

        /**
        * Construtor parâmeterizado da classe CatClientes
        * @param clientes
        * @return objeto definido com os parametros
        */

        public CatClientes(Set<ICliente> clientes){
            setClientes(clientes);
        }

        /**
        * Construtor parâmeterizado da classe produto
        * @param cc Catalogo de Clientes
        * @return novo objeto produto definido com os parametros
        */
        public CatClientes(CatClientes cc){
            setClientes(cc.getClientes());
        }


        public Set <ICliente> getClientes(){
            return this.clientes.stream().map(ICliente::clone).collect(Collectors.toSet());
        }

        public void setClientes (Set <ICliente> catp){
            this.clientes=catp.stream().map(ICliente::clone).collect(Collectors.toSet());
        }


        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            CatClientes catCli = (CatClientes) o;
            return Objects.equals(clientes, catCli.clientes);
        }


        public int hashCode() {
            return Objects.hash(clientes);
        }


        public String toString() {
            return "model.Catalogos.CatClientes{" +
                    "clientes=" + clientes +
                    '}';
        }

        public CatClientes clone(){
        return new CatClientes(this);
        }

        public boolean existeCliente (ICliente p){
            return this.clientes.contains(p);
        }

        public void insereCliente (ICliente p){
            this.clientes.add(p.clone());
        }

        public int numeroClientes(){
            return this.clientes.size();
        }
    }




