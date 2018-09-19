#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
void invertir(list<T>& l){
    list<T> aux = l;
    l.clear();
    typename list<T>::iterator it=aux.end();
    do{
        it--;
        l.push_back(*it);
    }while(it!= aux.begin());
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
    
    invertir(lista);
    
    cout << "Inveritida: " << endl;
    for(list<int>::iterator it=lista.begin(); it!= lista.end(); it++){
        cout << *it << endl;
    }
    
    return 0;
}

