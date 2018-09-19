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

class ComparaTamanio{
public:
  bool operator()(const string & p1, const string & p2) const {
      if(p1.length() < p2.length())
        return true;
      else if(p1.length() > p2.length())
        return false;
      else
        for(int i = 0; i < p1.length(); i++){
          if(p1[i] < p2[i])
            return true;
          else if(p1[i] > p2[i])
            return false;
        }
    return false;
  }
};

int main(){
  priority_queue<string, vector<string>, ComparaTamanio> prueba;

  string a = "add";
  string b = "addfafasfas";

  prueba.push(a);
  prueba.push(b);

  while(!prueba.empty()){
    cout << " " << prueba.top() << endl;
    prueba.pop();
  }
}
