#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv) {
    map<pair<float,float>, int> coordenadas;
    pair<float,float> coordenada;
    
    cout << "Introduzca coordenadas" << endl << flush;
    
    cout << "Primera: " << endl << flush;
    cin >> coordenada.first;
    cout << "Segunda: " << endl << flush;        
    cin >> coordenada.second;

    do{
        coordenadas[coordenada]++;
        cout << "Primera: " << endl << flush;
        cin >> coordenada.first;
        cout << "Segunda: " << endl << flush;        
        cin >> coordenada.second;
    }while(coordenada.first != -1);
    
    for(map<pair<float,float>, int>::iterator it = coordenadas.begin(); it != coordenadas.end(); it++){
        cout << it->first.first << " " << it->first.second << " " << it->second << endl << flush;
    }

    return 0;
}
