package Models.Queries;

import Models.Catalogos.IProduto;

public class ParQuery10 {


        private IProduto produto;
        private double[][] tabela;

        public ParQuery10(IProduto p, double[][] tabela){
            this.produto = p;
            this.tabela = tabela;
        }
        public IProduto getProduto(){
            return this.produto;
        }
        public double[][] getTabela(){
            return this.tabela;
        }

        public void addTabela(int i,int j,double value){
            this.tabela[i][j]=value;
        }
        public String toString(){
            StringBuilder sb = new StringBuilder();
            sb.append("Produto: ").append(this.produto.toString()).append("\n");
            for (int i = 0; i < tabela.length; i++) {
                for (int j = 0; j < tabela[i].length; j++) {
                    sb.append(i+1).append(":").append(String.format("%08f", tabela[i][j])).append(" ");
                }
                sb.append("\n");
            }
            return sb.toString();
        }
    }
