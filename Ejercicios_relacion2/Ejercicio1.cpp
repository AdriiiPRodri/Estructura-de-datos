/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/

#include <stack>
#include <vector>

using namespace std;

stack<T> P;

T x, y;

void funcion(stack<T>& P, T x, T y){
  vector<T> aux;

  while(!P.empty()){
    if(P.top() == x)
      aux.push_back(y);
    else
      aux.push_back(P.top());
    P.pop();
  }

  for(int i = 0; i < aux.size(); i++)
    P.push(aux[i]);
}
