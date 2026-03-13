#include <cstdlib>
#include <iostream>

#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int r = std::rand() % 3;

    if (r == 0)
    {
        std::cout << "Generated A\n";
        return new A;
    }
    else if (r == 1)
    {
        std::cout << "Generated B\n";
        return new B;
    }
    else
    {
        std::cout << "Generated C\n";
        return new C;
    }
}


void identify(Base* p)
{
	std::cout << "Identifying from pointer: ";
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p)
{
    std::cout << "Identifying from reference: ";
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (...) {}
}
