#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <array>
#include <cstddef>   // size_t
#include <string_view>

//#include "Crow.hpp"


template <typename T>
class Stack



{

    public:

       Stack            ( const unsigned int & capacity = 0);                          //default constructor

       Stack            (const  Stack & original);                                   //copy constructor
       Stack & operator=(const Stack & rhs);                                        //copy assignment operator
      ~Stack();                                                                    //destructor

      T & top()               const;
      unsigned capacity()     const;
      unsigned size()         const;

      void push(const T & crow) ;
      void pop() ;




    private:

      unsigned int _capacity;
      unsigned int _size;
      std::unique_ptr<T[]> _array;

};

#include "Stack.hxx"