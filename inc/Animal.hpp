#ifndef ANIMAL_H
	#define ANIMAL_H

# include <string>

class Animal {
	public:
		// def constr
		Animal();
		// param constr
		Animal(int age, std::string name);
		// copy
		// compare
		// destr
		~Animal();

	private:
		int 		_age;
		std::string _name;
};

#endif