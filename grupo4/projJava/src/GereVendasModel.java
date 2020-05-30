import Models.Catalogos.*;
import Common.Constantes;
import Models.Faturacao.Faturacao;
import Models.Faturacao.IFaturacao;
import Models.Filial.Filial;
import Models.Filial.IFilial;
import Models.Filial.InfoFilial;
import Models.Queries.*;
import Models.Venda;


import java.io.*;
import java.util.*;

import java.util.stream.Collectors;


public class GereVendasModel implements Serializable {
    private ICatProdutos catprodutos;
    private ICatClientes catclientes;
    private IFaturacao faturacao;
    private List<IFilial> filiais;
    private InfoVendasFile iv;

    public GereVendasModel() {
        this.faturacao = new Faturacao();
        this.catprodutos = new CatProds();
        this.catclientes = new CatClientes();
        List<IFilial> fl = new ArrayList <> ();
        for (int i=0; i< Constantes.FILIAIS; i++){
            fl.add(new Filial ());
        }
        this.filiais=fl;
        this.iv=new InfoVendasFile();
    }

    public GereVendasModel(IFaturacao faturacao, ICatProdutos catprodutos, ICatClientes catclientes,List<Filial>filiais,InfoVendasFile iv) {
        this.catprodutos = catprodutos.clone();
        this.catclientes = catclientes.clone();
        this.faturacao = faturacao.clone();
        this.filiais = filiais.stream().map(Filial::clone).collect(Collectors.toList());
        this.iv=iv.clone();
    }

    public GereVendasModel(GereVendasModel model){
        this.catclientes=model.getCatClientes();
        this.catprodutos=model.getCatProdutos();
        this.faturacao=model.getFaturacao();
        this.filiais=model.getFiliais();
        this.iv=model.getIv();
    }

    /**
     * Getters
     */
    public ICatProdutos getCatProdutos() {
        return catprodutos.clone();
    }

    public ICatClientes getCatClientes() {
        return catclientes.clone();
    }

    public IFaturacao getFaturacao() {
        return faturacao.clone();
    }

    public List<IFilial> getFiliais() {
        return filiais.stream().map(IFilial::clone).collect(Collectors.toList());
    }

    public InfoVendasFile getIv() { return iv.clone(); }


    /**
     * Setters
     */
    public void setCatprodutos(CatProds catprodutos) {
        this.catprodutos = catprodutos.clone();
    }

    public void setCatclientes(CatClientes catclientes) {
        this.catclientes = catclientes.clone();
    }

    public void setFaturacao(Faturacao faturacao) {
        this.faturacao = faturacao.clone();
    }

    public void setFiliais(List<Filial> filiais) {
        this.filiais = filiais.stream().map(Filial::clone).collect(Collectors.toList());
    }




    /**
     * Clone
     */
    public GereVendasModel clone(){
        return new GereVendasModel(this);
    }

    public void lerFilesProdutos (String filename){
        BufferedReader inFile = null;
        String line=null;
        try{
            this.catprodutos= new CatProds();
            Crono.start();
            inFile = new BufferedReader(new FileReader(filename));
            while ((line=inFile.readLine())!=null){
                this.catprodutos.insereProduto(new Produto(line));
            }
            System.out.println("\n[Leitura do ficheiro de produtos]: " + Crono.stop() + " s");
        }
        catch(IOException e) {System.out.println(e);}
    }

    public void lerFilesClientes (String nomeFich){
        BufferedReader inFile = null; String linha=null;
        try{
            this.catclientes = new CatClientes ();
            Crono.start();
            inFile = new BufferedReader (new FileReader (nomeFich));
            while ((linha=inFile.readLine())!=null){
                this.catclientes.insereCliente(new Cliente(linha));
            }
            System.out.println("\n[Leitura do ficheiro de clientes]: " + Crono.stop() + " s");
        }
        catch(IOException e) {System.out.println(e);}
    }

    public Venda linhaToVenda (String linha){
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

        if(v.validaV(this.catprodutos,this.catclientes)) { return v; }
        else return null;
    }

    public void lerVendas(String filename){
        BufferedReader inFile = null;
        String linha = null;

        int erradas,num_compras_preco_0 ;
        erradas = num_compras_preco_0 = 0;

        try{
            Crono.start();
            inFile= new BufferedReader(new FileReader(filename));
            int x=0;
            while((linha = inFile.readLine()) != null){
              Venda v = linhaToVenda(linha);
                if(v!=null){
                    x++;
                    this.faturacao.insereVenda(v);
                    this.filiais.get(v.getFilial()-1).insereVenda(v);
                    if(v.getPreco() == 0) num_compras_preco_0++;
                }else{erradas++;}
            }
            this.iv.setNum_compras_preco_0(num_compras_preco_0);
            this.iv.setFile_name(filename);
            this.iv.setLinhas_erradas(erradas);
            System.out.println("\n[Leitura do ficheiro de vendas]: " + Crono.stop() + " s");
            System.out.println("\n[Linhas lidas]: " + x);
            System.out.println("\n[Linhas  erradas: " + erradas);
        }
        catch(IOException e){System.out.println(e);};
    }

    public String [] lerConfigs(){
        BufferedReader inFile=null;
        String linha=null;
        String [] configs = new String [4];
        int i=0;
        try{
            inFile = new BufferedReader (new FileReader (Constantes.CONFIGS_FILE_NAME));
            while((linha=inFile.readLine())!=null && i<4){
                configs[i++]=linha;
            }
        }
        catch(IOException e) {System.out.println(e);}

        return configs;
    }

    public void guardaEstado(String fileName) throws FileNotFoundException,IOException{
        FileOutputStream fos = new FileOutputStream(fileName);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(this); // guarda o objeto de uma só vez
        oos.flush();
        oos.close();
    }

    public static GereVendasModel carregaEstado(String fileName) throws FileNotFoundException,IOException,ClassNotFoundException{
        FileInputStream fis = new FileInputStream(fileName);
        ObjectInputStream ois = new ObjectInputStream(fis);
        GereVendasModel model = (GereVendasModel)ois.readObject();
        ois.close();
        return model;
    }

    /**
     * Queries Estatistica 1.1
     */
    public int totalBuyers(){
        List<ICliente> lst= new ArrayList<>();
       // this.filiais.stream().map(IFilial:filialBuyers).collect(Collectors.toList());

        for( IFilial f : this.filiais){

            lst.addAll(f.filialBuyers());
        }

        return (int) lst.stream().distinct().count();
    }
    public List<String> Querie11(){

        List<String> l = new ArrayList <>();
        l.add(this.iv.getFile_name());
        l.add(Integer.valueOf(this.iv.getLinhas_erradas()).toString());
        l.add(Integer.valueOf(this.catprodutos.numeroProdutos()).toString());
        l.add(Integer.valueOf(this.faturacao.numeroProdsComprados()).toString());
        int produtosNaoComprados = Integer.parseInt(l.get(2))-Integer.parseInt(l.get(3));
        l.add(Integer.valueOf(produtosNaoComprados).toString());
        l.add(Integer.valueOf(this.catclientes.numeroClientes()).toString());
        l.add(Integer.valueOf(this.totalBuyers()).toString());
        int clientesNComprados = Integer.parseInt(l.get(5))-Integer.parseInt(l.get(6));
        l.add(Integer.valueOf(clientesNComprados).toString());
        l.add(Float.valueOf(this.faturacao.faturacaoTotal()).toString());
        l.add(Integer.valueOf(this.iv.getNum_compras_preco_0()).toString());

        return l;

    }

    public List<Integer> Querie121(){
       List<Integer> lst=new ArrayList<>();
       for(int i=0;i < Constantes.MESES;i++)
        lst.add(this.faturacao.numComprasMes(i));

        return lst;
    }




    //Consultas estatisticas
    /**
     * 1.1
     */



    /**
     * 1.2
     */




    //Consultas interativas

    //1)
    public Set<IProduto> produtosNaoComprados(){
        return this.catprodutos.getProdutos().stream().filter(e-> !this.faturacao.existeProduto(e)).collect(Collectors.toCollection(TreeSet::new));
    }

    //2)
    public ParQuery2[] numeroTotalVendasEClientesMes(int mes){
        List<ICliente> lstTotal= new ArrayList<>();
        ParQuery2[] lista = new ParQuery2[Constantes.FILIAIS+1];
        int vendastotal=0;
        int i=0;
        for( IFilial f : this.filiais){
            List<ICliente> clientesFilial = f.filialbuyersMes(mes);
            int vendas=f.numVendas(mes);
            lista[i++]=new ParQuery2(vendas,clientesFilial.size());
            lstTotal.addAll(clientesFilial);
            vendastotal+=vendas;
        }
        ParQuery2 p = new ParQuery2();
        p.setNrVendas(vendastotal);
        p.setNrClientes((int) lstTotal.stream().distinct().count());
        lista[i]= p ;
        return lista;
    }

    //3)
    public TrioQuery3 quantasComprasFezPMes(ICliente c){
        float faturado = 0.0f;
        int vendas,i;
        i=vendas=0;

        TrioQuery3 p = new TrioQuery3();

        for (i=0;i<Constantes.MESES;i++){
            List<IProduto> l = new ArrayList<>();
            for( IFilial f : this.filiais){
                l.addAll(f.getProdutosClientePMes(c,i));
                vendas += f.nrComprasClientePMes(c,i);
                faturado += f.getFaturadoClienteMes(c,i);
            }
            p.setVenda(i,vendas);
            p.setProdutos(i,(int)l.stream().distinct().count());
            p.setFaturado(i,faturado);
            vendas =0;
            faturado=0.0f;
        }
        return p;
    }


    //4)
    public TrioQuery4[] querie4 (IProduto p){
        TrioQuery4[] trios = new TrioQuery4[Constantes.MESES];
        float total_faturado=0.0f;
        int num_compras=0;

        for(int i=0;i<Constantes.MESES;i++){
            List <ICliente> list = new ArrayList<>();
            total_faturado=this.faturacao.totalFaturadoProd(p,i); // calcula total faturado pelo produto na faturacao
            num_compras=this.faturacao.totalVendasProd(p,i); // calcula quantas vezes foi comprado
            for(IFilial f : this.filiais)           // percorre filiais
                list.addAll(f.buyersProduct(p,i));  // junta clientes que compraram o produto
            trios[i]= new TrioQuery4(total_faturado,num_compras,(int)list.stream().distinct().count()); //adiciona trio correpondente ao mes i
        }

       return trios;
    }


    //5)
    public Set<ParQuery5> query5(ICliente c){
        List<InfoFilial> compras= new ArrayList<>();

        for(IFilial f: this.filiais)
            compras.addAll(f.comprasCliente(c)); // compras totais do cliente

        // Organiza compras por produto
        Map<IProduto,List<InfoFilial>> map = compras.stream().collect(Collectors.groupingBy(InfoFilial::getProduto,
                                                                                 Collectors.mapping(InfoFilial::clone,Collectors.toList())));

        // Calcula a quantidade de cada produto e insere ordenadmente no set

        return map.entrySet().stream().map(x-> new ParQuery5(x.getKey().clone(),x.getValue().stream()
                                .mapToInt(InfoFilial::getQuant).sum())).
                                 collect(Collectors.toCollection(TreeSet::new));
    }

    public int buyersProduct(IProduto p){
        List <ICliente> list = new ArrayList<>();
        for(IFilial f : this.filiais)           // percorre filiais
            list.addAll(f.buyersProduct(p));

        return (int)list.stream().distinct().count();
    }

    public Set<TrioQuery6> query6 (int limit){
        Set<TrioQuery6> trios = new TreeSet<>();

        Set<ParQuery5> mostSelledProds=this.faturacao.mostSelledProds(limit);

        for( ParQuery5 par : mostSelledProds)
             trios.add(new TrioQuery6(par.getProduto(),par.getQuantidade(),buyersProduct(par.getProduto())));

        return trios;
    }


    public List<Set<ParQuery7>> query7 () {
        List<Set<ParQuery7>> l = new ArrayList<>();

        for (IFilial f : this.filiais) {
            l.add(f.top3Compradores());

        }
        return l;
    }




    public List<ParQuery8> query8(int limit){
        List<ParQuery8> pares = new ArrayList<>();

        for(IFilial f : this.filiais){
            pares.addAll(f.allClientsProducts());
        }

       return pares.stream().collect(Collectors.groupingBy(ParQuery8::getCliente)).entrySet().stream().
        map(x -> new ParQuery8 (x.getKey().clone(), x.getValue().stream().mapToInt(ParQuery8::getQuant).sum()))
       .sorted(new ComparatorQuery8()).limit(limit).collect(Collectors.toList());

    }




    //9)
    public List<ParQuerie9> query9(IProduto p,int limit){
        List<ParQuerie9> pares = new ArrayList<>();

        for(IFilial f : this.filiais){
            pares.addAll( f.nrComprasClienteProduto(p));
        }
        return  pares.stream().collect(Collectors.groupingBy(ParQuerie9::getCliente)).entrySet().stream().
                map(x-> new ParQuerie9 (x.getKey().clone(),(float)x.getValue().stream().mapToDouble(ParQuerie9::getFaturado).sum(),x.getValue().stream().mapToInt(ParQuerie9::getTotal).sum())).
                sorted(new ComparatorQuery9()).limit(limit).collect((Collectors.toList()));

    }



}

