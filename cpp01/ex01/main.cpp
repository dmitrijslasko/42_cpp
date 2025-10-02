#include "Zombie.hpp"

int main( void ) {
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();

    randomChump("Stacky");
    delete heapZombie;
    return 0;
}