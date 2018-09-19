/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/
void ComprobarParentesis(string cadena){
  for(int i = 0; i < cadena.length(); i++)
    if (cadena.charAt(i) == '(')
      pila.push(')');
    else if (cadena.charAt(i) == ')'){
      if(pila.top() != ')'){
        cout << "Parétesis no balanceados."
        return 1;
      }
      pila.pop();
    }
}
