/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Principal;

import Conseitual.Lista;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author paulovictor
 */
public class Hash {

    static final int num = 100;

    public static int conversao(String nome) { 
        int i;
        int soma = 0; 
        int tamanho = nome.length(); 
        int ascii;
        char character;
        for (i = 0; i < tamanho; i++) {         
            character = nome.charAt(i); 
            ascii = (int) character; 
            //System.out.println(ascii);
            soma = soma + ascii; 
        }
        return soma;
    }
    
    public static String aleatorio(String nome) { 
        int i;
        int tamanho = nome.length();
        char character;
        Random gerador = new Random();
        String soma = "";
        for (i = 0; i < tamanho; i++) {         
            character = nome.charAt(gerador.nextInt(tamanho));
            soma = soma + character; 
        }
        return soma;
    }

    public static void main(String[] args) {
        // TODO code application logic here
        //Variaveis
        Lista[] lis = new Lista[num];
        int i, inser, cont;
        String alfaberto = "ABCDEFGHIJKLMNOPQSTUVWXYZ"; 
        String telefone = "123456789"; 
        String bus; 
        String retorno;
        Scanner sc = new Scanner(System.in);

        //Criando listas
        for (i = 0; i < num; i++) {
            lis[i] = new Lista();
            lis[i].nElementos = 0;
        }

        //Entrada
        System.out.print("Digite o numero de insercoes: ");
        inser = sc.nextInt();
        long tempoInicialA = System.currentTimeMillis();
        for (i = 0; i < inser; i++) {
            //System.out.println("Digite o nome:");
            String nome = aleatorio(alfaberto);
            //System.out.println(nome);
            //Verifica se o nome já existe 
            cont = lis[conversao(nome)%num].igual(nome);
            if (cont != 0) {
                while (cont != 0) {
                    //System.out.println("O nome ja existe, digite outro:");
                    nome = aleatorio(alfaberto);
                    cont = lis[conversao(nome)%num].igual(nome);
                }
            }
            //System.out.println("Digite o endereco:");
            String end = aleatorio(alfaberto);
            //System.out.println("Digite o telefone:");
            int tele = Integer.parseInt(aleatorio(telefone));
            lis[conversao(nome)%num].adiciona(nome, tele, end);
        }
        long tempoFinalA = System.currentTimeMillis();
        System.out.printf("Tempo de execucao da insercao: %.3f ms%n", (tempoFinalA - tempoInicialA) / 1000d);
        System.out.println();

        //Impresão
        long tempoInicialB = System.currentTimeMillis();
        for (i = 0; i < num; i++) {
            lis[i].imprime(i);
        }
        long tempoFinalB = System.currentTimeMillis();
        System.out.println();
        System.out.printf("Tempo de execucao da impresao: %.3f ms%n", (tempoFinalB - tempoInicialB) / 1000d);
        System.out.println();

        //Busca
        System.out.println("Digite o nome que queria ver: ");
        bus = sc.next();
        long tempoInicialC = System.currentTimeMillis();
        retorno = lis[conversao(bus)%num].busca(bus);
        long tempoFinalC = System.currentTimeMillis();
        System.out.println(retorno);
        System.out.printf("Tempo de execucao da busca: %.3f ms%n", (tempoFinalC - tempoInicialC) / 1000d);
    }
}
