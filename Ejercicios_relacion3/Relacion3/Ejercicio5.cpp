#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
void elimina(list<T> &l, T ele){
    typename list<T>::iterator it=l.begin();
    while(it!= l.end()){
        if(*it==ele){
            typename list<T>::iterator q= it;
            it++;
            q=l.erase(q);
        }
        else
            it++;
    }
}

int main(int argc, char** argv) {
    list<int> lista;
    int x=1;
        
    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(5);
    lista.push_back(3);
    
    for(list<int>::iterator it=lista.begin(); it!= lista.end(); it++){
        cout << *it << endl;
    }
    
    elimina(lista, x);
    /*
    list<int>::iterator it=lista.begin();
    list<int>::iterator q=it;
    it++;
    lista.erase(q);
    */
    cout << endl;
    for(list<int>::iterator it=lista.begin(); it!= lista.end(); it++){
        cout << *it << endl;
    }
    
    return 0;
}

