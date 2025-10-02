#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact {
	
	public:

		Contact(void);
		Contact(const std::string firstName, 
				const std::string lastName,
				const std::string nickname,
				const std::string phoneNumber,
				const std::string darkestSecret);

		~Contact(void);
		
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);

	private:
		std::string _firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string	_darkestSecret;
};

#endif