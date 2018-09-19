/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/
#include <queue>

using namespace std;

class Pila{
private:
  queue<T> In_queue;
  queue<T> Out_queue;       // Esta es nuestra cola

public:
  Pila(vector<T> datos){
    for(int i = 0; i < datos.size(); i++)
      In_queue.push(datos[i]);
  }

  void push(dato){                        // Tienen un orden de eficiencia logaritmico
    if (In_queue.isEmpty()) {
        while (!Out_queue.isEmpty()) {
           In_queue.push(Out_queue.back());
           Out_queue.pop();
        }
    }
    In_queue.push(dato);
  }

  void pop(){
    if (Out_queue.isEmpty()) {
        while (!In_queue.isEmpty()) {
           Out_queue.push(In_queue.front());
           In_queue.pop();
        }
    }
    Out_queue.pop();
  }

  bool empty(){
    return In_queue.empty() && Out_queue.empty();
  }

  int size(){
    if(In_queue.size() < Out_queue.size()){
      return Out_queue.size();
    }
    return In_queue.size();
  }

  bool operator<(const stack<T> b){
    Queue<T> aux(Out_queue);
    stack<T> aux1(b);

    if(aux.size() == b.size())
      while(!aux.empty()){
        if(aux.front() >= b.top())
          return false;
        aux.pop();
        aux1.pop();
      }
    else
      return false;

    return true;
  }

  bool operator==(const stack<T> b){
    Queue<T> aux(Out_queue);
    stack<T> aux1(b);

    if(aux.size() == b.size())
      while(!aux.empty()){
        if(aux.front() != b.top())
          return false;
        aux.pop();
        aux1.pop();
      }
    else
      return false;

    return true;
  }

  int top(){
    return In_queue.back();
  }
}
