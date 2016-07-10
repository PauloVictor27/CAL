/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Matriz;

/**
 *
 * @author paulovictor
 */
public class Matriz {
    private int matriz[][] = new int[3][3];

    /**
     * @return the matriz
     */
    public int[][] getMatriz() {
        return matriz;
    }
    
    public int getElementoMatriz(int i, int j) {
        return matriz[i][j];
    }

    /**
     * @param matriz the matriz to set
     */
    public void setMatriz(int[][] matriz) {
        this.matriz = matriz;
    }
    
    public void rebeceMatriz(int[][] matriz) {
        int i, j;
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                this.matriz[i][j] = matriz[i][j];
            }
        }
    }
}
