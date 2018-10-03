/*implementacion de la interfaz lista, que mediante un array unidimensional y una variable longitud
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacion.listas;
//implements LISTA

/**
 *
 * @author i.sanandres.2017
 */
public class ListaArray {

    private int numElementos = 5;
    int lista[] = new int[numElementos]; //contiene los elementos de la lista
    int longitud; //contiene el nº de elementos actual de la lista
    //constuctor:
    //Inicializa los datos a lista vacia con longitud 0 y elementos 0

    public ListaArray() {
        longitud = 0;
        for (int i = 0; i < numElementos; i++) {
            lista[i] = 0;
        }
    }

    //operaciones de la clase
    //aqui copio lo que deberia tener en LISTA
    public boolean add(int elem) { //inserta un elemento en una posición
        boolean resultado;
        if (longitud == numElementos) {
            //duplicar el tamaño del array
            numElementos = numElementos * 2;
            int A[] = new int[numElementos];
            for (int i = 0; i < longitud; i++) {
                A[i] = lista[i];

            }
            lista = A;
        }
        lista[longitud] = elem;
        longitud++;
        resultado = true;

        return resultado;
    }
    public void add (int index, int elem){ //añade un elemento en una posicion index
        for(int i=0;i<longitud;i++){
            if(i==index){
                lista[i]=elem;
            }
        }
    }
    public boolean remove(int index){ //borra un elemento del indice que le llega. Devuelve true si lo ha borrado
        boolean borrado=false;
        for(int i=0;i<longitud;i++){
            if(i==index){
              for(int j=0;j<longitud;j++){
                  lista[j-1]=lista[j];
                  borrado=true;
              }  
            }
        }
        
        return borrado;
    }
    public boolean removeElem(int elem){ //borra la primera ocurrencia de elem en la lista. Devuelve true si lo ha borrado
        boolean encontrado=false;
        int i=0;
        while((i<longitud)&&(!encontrado)){
        if(lista[i]==elem){
            encontrado=true;
            for(int j=i+1;j<longitud;j++)
                lista[j-1]=lista[j];
            
                longitud--;
            
        }
        i++;
    }
        
        return encontrado;
    }

    public int size() { //te devuelve el nº de elementos de la lista
        return longitud;
    }

    public boolean isEmpty() { // te dice si está vacio y devuelve true en tal caso
        boolean vacia;
        if (longitud == 0) {
            vacia = true;
        } else {
            vacia = false;
        }
        return vacia;
    }

    public String toString() { //devuelve los elementos en un string
        String cadena = "{";
        for (int i = 0; i < longitud; i++) {
            cadena = cadena + lista[i] + "";
        }
        cadena = cadena + "} " + "longitud = " + longitud;

        return cadena;
    }

    public boolean equals(LISTA list){ //comparar dos listas. Devuelve true si la lista invocante es igual a list
        boolean iguales=false;
        int contador=0;
        for(int i=0;i<longitud;i++){
            for(int j=0;j<longitud;j++){
                
                    
                
            }
        }
        
        return iguales;
    }
    public boolean contains(int elem){//Devuelve true si elem está en la lista
        boolean encontrado=false;
        for(int i=0;i<longitud;i++){
            if(lista[i]==elem){
                encontrado=true;
            }
        }
        
        return encontrado;
    }
    public int get(int index){//Devuelve el elemento situado en una posicion index
        int elemindex=0;
        for(int i=0;i<longitud;i++){
            if(i==index){
              elemindex=lista[i];  
            }
        }
        return elemindex;
    }
    public int indexOf(int elem){//devuelve el indice de un elemento que recibe como argumento
        int index=0;
        for(int i=0;i<longitud;i++){
          if(lista[i]==elem){
              index=i;
          }  
        }
        return index;
    }
    //public int set(int index,int elem);//sustituye el elemento situado en index por elem. Devuelve el elemento original
    public void clear(){//borra todos los elementos de la lista invocante. 
        boolean borrado;
        for (int i=0;i<longitud;i++){
            if(lista[i]==numElementos){
                for(int j=i+1;j<longitud;j++){
                    lista[j-1]=lista[j];
                    
                }
                longitud--;
            }
        }
        
    }
}
