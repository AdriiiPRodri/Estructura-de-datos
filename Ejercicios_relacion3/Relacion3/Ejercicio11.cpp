#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
bool contenida(const list<T> &l1, const list<T> &l2){
    if(l1.size() <= l2.size()){
        int contador = 0;
        typename list<T>::const_iterator it1=l1.begin();
        typename list<T>::const_iterator it2=l2.begin();
        do{
            if(*it1 == *it2){
                it1++;
                it2++;
                contador++;
            }
            else if(it1==l1.begin())
                it2++;
            else if(it1 != l1.end())
                return false;
        }while(it1!= l1.end() && it2 != l2.end());

        return contador == l1.size();
    }
    return false;
}

int main(int argc, char** argv) {
    list<int> lista1;
    list<int> lista2;
    
    lista1.push_back(3);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    
    lista2.push_back(2);
    lista2.push_back(1);
    lista2.push_back(1);
    lista2.push_back(3);
    lista2.push_back(1);
    lista2.push_back(1);
    lista2.push_back(3);
    
    cout << "Lista1: " << endl;
    for(list<int>::iterator it=lista1.begin(); it != lista1.end(); it++){
        cout << *it << endl;
    }
    
    cout << "Lista2: " << endl;
    for(list<int>::iterator it=lista2.begin(); it != lista2.end(); it++){
        cout << *it << endl;
    }
    
    if(contenida(lista1, lista2))
        cout << "Esta contenida." << endl;
    else
        cout << "No contenida" << endl;
    
    return 0;
}

