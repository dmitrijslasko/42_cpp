#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_age = 0;
	_populationSize++;
	return;
}

Sample::Sample(int age, int kids, int shoe_size) : _age(age), _kids(kids), _shoe_size(shoe_size) {
	std::cout << "Paramterized constructor called" << std::endl;
	_populationSize++;
	return;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	_populationSize--;
	return;
}

void Sample::print(void) {
	std::cout << "print function called!" << std::endl;
}

int Sample::getAge(void) {
	return this->_age;
}

void Sample::setAge(int age) {
	this->_age = age;
}

int Sample::getPopulationSize(void) {
	return _populationSize;
}

int Sample::_populationSize = 0;