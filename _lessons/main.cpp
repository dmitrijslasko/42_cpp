#include <iostream>
#include <string>

int main(){
    std::string name;
    name = "Dmitrijs Lasko";

    std::cout << name << std::endl;
    char *start = &name[0];

    // begin() returns an iterator, which is essentially a pointer to the first element of the string
    auto start2 = name.begin();

    std::cout << *start2 << std::endl;
    
    *(name.end() - 1) = 's'; // Modifying the last character of the string using end() iterator
    std::cout << name << std::endl;
    std::cout << name << std::endl;


    return 0;
}