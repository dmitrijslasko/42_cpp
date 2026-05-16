#include <iostream>
using std::cout;
using std::endl;


class myClass {
	private:
		int _value;

	public:
		myClass() {};
		myClass(int value) : _value(value) {};
		
		// Copy Constructor
		myClass(const myClass &other) {
			// Here's the code for the copy constructor, which performs a deep copy of the resources.
		}

		myClass& operator = (const myClass &other) {
			if (this != &other) {
				// deep copy of resources
			}
			return *this;
		} 
		
		myClass operator + (const myClass &other) const {
			cout << "Operator + override!" << endl;
			return myClass(_value + other._value);
		}

		myClass operator - (const myClass &other) const {
			cout << "Operator - override!" << endl;
			return myClass(_value - other._value);
		}

		// Copy Assignment Operator

		~myClass() {};

		void setValue(int value) {
			_value = value;
		}
		
		int getValue() {
			return _value;
		}

		friend std::ostream& operator << (std::ostream &out, const myClass &instance) {
			out << "Hello. My value is ";
			out << instance.getValue();
			return out;
		}

};


int main() {
	myClass x(20);
	myClass y(10);

	// x.setAge(10);
	cout << x.getValue() << endl;
	myClass z = x - y;
	// cout << x + y << endl;
	cout << z.getValue() << endl;
	cout << z << endl;
	return 0;
}