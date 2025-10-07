#include "Zombie.hpp"

int main( void ) {
    // heap zombie, needs to be deleted manually
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();

    // stack zombie, will be deleted automatically
    randomChump("Stacky");
    delete heapZombie;
    return 0;
}
