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

struct Persona{
  string Nombre, apellidos;
  int prioridad;

  int getPrioridad() const{
    return prioridad;
  }

  bool operator<(const Persona &person) const{      // Debemos de sobrecargar este operador para que la cola de prioridad pueda hacer la operación <
    return this->getPrioridad() < person.getPrioridad();
  }
};

int main(){
  priority_queue<Persona> prueba;

  Persona Persona1;
  Persona1.Nombre = "Adri";
  Persona1.apellidos = "Pena";
  Persona1.prioridad = 8;
  Persona Persona2;
  Persona2.Nombre = "Juan";
  Persona2.apellidos = "Garcia";
  Persona2.prioridad = 4;

  prueba.push(Persona1);
  prueba.push(Persona2);

  while(!prueba.empty()){
    cout << " " << prueba.top().Nombre << endl;
    prueba.pop();
  }
}
