#include "conjunto.h"
#include "enfermedad.h"
#include "mutacion.h"

using namespace std;

class ComparacionPorID {
public:
    bool operator()(const mutacion &a, const mutacion &b) {
        return (a.getID() < b.getID());
    }
};

class ComparacionPorCrPos {
public:
    bool operator()(const mutacion &a, const mutacion &b) {
        ///El orden viene determinado por Chr y pos. El primer criterio es el n�mero de cromosoma. El orden para el n�mero de cromosoma se rige por "1"<"2"<"3"<->->-><"22"<"X"<"Y"<"MT". Dos mutaciones del mismo cromosoma deben ordenarse seg�n su posici�n, de menor posici�n a mayor (orden natural de enteros)->
        if(a.getChr()=="MT"){             //en caso de que sea MT
            if(b.getChr()!="MT")
               return false;
        }
        else if(a.getChr()>="X"){           //en caso de que sea X, Y
           //cout << getChr() << "\n";
           if(b.getChr()=="MT")       //si el que comparamos es MT, es menor el this
              return true;
           else if(b.getChr() != a.getChr())
              return a.getChr() < b.getChr();
        }
        else{                          //en caso de que sea numero
            if(b.getChr()>="MT"){
               return true;
            }
            else{
                  //cout << m.getChr() << "\n";
              if(atoi(a.getChr().c_str())!=atoi(b.getChr().c_str()))
                  return atoi(a.getChr().c_str())<atoi(b.getChr().c_str());
            }
        }

         return a.getPos() < b.getPos();
    }
};

class ComparacionEnfermedad{
  bool operator()(const enfermedad & e1, const enfermedad & e2) const{   //Orden alfabético por campo name.
     return e1.getName() < e2.getName();
  }
};
