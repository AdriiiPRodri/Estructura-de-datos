/*
 * enfermedad.h
 *
 * Copyright  (C) Juan F. Huete y Carlos Cano
*/
#ifndef __ENFERMEDAD_H
#define __ENFERMEDAD_H

#include <string>
#include <iostream>

using namespace std;


//! Clase enfermedad, asociada al TDA enfermedad
/*! enfermedad::enfermedad,  .....
 * Descripción contiene toda la información asociada a una enfermedad almacenada en la BD ClinVar-dbSNP (nombre de la enfermedad, id, BD que provee el id)
*/

class enfermedad {
private:
  string  name;       /** \brief variable que contiene el nombre de la enfermedad */
  string  ID;         /** \brief variable que contiene el ID correspondiente a la enfermedad */
  string  database;   /** \brief variable que contine la base de datos correspondiente a la enfermedad */

public:

 enfermedad (); //Constructor de enfermedad por defecto
 enfermedad (const string & name, const string & ID, const string & database);

 void setName(const string & name);
 void setID(const string & ID);
 void setDatabase(const string & database);

 string getName( ) const;
 string getID( ) const;
 string getDatabase( ) const;

 enfermedad & operator=(const enfermedad & e);
 string toString() const;

// Operadores relacionales
 bool operator==(const enfermedad & e) const;
 bool operator!=(const enfermedad & e) const;
 bool operator<(const enfermedad & e) const;	//Orden alfabético por campo name.

 bool nameContains(const string & str) const;   //Devuelve True si str está incluido en el nombre de la enfermedad, aunque no se trate del nombre completo. No debe ser sensible a mayúsculas/minúsculas.

};

 ostream& operator<< ( ostream& os, const enfermedad & e); //imprime enfermedad (con TODOS sus campos)

#include "enfermedad.hxx" // Incluimos la implementacion.


#endif
