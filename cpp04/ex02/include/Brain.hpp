#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include "_colors.hpp"

#define	IDEAS_COUNT 100


class Brain {

	private:
		std::string		_ideas[IDEAS_COUNT];
		size_t			_idea_count;

	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif
