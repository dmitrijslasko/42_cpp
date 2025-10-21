#include <iostream>
#include "Fixed.hpp"

// 1. default constructor
Fixed::Fixed( void ) : _value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

// 2.1. A constructor that takes a constant integer as a parameter
Fixed::Fixed(const int input) {
	//std::cout << "Int constructor called" << std::endl;
	this->_value = input << _fractional_bits;
}

// 2.2. A constructor that takes a constant floating-point number as a parameter.
Fixed::Fixed(const float input) {
	//std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(input * (1 << _fractional_bits)));
}

// 3. Copy constructor
Fixed::Fixed(const Fixed& other) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// 4. Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed& other) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

// 5. Destructor
Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

// member functions
int Fixed::getRawBits ( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits ( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

// A member function float toFloat( void ) const
float Fixed::toFloat( void ) const {
	//std::cout << "toFloat member function called" << std::endl;
	return static_cast<float>(_value) / (1 << _fractional_bits);
}

//A member function int toInt( void ) const;
int Fixed::toInt( void ) const {
	//std::cout << "toInt member function called" << std::endl;
	return _value >> _fractional_bits;
}

bool Fixed::operator>(const Fixed &other) const {
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->_value != other._value;
}


Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// Pre-increment
Fixed& Fixed::operator++() {
	_value += 1;        // smallest epsilon step
	return *this;       // return updated object
}

// Post-increment
Fixed Fixed::operator++(int) {
	Fixed temp(*this);  // make a copy of the current state
	_value += 1;        // increment this object
	return temp;        // return the old value
}

// Pre-decrement
Fixed& Fixed::operator--() {
	_value -= 1;
	return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_value -= 1;
	return temp;
}

// ---------- MIN ----------
Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

// ---------- MAX ----------
Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fp_number) {
    out << fp_number.toFloat();
    return out;
}
