#pragma once

# include <iostream>

// The Orthodox Canonical Form (also called the Rule of Three) is a set of four essential
// functions that every well-behaved C++ class should define when it manages resources —
// or simply to make its behavior explicit.

class Fixed {

	public:
		// 1. default constructor
		Fixed();
		// 2. parameterized constructor
		Fixed(const int input);
		Fixed(const float input);
		// 2. copy constructor
		Fixed(const Fixed& other);
		// 3. copy assignment operator overload
		Fixed& operator=(const Fixed& other);
		// 4. destructor
		~Fixed();

		// public methods
		int getRawBits ( void ) const;
		void setRawBits (int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int	_value;
		static const int _fractional_bits = 8;
};

//		An overload of the insertion («) operator that inserts a floating-point representation
//of the fixed-point number into the output stream object passed as a parameter.
std::ostream& operator<<(std::ostream& out, const Fixed& fp_number);
