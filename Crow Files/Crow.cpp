#include <array>
#include <iomanip>    // quoted()
#include <iostream>
#include <locale>
#include <random>
#include <string>    // string,  to_string()
#include <string_view>
#include "Address.hpp"
#include "Crow.hpp"



   namespace   // unnamed, anonymous namespace
   {
     std::random_device  seed;
     std:: default_random_engine my_engine( seed());


     Gender random_gender()
     {
       static std::uniform_int_distribution<unsigned> randomSelected(0, 1);
       return randomSelected( my_engine ) ==0 ? Gender::Boy : Gender::Girl;
     }
   }


/***********************************************************************************************************************************
** Constructors, destructor and assignment operators
***********************************************************************************************************************************/


Crow & Crow::operator=(const Crow & rhs)      = default;
Crow::Crow            (const Crow & original)

{
  std::cout << "Copying " << &original << " to " << this << '\n';  //copying message
}

Crow::~Crow()                                                     //default constructor
{std::cout << "Destroying object " << this <<'\n';}               //destroying message




Crow::Crow()
: _gender( random_gender() ),
  _id ( nextAvailableID++  ),
  _name ( std::string(" Luna ") + ( _gender == Gender::Boy ? "Boy " : "Girl ") + std::to_string( _id) )

  {
    std::cout << "Constructing " << this <<'\n';                //constructing message
  }




Crow::Crow(std::string name)
: _gender( random_gender() ),
  _id    ( nextAvailableID++ ),
  _name  ( name )

  {
    std::cout << "Constructing " << this <<'\n';              //constructing message
  }


/***********************************************************************************************************************************
** Queries
***********************************************************************************************************************************/

std::string Crow::name() const
{ return _name; }


Gender Crow::gender() const
{return _gender; }


std::size_t Crow::id() const
{ return _id; }



void  Crow::talk()
{std::cout << "Caw! My name is Luna!\n";}


void   Crow::sing()
{std::cout << "Caw caw! I'm a singing crow!\n";}


void   Crow::fetch()
{std::cout << "Luna goes to fetch the toy.\n";}


int   Crow::hop()
{
  int tilesHopped=0;
  unsigned ourGenNum;
      std::random_device random;
      std::mt19937 generated(random());
      std::uniform_int_distribution<unsigned> numberGen(1,100);
  ourGenNum = numberGen(generated);

  if ((ourGenNum >= 1)&&(ourGenNum <= 10))
  {tilesHopped = 3;}                                   //10% Forward 3 squares ( e.g., return 3)

  else if ((ourGenNum >= 11)&&(ourGenNum <= 40))
  {tilesHopped = 1;}                                   //30% Forward 1 square

  else if ((ourGenNum >= 41)&&(ourGenNum <= 55))
  {tilesHopped = -1;}                                  //15% Back 1 square

  else if ((ourGenNum >= 56)&&(ourGenNum <= 65))
  {tilesHopped = -2;}                                 //10% Back 2 squares

  else if ((ourGenNum >= 66)&&(ourGenNum <= 100))
  {tilesHopped = 0;}                                 //35% ignore and dont move

 return   tilesHopped;
}



/***********************************************************************************************************************************
** Mutators
***********************************************************************************************************************************/


// Updates the Crow's name
Crow & Crow::name( std::string newName )
{
  _name = newName;
  return *this;
}



/***********************************************************************************************************************************
** Relational Operators
***********************************************************************************************************************************/

bool operator<( const Crow & lhs, const Crow & rhs )
{
  if( lhs._name   != rhs._name   )   return lhs._name   < rhs._name ;    // if name is different you have your answer, otherwise if they're the same then you have your answer
  if( lhs._gender != rhs._gender )   return lhs._gender < rhs._gender;   // if gender is different you have your answer, otherwise if they're the same then
  else                               return lhs._id  < rhs._id;          // you have your answer
}

bool operator==( const Crow & lhs, const Crow & rhs )
{
  return lhs._name    == rhs._name
      && lhs._gender  == rhs._gender
      && lhs._id      == rhs._id;}
bool operator!=( const Crow & lhs, const Crow & rhs )   { return !( lhs == rhs ); }
bool operator<=( const Crow & lhs, const Crow & rhs )   { return !( rhs <  lhs ); }
bool operator> ( const Crow & lhs, const Crow & rhs )   { return  ( rhs <  lhs ); }
bool operator>=( const Crow & lhs, const Crow & rhs )   { return !( lhs <  rhs ); }




/***********************************************************************************************************************************
** Insertion (write) and extraction (read) symmetrical operators
**   Format:    Boy or Girl
***********************************************************************************************************************************/

std::ostream & operator<<( std::ostream & outputStream, const Crow & crow )
{
  outputStream << crow._id                  << ", "
               << std::quoted( crow._name ) << ", "
               << crow._gender              << ", ";
  return outputStream;
}

std::istream & operator>>( std::istream & inputStream, Crow & crow )
{
  Crow workingCopy;
  char delimiter = '\0';

  inputStream >>             workingCopy._id     >> delimiter
              >> std::quoted(workingCopy._name)  >> delimiter
              >>             workingCopy._gender >> delimiter;
  if( inputStream ) crow = workingCopy;
  return inputStream;
}


std::ostream & operator<<( std::ostream & s, const Gender & gender )
{ return s << (gender == Gender::Boy ? "Boy" : "Girl"); }


std::istream & operator>>( std::istream & s, Gender & gender )
{
  std::string token;
  s >> token;

  static std::locale locale;
  for( auto & c : token ) c = std::tolower( c, locale );

  if     ( token == "boy"  ) gender = Gender::Boy;
  else if( token == "girl" ) gender = Gender::Girl;
  else                       s.setstate( std::ios_base::failbit );

  return s;
}
