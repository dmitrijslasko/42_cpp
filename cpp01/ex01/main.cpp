#include "Zombie.hpp"

// is it possible to create a horde on stack?

int main( int argc, char *argv[] ) {

    if (argc < 3 || argc > 3) {
        std::cout << "I strictly insist that you use 2 arguments: (1) zombie count and (2) zombie name." << std::endl;
        return 0;
    }
    int N = atoi(argv[1]);

    if (N < 0) {
        std::cout << "Zombie count can't be less than 0." << std::endl;
        return 0;
    }

    Zombie *horde = zombieHorde(N, argv[2]);
    if (!horde)
    {
        std::cout << "No horde got created!" << std::endl;
        return 0;
    }
    
    for (int i = 0; i < N; i++) {
        std::cout << "Checking horde member " << i << std::endl;
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
