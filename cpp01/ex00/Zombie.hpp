#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

// First, implement a Zombie class.
// It has a private string attribute name.
// Add a member function void announce( void ); to the Zombie class.
// Zombies announce themselves as follows:
// <name>: BraiiiiiiinnnzzzZ...
// Do not print the angle brackets (< and >).

// For a zombie named Foo, the message would be:
// Foo: BraiiiiiiinnnzzzZ...

// Then, implement the following two functions:
// (1) Zombie* newZombie( std::string name );
// This function creates a zombie, names it, and returns it so you can use it outside of the function scope.

// (2) void randomChump( std::string name );
// This function creates a zombie, names it, and makes it announce itself.

// Now, what is the actual point of the exercise? You have to determine in which case
// it is better to allocate zombies on the stack or the heap.

// Zombies must be destroyed when you no longer need them. The destructor must print
// a message with the name of the zombie for debugging purposes.


class Zombie {
    public:
        // 1. Constructors
        Zombie();                   // default constructor
        Zombie( std::string name );           // parameterized constructor

        // 2. Destructor
        ~Zombie();

        // 3. Public member functions
        void announce( void );

    private:
        std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
