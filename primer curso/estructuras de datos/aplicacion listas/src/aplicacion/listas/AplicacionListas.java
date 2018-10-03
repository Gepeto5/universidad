/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacion.listas;

/**
 *
 * @author i.sanandres.2017
 */
public class AplicacionListas {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ListaArray list=new ListaArray();
        System.out.println(list.size());
        System.out.println(list.toString());
        list.add(2);
        list.add(3);
        list.add(4);
        System.out.println(list.toString());
        list.removeElem(3);
         System.out.println(list.toString());
    }
    
}
