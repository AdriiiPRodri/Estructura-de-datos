#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
list<T> invertir(list<T> l){
    typename list<T>::iterator it=l.end();
    list<T> inversa;
    do{
        it--;
        inversa.push_back(*it);
    }while(it!= l.begin());
    
    return inversa;
}

int main(int argc, char** argv) {
    list<int> lista;
    list<int> inv;
        
    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(5);
    lista.push_back(3);
    
    for(list<int>::iterator it=lista.begin(); it != lista.end(); it++){
        cout << *it << endl;
    }
    
    inv = invertir(lista);
    
    cout << "Inveritida: " << endl;
    for(list<int>::iterator it=inv.begin(); it!= inv.end(); it++){
        cout << *it << endl;
    }
    
    return 0;
}

