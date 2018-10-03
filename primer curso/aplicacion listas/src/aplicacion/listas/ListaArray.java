/*implementacion de la interfaz lista, que mediante un array unidimensional y una variable longitud
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacion.listas;

/**
 *
 * @author i.sanandres.2017
 */
public class ListaArray {
   private int numElementos=5;
   int lista[]=new int[numElementos]; //contiene los elementos de la lista
   int longitud; //contiene el nº de elementos actual de la lista
   //constuctor:
   //Inicializa los datos a lista vacia con longitud 0 y elementos 0
   public ListaArray(){
       longitud=0;
       for(int i=0;i<numElementos;i++)
           lista[i]=0;
   }
   //operaciones de la clase
    //aqui copio lo que deberia tener en LISTA
   //public boolean add(int elem); //inserta un elemento en una posición
    //public void add (int index, int elem); //añade uun elemento en una posicion index
    //public boolean remove(int index); //borra un elemento del indice que le llega. Devuelve true si lo ha borrado
    //public boolean removeElem(int elem); //borra la primera ocurrencia de elem en la lista. Devuelve true si lo ha borrado
    public int size(){ //te devuelve el nº de elementos de la lista
    return longitud;
    }
    public boolean isEmpty(){ // te dice si está vacio y devuelve true en tal caso
        boolean vacia;
        
        return vacia;
    }
    }
    //public String toString(); //devuelve los elementos en un string
    //public boolean equals(LISTA list); //comparar dos listas. Devuelve true si la lista invocante es igual a list
    //public boolean contains(int elem);//Devuelve true si elem está en la lista
    //public int get(int index);//Devuelve el elemento situado en una posicion index
    //public int indexOf(int elem);//devuelve el indice de un elemento que recibe como argumento
    //public int set(int index,int elem);//sustituye el elemento situado en index por elem. Devuelve el elemento original
    //public void clear();//borra todos los elementos de la lista invocante. 
}
