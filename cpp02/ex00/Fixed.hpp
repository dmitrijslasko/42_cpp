#pragma once

# include <iostream>

// The Orthodox Canonical Form (also called the Rule of Three) is a set of four essential
// functions that every well-behaved C++ class should define when it manages resources —
// or simply to make its behavior explicit.

//Each fixed-point value is stored as an integer, but scaled by 2^fractional_bits
class Fixed {

	public:
		// 1. default constructor
		Fixed();
		// 2. copy constructor
		Fixed(const Fixed& other);
		// 3. copy assignment operator overload
		Fixed& operator=(const Fixed& other);
		// 4. destructor
		~Fixed();

		// public methods
		int getRawBits ( void ) const;
		void setRawBits (int const raw );

	private:
		int _value;
		static const int _fractional_bits = 8;


};
