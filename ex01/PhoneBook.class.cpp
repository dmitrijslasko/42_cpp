#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "PhoneBook.class.hpp"
#include "settings.h"
#include "utilities.h"

size_t PhoneBook::_contactsCount = 0;

PhoneBook::PhoneBook(void) {
	if (SHOW_DEBUG)
		std::cout << "PhoneBook.class default constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
	if (SHOW_DEBUG)
		std::cout << "PhoneBook.class destructor called" << std::endl;
}

void PhoneBook::_pushContacts(void)
{
	int maxIndex = PhoneBook::_contactsCount;

	if (maxIndex == MAX_CONTACTS)
		maxIndex = MAX_CONTACTS - 1;
	for (int i = maxIndex - 1; i >= 0; i--)
		_contacts[i + 1] = _contacts[i];
}

void PhoneBook::add(void) {
	if (SHOW_DEBUG)
		std::cout << "PhoneBook.class add method" << std::endl;

	std::string firstName = promptInput(PROMPT_FIRST_NAME);
	std::string lastName = promptInput(PROMPT_LAST_NAME);
	std::string nickname = promptInput(PROMPT_NICKNAME);
	std::string phoneNumber = promptInput(PROMPT_PHONE_NUMBER);
	std::string darkestSecret = promptInput(PROMPT_DARKEST_SECRET);

	size_t index = 0;

	_pushContacts();
	Contact new_contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->_contacts[index] = new_contact;

	printLineBreaks(1, GREEN);
	std::cout << printColor("✅ Contact added to the phonebook!", B_GREEN);
	std::cout << std::endl;
	printLineBreaks(1, GREEN);
	std::cout << std::endl;

	if (PhoneBook::_contactsCount < MAX_CONTACTS)
		PhoneBook::_contactsCount++;
}

void printHeader(void) {
    std::cout 	<< std::setw(DISPLAY_FIELD_WIDTH) << std::right << "#"
				<< SEP_CLR << SEP_CHAR << RESET
    			<< std::setw(DISPLAY_FIELD_WIDTH) << std::right << "First"
				<< SEP_CLR << SEP_CHAR << RESET
    			<< std::setw(DISPLAY_FIELD_WIDTH) << std::right << "Last"
				<< SEP_CLR << SEP_CHAR << RESET
    			<< std::setw(DISPLAY_FIELD_WIDTH) << std::right << "Nickname"
				<< SEP_CLR << SEP_CHAR << RESET
    			<< std::endl;
}

std::string formatField(const std::string& str, size_t width) {
    if (str.length() > width)
        return str.substr(0, width - 3) + "...";
    else
        return str;
}

bool isNumber(const std::string &str) {
	if (str.empty())
		return (false);

	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

int	PhoneBook::_printOutPhonebook(void) {

	if (PhoneBook::_contactsCount == 0)
	{
		std::cout << printColor("❌ Phonebook is empty, nothing to show!", B_RED) << std::endl;
		std::cout << std::endl;
		return 1;
	}

	printLineBreaks(1, RED);
	printHeader();
	printLineBreaks(1, SEP_CLR);

	for (size_t i = 0; i < PhoneBook::_contactsCount; i++)
	{
		std::cout 	<< std::setw(DISPLAY_FIELD_WIDTH) << std::right << i + 1
					<< SEP_CLR << SEP_CHAR << RESET
					<< std::setw(DISPLAY_FIELD_WIDTH) << std::right << formatField(PhoneBook::_contacts[i].getFirstName(), DISPLAY_FIELD_WIDTH)
					<< SEP_CLR << SEP_CHAR << RESET
					<< std::setw(DISPLAY_FIELD_WIDTH) << std::right << formatField(PhoneBook::_contacts[i].getLastName(), DISPLAY_FIELD_WIDTH)
					<< SEP_CLR << SEP_CHAR << RESET
					<< std::setw(DISPLAY_FIELD_WIDTH) << std::right << formatField(PhoneBook::_contacts[i].getNickname(), DISPLAY_FIELD_WIDTH)
					<< SEP_CLR << SEP_CHAR << RESET
					<< std::endl;
	}
	printLineBreaks(1, SEP_CLR);
	return 0;
}

void PhoneBook::search(void) {
	if (SHOW_DEBUG)
		std::cout << "PhoneBook.class search method" << std::endl;

	if (PhoneBook::_printOutPhonebook())
		return ;

	std::string chosenIndex;
	size_t index = 0;
	while (index <= 0 || index >= PhoneBook::_contactsCount)
	{
		chosenIndex = promptInput(printColor("Choose an index to display contact info > ", B_YELLOW));
		if (!isNumber(chosenIndex))
		{
			std::cout << B_RED << "❌ Not a valid index. Try again!\n" << RESET << std::endl;
			continue ;
		}

		index = std::atoi(chosenIndex.c_str()) - 1;
		if (index >= 0 && index < PhoneBook::_contactsCount)
			break ;
		std::cout << B_RED << "❌ Index out of range!\n" << RESET << std::endl;
	}

	std::cout << std::endl;
	printLineBreaks(1, GREEN);
	std::cout << printColor("👍 Here is your contact info: ", B_GREEN) << std::endl;
	printLineBreaks(1, GREEN);
	std::cout << std::setw(20) << std::left << PROMPT_FIRST_NAME << PhoneBook::_contacts[index].getFirstName() << std::endl;
	std::cout << std::setw(20) << std::left << PROMPT_LAST_NAME << PhoneBook::_contacts[index].getLastName() << std::endl;
	std::cout << std::setw(20) << std::left << PROMPT_NICKNAME << PhoneBook::_contacts[index].getNickname() << std::endl;
	std::cout << std::setw(20) << std::left << PROMPT_PHONE_NUMBER << PhoneBook::_contacts[index].getPhoneNumber() << std::endl;
	std::cout << std::setw(20) << std::left << PROMPT_DARKEST_SECRET << PhoneBook::_contacts[index].getDarkestSecret() << std::endl;
	printLineBreaks(1, CYAN);
	std::cout << std::endl;
}

bool PhoneBook::exit(void) {
	if (SHOW_DEBUG)
		std::cout << "PhoneBook.class search method" << std::endl;

	std::string resp;

	while (true) {
		size_t contactsCount = PhoneBook::_contactsCount;
		if (contactsCount > 0)
			std::cout << contactsCount <<" contact(s) will get permanently lost. ";
		std::cout << "Are you sure? (Y/N): " << std::flush;
		std::getline(std::cin, resp);
		if (resp == "Y" || resp == "y")
		{
			std::cout << std::endl;
			return true;
		}
		else if (resp == "N" || resp == "n")
		{
			std::cout << std::endl;
			return false;
		}
		else if (std::cin.eof())
		{
			std::cout << EOF_DETECTED_TEXT << std::endl;
			exit();
		}
		else
			std::cout << printColor("❌ Invalid input, please type Y or N.\n", B_RED) << std::endl;
	}
}
