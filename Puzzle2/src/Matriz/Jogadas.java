/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Matriz;

import java.util.ArrayList;

/**
 *
 * @author paulovictor
 */
public class Jogadas {
    private Matriz atual = new Matriz();
    private ArrayList<Matriz> movimentos = new ArrayList<Matriz>();

    /**
     * @return the atual
     */
    public Matriz getAtual() {
        return atual;
    }

    /**
     * @param atual the atual to set
     */
    public void setAtual(Matriz atual) {
        this.atual = atual;
    }

    /**
     * @return the movimentos
     */
    public ArrayList<Matriz> getMovimentos() {
        return movimentos;
    }

    /**
     * @param movimentos the movimentos to set
     */
    public void setMovimentos(ArrayList<Matriz> movimentos) {
        this.movimentos = movimentos;
    }
}
