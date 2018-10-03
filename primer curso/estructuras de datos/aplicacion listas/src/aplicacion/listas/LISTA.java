/*
 * Interfaz de lista con las operaciones de listas de enteros
 */
package aplicacion.listas;

/**
 *
 * @author i.sanandres.2017
 */
public interface LISTA {
    public boolean add(int elem); //inserta un elemento en una posición
    public void add (int index, int elem); //añade uun elemento en una posicion index
    public boolean remove(int index); //borra un elemento del indice que le llega. Devuelve true si lo ha borrado
    public boolean removeElem(int elem); //borra la primera ocurrencia de elem en la lista. Devuelve true si lo ha borrado
    public int size(); //te devuelve el nº de elementos de la lista
    public boolean isEmpty(); // te dice si está vacio y devuelve true en tal caso
    public String toString(); //devuelve los elementos en un string
    public boolean equals(LISTA list); //comparar dos listas. Devuelve true si la lista invocante es igual a list
    public boolean contains(int elem);//Devuelve true si elem está en la lista
    public int get(int index);//Devuelve el elemento situado en una posicion index
    public int indexOf(int elem);//devuelve el indice de un elemento que recibe como argumento
    public int set(int index,int elem);//sustituye el elemento situado en index por elem. Devuelve el elemento original
    public void clear();//borra todos los elementos de la lista invocante. 
}
