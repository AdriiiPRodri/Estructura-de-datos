#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void intercalar(vector<T> &v, vector<pair<int, T> > pos){
    
    typename vector< T >::iterator it = v.begin();
    for(int i = 0; i < pos.size(); i++){
        for(int j = 0; j < pos[i].first; j++)
            it++;
        v.insert(it, pos[i].second);
    }
}

int main(int argc, char** argv) {
    vector<int> a;
    vector< pair<int,int> > b;
    
    a.push_back(4);
    a.push_back(7);
    
    b.push_back(pair<int,int> (1,1));
    
    intercalar(a,b);
    
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << endl << flush;
    
    return 0;
}
