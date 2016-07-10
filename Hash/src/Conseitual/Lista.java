/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Conseitual;

/**
 *
 * @author paulovictor
 */
public class Lista {
    private Elemento primeiro;
    private Elemento ultimo;
    public int nElementos;
    
    public void adicionaInicio(String n, int tele, String end) {
        Elemento novo = new Elemento();
        novo.setNumero(tele);
        novo.setNome(n);
        novo.setEndereco(end);
        this.primeiro = novo;
        this.ultimo = novo;
        this.nElementos++;
    }
    
    public void adiciona(String n, int tele, String end) {
        if (this.nElementos == 0) {
            this.adicionaInicio(n, tele, end);
        } else {
            Elemento novo = new Elemento();
            novo.setNumero(tele);
            novo.setNome(n);
            novo.setEndereco(end);
            this.ultimo.setProximo(novo);
            novo.setAnterior(this.ultimo);
            this.ultimo = novo;
            this.nElementos++;
        }
    }
    
    public void imprime(int n) {
        Elemento atual = this.primeiro;
        int i;
        System.out.print(n+") ");
        for (i = 1; i <= nElementos; i++) {
            System.out.print("["+atual.getNome()+", "+atual.getNumero()+", "+atual.getEndereco()+"] ");
            atual = atual.getProximo();
        }
         System.out.println();
    }
        
    public String busca(String nome) {
        Elemento atual = this.primeiro;
        while (atual != null) {
            if (atual.getNome().equals(nome) == true ) {
                return ("Nome: "+atual.getNome()+", Telefone: "+atual.getNumero()+", Endereco: "+atual.getEndereco());
            }
            atual = atual.getProximo();
        }
        return ("Pessoa nao encontrada");
    }
    
    public int igual(String nome) {
        Elemento atual = this.primeiro;
        int cont = 0;
        while (atual != null) {
            if (atual.getNome().equals(nome) == true ) {
                cont++;
            }
            atual = atual.getProximo();
        }
        return cont;
    }
}
