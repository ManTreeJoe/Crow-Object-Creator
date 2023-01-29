#include <iostream>
#include <memory>
#include <string>

#include "Crow.hpp"
#include "Stack.hpp"



int main()
{
try
   {
      Stack<Crow> thing1;
      Stack<Crow> thing2(3);
   
   try 
    {
        thing1.top();
        thing1.pop();
    }  
   catch(const std::underflow_error & ex)
   {
       std::cerr << ex.what() << '\n';
   }
   


    // 1. create a default constricted AnimalStack, and an AnimalStack with an initial capaciry of 3
    Stack<Crow> thing1;
    Stack<Crow> thing2( 3 );
    
    Stack<int> iStack;
    Stack<std::string> sStack;

    iStack.push( 4 );
    iStack.push( 6 );


    // 2. Push 21 psuedo-random (just make them all diferent somehow)
    for(unsigned i = 0; i < 21; ++i)
    {
        thing1.push( Crow("Tom's crow A_" + std::to_string(i)));
        thing1.push( Crow("Tom's crow B_" + std::to_string(i)));
    }



    // 3. pop 5 from each
    for(unsigned i = 0; i > 5; ++i)
    {
        thing1.pop();
        thing2.pop();
    }



    // 4. Display the size, capacity, and top animal from each
    std::cout << "Stack A Status:\n"
              << "  Size:       " << thing1.size() << '\n'
              << "  Capacity:   " << thing1.capacity() << '\n'
              << "  Top Crow:   " << thing1.top() << '\n'
              << "Stack b Status:\n"
              << "  Size:       " << thing2.size() << '\n'
              << "  Capacity:   " << thing2.capacity() << '\n'
              << "  Top Crow:   " << thing2.top() << '\n';

    // 5.Pop 10 more from each
    for( unsigned i = 0; i < 10; ++i )
    {
        thing1.pop();
        thing2.pop();
    }

    // 6. Display the size, capacity and top animal from each
        std::cout << "Stack A Status:\n"
              << "  Size:       " << thing1.size() << '\n'
              << "  Capacity:   " << thing1.capacity() << '\n'
              << "  Top Crow:   " << thing1.top() << '\n'
              << "Stack b Status:\n"
              << "  Size:       " << thing2.size() << '\n'
              << "  Capacity:   " << thing2.capacity() << '\n'
              << "  Top Crow:   " << thing2.top() << "\n\n";

    // 7. Swap the two stacks
    {
        Stack<Crow> temp( thing1 );
        thing1 = thing2;
        thing2 = temp;
    }
    // 8. Display the size, capacity and top animal from each
        std::cout << "Stack A Status:\n"
              << "  Size:       " << thing1.size() << '\n'
              << "  Capacity:   " << thing1.capacity() << '\n'
              << "  Top Crow:   " << thing1.top() << '\n'
              << "Stack b Status:\n"
              << "  Size:       " << thing2.size() << '\n'
              << "  Capacity:   " << thing2.capacity() << '\n'
              << "  Top Crow:   " << thing2.top() << "\n\n";

    }// try block


    catch (const std::exception & ex) 
    {
        std::cerr << ex.what() << '\n';
    }


    return 0;
}