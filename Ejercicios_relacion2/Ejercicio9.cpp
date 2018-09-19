/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/
class Ventana{
private:
  stack<T> In_Stack;
  stack<T> Out_Stack;

public:
  void Insertar(string x){
    if (In_Stack.isEmpty()) {
        while (!Out_Stack.isEmpty()) {
           In_Stack.push(Out_Stack.top());
           Out_Stack.pop();
        }
    }
    In_Stack.push(x);
  }

  void Derecha(){
    if (In_Stack.isEmpty()) {
        while (!Out_Stack.isEmpty()) {
           In_Stack.push(Out_Stack.top());
           Out_Stack.pop();
        }
    }
    string aux = In_Stack.top();
    In_Stack.pop();
    In_Stack.push(" ");
    In_Stack.push(aux);
  }

  void Izquierda(){
    if (Out_Stack.isEmpty()) {
        while (!In_Stack.isEmpty()) {
           Out_Stack.push(In_Stack.top());
           In_Stack.pop();
        }
    }
    Out_Stack.pop();
    string aux = Out_Stack.top();
    Out_Stack.pop();
    Out_Stack.push(" ");
    Out_Stack.push(aux);
  }

  void Borrar(){
    In_Stack.pop();
  }

}
