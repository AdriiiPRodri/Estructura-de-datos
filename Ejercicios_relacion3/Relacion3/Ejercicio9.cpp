#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
list<T> mezclar(const list<T> &l1, const list<T> &l2){
    list<T> devolver = l1;
    list<T> mezclo = l2;            // Se debe de crear debido al const de l2
    devolver.merge(mezclo);
    devolver.sort();                // Ordenamos
    
    return devolver;
}

int main(int argc, char** argv) {
    list<int> lista1;
    list<int> lista2;
    list<int> mezcla;
        
    lista1.push_back(2);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(5);
    lista1.push_back(3);
    
    lista2.push_back(6);
    lista2.push_back(7);
    lista2.push_back(4);
    lista2.push_back(6);
    lista2.push_back(6);
    lista2.push_back(2);
    lista2.push_back(1);
    
    cout << "Lista1: " << endl;
    for(list<int>::iterator it=lista1.begin(); it != lista1.end(); it++){
        cout << *it << endl;
    }
    
    cout << "Lista2: " << endl;
    for(list<int>::iterator it=lista2.begin(); it != lista2.end(); it++){
        cout << *it << endl;
    }
    
    mezcla = mezclar(lista1, lista2);
    
    cout << "Mezclada: " << endl;
    for(list<int>::iterator it = mezcla.begin(); it != mezcla.end(); it++){
        cout << *it << endl;
    }
    
    return 0;
}

