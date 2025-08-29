#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {
	
	public:
		Contact(void);
		Contact(const std::string, 
				const std::string, 
				const std::string,
				const std::string,
				const std::string);
		~Contact(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);

	private:
		// int			_index;
		std::string _firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string	_darkestSecret;
};

#endif