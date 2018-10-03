/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacionlistaenlazada;

/**
 *
 * @author i.sanandres.2017
 */
public class ListaEnlazada {
    
    //datos:
    Nodo lista;
    
    //Constructor:
    public ListaEnlazada(){
        lista=null;
        
    }
    public boolean isEmpty(){
        
        
        
       return (lista==null);
       
    }
    public boolean add(int elem){
        boolean resultado;
        Nodo nuevoNodo=new Nodo(elem);
        Nodo nodoActual;
        nodoActual=lista;
        if(!isEmpty()){
            while(nodoActual.sig !=null){
                nodoActual=nodoActual.sig;
            }
                 nodoActual.sig=nuevoNodo;   
        }
        else{
            lista=nuevoNodo;
        }
        resultado=true;
        return resultado;
    }
}
