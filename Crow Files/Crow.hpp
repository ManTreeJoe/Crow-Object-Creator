#pragma once

#include <cstddef>        // size_t
#include <iostream>       // istream, ostream
#include <string>         // string
#include <string_view>    // string_view



enum class Gender {Boy, Girl};
std::ostream & operator<<( std::ostream & s, const Gender & gender );
std::istream & operator>>( std::istream & s,       Gender & gender );




class Crow
{
  friend std::ostream & operator<<( std::ostream & outputStream, const Crow & crow );
  friend std::istream & operator>>( std::istream & inputStream, Crow & crow );

  // Relational operators need access to private members
  friend bool operator==( const Crow & lhs, const Crow & rhs );
  friend bool operator< ( const Crow & lhs, const Crow & rhs );




public:
  Crow ();                                               //initializes the crow's name as "Luna"
  Crow (std::string CrowName);

  Crow        ( const Crow & original );                 // Copy Constructor
  Crow & operator=( const Crow & rhs  );                 // Copy Assignment operators
  ~Crow();                                               // Destructor


//Queries

std::string name   () const;                            //Returns the crow's name
Gender gender      () const;                            //Returns the crow's gender
std::size_t id     () const;


//Mutators

Crow & name( std::string newName  );                   //Updates the crow's name

Gender gender_roll();


//Actions

void    talk();                                        // returns "Caw! My name is Luna!"
void    sing();                                        // sings "Caw caw! I'm a singing crow!"
void   fetch();                                        // returns "Luna goes to fetch the toy."
int      hop();                                        // crow's hopping sequence



private:
  std::string           _name;
  Gender                _gender = Gender::Boy;
  std::size_t           _id = 0;



//Class attributes

inline static std::size_t nextAvailableID = 1'350'001;


};

 bool operator==( const Crow & lhs, const Crow & rhs );
 bool operator!=( const Crow & lhs, const Crow & rhs );
 bool operator< ( const Crow & lhs, const Crow & rhs );
 bool operator<=( const Crow & lhs, const Crow & rhs );
 bool operator> ( const Crow & lhs, const Crow & rhs );
 bool operator>=( const Crow & lhs, const Crow & rhs );
