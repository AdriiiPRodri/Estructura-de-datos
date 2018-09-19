#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
list<T> sustituye(const list<T> &l1, const int x){
    list<T> devolver = l1;
    typename list<T>::const_iterator it=devolver.begin();
    
    do{
        if(*it == x){
            it++;                           // Con esto hacemos que se añada después de encontrar el valor y no justo antes que es el comportamiento por defecto
            devolver.insert(it, x - 1);
        }
        else
            it++;
    }while(it!= devolver.end());

    return devolver;
}

int main(int argc, char** argv) {
    list<int> lista1;
    list<int> inserccion;
    int x = 1;
        
    lista1.push_back(2);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(5);
    lista1.push_back(3);
    
    cout << "Lista1: " << endl;
    for(list<int>::iterator it=lista1.begin(); it != lista1.end(); it++){
        cout << *it << endl;
    }
    
    inserccion = sustituye(lista1, x);
    
    cout << "Insertado: " << endl;
    for(list<int>::iterator it = inserccion.begin(); it != inserccion.end(); it++){
        cout << *it << endl;
    }
    
    return 0;
}

