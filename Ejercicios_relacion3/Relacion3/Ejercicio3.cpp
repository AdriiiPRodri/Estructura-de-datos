#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

string encripta(const string& s, const map<char,char> &cod){
    string encriptada= s;
    char aux;
    for(int i=0; i<encriptada.size(); i++){
        aux=encriptada[i];
        encriptada[i]=cod.find(aux)->first;
    }
    
    return encriptada;
}

int main(int argc, char** argv) {
    map<char,char> codif;
    string encriptada;
    
    for(char c='a'; c<='z'; c++){
        codif[c]=(c+2);
    }
    
    encriptada= encripta("juane", codif);
    
    cout << encriptada;
    
    return 0;
}

