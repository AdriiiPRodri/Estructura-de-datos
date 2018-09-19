#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class vdinamico{
    public:
        vdinamico(){
            n = 0;
        }

        vdinamico(const vdinamico& v){
            n = v.size();
            coefs = v.getCoefs();
        }

        void push_back(T i){
            n++;
            coefs.push_back(i);
        }

        list< pair<int, T> > getCoefs() const{
            return coefs;
        }

        int size() const{
            return coefs.size();
        }

        T operator[](int i) const{
            if(i >= 0 && i < size()){
                typename list< T >::const_iterator it = coefs.begin();
                for(int j = 0; j < i; j++)
                    it++;
                return *it;
            }

        }

        void remove(const T& i){
            coefs.remove(i);
            n = coefs.size();
        }

        void resize(int nuevo){
            n = nuevo;
            coefs.resize(n);
        }

        vdinamico& operator=(const vdinamico& original){
            n = original.size();
            coefs = original.getCoefs();
        }

        private:
            list< T > coefs;
            int n;
};

int main(int argc, char** argv) {
    vdinamico<int> a;

    a.push_back(4);
    a.push_back(7);
    a.remove(4);

    for(int i = 0; i < a.size(); i++)
        cout << a[i] << endl << flush;

    return 0;
}
