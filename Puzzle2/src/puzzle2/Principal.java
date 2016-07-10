/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package puzzle2;

import Matriz.Jogadas;
import Matriz.Matriz;
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

    public static int repetida(ArrayList<Matriz> matriz1, int[][] matriz2) {
        int rep = 0;
        int k;
        for (k = 0; k < matriz1.size(); k++) {
            if (comparaMatriz(matriz1.get(k).getMatriz(), matriz2) == 9) {
                rep++;
            }
        }
        return rep;
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
    public static void percurso(ArrayList<Jogadas> caminhos, Jogadas jogo, int x, int y, int tentativas, int n) {
        Jogadas aux1 = new Jogadas();
        Jogadas aux2 = new Jogadas();
        Jogadas aux3 = new Jogadas();
        Jogadas aux4 = new Jogadas();

        ArrayList<Matriz> l = jogo.getMovimentos();

        Matriz matriz1 = new Matriz();
        Matriz matriz2 = new Matriz();
        Matriz matriz3 = new Matriz();
        Matriz matriz4 = new Matriz();

        int i;

        aux1.setAtual(jogo.getAtual());
        aux2.setAtual(jogo.getAtual());
        aux3.setAtual(jogo.getAtual());
        aux4.setAtual(jogo.getAtual());

        for (i = 0; i < l.size(); i++) {
            aux1.getMovimentos().add(l.get(i));
            aux2.getMovimentos().add(l.get(i));
            aux3.getMovimentos().add(l.get(i));
            aux4.getMovimentos().add(l.get(i));
        }

        x = encontraX(jogo.getAtual().getMatriz());
        y = encontraY(jogo.getAtual().getMatriz());

        //Inicia as matrizes
        matriz1.rebeceMatriz(aux1.getAtual().getMatriz());
        matriz2.rebeceMatriz(aux1.getAtual().getMatriz());
        matriz3.rebeceMatriz(aux1.getAtual().getMatriz());
        matriz4.rebeceMatriz(aux1.getAtual().getMatriz());

        //espaco(n);
        //System.out.println("Jogadas "+tentativas+", Matriz atual:");
        //imprimeMatriz(jogo.getAtual(), n);
        //System.out.println();
        if (tentativas < 10) {
            if (comparaMatriz(jogo.getAtual().getMatriz(), ordenado) == 9) {
                //System.out.println("Caminho encontrado");
                //System.out.println("Movimentos: ");
                caminhos.add(jogo);

            } else {
                //Movimento a esquerda
                if (y > 0) {
                    movimento(matriz1.getMatriz(), x, y, x, (y - 1));
                    //espaco(n);
                    //System.out.println("Movimento da Matriz:");
                    //imprimeMatriz(matriz1, n);
                    //System.out.println();
                    //espaco(n);
                    //System.out.println("Matrizes iguais: " + aux1.getMovimentos().igual(matriz1));
                    //System.out.println();
                    if (repetida(aux1.getMovimentos(), matriz1.getMatriz()) == 0) {
                        aux1.getMovimentos().add(matriz1);
                        aux1.setAtual(matriz1);
                        //imprimeMatriz(matriz1);
                        percurso(caminhos, aux1, x, y, (tentativas + 1), (n + 1));
                    }
                }

                //Movimento a direita
                if (y < 2) {
                    movimento(matriz2.getMatriz(), x, y, x, (y + 1));
                    //espaco(n);
                    //System.out.println("Movimento da Matriz:");
                    //imprimeMatriz(matriz2, n);
                    //System.out.println();
                    //espaco(n);
                    //System.out.println("Matrizes iguais: " + aux2.getMovimentos().igual(matriz2));
                    //System.out.println();
                    if (repetida(aux2.getMovimentos(), matriz2.getMatriz()) == 0) {
                        aux2.getMovimentos().add(matriz2);
                        aux2.setAtual(matriz2);
                        //imprimeMatriz(matriz2);
                        percurso(caminhos, aux2, x, y, (tentativas + 1), (n + 1));
                    }
                }

                //Movimento pra cima
                if (x > 0) {
                    movimento(matriz3.getMatriz(), x, y, (x - 1), y);
                    //espaco(n);
                    //System.out.println("Movimento da Matriz:");
                    //imprimeMatriz(matriz3, n);
                    //System.out.println();
                    //espaco(n);
                    //System.out.println("Matrizes iguais: " + aux3.getMovimentos().igual(matriz3));
                    //System.out.println();
                    if (repetida(aux3.getMovimentos(), matriz3.getMatriz()) == 0) {
                        aux3.getMovimentos().add(matriz3);
                        aux3.setAtual(matriz3);
                        //imprimeMatriz(matriz3);
                        percurso(caminhos, aux3, x, y, (tentativas + 1), (n + 1));
                    }
                }

                //Movimento pra baixo
                if (x < 2) {
                    movimento(matriz4.getMatriz(), x, y, (x + 1), y);
                    //espaco(n);
                    //System.out.println("Movimento da Matriz:");
                    //imprimeMatriz(matriz4, n);
                    //System.out.println();
                    //espaco(n);
                    //System.out.println("Matrizes iguais: " + aux4.getMovimentos().igual(matriz4));
                    //System.out.println();
                    if (repetida(aux4.getMovimentos(), matriz4.getMatriz()) == 0) {
                        aux4.getMovimentos().add(matriz4);
                        aux4.setAtual(matriz4);
                        //imprimeMatriz(matriz4);
                        percurso(caminhos, aux4, x, y, (tentativas + 1), (n + 1));
                    }
                }

            }
        }
    }

    public static int menorElemento(ArrayList<Jogadas> jogadas) {
        int i;
        int pos = 0;
        int menor = Integer.MAX_VALUE;
        for (i = 0; i < jogadas.size(); i++) {
            if (jogadas.get(i).getMovimentos().size() < menor) {
                menor = jogadas.get(i).getMovimentos().size();
                pos = i;
            }
        }
        return pos;
    }

    public static void main(String[] args) {
        int x, y, i, j;

        int entrada[][] = {{1, 2, 3},
        {4, 5, 6},
        {0, 7, 8}};

        Matriz matrizentrada = new Matriz();
        matrizentrada.rebeceMatriz(entrada);

        Jogadas jogo = new Jogadas();
        jogo.setAtual(matrizentrada);
        jogo.getMovimentos().add(matrizentrada);

        ArrayList<Jogadas> jogadas = new ArrayList<Jogadas>();
        int melhorJogada;

        x = encontraX(entrada);
        y = encontraY(entrada);

        percurso(jogadas, jogo, x, y, 0, 0);
        melhorJogada = menorElemento(jogadas);

        if (jogadas.size() == 0) {
            System.out.println("Solucao nao encontrada");
        } else {
            /*
            for (i = 0; i < jogadas.size(); i++) {
                System.out.println("Movimentos: " + (jogadas.get(i).getMovimentos().size() - 1));
                for (j = 0; j < jogadas.get(i).getMovimentos().size(); j++) {
                    imprimeMatriz(jogadas.get(i).getMovimentos().get(j).getMatriz(), 0);
                    System.out.println();
                }

            }*/

            System.out.println("--------------------------------------------");
            System.out.println("Melhor Jogada, Movimentos: " + ((jogadas.get(melhorJogada).getMovimentos().size()) - 1));
            for (i = 0; i < jogadas.get(melhorJogada).getMovimentos().size(); i++) {
                imprimeMatriz(jogadas.get(melhorJogada).getMovimentos().get(i).getMatriz(), 0);
                System.out.println();
            }
        }
    }
}
