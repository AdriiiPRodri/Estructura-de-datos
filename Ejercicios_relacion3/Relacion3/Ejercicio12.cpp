#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
list<T> posics(const list<T> &l1, const list<list<T>> &l2){
    list<T> devolver;
    typename list<T>::iterator it=l1.begin();
    list<list<int>::iterator>::iterator it2=l2.begin();
    
    while(it!=l1.end() && it2!= l2.end()){
        if(it == *it2){
            devolver.push_back(it);
            it++;
            it2++;
        }
        else
            it++;
    }
    
    return devolver;
}

int main(int argc, char** argv) {
    list<int> lista1, devolver;
    list<list<int>::iterator> lista2;
    
    lista1.push_back(1);
    lista1.push_back(2);
    lista1.push_back(3);
    lista1.push_back(4);
    lista1.push_back(5);
    
    lista2.push_back(++lista1.begin());
    lista2.push_back(++++lista1.begin());
    lista2.push_back(++++++lista1.begin());
    
    cout << "Lista1: " << endl;
    for(list<int>::iterator it=lista1.begin(); it != lista1.end(); it++){
        cout << *it << endl;
    }
    
    cout << "Lista2: " << endl;
    for(list<list<int>::iterator>::iterator it=lista2.begin(); it != lista2.end(); it++){
        cout << *(*it) << endl;
    }
    
    devolver=posics(lista1, lista2);
    
    return 0;
}

