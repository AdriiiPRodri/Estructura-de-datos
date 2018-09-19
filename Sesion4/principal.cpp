#include "mutacion.h"
#include "enfermedad.h"
#include "conjunto.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

	/** @brief lee un fichero de mutaciones, linea a linea
	@param[in] s nombre del fichero
  @param[in,out] cm objeto tipo conjunto sobre el que se almacenan las mutaciones
	@return true si la lectura ha sido correcta, false en caso contrario
	*/

/*bool load(conjunto &  cm, const string & s) {
 ifstream fe;
 string cadena;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail()){
   cerr << "Error al abrir el fichero " << s << endl;
 }
 else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{
      getline(fe,cadena,'\n');
    }while (cadena.find("#")==0 && !fe.eof());

    //leo la tabla de mutaciones, una línea cada vez
    while ( !fe.eof()){
        //cout << "leo:: "<< cadena << endl;
        // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
        mutacion mut = mutacion(cadena);
        // Insertar mutación en el conjunto
        cm.insert(mut);
        getline(fe,cadena,'\n');
    }
    //sort(cm.begin(), cm.end());
    fe.close();
    return true;
  } // else
  fe.close();
  return false;
 }
*/

int main(int argc, char *argv[]){
  /*pair<conjunto::value_type,bool> busq_aux;
  conjunto conjuntoMutaciones;
  string query_str;
  high_resolution_clock::time_point tantes,tdespues;
  duration<double> tiempo_transcurrido;
*/
  //for (int tama = 1; tama < 130000 ; tama+= 25000){
    //tantes = high_resolution_clock::now();
  //  load(conjuntoMutaciones, "clinvar_20160831.vcf");
    //tdespues = high_resolution_clock::now();
    //tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);

    //cout << tama << " " << tiempo_transcurrido.count() << endl;
  //}
  //Imprimir número de elementos almacenados en conjuntoMutaciones
  //cout << "Lectura del fichero finalizada. Mutaciones cargadas: "<<conjuntoMutaciones.size()<<endl;

  //Imprimir cuántas mutaciones están asociadas al cromosoma 1:
  //cout << "\nMutaciones asociadas a Chr 1: "<< conjuntoMutaciones.lower_bound("2", 1)-conjuntoMutaciones.begin()<< "\n\n";

  /**@todo ¿Existe la mutación con ID "rs147165522"? Imprimir la mutación y las enfermedades asociadas */
	/*cout << "Existe la mutacion con ID rs147165522?: \n";
	busq_aux= conjuntoMutaciones.find("rs147165522");
	if(busq_aux.second)
		cout << busq_aux.first;
	else
		cout << "No existe la mutacion.\n";
  */
  /**@todo ¿Existe la mutación en chr/pos "14"/67769578? Imprimir la mutación y las enfermedades asociadas */
	/*cout << "Existe la mutacion chr/pos 14/67769578?: \n";
	busq_aux= conjuntoMutaciones.find("14", 67769578);
	if(busq_aux.second)
		cout << busq_aux.first;
	else
		cout << "No existe la mutacion.\n";
  */
  /**@todo ¿Cómo podríamos calcular el número de mutaciones del cromosoma 3? (utiliza lower_bound / upper_bound) */
  //cout << "\nMutaciones asociadas a Chr 3: "<< conjuntoMutaciones.lower_bound("4", 1)-conjuntoMutaciones.upper_bound("3", 1)<< "\n\n";

  /**@todo Analiza la eficiencia teórica y empírica de las operaciones find, insert y erase */

/*  for (int tama = 1; tama < conjuntoMutaciones.size() ; tama+= 2000){
    tantes = high_resolution_clock::now();
    conjuntoMutaciones.erase("1", 6546, tama);
    tdespues = high_resolution_clock::now();
    tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);

    cout << tama << " " << tiempo_transcurrido.count() << endl;
  }
*/

conjunto<mutacion, ComparacionPorID> mutID;
load(mutID, "clinvar_20160831.vcf");
ComparacionPorID funtor;

if(funtor(mutID[i]))

  return 0;
}
