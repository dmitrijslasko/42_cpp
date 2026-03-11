#include <iostream>

#include "Serializer.hpp"
#include "utils.hpp"

int main()
{
    Data data;

    data.id = 42;
    data.name = "example";

    Data* original = &data;

    uintptr_t raw = Serializer::serialize(original);

    Data* restored = Serializer::deserialize(raw);

    printSeparator();

    std::cout << "Original pointer:  " << original << std::endl;
    std::cout << "Serialized value:  " << raw << std::endl;
    std::cout << "Restored pointer:  " << restored << std::endl;
    
    printSeparator();
    if (original == restored)
        std::cout << "✅ Pointers match" << std::endl;
    else
        std::cout << "❌ Pointers do NOT match" << std::endl;

    printSeparator();
    return 0;
}
