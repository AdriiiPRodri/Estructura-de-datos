#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

string desencripta(const string& s, const map<char,char> &cod){
    string desencriptada= s;
    char aux;
    for(int i=0; i<desencriptada.size(); i++){
        aux=desencriptada[i];
        desencriptada[i]=cod.find(aux)->second;
    }
    
    return desencriptada;
}

int main(int argc, char** argv) {
    map<char,char> codif;
    string desencriptada;
    
    for(char c='a'; c<='z'; c++){
        codif[c]=(c-2);
    }
    
    desencriptada= desencripta("lwcpg", codif);
    
    cout << desencriptada;
    
    return 0;
}

