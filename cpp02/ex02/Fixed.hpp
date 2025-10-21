#pragma once

# include <iostream>
#include <cmath>

// The Orthodox Canonical Form (also called the Rule of Three) is a set of four essential
// functions that every well-behaved C++ class should define when it manages resources —
// or simply to make its behavior explicit.

//Fixed class stores numbers in fixed-point format
class Fixed {

	public:
		// 1. default constructor
		Fixed();
		// 2. parameterized constructor
		// 2.1. A constructor that takes a constant integer as a parameter
		Fixed(const int input);
		// 2.2. A constructor that takes a constant floating-point number as a parameter.
		Fixed(const float input);
		// 3. copy constructor
		Fixed(const Fixed& other);
		// 4. copy assignment operator overload
		Fixed& operator=(const Fixed& other);
		// 5. destructor
		~Fixed();

		// public methods
		int getRawBits ( void ) const;
		void setRawBits (int const raw );
		// A member function float toFloat( void ) const
		float toFloat( void ) const;
		//A member function int toInt( void ) const;
		int toInt( void ) const;

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Increment / Decrement operators
		Fixed& operator++();     // pre-increment (++a)
		Fixed operator++(int);   // post-increment (a++)
		Fixed& operator--();     // pre-decrement (--a)
		Fixed operator--(int);   // post-decrement (a--)

		// Min / Max functions
		//By providing both const and non-const versions:
		//The compiler automatically picks the right one.
		//You get maximum flexibility:
		//returns non-const ref if you pass non-const objects;
		//returns const ref if you pass const objects.
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

	private:
		//_	value stores both integer and fractional parts, scaled by 2^_fractional_bits.
		//	So if _fractional_bits = 8, then _value = 256 represents 1.0 (because 256 / 2⁸ = 1).
		int	_value;
		static const int _fractional_bits = 8;
};

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter.
// You can’t modify std::ostream, so you can’t make this function a member of your class.
// Instead, you define it as a non-member (usually a friend so it can access private members if needed).
std::ostream& operator<<(std::ostream &out, const Fixed &fp_number);
