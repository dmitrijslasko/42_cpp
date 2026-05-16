/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vect2.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroux <aroux@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:45:27 by aroux             #+#    #+#             */
/*   Updated: 2025/06/20 14:10:46 by aroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class vect2 {
private:
    int x, y;

public:
// CONSTRUCTORS
	vect2() : x(0), y(0) {};
    vect2(int x, int y) : x(x), y(y) {};
    vect2(const vect2& copy) : x(copy.x), y(copy.y) {};

// ASSIGNEMENT (1 op)
    vect2& operator=(const vect2& other) {
        if (*this != other)  {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

// INDEX (2 ops)
    int& operator[](int i) {    
		if (i == 0)
			return x;
		else
			return y;
    }

    int operator[](int i) const {
        if (i == 0)
			return x;
		else
			return y;
    }

// OUTPUT (1 op)
    friend std::ostream& operator<<(std::ostream& os, const vect2& v) {
        os << "{" << v[0] << ", " << v[1] << "}";
        return os;
    }
// INCR & DECR (4 operators)
    vect2 operator++(int) {
        vect2 tmp = *this;
        x++;
        y++;
        return tmp;
    }

    vect2& operator++() {
        x++;
        y++;
        return *this;
    }

    vect2 operator--(int) {
        vect2 tmp = *this;
        x--;
        y--;
        return tmp;
    }

    vect2& operator--() {
        x--;
        y--;
        return *this;
    }

// ADDITION (2 op) & SUBSTRACTION (3 op)
    vect2& operator+=(const vect2& oth) {
        x += oth.x;
        y += oth.y;
        return *this;
    }

    vect2& operator-=(const vect2& oth) {
        x -= oth.x;
        y -= oth.y;
        return *this;
    }

    vect2 operator+(const vect2& oth) const { return vect2(x + oth.x, y + oth.y); }

    vect2 operator-(const vect2& oth) const { return vect2(x - oth.x, y - oth.y); }

	vect2 operator-() { return vect2(-x, -y); }

// MULTIPLICATION (3ops: v*s, s*v, v*=s)
    vect2 operator*(int s) const { return vect2(x * s, y * s); }

    friend vect2 operator*(int s, const vect2& v) { return vect2(v.x * s, v.y * s); }

    vect2& operator*=(int s) {
        x *= s;
        y *= s;
        return *this;
    }

// == && != ops
    bool operator==(const vect2& other) { return (x == other.x && y == other.y);  }

    bool operator!=(const vect2& other) {
        //return !(x == oth.x && y == oth.y);		// both solutions are equivalent if == is defined before
		return !(*this == other);
    }

};
