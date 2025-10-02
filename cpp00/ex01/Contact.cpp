#include <iostream>
#include <string>
#include "Contact.hpp"
#include "settings.h"

Contact::Contact( void ) {
	if (SHOW_DEBUG)
		std::cout << "Contact.class default constructor called" << std::endl;
}

Contact::Contact(
		const std::string firstName,
		const std::string lastName,
		const std::string nickname,
		const std::string phoneNumber,
		const std::string darkestSecret) {
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_nickname = nickname;
		this->_phoneNumber = phoneNumber;
		this->_darkestSecret = darkestSecret;
	if (SHOW_DEBUG)
		std::cout << "Contact.class parameterized constructor called" << std::endl;
}

Contact::~Contact( void ) {
	if (SHOW_DEBUG)
		std::cout << "Contact.class destructor called" << std::endl;
}

std::string Contact::getFirstName( void ) {
	return this->_firstName;
}

std::string Contact::getLastName( void ) {
	return this->_lastName;
}

std::string Contact::getNickname( void ) {
	return this->_nickname;
}

std::string Contact::getPhoneNumber( void ) {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret( void ) {
	return this->_darkestSecret;
}