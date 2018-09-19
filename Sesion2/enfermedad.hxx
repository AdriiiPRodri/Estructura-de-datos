enfermedad::enfermedad(){
  /**
  @brief Constructor por defecto de la clase enfermedad
  */
  this->name = "";
  this->ID = "";
  this->database = "";
}

enfermedad::enfermedad(const string & name, const string & ID, const string & database){
  /**
  @brief Constructor con parámetros, recibe todos los campos necesarios y inicializa con sus respectivos valores
  */
 this->name = name;
 this->ID = ID;
 this->database = database;
}

void enfermedad::setName(const string & name){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada name de la clase enfermedad.
  @param[in] string name
  */
  this->name = name;
}

void enfermedad::setID(const string & ID){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada ID de la clase enfermedad.
  @param[in] string ID
  */
  this->ID = ID;
}

void enfermedad::setDatabase(const string & database){
  /**
  @brief Método permitido para la edición y inicialización de la variable privada database de la clase enfermedad.
  @param[in] string database
  */
  this->database = database;
}

string enfermedad::getName( ) const{
  /**
  @brief Método consultor de la variable privada name, devuelve el mismo.
	@return Variable privada name
  */
  return this->name;
}

string enfermedad::getID( ) const{
  /**
  @brief Método consultor de la variable privada ID, devuelve el mismo.
  @return Variable privada ID
  */
  return this->ID;
}
string enfermedad::getDatabase( ) const{
  /**
  @brief Método consultor de la variable privada database, devuelve la mismo.
  @return Variable privada database
  */
  return this->database;
}

enfermedad & enfermedad::operator=(const enfermedad & e){
  /**
  @brief Operador sobrecargado =, este operador recibe como parámetro una enfermedad e iguala los campos de la primera enfermedad a los parámetros de la segunda enfermedad ---> e1 = e2
  e1 es la primera enfermedad y a la que se le asocian los campos de la segunda enfermedad la cual es e2
	@param[in]  e objeto enfermedad
  @return Objeto enfermedad inicial ya igualado al pasado por parámetro
	*/
  this->setName(e.getName());
  this->setID(e.getID());
  this->setDatabase(e.getDatabase());

  return *this;
}

string enfermedad::toString() const{
  /**
  @brief Método para mostrar en pantalla la informacion del objeto asociado a dicho método
	@return String con name , ID, database
	*/
  string out = getName() + "\t" + getID() + "\t" + getDatabase();

  return out;
}

bool enfermedad::operator==(const enfermedad & e) const{
  /**
  @brief Operador sobrecargado ==, este operador recibe como parámetro una enfermedad y comprueba que el campo ID de la misma sea el mismo que el ID de la enfermedad 1, es decir, comprueba si
  son la misma enfermedad.
	@param[in] e objeto enfermedad
	@return  En caso de ser iguales las enfermedades, devuelve true
	*/
  return getID() == e.getID();
}

bool enfermedad::operator!=(const enfermedad & e) const{
  /**
  @brief Operador sobrecargado !=, totalmente opuesto al anterior, compara el campo ID
  @param[in] e objeto enfermedad
	@return  En caso de ser distintas enfermedades, devuelve true
  */
  return getID() != e.getID();
}

bool enfermedad::operator<(const enfermedad & e) const{   //Orden alfabético por campo name.
  /**
  @brief Operador sobrecargado <, en este caso comparamos dos string correspondientes al campo name de cada enfermedad y nos dice si están almacenados por orden alfabético
  @param[in] e objeto enfermedad
	@return  En caso de estar odenadas devuelve true en otro caso false
  */
  return getName() < e.getName();
}

bool enfermedad::nameContains(const string& str) const{
  /**
  @brief método para comprobar si nuestra enfermedad contiene en la variable de tipo string una subcadena pasada por parámetro
  @param[in] String
	@return  En caso de contener la subcadena devuelve true
  */
  if(getName().find(str) == -1)
    return false;
  else
    return true;
}

ostream& operator<< ( ostream& os, const enfermedad & e){
  /**
  @brief método externo a la clase el cual nos sirve para mostrar toda la informacion de la enfermedad correspondiente, funciona en consonancia con el método toString()
  @param[in] e objeto enfermedad
	@return  Devuelve un flujo de salida con los datos de la enfermedad
  */
   os << e.toString();
   return os;
}
