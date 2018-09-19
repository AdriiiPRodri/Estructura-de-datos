#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class vdisperso{
    public:
        vdisperso(){
            n=0;
        }
        
        vdisperso(const vector<T> $v){
        }
        
        void asignar_coeficiente(int i, const T &x){
            bool setted=false;
            
            typename list<pair<int, T> >::iterator it=coefs.begin();
            
            if(x==0)
                return;
            
            if(n==0){
                coefs.push_back(pair<int,T>(i,x));
            }
            
            while(it != coefs.end() && !setted){
                if(it->first==i){
                    it->second=x;
                    
                    setted=true;
                }
                else if(it != coefs.end() && it->first > i){
                    coefs.insert(it, pair<int,T>(i, x));
                    setted=true;
                    
                }
                    
                if(!setted)
                    coefs.push_back(pair<int,T>(i, x));
                
            }
            n++;
        }
        
        vector<T> convertir() const{
            int pos=0;
            vector<T> dev;//=vector<T>(coefs.begin()->first);
            typename list<pair<int,T> >::const_iterator it=coefs.begin();
            
            while(it != coefs.end() || pos < (coefs.end()--)->first){
                if(pos==it->first && it != coefs.end()){
                    dev.push_back(it->second);
                    it++;
                    pos++;
                }
                else{
                    dev.push_back(0);
                    pos++;
                }
            }
            
            return dev;
        }
        
        
        
        void imprimir(){
            cout << "Vector disperso: " << endl;
            for(typename list<pair<int, T> >::iterator it=coefs.begin(); it != coefs.end(); it++){
                cout << (*it).first << ": " << (*it).second << endl;
            }
        }
        
        
        private:
            list< pair<int, T> > coefs;
            int n;
};

int main(int argc, char** argv) {
    vector<int> prueba;
    vdisperso<int> vdisp;
    
    vdisp.asignar_coeficiente(5, 2);
    vdisp.asignar_coeficiente(2, 1);
    vdisp.asignar_coeficiente(1, 6);
    
    vdisp.imprimir();
    
    prueba= vdisp.convertir();

    cout << endl;
    for(int i=0; i<prueba.size(); i++){
        cout << i << ": " << prueba[i] << endl;
    }
    
    return 0;
}

