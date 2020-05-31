import Common.Constantes;
import Common.Crono;
import Common.Input;
import Models.Catalogos.Cliente;
import Models.Catalogos.ICliente;
import Models.Catalogos.IProduto;
import Models.Catalogos.Produto;
import Models.Vendas.IVenda;
import Models.Venda;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Collectors;

public class Testes {

    public static void main (String [] args){
       System.out.println("Começar testes(S/N)");
       String op= Input.lerString();
       if(op.equals("S")) runtestes();
       else System.exit(0);
    }

    private static void runtestes(){

        Collection<IProduto> prods = lerCatlogoProdTreeSet("ficheiros/Produtos.txt");
        Collection<ICliente> clis = lerCatlogoCliTreeSet("ficheiros/Clientes.txt");

        System.out.println("\nClientes e Produtos em TreeSet:\n");
        System.out.println("\nSem parsing e com parsing com validacao e sem validacao :\n");
        System.out.println("\n                                                  BufferReader           Files");
        //----------------------------------------------------------------------------------------------------------------
        Crono.start();
        leituraBufferSemParsing("ficheiros/Vendas_1M.txt");
        System.out.print("\n[Vendas_1M.txt|Sem parsing]:                        "+Crono.stop()+" s");
        Crono.start();
        Crono.start();
        leituraFilesSemParsing("ficheiros/Vendas_1M.txt");
        System.out.print("          "+ Crono.stop() + " s");
        leituraBufferComParsing("ficheiros/Vendas_1M.txt");
        System.out.print("\n[Vendas_1M.txt|Parsing sem validacao]:              "+ Crono.stop()+" s");
        Crono.start();
        leituraFilesComParsing("ficheiros/Vendas_1M.txt");
        System.out.print("          "+ Crono.stop() + " s");
        Crono.start();
        leituraBufferComParsingValidacao("ficheiros/Vendas_1M.txt",prods,clis);
        System.out.print("\n[Vendas_1M.txt|Parsing e validacao]:               "+ Crono.stop()+" s");
        Crono.start();
        leituraFilesComParsingValidacao("ficheiros/Vendas_1M.txt",prods,clis);
        System.out.print("          "+ Crono.stop() + " s\n");

        //-----------------------------------------3Milhoes-----------------------------
        Crono.start();
        leituraBufferSemParsing("ficheiros/Vendas_3M.txt");
        System.out.print("\n[Vendas_3M.txt|Sem parsing]:                        "+Crono.stop()+" s");
        Crono.start();
        Crono.start();
        leituraFilesSemParsing("ficheiros/Vendas_3M.txt");
        System.out.print("          "+ Crono.stop() + " s");
        leituraBufferComParsing("ficheiros/Vendas_3M.txt");
        System.out.print("\n[Vendas_3M.txt|Parsing sem validacao]:              "+ Crono.stop()+" s");
        Crono.start();
        leituraFilesComParsing("ficheiros/Vendas_3M.txt");
        System.out.print("          "+ Crono.stop() + " s");
        Crono.start();
        leituraBufferComParsingValidacao("ficheiros/Vendas_3M.txt",prods,clis);
        System.out.print("\n[Vendas_3M.txt|Parsing e validacao]:               "+ Crono.stop()+" s");
        Crono.start();
        leituraFilesComParsingValidacao("ficheiros/Vendas_3M.txt",prods,clis);
        System.out.print("          "+ Crono.stop() + " s\n");

        //-----------------------------------------5Milhoes-----------------------------
        Crono.start();
        leituraBufferSemParsing("ficheiros/Vendas_5M.txt");
        System.out.print("\n[Vendas_5M.txt|Sem parsing]:                        "+Crono.stop()+" s");
        Crono.start();
        Crono.start();
        leituraFilesSemParsing("ficheiros/Vendas_5M.txt");
        System.out.print("          "+ Crono.stop() + " s");
        leituraBufferComParsing("ficheiros/Vendas_5M.txt");
        System.out.print("\n[Vendas_5M.txt|Parsing sem validacao]:              "+ Crono.stop()+" s");
        Crono.start();
        leituraFilesComParsing("ficheiros/Vendas_5M.txt");
        System.out.print("          "+ Crono.stop() + " s");
        Crono.start();
        leituraBufferComParsingValidacao("ficheiros/Vendas_5M.txt",prods,clis);
        System.out.print("\n[Vendas_5M.txt|Parsing e validacao]:               "+ Crono.stop()+" s");
        Crono.start();
        leituraFilesComParsingValidacao("ficheiros/Vendas_5M.txt",prods,clis);
        System.out.print("          "+ Crono.stop() + " s\n");

    }

    private static Set<IProduto> lerCatlogoProdTreeSet(String fichtxt){
        Set<IProduto> linhas =new TreeSet<>();
        BufferedReader inFile = null;
        String linha=null;
        try{
            inFile = new BufferedReader (new FileReader (fichtxt));
            while ((linha=inFile.readLine())!=null) linhas.add(new Produto(linha));
        }
        catch(IOException e) {System.out.println(e);}
        return linhas;
    }
    private static Set<ICliente> lerCatlogoCliTreeSet(String fichtxt){
        Set<ICliente> linhas =new TreeSet<>();
        BufferedReader inFile = null;
        String linha=null;
        try{
            inFile = new BufferedReader (new FileReader (fichtxt));
            while ((linha=inFile.readLine())!=null) linhas.add(new Cliente(linha));
        }
        catch(IOException e) {System.out.println(e);}
        return linhas;
    }

    private static List<String> leituraBufferSemParsing (String fichtxt){
        List<String> linhas =new ArrayList<> ();
        BufferedReader inFile = null;
        String linha=null;
        try{
            inFile = new BufferedReader (new FileReader (fichtxt));
            while ((linha=inFile.readLine())!=null) linhas.add(linha);
        }
        catch(IOException exc) {System.out.println(exc);}
        return linhas;
    }

    private static List<IVenda> leituraBufferComParsing(String fichtxt){
        List<IVenda> linhas =new ArrayList<> ();
        BufferedReader inFile = null;
        String linha=null;
        try{
            inFile = new BufferedReader (new FileReader (fichtxt));
            while ((linha=inFile.readLine())!=null) linhas.add(linhaToVendaSemValidacao(linha));
        }
        catch(IOException exc) {System.out.println(exc);}
        return linhas;
    }
    private static List<IVenda> leituraBufferComParsingValidacao (String fichtxt, Collection <IProduto> prods, Collection <ICliente> cli){
        List<IVenda> linhas =new ArrayList<> ();
        BufferedReader inFile = null;
        String linha=null;
        try{
            inFile = new BufferedReader (new FileReader (fichtxt));
            while ((linha=inFile.readLine())!=null) linhas.add(linhaToVenda(linha,prods,cli));
        }
        catch(IOException exc) {System.out.println(exc);}
        return linhas;
    }

    private static List<String> leituraFilesSemParsing(String fichtxt){
        List<String> linhas = new ArrayList<>();
        try{
            linhas = Files.readAllLines(Paths.get(fichtxt));
        } catch (IOException exc) {System.out.println(exc);}
        return linhas;
    }

    private static List<IVenda> leituraFilesComParsing(String fichtxt){
        List<String> linhas = new ArrayList<>();
        try{
            linhas = Files.readAllLines(Paths.get(fichtxt));
        } catch (IOException exc) {System.out.println(exc);}
        return linhas.stream().map(s-> linhaToVendaSemValidacao(s)).collect(Collectors.toList());
    }

    private static List<IVenda> leituraFilesComParsingValidacao(String fichtxt,Collection <IProduto> prods, Collection <ICliente> cli) {
        List<String> linhas = new ArrayList<>();
        try {
            linhas = Files.readAllLines(Paths.get(fichtxt));
        } catch (IOException exc) {
            System.out.println(exc);
        }
        return linhas.stream().map(s -> linhaToVenda(s, prods, cli)).collect(Collectors.toList());
    }

    private static IVenda linhaToVendaSemValidacao (String linha){
            String codProd, codCli;
            char tipoCompra;
            int mes = 0; int filial=0; int quant=0; float preco=0;
            String [] campos = linha.split(" ");
            codProd = campos [0];
            codCli = campos [4];
            tipoCompra = campos[3].charAt(0);
            try{
                preco = Float.parseFloat(campos[1]);
                quant = Integer.parseInt(campos[2]);
                mes = Integer.parseInt(campos[5]);
                filial = Integer.parseInt(campos[6]);
            }
            catch(NumberFormatException e) {return null;}

            Venda v = new Venda(new Produto(codProd),new Cliente(codCli),preco, quant,tipoCompra,mes,filial);

            return v;
        }

    private static IVenda linhaToVenda (String linha, Collection<IProduto> catprods, Collection <ICliente> catcli){
            String codProd, codCli;
            char tipoCompra;
            int mes = 0; int filial=0; int quant=0; float preco=0;
            String [] campos = linha.split(" ");
            codProd = campos [0];
            codCli = campos [4];
            tipoCompra = campos[3].charAt(0);
            try{
                preco = Float.parseFloat(campos[1]);
                quant = Integer.parseInt(campos[2]);
                mes = Integer.parseInt(campos[5]);
                filial = Integer.parseInt(campos[6]);
            }
            catch(NumberFormatException e) {return null;}

            Venda v = new Venda(new Produto(codProd),new Cliente(codCli),preco, quant,tipoCompra,mes,filial);

            if(validaVenda(v,catprods,catcli)) { return v; }
            else return null;
        }

    private static boolean validaVenda(IVenda v,Collection<IProduto> catprods, Collection <ICliente> catcli){

        if (!catprods.contains(v.getProduto())) return false;
        if (!catcli.contains(v.getCliente())) return false;
        if (!v.getProduto().validaProd()) return false;
        if (!v.getCliente().validaCliente()) return false;
        if (!((v.getPreco())>=0.0 && (v.getPreco())<=999.99))return false;
        if (!((v.getQuantidade())>=1 && (v.getQuantidade())<=200)) return false;
        if (!((v.getTipoCompra()=='N') ||(v.getTipoCompra()=='P'))) return false;
        if (!((v.getMes())>=1 && (v.getMes())<= Constantes.MESES)) return false;
        if (!((v.getFilial())>=1 && (v.getFilial())<=Constantes.FILIAIS)) return false;

        return true;
    }
}


