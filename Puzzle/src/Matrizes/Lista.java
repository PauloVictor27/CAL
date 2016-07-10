/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Matrizes;

/**
 *
 * @author paulovictor
 */
public class Lista {

    private Elemento primeiro;
    private Elemento ultimo;
    public int nElementos = 0;

    public void adicionaInicio(int[][] tabela) {
        Elemento novo = new Elemento();
        novo.setTabela(tabela);
        this.setPrimeiro(novo);
        this.setUltimo(novo);
        this.nElementos++;
    }

    public void adiciona(int[][] tabela) {
        if (this.nElementos == 0) {
            this.adicionaInicio(tabela);
        } else {
            Elemento novo = new Elemento();
            novo.setTabela(tabela);
            this.getUltimo().setProximo(novo);
            novo.setAnterior(this.getUltimo());
            this.setUltimo(novo);
            this.nElementos++;
        }
    }
    
    

    public void imprime() {
        Elemento atual = this.getPrimeiro();
        int i, j, k;
        for (k = 1; k <= nElementos; k++) {
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    System.out.print(atual.getElementoTabela(i, j) + " ");
                }
                System.out.println();
            }
            atual = atual.getProximo();
            System.out.println();
        }
        System.out.println();
    }

    public int compara(int[][] matriz1, int[][] matriz2) {
        int cont = 0;
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (matriz1[i][j] == matriz2[i][j]) {
                    cont++;
                }
            }
        }
        return cont;
    }

    public int igual(int[][] matriz) {
        Elemento atual = this.getPrimeiro();
        int cont = 0;
        while (atual != null) {
            if (compara(atual.getTabela(), matriz) == 9) {
                cont++;
            }
            atual = atual.getProximo();
        }
        return cont;
    }

    /**
     * @return the primeiro
     */
    public Elemento getPrimeiro() {
        return primeiro;
    }

    /**
     * @param primeiro the primeiro to set
     */
    public void setPrimeiro(Elemento primeiro) {
        this.primeiro = primeiro;
    }

    /**
     * @return the ultimo
     */
    public Elemento getUltimo() {
        return ultimo;
    }

    /**
     * @param ultimo the ultimo to set
     */
    public void setUltimo(Elemento ultimo) {
        this.ultimo = ultimo;
    }
}
