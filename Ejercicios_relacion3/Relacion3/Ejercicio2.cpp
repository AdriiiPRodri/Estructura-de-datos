#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

map<string,int> palabras(string expresion){
    map<string,int> dicc;
    
    ifstream fe(expresion);
    while(!fe.eof()){
        string aux;
        fe >> aux;
        dicc[aux]++;
    }

    return dicc;
}

multimap<string,int> devolver(const map<string,int>& m){
    multimap<string,int> dev;
    
    for(map<string,int>::const_iterator it = m.cbegin(); it != m.cend(); it++){
        for(int i = 0; i < it->second; i++){
            dev.insert(*it);
        }
    }
    
    return dev;
}

int main(int argc, char** argv){
    map<string,int> decc;
    decc = palabras(argv[1]);
    multimap<string,int> docc;
    docc = devolver(decc);
    for(multimap<string,int>::iterator it = docc.begin(); it != docc.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
