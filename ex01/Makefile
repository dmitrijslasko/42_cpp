RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
RST = \033[0m

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
# In a Makefile, both CFLAGS and CXXFLAGS are variables used to specify compiler options, but they apply to different languages:
# CFLAGS = C
# CXXFLAGS = C++

NAME = phonebook
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

# Function for status messages
define status
	@echo "--------------------------------------------------------------------"
	@echo "${GREEN}>>>$(1) ${RST}"
	@echo "--------------------------------------------------------------------"
endef

# Linking
$(NAME): $(OBJ)
	$(call status, Linking object files...)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Compilation
%.o: %.cpp
	$(call status, Compiling object files $< ...)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	$(call status, Performing clean - deleting object files...)
	rm -f $(OBJ)

fclean: clean
	$(call status, Performing full clean – deleting binaries and object files...)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re