#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
void eliminaDuplicados(list<T> &l){
    for(typename list<T>::iterator it=l.begin(); it!= l.end(); it++){
        typename list<T>::iterator q= it;
        ++q;
        while(q != l.end()){
            if(*it==*q)
                q=l.erase(q);
            else
                ++q;
        }
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
    lista.push_back(3);
    
    for(list<int>::iterator it=lista.begin(); it!= lista.end(); it++){
        cout << *it << endl;
    }
    
    eliminaDuplicados(lista);
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

