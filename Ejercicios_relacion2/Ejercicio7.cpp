/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/
void Insertar(stack<T>& P, int pos, elemento x){
  int insertar = P.size() - pos;
  stack<T> aux;

  for(int i = 0; i < insertar; i++){
    aux.push(P.top());                  // Clonamos la pila al reves
    P.pop();
  }
  P.push(x);
  while(!aux.empty()){
    P.push(aux.top());
    aux.pop();
  }
}
