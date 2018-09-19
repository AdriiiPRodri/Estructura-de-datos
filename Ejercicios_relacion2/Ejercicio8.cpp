/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/
void Insertar(queue<T>& Q, int pos, elemento x){
  queue<T> aux;

  for(int i = 0; i < pos; i++){   // Guardamos en una pila los primeros pos elementos
    aux.push(Q.front());
    Q.pop();
  }

  aux.push(x);

  while(!Q.empty()){              // Añadimos los restantes
    aux.push(Q.front());
    Q.pop();
  }

  Q = aux;
}
