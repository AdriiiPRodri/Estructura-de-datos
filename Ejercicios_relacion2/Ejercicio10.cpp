/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/
bool Palindromo(string comprobar){
  stack<char> pila;
  queue<char> cola;

  for(int i = 0; i < comprobar.length(); i++){
    pila.push(comprobar[i]);
    cola.push(comprobar[i]);
  }

  for(int i = 0; i < pila.size(); i++){
    if(pila.top() != cola.front())
      return false;
    pila.pop();
    cola.pop();
  }

  return true;
}
