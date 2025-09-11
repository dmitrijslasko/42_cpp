#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"
# include "settings.h"

class PhoneBook {
	
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void add(void);
		void search(void);
		bool exit(void);
		int printOutPhonebook(void);

		void pushContacts(void);

	private:
		Contact			_contacts[MAX_CONTACTS];
		static size_t	_contactsCount;
};

#endif