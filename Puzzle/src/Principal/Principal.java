/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Principal;

import Jogadas.Jogada;
import Jogadas.MenorCaminho;
import Matrizes.Elemento;
import Matrizes.Lista;
import java.util.ArrayList;

/**
 *
 * @author paulovictor
 */
public class Principal {

    public static int ordenado[][] = {{1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}};

    /**
     * @param args the command line arguments
     */
    public static int comparaMatriz(int[][] matriz1, int[][] matriz2) {
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

    public static void espaco(int n) {
        int i;
        for (i = 0; i < n; i++) {
            System.out.print(" ");
        }
    }

    public static void imprimeMatriz(int[][] matriz, int n) {
        int i, j;
        for (i = 0; i < 3; i++) {
            espaco(n);
            for (j = 0; j < 3; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }

    //Encontra a linha do 0
    public static int encontraX(int matriz[][]) {
        int i, j;
        int ret = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (matriz[i][j] == 0) {
                    ret = i;
                }
            }
        }
        return ret;
    }

    //Encontra a coluna do 0
    public static int encontraY(int matriz[][]) {
        int i, j;
        int ret = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (matriz[i][j] == 0) {
                    ret = j;
                }
            }
        }
        return ret;
    }

    //Movimenta a matriz
    public static void movimento(int matriz[][], int movimentox1, int movimentoy1, int movimentox2, int movimentoy2) {
        int aux;

        aux = matriz[movimentox2][movimentoy2];
        matriz[movimentox2][movimentoy2] = matriz[movimentox1][movimentoy1];
        matriz[movimentox1][movimentoy1] = aux;

    }

    //Realiza os possiveis percursos
    public static void percurso(ArrayList<Jogada> caminhos, Jogada jogo, int x, int y, int tentativas, int n) {
        Jogada aux1 = new Jogada();
        Jogada aux2 = new Jogada();
        Jogada aux3 = new Jogada();
        Jogada aux4 = new Jogada();
        
        Lista l = jogo.getMovimentos();
        Elemento e = l.getPrimeiro();

        int matriz1[][] = new int[3][3];
        int matriz2[][] = new int[3][3];
        int matriz3[][] = new int[3][3];
        int matriz4[][] = new int[3][3];

        int i, j, k;

        aux1.setAtual(jogo.getAtual());
        aux2.setAtual(jogo.getAtual());
        aux3.setAtual(jogo.getAtual());
        aux4.setAtual(jogo.getAtual());

        for(k = 0; k < l.nElementos; k++){
            aux1.getMovimentos().adiciona(e.getTabela());
            aux2.getMovimentos().adiciona(e.getTabela());
            aux3.getMovimentos().adiciona(e.getTabela());
            aux4.getMovimentos().adiciona(e.getTabela());
            e = e.getProximo();
        }
                
        x = encontraX(jogo.getAtual());
        y = encontraY(jogo.getAtual());

        //Inicia as matrizes
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                matriz1[i][j] = aux1.getElementoAtual(i, j);
                matriz2[i][j] = aux2.getElementoAtual(i, j);
                matriz3[i][j] = aux3.getElementoAtual(i, j);
                matriz4[i][j] = aux4.getElementoAtual(i, j);
            }
        }

        //espaco(n);
        //System.out.println("Jogada "+tentativas+", Matriz atual:");
        //imprimeMatriz(jogo.getAtual(), n);
        //System.out.println();

        if (tentativas < 20) {
            if (comparaMatriz(jogo.getAtual(), ordenado) == 9) {
                //System.out.println("Caminho encontrado");
                //System.out.println("Movimentos: ");
                caminhos.add(jogo);
          
            } else {
                //Movimento a esquerda
                if (y > 0) {
                    movimento(matriz1, x, y, x, (y - 1));
                    //espaco(n);
                    //System.out.println("Movimento da Matriz:");
                    //imprimeMatriz(matriz1, n);
                    //System.out.println();
                    //espaco(n);
                    //System.out.println("Matrizes iguais: " + aux1.getMovimentos().igual(matriz1));
                    //System.out.println();
                    if (aux1.getMovimentos().igual(matriz1) == 0) {
                        aux1.getMovimentos().adiciona(matriz1);
                        aux1.setAtual(matriz1);
                        //imprimeMatriz(matriz1);
                        percurso(caminhos, aux1, x, y, (tentativas + 1), (n + 1));
                    }
                }

                //Movimento a direita
                if (y < 2) {
                    movimento(matriz2, x, y, x, (y + 1));
                    //espaco(n);
                    //System.out.println("Movimento da Matriz:");
                    //imprimeMatriz(matriz2, n);
                    //System.out.println();
                    //espaco(n);
                    //System.out.println("Matrizes iguais: " + aux2.getMovimentos().igual(matriz2));
                    //System.out.println();
                    if (aux2.getMovimentos().igual(matriz2) == 0) {
                        aux2.getMovimentos().adiciona(matriz2);
                        aux2.setAtual(matriz2);
                        //imprimeMatriz(matriz2);
                        percurso(caminhos, aux2, x, y, (tentativas + 1), (n + 1));
                    }
                }

                //Movimento pra cima
                if (x > 0) {
                    movimento(matriz3, x, y, (x - 1), y);
                    //espaco(n);
                    //System.out.println("Movimento da Matriz:");
                    //imprimeMatriz(matriz3, n);
                    //System.out.println();
                    //espaco(n);
                    //System.out.println("Matrizes iguais: " + aux3.getMovimentos().igual(matriz3));
                    //System.out.println();
                    if (aux3.getMovimentos().igual(matriz3) == 0) {
                        aux3.getMovimentos().adiciona(matriz3);
                        aux3.setAtual(matriz3);
                        //imprimeMatriz(matriz3);
                        percurso(caminhos, aux3, x, y, (tentativas + 1), (n + 1));
                    }
                }

                //Movimento pra baixo
                if (x < 2) {
                    movimento(matriz4, x, y, (x + 1), y);
                    //espaco(n);
                    //System.out.println("Movimento da Matriz:");
                    //imprimeMatriz(matriz4, n);
                    //System.out.println();
                    //espaco(n);
                    //System.out.println("Matrizes iguais: " + aux4.getMovimentos().igual(matriz4));
                    //System.out.println();
                    if (aux4.getMovimentos().igual(matriz4) == 0) {
                        aux4.getMovimentos().adiciona(matriz4);
                        aux4.setAtual(matriz4);
                        //imprimeMatriz(matriz4);
                        percurso(caminhos, aux4, x, y, (tentativas + 1), (n + 1));
                    }
                }

            }
        }
    }

    public static int menorElemento(ArrayList<Jogada> jogadas){
        int i; 
        int pos = 0;
        int menor = Integer.MAX_VALUE;
        for(i= 0; i < jogadas.size(); i++){
            if(jogadas.get(i).getMovimentos().nElementos < menor){
                menor = jogadas.get(i).getMovimentos().nElementos;
                pos = i;
            }
        }
        return pos;
    }
    
    public static void main(String[] args) {
        int x, y, i;

        int entrada[][] = {{1, 2, 3},
        {0, 5, 6},
        {4, 7, 8}};

        Jogada jogo = new Jogada();
        jogo.setAtual(entrada);
        jogo.getMovimentos().adiciona(entrada);
        
        ArrayList<Jogada> jogadas = new ArrayList<Jogada>();
        int melhorJogada;
        
        MenorCaminho solucao = new MenorCaminho();
        solucao.setQuantidade(Integer.MAX_VALUE);

        x = encontraX(entrada);
        y = encontraY(entrada);

        percurso(jogadas, jogo, x, y, 0, 0);
        melhorJogada = menorElemento(jogadas);
        
        for(i = 0; i < jogadas.size(); i++){
            System.out.println("Movimentos: "+(jogadas.get(i).getMovimentos().nElementos - 1));
            jogadas.get(i).getMovimentos().imprime();
        }
        
        System.out.println("--------------------------------------------");
        System.out.println("Melhor Jogada, Movimentos: "+((jogadas.get(melhorJogada).getMovimentos().nElementos)-1));
        jogadas.get(melhorJogada).getMovimentos().imprime();
    }
}
