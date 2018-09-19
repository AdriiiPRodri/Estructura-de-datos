#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

class Pacientes{
    public:
        Pacientes(){}
        
        void setNombre(const string &n){
            nombre.push_back(n);
        }
        
        void setApellidos(const string &a){
            apellidos.push_back(a);
        }
        
        void setDNI(const string &e){
            DNI.push_back(e);
        }
        
        void setGravedad(const string &p){
            gravedad.push_back(p);
        }
        
        void insert(string nom, string D, string gr, string ape){
            bool esta = false;
            for(list<string>::iterator it = DNI.begin(); it != DNI.end() && !esta; it++)
                if(*it == D)
                    esta = true;
            if(!esta){
                nombre.push_back(nom);
                DNI.push_back(D);
                gravedad.push_back(gr);
                apellidos.push_back(ape);
            }
        }
        
        void remove(string D){
            bool salir = false;
            list<string>::iterator nt = nombre.begin();
            list<string>::iterator at = apellidos.begin();
            list<string>::iterator gt = gravedad.begin();
            for(list<string>::iterator it = DNI.begin(); it != DNI.end() && !salir; it++){
                if(*it == D){
                    DNI.remove(D);
                    nombre.remove(*nt);
                    apellidos.remove(*at);
                    gravedad.remove(*gt);
                    salir = true;
                }
                else{
                    nt++;
                    at++;
                    gt++;
                }
            }
        }
        
        list< string >::const_iterator buscarDNI(const string &ape){
            for(list< string >::const_iterator it = DNI.begin(); it != DNI.end(); it++)
                if(*it == ape){
                    cout << "Lo encuentra" << endl << flush;
                    return it;
                }
        }

        private:
            list< string > nombre;
            list< string > apellidos;
            list< string > DNI;
            list< string > gravedad;
};

int main(int argc, char** argv) {
    Pacientes a;

    a.setNombre("Adrian Jesus");
    a.setApellidos("Peña Rodriguez");
    a.setGravedad("Resfriado");
    a.setDNI("54654231L");

    a.buscarDNI("54654231L");
    
    a.remove("54654231L");
    
    a.buscarDNI("54654231L");
    
    a.insert("Aaaaa", "aedasdsa2", "nada", "ppeepe");
    
    a.buscarDNI("aedasdsa2");

    return 0;
}
