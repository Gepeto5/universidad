/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prac6;

import java.util.Scanner;

/**
 *
 * @author i.sanandres.2017
 */
public class Prac6 {

    /**
     * @param args the command line arguments
     */
    public static void colegas(int num, int cifra) {
        int primercifra, ultimocifra;
        primercifra = num;
        ultimocifra = num % 10;
        while (primercifra >= 10) {

            primercifra = primercifra / 10;
        }
        if (primercifra == ultimocifra && primercifra == cifra && ultimocifra == cifra) {
            System.out.println("La cifra " + cifra + " es un número amigo de " + num);
        } else {
            System.out.println("La cifra " + cifra + " NO es número amigo de " + num);
        }
    }

    public static int sumacifras(int num) {
        int resto, suma;
        suma = 0;
        resto = 0;
        while (num > 9) {
            resto = num % 10;
            suma += resto;
            num = num / 10;
            if (num < 10 && num > 0) {
                suma += num;
            }
        }
        return suma;
    }

    public static void sinceros(int base, int limite) {
        int comprobador;
        for (int i = base; i <= limite; i++) {
            if (i % base == 0) {
                comprobador = sumacifras(i);
                if (comprobador == base) {
                    System.out.println(i);

                }
            }
        }

    }

    public static void main(String[] args) {
        // TODO code application logic her
        Scanner entrada = new Scanner(System.in);
        int opciones;
        boolean fin;
        fin = true;
        System.out.println("PRÁCTICA DE SUBPROGRAMAS por SANANDRÉS, GUTIÉRREZ, Iván");
        while (fin = true) {
        System.out.println("1-Números sinceros \n 2-Números colegas \n 3-Finalizar");
        opciones = entrada.nextInt();
        while (opciones < 1 || opciones > 3) {
            System.out.print("Error. Introduzca un Nº del 1 al 3 para elegir una opción: ");
            opciones=entrada.nextInt();
        }
        
            switch (opciones) {
                case 1:
                    int bas,
                     lim;
                    System.out.print("Introduzca la base (Nº positivo de 1 cifra): ");
                    bas = entrada.nextInt();
                    while (bas >= 10 || bas < 0) {
                        System.out.print("Número no válido. Introduzca un Nº positivo de 1 cifra: ");
                        bas = entrada.nextInt();
                    }
                    System.out.print("Introduzca el límite (Nº mayor que 9): ");
                    lim = entrada.nextInt();
                    while (lim <= 9) {
                        System.out.print("Número no válido. Introduzca un Nº mayor que 9: ");
                        lim = entrada.nextInt();
                    }

                    sinceros(bas, lim);
                    fin = true;
                    break;
                case 2:
                    int numero,
                     cifra;
                    System.out.print("Introduzca un Nº mayor que 0: ");
                    numero = entrada.nextInt();
                    while (numero < 0) {
                        System.out.print("Nº no válido. Introduzca un Nº mayor que 0: ");
                        numero = entrada.nextInt();
                    }
                    System.out.print("Introduzca un Nº positivo de 1 cifra: ");
                    cifra = entrada.nextInt();
                    while (cifra < 0 || cifra > 9) {
                        System.out.print("Nº no válido. Introduzca un Nº positivo de 1 cifra: ");
                    }
                    colegas(numero, cifra);
                    fin = true;
                    break;
                case 3:
                    fin = false;
                    break;
                default:
            }
        }fin=false;
    }
}