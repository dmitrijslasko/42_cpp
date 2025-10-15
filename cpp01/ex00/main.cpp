#include "Zombie.hpp"

int main( void ) {
    // heap zombie, needs to be deleted manually
    Zombie* heapZombie = newZombie("Heapie");
    heapZombie->announce();

    // stack zombie, will be deleted automatically
    randomChump("Stacky");
    delete heapZombie;
    return 0;
}

//✅ Use stack allocation when:
//You only need the object inside the current function or block.
//You don’t need to return it or keep it for later.

//✅ Use heap allocation when:
//You need to return the object from a function (like newZombie does).
//You need it to persist beyond the scope of its creation
