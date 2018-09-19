/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/
#include <queue>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class CuentaVocales{
public:
  bool operator()(const string & p1, const string & p2) const {
      int contador_p1 = 0;
      int contador_p2 = 0;

      for(int i = 0; i < p1.length(); i++)
        if(p1[i] == 'a' || p1[i] == 'e' || p1[i] == 'i' || p1[i] == 'o' || p1[i] == 'u')
          contador_p1++;
      for(int i = 0; i < p2.length(); i++)
        if(p2[i] == 'a' || p2[i] == 'e' || p2[i] == 'i' || p2[i] == 'o' || p2[i] == 'u')
          contador_p2++;

      return contador_p1 < contador_p2;
  }
};

int main(){
  priority_queue<string, vector<string>, CuentaVocales> prueba;

  string a = "addaaaa";
  string b = "addfafasfas";

  prueba.push(a);
  prueba.push(b);

  while(!prueba.empty()){
    cout << " " << prueba.top() << endl;
    prueba.pop();
  }
}
