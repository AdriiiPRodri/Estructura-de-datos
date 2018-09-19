/** @brief fichero de implementacion de la clase conjunto

*/
template <typename T, typename CMP>
conjunto<T,CMP>::conjunto(){

}

//CONSTRUCTOR COPIA
template <typename T, typename CMP>
conjunto<T,CMP>::conjunto(const conjunto<T,CMP> & d){
   this->vm= d.vm;
   this->cmp = d.comp;
}


//METODOS FIND
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::find (const typename conjunto<T,CMP>::value_type & s){
  if(binary_search(this->begin(), this->end(), s))
      return s;

  return this->end();
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::find (const typename conjunto<T,CMP>::value_type & s) const{
  if(binary_search(this->cbegin(), this->cend(), s))
      return s;

  return this->cend();
}

//METODO COUNT
template <typename T, typename CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::count (const typename conjunto<T,CMP>::value_type & e) const{
  return binary_search(this->cbegin(), this->cend(), e);
}

//METODOS INSERT
template <typename T, typename CMP>

pair<typename conjunto<T,CMP>::iterator,bool> conjunto<T,CMP>::insert( const T & c){
  pair<typename conjunto<T,CMP>::iterator,bool> salida;
  bool fin = false;
  for (auto it = vm.begin(); it!=vm.end() && !fin; ){
    if (comp(*it,c) )
      it++;
    else if (!comp(*it,c) && !comp(c,*it)){ // equivalentes segun CMP
      salida.first = vm.end();
      salida.second = false;
      fin = true;
    }else {
      salida.first = vm.insert(it,c);
      salida.second = fin = true;
    }
  } // del for
  if (!fin){
    salida.first = vm.insert(vm.end(),c);
    salida.second = true;
  }
  return salida;
}

//METODOS ERASE
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::erase (const typename conjunto<T,CMP>::iterator position){

    if(binary_search(this->begin(), this->end(), position) ){
        vm.erase(position);
        return 1 + position;
    }

    return this->end();
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::erase (const typename conjunto<T,CMP>::value_type& val){
  for(typename conjunto<T,CMP>::iterator it = this->begin(); it <= this->end(); it++)
    if(*it == val){
      vm.erase(it);
      return 1 + it;
    }

    return this->end();
}

//METODO CLEAR
template <typename T, typename CMP>
void conjunto<T,CMP>::clear(){
   vm.clear();
}

//METODO SIZE
template <typename T, typename CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::size() const{
   return this->vm.size();
}


//METODO EMPTY
template <typename T, typename CMP>
bool conjunto<T,CMP>::empty() const{
   return !vm.size();
}

//OPERATOR =
template <typename T, typename CMP>
conjunto<T,CMP>& conjunto<T,CMP>::operator=(const conjunto & org){
  this->vm = org.vm;                                  // Permitido en la clase vector de la STL

  return *this;
}

//METODO BEGIN
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::begin(){
   return this->vm.begin();
}

//METODO CBEGIN
template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cbegin() const{
   return this->vm.cbegin();
}

//METODO END
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::end(){
   return this->vm.end();
}

//METODO CEND
template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cend() const{
   return this->vm.cend();
}

//METODOS LOWER_BOUND
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::lower_bound (const typename conjunto<T,CMP>::value_type& val){
  typename conjunto<T,CMP>::iterator it;

  for(it=this->begin(); it!=this->end(); it++){
      if(!(*it<val))
          return it;
  }
  return this->vm.end();
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::lower_bound (const typename conjunto<T,CMP>::value_type & val) const{
    typename conjunto<T,CMP>::const_iterator it;

    for(it=this->cbegin(); it!=this->cend(); it++){
        if(!(*it<val))
            return it;
    }
    return this->vm.cend();
}


//METODOS UPPER BOUND
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::upper_bound (const typename conjunto<T,CMP>::value_type& val){
  typename conjunto<T,CMP>::const_iterator it;

  for(it=this->begin(); it!=this->end(); it++){
      if(val<*it)
          return it;
  }
  return this->vm.end();
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::upper_bound (const typename conjunto<T,CMP>::value_type & val) const{
    typename conjunto<T,CMP>::const_iterator it;

    for(it=this->cbegin(); it!=this->cend(); it++){
        if(val<*it)
            return it;
    }
    return this->vm.cend();
}

//INVARIANTE DE REPRESENTACION
template <typename T, typename CMP>
bool conjunto<T,CMP>::cheq_rep() const{
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
template <typename T, typename CMP>
ostream& operator<< (ostream& os, const conjunto<T,CMP>& c){
   //Imprimir todo el conjunto de mutaciones

   for(typename conjunto<T,CMP>::const_iterator it=c.cbegin(); it<c.cend(); it++){
      os << *it;
      if((it+1)!=c.cend())
         os << ", ";
   }
   os << "\n";

   return os;
}
