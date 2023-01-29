#include <array>
#include <iomanip>    // quoted()
#include <iostream>
#include <locale>
#include <memory>
#include <string>    // string,  to_string()
#include <string_view>
#include <stdexcept> 

#include "Stack.hpp"
//#include "Crow.hpp"





template <typename T>
Stack<T>::Stack( const unsigned int & capacity)
: _capacity(capacity), _size(0), _array(std::make_unique<T[]>(capacity) )
{}


template <typename T>
Stack<T>::Stack            ( const Stack & original )                                                                 // copy constructor
: _capacity( original._capacity ), _size( original._size ), _array( std::make_unique<T[]> (original._capacity ) )

{
  for ( std::size_t i=0; i < _size; ++i )
  {
    _array[i] = original._array[i];
  }
}

template <typename T>
Stack<T> & Stack<T>::operator=( const Stack & rhs      )                                                               // copy assignment operator
{
  _capacity = rhs._capacity;
  _size     = rhs._size;
  _array    = std::make_unique<T[]> (rhs._capacity);



  for( std::size_t i=0; i < _size; ++i )
  {
    _array[i] = rhs._array[i];
  }
  return *this;
}

template <typename T>
Stack<T>::~Stack()
{}


template <typename T>
T & Stack<T>::top() const
{
  if(_size == 0) 
  {
    throw std::runtime_error("stack is empty");

    return _array[_size-1];
  
  }
    
}

template <typename T>
unsigned Stack<T>::capacity() const
{ return _capacity; }

template <typename T>
unsigned Stack<T>::size() const
{ return _size; }




template <typename T>
void Stack<T>::push(const T & Crow)
{
  if(_size >= _capacity)
  {
    _capacity+=10;
    std::unique_ptr<Crow[]> _biggerArray = std::make_unique<T[]>(_capacity);

    for(std::size_t i =0; i<_size; ++i)
    {
      _biggerArray[i] = _array[i];
    }
      _array=std::move(_biggerArray);
  }
  _array[_size] = Crow;
  ++_size;
}





template <typename T>
void Stack<T>::pop()
{
  if(_size == 0)  Throw std::underflow_error( "Attempted to remove element from an empty stack" );
  

    --_size;
  
  
    if( _size + 10 < _capacity)
    {
      _capacity-=10;
      std::unique_ptr<T[]> _smallerArray = std::make_unique<T[]>(_capacity);
      for(std::size_t i=0; i<_size; ++i)
      {
        _smallerArray[i] = _array[i];
      }
      _array = std::move(_smallerArray);
    }
  }


