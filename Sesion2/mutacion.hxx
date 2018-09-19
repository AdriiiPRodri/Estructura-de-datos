mutacion::mutacion(){
  /** @brief Constructor por defecto de la clase mutación

  */
  ID = "";
  chr = "";
  pos = -1;
  ref_alt = vector<string>();
  genes = vector<string>();
  common = 0;
  caf = vector<float>();
  enfermedades = vector<enfermedad>();
  clnsig = vector<int>();
}

mutacion::mutacion(const mutacion& m){
  /**
  @brief Constructor copia, recibe recibe una mutación y crea una copia de esta
  */
 ID = m.getID();
 chr = m.getChr();
 pos = m.getPos();
 ref_alt = m.getRef_alt();
 genes = m.getGenes();
 common = m.getCommon();
 caf = m.getCaf();
 enfermedades = m.getEnfermedades();
 clnsig = m.getClnsig();
}

mutacion::mutacion(const string& str){
  /**
  @brief Constructor a traves de un string, recibe recibe una cadena con toda la información y crea un objeto a raíz de esta
  @param[in] string str
  */
   char p;
   int pos_i=0, pos_f=0, aux_int=0, i=0;
   string aux_str, aux_str2;
   float fl;

   /*Numero de cromosoma*/
   pos_f= str.find('\t');

   aux_str= str.substr(0, pos_f);
   this->chr= aux_str;

   /*Posicion*/
   pos_i= pos_f+1;
   pos_f= str.find('\t', pos_i);
   aux_int= atoi(str.substr(pos_i, pos_f-pos_i).c_str());
   this->pos=aux_int;

   /*ID*/
   pos_i= pos_f+1;
   pos_f= str.find('\t', pos_i);
   aux_str= str.substr(pos_i, pos_f-pos_i);
   this->ID= aux_str;

   /*ref*/
   pos_i= pos_f+1;
   pos_f= str.find('\t', pos_i);
   aux_str= str.substr(pos_i, pos_f-pos_i);
   mutacion::ref_alt.push_back(aux_str);

   /*alt*/
   pos_i= pos_f+1;
   pos_f= str.find('\t', pos_i);
   aux_str= str.substr(pos_i, pos_f-pos_i);

      pos_f= aux_str.find(',', 0);
      if(pos_f != -1){
         pos_i= 0;
         do{
            aux_str2= aux_str.substr(pos_i, pos_f-pos_i);
            pos_i= pos_f+1;
            this->ref_alt.push_back(aux_str2);
            pos_f= aux_str.find(',', pos_i);
         }while(pos_f != -1);

         aux_str2= aux_str.substr(pos_i, aux_str.size()-pos_i);
         this->ref_alt.push_back(aux_str2);
      }
      else{
         aux_str2= aux_str.substr(0, aux_str.size());
         this->ref_alt.push_back(aux_str2);
      }



   /*INFORMACION DE CADA MUTACION*/
   /*genes*/
   pos_i= pos_f+1;
   pos_i= str.find("GENEINFO=");
   if(pos_i!=-1){
      pos_i+=9;
      pos_f= str.find(';', pos_i);
      aux_str= str.substr(pos_i, pos_f-pos_i);
   }
   else
      aux_str= "";

   mutacion::genes.push_back(aux_str);

   /*CAF*/
   pos_i= str.find("CAF=");
   if(pos_i!=-1){
      pos_i+=4;
      pos_f= str.find(';', pos_i);
      aux_str= str.substr(pos_i, pos_f+1-pos_i);
   }
   else
      aux_str= "";

   //Separamos los posibles campos de caf
   if(!aux_str.empty()){
      pos_f= aux_str.find(',', 0);
      if(pos_f != -1){
         pos_i=0;
         do{
            aux_str2= aux_str.substr(pos_i, pos_f);
            pos_i= pos_f+1;
            fl=strtof(aux_str2.c_str(), 0);
            this->caf.push_back(fl);
            pos_f= aux_str.find(',', pos_i);
         }while(pos_f != -1);

         aux_str2= aux_str.substr(pos_i, aux_str.size()-1);
         fl=strtof(aux_str2.c_str(), 0);
         this->caf.push_back(fl);
      }
   }


   /*COMMON*/
pos_i= str.find("COMMON=");
   if(pos_i!=-1){
      pos_i+=7;
      aux_str= str.substr(pos_i, 1);
      mutacion::common=aux_str.c_str();
   }
   else
      mutacion::common= false;


   /*ENFERMEDADES*/
   /*Dentro de la clase mutacion todavia, almacenamos en el vector clnsig*/
   pos_i= str.find("CLNSIG=")+7;
   pos_f= str.find(';', pos_i);
   aux_str= str.substr(pos_i, pos_f-pos_i);

   //Separamos todos los campos posibles de clnsig y los metemos en el vector

   pos_f= aux_str.find('|', 0);
   if(pos_f == -1)
      pos_f= aux_str.find(',', 0);
   if(pos_f != -1){
      pos_i=0;
      do{
         aux_str2= aux_str.substr(pos_i, pos_f);
         pos_i= pos_f+1;
         aux_int=atoi(aux_str2.c_str());
         this->clnsig.push_back(aux_int);
         pos_f= aux_str.find('|', pos_i);
         if(pos_f == -1)
            pos_f= aux_str.find(',', pos_i);
      }while(pos_f != -1);

      aux_str2= aux_str.substr(pos_i, aux_str.size());
      aux_int=atoi(aux_str2.c_str());
      this->clnsig.push_back(aux_int);
   }
   else{
      aux_int=atoi(aux_str.c_str());
      this->clnsig.push_back(aux_int);
   }


   enfermedad aux_e;   //creamos enfermedad

   //Nombre de la enfermedad//
   pos_i= str.find("CLNDBN=")+7;
   pos_f= str.find(';', pos_i);
   aux_str= str.substr(pos_i, pos_f-pos_i);

   //separamos cada posible campo de clndbn(nombre enfermedad)
   pos_f= aux_str.find('|', 0);
   if(pos_f == -1)
      pos_f= aux_str.find(',', 0);
   if(pos_f != -1){
      pos_i=0;
      do{
         aux_str2= aux_str.substr(pos_i, pos_f-pos_i);
         pos_i= pos_f+1;
         aux_e.setName(aux_str2);
         this->enfermedades.push_back(aux_e);
         pos_f= aux_str.find('|', pos_i);
         if(pos_f == -1)
            pos_f= aux_str.find(',', pos_i);
      }while(pos_f != -1);

      aux_str2= aux_str.substr(pos_i, aux_str.size());
      aux_e.setName(aux_str2);
      this->enfermedades.push_back(aux_e);
   }
   else{
      aux_e.setName(aux_str);
      this->enfermedades.push_back(aux_e);
   }

   //Tenemos ya el nº de enfermedades con sus nombres en el vector, falta añadir sus ID y sus bases de datos.///

   //ID de la enfermedad//
   pos_i= str.find("CLNDSDBID=")+10;
   pos_f= str.find(';', pos_i);
   aux_str= str.substr(pos_i, pos_f-pos_i);

   pos_f= aux_str.find('|', 0);
   if(pos_f == -1)
      pos_f= aux_str.find(',', 0);
   if(pos_f != -1){
      pos_i=0;
      for(i=0; i<this->enfermedades.size()-1 && pos_f != -1; i++){
         aux_str2= aux_str.substr(pos_i, pos_f-pos_i);
         pos_i= pos_f+1;
         enfermedades[i].setID(aux_str2);
         pos_f= aux_str.find('|', pos_i);
         if(pos_f == -1)
            pos_f= aux_str.find(',', pos_i);
      }
      aux_str2= aux_str.substr(pos_i, aux_str.size());
      enfermedades[i].setID(aux_str2);
   }
   else
      enfermedades[0].setID(aux_str);


   //Base de datos de la enfermedad//
   pos_i= str.find("CLNDSDB=")+8;
   pos_f= str.find(';', pos_i);
   aux_str= str.substr(pos_i, pos_f-pos_i);

   pos_f= aux_str.find('|', 0);
   if(pos_f == -1)
      pos_f= aux_str.find(',', 0);
   if(pos_f != -1){
      pos_i=0;
      for(i=0; i<this->enfermedades.size()-1 && pos_f != -1; i++){
         aux_str2= aux_str.substr(pos_i, pos_f-pos_i);
         pos_i= pos_f+1;
         enfermedades[i].setDatabase(aux_str2);
         pos_f= aux_str.find('|', pos_i);
         if(pos_f == -1)
            pos_f= aux_str.find(',', pos_i);
      }
      aux_str2= aux_str.substr(pos_i, aux_str.size());
      enfermedades[i].setDatabase(aux_str2);
   }
   else
      enfermedades[0].setDatabase(aux_str);
}


void mutacion::setID(const string & ID){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada ID de la clase mutación.
  @param[in] string ID
  */
  this->ID = ID;
}

void mutacion::setChr(const string & chr){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada chr de la clase mutacion.
  @param[in] string chr
  */
  this->chr = chr;
}

void mutacion::setPos(const unsigned int & pos){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada pos de la clase mutacion.
  @param[in] unsigned int pos
  */
  this->pos = pos;
}

void mutacion::setRef_alt(const std::vector<string> & ref_alt){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada ref_alt de la clase mutación.
  @param[in] vector<string> ref_alt
  */
  this->ref_alt = ref_alt;
}

void mutacion::setGenes(const std::vector<string> & genes){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada genes de la clase mutación.
  @param[in] vector<string> genes
  */
  this->genes = genes;
}

void mutacion::setCommon(const bool & common){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada common de la clase mutación.
  @param[in] bool common
  */
  this->common = common;
}

void mutacion::setCaf(const std::vector<float> & caf){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada caf de la clase mutación.
  @param[in] vector<float> caf
  */
  this->caf = caf;
}

void mutacion::setEnfermedades(const std::vector<enfermedad> & enfermedades){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada enfermedades de la clase mutación.
  @param[in] vector<enfermedad> enfermedades
  */
  this->enfermedades = enfermedades;
}

void mutacion::setClnsig(const std::vector<int> & clnsig){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada clnsig de la clase mutación.
  @param[in] vector<int> clnsig
  */
  this->clnsig = clnsig;
}

string mutacion::getID( ) const{
  /**
  @brief Método consultor de la variable privada ID, devuelve el mismo.
	@return Variable privada ID
  */
  return ID;
}

string mutacion::getChr( ) const{
  /**
  @brief Método consultor de la variable privada chr, devuelve el mismo.
	@return Variable privada chr
  */
  return chr;
}

unsigned int mutacion::getPos( ) const{
  /**
  @brief Método consultor de la variable privada pos, devuelve la misma.
	@return Variable privada pos
  */
  return pos;
}

const std::vector<string> & mutacion::getRef_alt () const{
  /**
  @brief Método consultor de la variable privada ref_alt, devuelve el mismo.
	@return Variable privada ref_alt
  */
  return ref_alt;
}

const std::vector<string> & mutacion::getGenes () const{
  /**
  @brief Método consultor de la variable privada genes, devuelve los mismos.
	@return Variable privada genes
  */
  return genes;
}

bool mutacion::getCommon () const{
  /**
  @brief Método consultor de la variable privada common, devuelve el mismo.
	@return Variable privada common
  */
  return common;
}

const std::vector<float> & mutacion::getCaf () const{
  /**
  @brief Método consultor de la variable privada caf, devuelve los mismos.
	@return Variable privada caf
  */
  return caf;
}

const std::vector<enfermedad> & mutacion::getEnfermedades () const{
  /**
  @brief Método consultor de la variable privada enfermedades, devuelve las mismas.
	@return Variable privada enfermedades
  */
  return enfermedades;
}

const std::vector<int> & mutacion::getClnsig () const{
  /**
  @brief Método consultor de la variable privada clnsig, devuelve el mismo.
	@return Variable privada clnsig
  */
  return clnsig;
}

mutacion & mutacion::operator=(const mutacion & m){
  /**
  @brief Operador sobrecargado =, este operador recibe como parámetro una mutación m iguala los campos de la primera mutación a los parámetros de la segunda mutación ---> m1 = m2
  m1 es la primera mutación y a la que se le asocian los campos de la segunda mutación la cual es m2
	@param[in]  m objeto mutación
  @return Objeto mutación inicial ya igualado al pasado por parámetro
	*/
  this->setID(m.getID());
  this->setChr(m.getChr());
  this->setPos(m.getPos());
  this->setRef_alt(m.getRef_alt());
  this->setGenes(m.getGenes());
  this->setCommon(m.getCommon());
  this->setCaf(m.getCaf());
  this->setEnfermedades(m.getEnfermedades());
  this->setClnsig(m.getClnsig());

  return *this;
}

bool mutacion::operator==(const mutacion & m) const{
  /**
  @brief Operador sobrecargado ==, este operador recibe como parámetro una mutacion y comprueba que el campo ID de la misma sea el mismo que el ID de la mutacion 1, es decir, comprueba si
  son la misma mutacion
	@param[in]  m objeto mutación
  @return true en caso de ser la misma enfermedad, false en el contrario
	*/
  if (getID() == m.getID())
    return true;
  else
    return false;
}

bool mutacion::operator<(const mutacion & m) const{
  /**
  @brief Operador sobrecargado <, en este caso comparamos dos string correspondientes al campo chr de cada mutacion y nos dice si están almacenados por orden, según el criterio de cromososa
  y según el criterio de pos, este segundo en caso de que el primero no nos aclare las dudas
	@param[in]  m objeto mutación
  @return true en caso de estar ordenadas, false en el contrario
	*/
  if(getChr() < m.getChr())
    return true;
  else if(getChr() > m.getChr())
    return false;
  else
    if(getPos() < m.getPos())
      return true;
    else
      return false;
}     //El orden viene determinado por Chr y pos. El primer criterio es el número de cromosoma. El orden para el número de cromosoma se rige por "1"<"2"<"3"<->->-><"22"<"X"<"Y"<"MT". Dos mutaciones del mismo cromosoma deben ordenarse según su posición, de menor posición a mayor (orden natural de enteros)->


ostream& operator<< ( ostream& os, const mutacion& mutacion){
  /**
  @brief método externo a la clase el cual nos sirve para mostrar toda la informacion de la mutación correspondiente
  @param[in] m objeto mutacion
	@return  Devuelve toda la información desglosada del objeto pasado por parámetro
  */
  os << "\nID = " << mutacion.getID() << endl;
  os << "n_CHR = " << mutacion.getChr() << endl;
  os << "Posición = " << mutacion.getPos() << endl;
  os << "Base_afectada = " << mutacion.getRef_alt()[0] << endl;
  os << "Bases_cambiantes = " << mutacion.getRef_alt()[1] << endl;
  os << "Genes_afectados = " << mutacion.getGenes()[0] << endl;
  for(int i = 1; i < mutacion.getGenes().size(); i++)
    os << ", " <<mutacion.getGenes()[i];

  os << "Probabilidad = " << mutacion.getCommon() << endl;
  /*os << "CAF = " << mutacion.getCaf()[0];
  for(int i = 1; i < mutacion.getCaf().size(); i++)
    os << ", " << mutacion.getCaf()[i];

  os << "\nNombre_enfermedad = " << mutacion.getEnfermedades()[0].getName();
  for(int i = 1; i < mutacion.getEnfermedades().size(); i++)
    os << ", " << mutacion.getEnfermedades()[i].getName();
  os << "\nID_enfermedad = " << mutacion.getEnfermedades()[0].getID();
  for(int i = 1; i < mutacion.getEnfermedades().size(); i++)
    os << ", " << mutacion.getEnfermedades()[i].getID();
  os << "\nDatabase = " << mutacion.getEnfermedades()[0].getDatabase();
  for(int i = 1; i < mutacion.getEnfermedades().size(); i++)
    os << ", " << mutacion.getEnfermedades()[i].getDatabase();
  os << "\nCLNSIG = [" << mutacion.getClnsig()[0];
  for(int i = 1; i < mutacion.getClnsig().size(); i++)
    os << ", " << mutacion.getClnsig()[i];
  os << "]" << endl;*/

  return os;
}   //Imprimir TODOS los campos del objeto mutación->
