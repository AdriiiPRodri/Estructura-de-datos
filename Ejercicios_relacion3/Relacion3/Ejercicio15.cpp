#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
list<pair<T,int> > comprimir(const list<T> &l){
    list<pair<T,int> > dev;
    
    if(l.size()>0){
        pair<T,int> p_aux(0,0);
        typename list<T>::const_iterator it=l.begin();
        p_aux.first=*it;
        
        while(it!=l.end()){
            if(p_aux.first==*it){
                p_aux.second++;
                it++;
            }
            else{
                dev.push_back(p_aux);
                p_aux.first=*it;
                p_aux.second=1;
                it++;
            }
        }
        dev.push_back(p_aux);
        
    }
    return dev;
}

template<typename T>
list<T> descomprimir(const list<pair<T,int> > &lc){
    list<T> dev;
    int i;
    
    for(typename list<pair<T,int> >::const_iterator it=lc.begin(); it!=lc.end(); it++){
        i=0;
        
        while(i<it->second){
            dev.push_back(it->first);
            i++;
        }
    }
    
    return dev;
}

int main(int argc, char** argv) {
    list<int> li, lprueba2;
    list<pair<int,int> > lp, lprueba;
    
    li.push_back(1);
    li.push_back(1);
    li.push_back(1);
    li.push_back(2);
    li.push_back(2);
    li.push_back(2);
    li.push_back(2);
    li.push_back(2);
    li.push_back(2);
    li.push_back(7);
    li.push_back(7);
    li.push_back(7);
    li.push_back(7);
    li.push_back(7);
    li.push_back(12);
    li.push_back(1);
    li.push_back(1);
    li.push_back(5);
    li.push_back(5);
    
    lp.push_back(pair<int,int>(1,3));
    lp.push_back(pair<int,int>(2,6));
    lp.push_back(pair<int,int>(7,5));
    lp.push_back(pair<int,int>(12,1));
    lp.push_back(pair<int,int>(1,2));
    lp.push_back(pair<int,int>(5,2));
    
    
    cout << endl;
   lprueba2= descomprimir(lp);
    for(list<int>::const_iterator ite=lprueba2.begin(); ite!=lprueba2.end(); ite++){
        cout << *ite << endl;
    }
    
    return 0;
}