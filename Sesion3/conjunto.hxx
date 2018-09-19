/** @brief fichero de implementacion de la clase conjunto

*/

conjunto::conjunto(){

}

//CONSTRUCTOR COPIA
conjunto::conjunto(const conjunto& con){
   this->vm= con.vm;
   //size_type= con.size_type;
   //this->value_type= con.value_type;
}


//METODOS FIND
pair<conjunto::value_type,bool>  conjunto::find (const str & chr, const unsigned int & pos, int tama) const{
  pair<conjunto::value_type,bool> par;
  mutacion m;
  m.setChr(chr);
  m.setPos(pos);

  if(binary_search(this->cbegin(), this->cbegin() + tama, m)){
    par.first = m;
    par.second = true;
  }
  else{
    par.first = *vm.cend();
    par.second = false;
  }

  return par;
}

pair<conjunto::value_type,bool>  conjunto::find (const str & ID) const{
  pair<conjunto::value_type,bool> par;
  mutacion m;
  par.first = m;
  par.second = false;

  for(conjunto::const_iterator it = this->cbegin(); it < this->cend(); it++)
    if(it->getID() == ID){
      par.first = *it;
      par.second = true;
    }

  return par;
}

pair<conjunto::value_type,bool>  conjunto::find (const conjunto::value_type & e) const{
  pair<conjunto::value_type,bool> par;

  if(binary_search(this->cbegin(), this->cend(), e)){
    par.first = e;
    par.second = true;
  }
  else{
    par.first = *vm.cend();
    par.second = false;
  }

  return par;
}

//METODOS COUNT
conjunto::size_type conjunto::count (const str & chr, const unsigned int & pos) const{
  mutacion e;
  e.setChr(chr);
  e.setPos(pos);
  return binary_search(this->cbegin(), this->cend(), e);
}

conjunto::size_type conjunto::count (const str & ID) const{
  for(conjunto::const_iterator it = this->vm.cbegin(); it < this->vm.cend(); it++)
    return it->getID() == ID;
}

conjunto::size_type conjunto::count (const conjunto::value_type & e) const{
  return binary_search(this->cbegin(), this->cend(), e);
}

//METODO INSERT
bool conjunto::insert(const conjunto::value_type & e){
    char c;
    conjunto::const_iterator it=this->begin();

        if(this->size()>0){
            if(binary_search(this->begin(), this->end(), e) ){
                mutacion m(e);
                it= this->lower_bound(e);
                if(it->getID()==e.getID())
					          return 0;
            }
            if(e<*(this->vm.end()-1)){
                it= this->lower_bound(e);
                this->vm.insert(it, e);
            }
            else{
                this->vm.insert(this->end(), e);
            }
        }
        else
            this->vm.insert(it, e);

    return true;
}

//METODOS ERASE
bool conjunto::erase(const str & chr, const unsigned int & pos, int tama){
  for(conjunto::iterator it = this->begin(); it <= this->begin() + tama; it++)
    if(it->getChr() == chr && it->getPos() == pos){
      vm.erase(it);
      return true;
    }

    return false;
}

bool conjunto::erase(const string & ID){
  for(conjunto::iterator it = this->begin(); it <= this->end(); it++)
    if(it->getID() == ID){
      vm.erase(it);
      return true;
    }

    return false;
}

bool conjunto::erase(const conjunto::value_type & e){
  for(conjunto::iterator it = this->begin(); it <= this->end(); it++)
    if(*it == e){
      vm.erase(it);
      return true;
    }

    return false;
}

//METODO CLEAR
void conjunto::clear(){
   vm.clear();
}

//METODO SIZE
conjunto::size_type conjunto::size() const{
   return this->vm.size();
}


//METODO EMPTY
bool conjunto::empty() const{
   return !vm.size();
}

//OPERATOR =
conjunto& conjunto::operator=(const conjunto & org){
  this->vm = org.vm;                                  // Permitido en la clase vector de la STL

  return *this;
}

//METODO BEGIN
conjunto::iterator conjunto::begin(){
   return this->vm.begin();
}

//METODO CBEGIN
conjunto::const_iterator conjunto::cbegin() const{
   return this->vm.cbegin();
}

//METODO END
conjunto::iterator conjunto::end(){
   return this->vm.end();
}

//METODO CEND
conjunto::const_iterator conjunto::cend() const{
   return this->vm.cend();
}

//METODOS LOWER_BOUND
conjunto::const_iterator conjunto::lower_bound (const str & chr, const unsigned int & pos) const{
    conjunto::const_iterator it;
    mutacion m_aux;
    m_aux.setChr(chr);
    m_aux.setPos(pos);

    for(it=this->cbegin(); it!=this->cend(); it++){
        if(!(*it<m_aux))
            return it;
    }
    return this->cend();
}

conjunto::const_iterator conjunto::lower_bound (const conjunto::value_type & e) const{
    conjunto::const_iterator it;

    for(it=this->cbegin(); it!=this->cend(); it++){
        if(!(*it<e))
            return it;
    }
    return this->vm.cend();
}


//METODOS UPPER BOUND
conjunto::const_iterator conjunto::upper_bound (const str & chr, const unsigned int & pos) const{
    conjunto::const_iterator it;
    mutacion m_aux;
    m_aux.setChr(chr);
    m_aux.setPos(pos);

    for(it=this->cbegin(); it!=this->cend(); it++){
        //cout << *it;
        if(m_aux<*it)
            return it;
    }
    return this->vm.cend();
}

conjunto::const_iterator conjunto::upper_bound (const conjunto::value_type & e) const{
    conjunto::const_iterator it;

    for(it=this->cbegin(); it!=this->cend(); it++){
        //cout << *it;
        if(e<*it)
            return it;
    }
    return this->vm.cend();
}

//INVARIANTE DE REPRESENTACION
bool conjunto::cheq_rep() const{
  int i,j;
  bool encontrado=false;
  vector<string> val_chr={"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "X", "Y", "MT"};

  //Buscamos si el cromosoma coincide con alguno de los validos y si la posicion es mayor de cero
  for(i=0; i<vm.size(); i++){
      mutacion m_aux=vm[i];
      for(j=0; j<val_chr.size() && !encontrado; j++){
         if(m_aux.getChr()==val_chr[j])
            encontrado=true;
      }
      if(m_aux.getPos()<=0)
         return 0;
  }
  if(!encontrado)
      return 0;

  //Ahora comprobamos que estan todos en orden
  for(i=0; i<vm.size(); i++){
      for(j=0; j<val_chr.size()-1; j++){
         if(vm[i].getChr()==vm[i+1].getChr()){
            if(vm[i].getPos()>=vm[i+1].getPos())
               return 0;
         }
         else{
            if(vm[i].getChr() >= vm[i+1].getChr())
               return 0;
         }
      }
  }

  return true;
}


//OPEREADOR DE SALIDA SOBRECARGADO
ostream& operator<< (ostream& os, const conjunto& c){
   //Imprimir todo el conjunto de mutaciones

   for(conjunto::const_iterator it=c.cbegin(); it<c.cend(); it++){
      os << *it;
      if((it+1)!=c.cend())
         os << ", ";
   }
   os << "\n";

   return os;
}
