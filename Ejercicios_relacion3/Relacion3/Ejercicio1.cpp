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

int main(int argc, char** argv){
    map<string,int> decc;
    decc = palabras(argv[1]);
    for(map<string,int>::iterator it = decc.begin(); it != decc.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
