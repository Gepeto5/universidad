/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prac9;
import java.io.BufferedReader;
import java.util.Scanner;
import java.io.*;

class Amigo implements Serializable{
    String amigo;
    int edad;
    String direccion;
}
/**
 *
 * @author i.sanandres.2017
 */
public class Prac9 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        // declaración de variables
        Scanner entrada=new Scanner(System.in);
        int opciones,telefono,num;
        boolean fin=true;
        String nombre;
        System.out.println("Práctica de ficheros por Sanandrés Gutiérrez, Iván");
        System.out.println("---------------------------------------------------");
        do{
        System.out.println("Menú:");
        System.out.println("1-Crear agenda \n2-Mostrar agenda \n3-Crear fichero amigo \n4-Mostrar fichero amigo \n5-Salir");
        System.out.println();
        System.out.print("Escoja una opción: ");
        opciones=entrada.nextInt();
        while(opciones<1||opciones>5){
            System.out.print("Error. Escoja una opción entre 1 y 5");
            opciones=entrada.nextInt();
        }
        switch (opciones){
            case 1:
                try{
                    PrintStream agenda=new PrintStream(new FileOutputStream ("agenda.txt"));
                    System.out.print("¿Cuántos alumnos quieres introducir? Introduzca 0 si desea salir ");
                    num=entrada.nextInt();
                    while(num<0){
                        System.out.print("Error. Introduce un nº entero positivo,o 0 para salir ");
                        num=entrada.nextInt();
                    }
                    while(num >0){
                        System.out.print("Introduzca el alumno: ");
                        nombre=entrada.next();
                        System.out.print("Introduzca su número de teléfono: ");
                        telefono=entrada.nextInt();
                        agenda.println("Nombre: "+nombre+"  Teléfono: "+telefono);
                        num--;
                    }
                }catch(FileNotFoundException e){
                    System.out.println("Fichero no encontrado");
                }catch(IOException exc){
                    System.out.println("Otro tipo de excepción");
                }
                break;
            case 2:
                try{
                    BufferedReader lec=new BufferedReader (new FileReader("agenda.txt"));
                    String st=lec.readLine();
                    while(st !=null){
                        System.out.println(st);
                        st=lec.readLine();
                    }
                }catch(FileNotFoundException e){
                    System.out.println("Fichero no encontrado");
                }catch(IOException exc){
                    System.out.println("Otro tipo de excepción");
                }
                break;
            case 3:
                try{
                    FileOutputStream out=new FileOutputStream ("Amigos.dat");
                    ObjectOutputStream so=new ObjectOutputStream(out);
                    Amigo all;
                    all=new Amigo();
                    all.amigo=entrada.nextLine();
                    all.edad=entrada.nextInt();
                    all.direccion=entrada.nextLine();
                    so.writeObject(all);
                    so.close();
                } catch(IOException exc){
                    System.out.println("Otro tipo de excepción");
                }
                break;
            case 4:
                break;
            case 5:
                fin=false;
                break;
        }
        }while (fin !=false);
    }
    
}
