/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio3.cpp
 * Author: Adrian Jesus Peña Rodriguez
 *
 * Created on January 28, 2017, 12:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

/////// Estructura del arbol binario ///////

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *btree;

btree createNode(int x){
    btree nuevo = new(struct nodo);
    nuevo->nro = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    
    return nuevo;
}

void insert(btree &tree, int x){
    if(tree == NULL)
        tree = createNode(x);
    else if(x < tree->nro)
        insert(tree->izq, x);
    else
        insert(tree->der, x);
}

void preOrder(btree tree){
    if(tree != NULL){
        cout << tree->nro << " ";
        preOrder(tree->izq);
        preOrder(tree->der);
    }
}

void inOrder(btree tree){
    if(tree != NULL){
        inOrder(tree->izq);
        cout << tree->nro << " ";
        inOrder(tree->der);
    }
}

void postOrder(btree tree){
    if(tree != NULL){
        postOrder(tree->izq);
        postOrder(tree->der);
        cout << tree->nro << " ";
    }
}

//////////////////////////////////////////

//////////////////////// Algoritmo ejercicio 3  ////////////////////////////

void nodeReverse(btree tree){
    if(tree == NULL)                // En caso de que el nodo que nos pasan sea nulo salimos de la funcion
        return;
    
    btree temp = tree->der;         // Guardamos el nodo de la derecha
    tree->der = tree->izq;          // Cambiamos el de la derecha por el de la izquierda
    tree->izq = temp;               // Asignamos a la izquierda el antiguo valor del de la derecha
    
    nodeReverse(tree->izq);         // Hacemos lo mismo con toda la rama de la izquierda(antigua derecha)
    nodeReverse(tree->der);         // Hacemos lo mismo con toda la rama de la derecha(antigua izquierda)
}

////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
    btree tree = NULL;               // Creamos el arbol

    int n;                          // Numero de nodos del arbol
    int x;                          // Elemento a insertar en cada nodo

    cout << "\n\t\t  ..[ ARBOL BINARIO ]..  \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insert( tree, x);
    }

    cout << "\n Mostrando ABB \n\n";
    //showTree( tree, 0);

    cout << "\n Recorridos del ABB";

    cout << "\n\n En orden   :  ";   inOrder(tree);
    cout << "\n\n Pre Orden  :  ";   preOrder(tree);
    cout << "\n\n Post Orden :  ";   postOrder(tree);

    cout << endl << endl;
    
    nodeReverse(tree);
    
    cout << "\n Recorridos despues de intercambair posiciones";

    cout << "\n\n En orden   :  ";   inOrder(tree);
    cout << "\n\n Pre Orden  :  ";   preOrder(tree);
    cout << "\n\n Post Orden :  ";   postOrder(tree);

    return 0;
}

