#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

class F1{
    public:
        F1(){}
        
        void setNombre(const string &n){
            nombre.push_back(n);
        }
        
        void setApellido(const string &a){
            apellido.push_back(a);
        }
        
        void setEscuderia(const string &e){
            escuderia.push_back(e);
        }
        
        void setPosicion(const int &p){
            posicion.push_back(p);
        }
        
        list< string >::const_iterator buscarApellido(const string &ape){
            for(list< string >::const_iterator it = apellido.begin(); it != apellido.end(); it++)
                if(*it == ape){
                    cout << "Lo encuentra" << endl << flush;
                    return it;
                }
        }

        private:
            list< string > nombre;
            list< string > apellido;
            list< int > posicion;
            list< string > escuderia;
};

int main(int argc, char** argv) {
    F1 a;

    a.setNombre("Adrian Jesus");
    a.setApellido("Peña");
    a.setPosicion(1);
    a.setEscuderia("McClaren");

    a.buscarApellido("Peña");

    return 0;
}

/* 
 * Pra que encuentre po cualquiera de los otros campos usaríamos un template T en el que se le
 * proporcionaría el tipo y un solo método nos serviría para buscar por cualquier campo 
*/
