#include <iostream>
#include "Fixed.hpp"

// 1. default constructor
Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// 2. copy constructor
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// 3. copy assignment operator overload
Fixed &Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

// 4. destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// member functions
int Fixed::getRawBits ( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits ( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
