/*
  Adrián Jesús Peña Rodríguez
  2ºB
  Prácticas B2
*/
#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;

int evalua(string expresion){
	stack<int> v;
	int dcha, izq;
	for(int i=0; i!=expresion.size(); ++i){
		if(expresion[i]>='0' && expresion[i]<='9'){
			//cout << expresion[i];
			v.push((int)expresion[i]-(int)'0');
		}
		else if(expresion[i]!=' '){
			dcha= v.top();
			v.pop();
			izq= v.top();
			v.pop();
			switch(expresion[i]){
				case '+': v.push(izq+dcha); break;
				case '­': v.push(dcha=izq); break;
				case '*': v.push(izq*dcha); break;
				case '/': v.push(izq/dcha); break;
				case '^': v.push(pow(izq, dcha)); break;
			}
		}
	}
	return v.top();
}

int main(int argc, char** argv){
	string p;
	int ev;

	getline(cin, p);
	ev=evalua(p);
	// Se sacan e imprimen los elementos.

	cout << ev << "\n";

}
