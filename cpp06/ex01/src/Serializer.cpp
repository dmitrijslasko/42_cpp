#include "Serializer.hpp"

// The serialize function takes a pointer to a Data object and converts it to an uintptr_t 
// (an unsigned integer type that can hold a pointer) using reinterpret_cast. 
// This allows us to store the pointer as an integer value.
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// The deserialize function takes an uintptr_t value and converts it back to a pointer to a Data object using reinterpret_cast. 
// This allows us to retrieve the original pointer from the integer value.
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
