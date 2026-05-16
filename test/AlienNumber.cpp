#include "AlienNumber.hpp"

AlienNumber AlienNumber::operator+(const AlienNumber& other) {
	return AlienNumber(_value + AlienNumber::_ALIEN_FACTOR * other._value);
}
	
AlienNumber AlienNumber::operator-(const AlienNumber& other) {
	return AlienNumber(_value - AlienNumber::_ALIEN_FACTOR * other._value);
}