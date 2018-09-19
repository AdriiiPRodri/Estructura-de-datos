/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/
#include <stack>

using namespace std;

class Cola{
private:
  stack<T> In_Stack;
  stack<T> Out_Stack;

public:
  Cola(vector<T> datos){
    for(int i = 0; i < datos.size(); i++)
      In_Stack.push(datos[i]);
  }

  void push(dato){
    if (In_Stack.isEmpty()) {
        while (!Out_Stack.isEmpty()) {
           In_Stack.push(Out_Stack.top());
           Out_Stack.pop();
        }
    }
    In_Stack.push(dato);
  }

  void pop(){

    if (Out_Stack.isEmpty()) {
        while (!In_Stack.isEmpty()) {
           Out_Stack.push(In_Stack.top());
           In_Stack.pop();
        }
    }
    Out_Stack.pop();
  }

  bool empty(){
    return In_Stack.empty() && Out_Stack.empty();
  }

  int size(){
    if(In_Stack.size() < Out_Stack.size()){
      return Out_Stack.size();
    }
    return In_Stack.size();
  }

  bool operator<(const stack<T> b){
    stack<T> aux(In_Stack);
    stack<T> aux1(b);     // Hacemos esto para no hacerle pop a una pila constante

    if(aux.size() == b.size())
      while(!aux.empty()){
        if(aux.top() >= b.top())
          return false;
        aux.pop();
        aux1.pop();
      }
    else
      return false;

    return true;
  }

  bool operator==(const stack<T> b){
    stack<T> aux(In_Stack);
    stack<T> aux1(b);     // Hacemos esto para no hacerle pop a una pila constante

    if(aux.size() == b.size())
      while(!aux.empty()){
        if(aux.top() != b.top())
          return false;
        aux.pop();
        aux1.pop();
      }
    else
      return false;

    return true;
  }

  int Front(){
    return Out_Stack.top();
  }

  int Back(){
    return In_Stack.top();
  }
}
