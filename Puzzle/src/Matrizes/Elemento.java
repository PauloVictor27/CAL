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
public class Elemento {
    private int tabela[][] = new int[3][3];
    private Elemento proximo;
    private Elemento anterior;

    /**
     * @return the tabela
     */
    public int[][] getTabela() {
        return tabela;
    }
    
    public int getElementoTabela(int i, int j) {
        return tabela[i][j];
    }

    /**
     * @param tabela the tabela to set
     */
    public void setTabela(int[][] tabela) {
        this.tabela = tabela;
    }

    /**
     * @return the proximo
     */
    public Elemento getProximo() {
        return proximo;
    }

    /**
     * @param proximo the proximo to set
     */
    public void setProximo(Elemento proximo) {
        this.proximo = proximo;
    }

    /**
     * @return the anterior
     */
    public Elemento getAnterior() {
        return anterior;
    }

    /**
     * @param anterior the anterior to set
     */
    public void setAnterior(Elemento anterior) {
        this.anterior = anterior;
    }
    
}
