/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Jogadas;

import Matrizes.Lista;


/**
 *
 * @author pv
 */
public class Jogada {
    private int atual[][] = new int[3][3];
    private Jogada proximo;
    private Jogada anterior;
    private Lista movimentos = new Lista();

    /**
     * @return the atual
     */
    
    public int[][] getAtual() {
        return atual;
    }
    
    public int getElementoAtual(int i, int j) {
        return atual[i][j];
    }

    /**
     * @param atual the atual to set
     */
    public void setAtual(int[][] atual) {
        this.atual = atual;
    }

    /**
     * @return the proximo
     */
    public Jogada getProximo() {
        return proximo;
    }

    /**
     * @param proximo the proximo to set
     */
    public void setProximo(Jogada proximo) {
        this.proximo = proximo;
    }
    
    public Lista getMovimentos() {
        return movimentos;
    }

    /**
     * @param proximo the proximo to set
     */
    public void setMovimentos(Lista movimentos) {
        this.movimentos = movimentos;
    }

    /**
     * @return the anterior
     */
    public Jogada getAnterior() {
        return anterior;
    }

    /**
     * @param anterior the anterior to set
     */
    public void setAnterior(Jogada anterior) {
        this.anterior = anterior;
    }
    
}
