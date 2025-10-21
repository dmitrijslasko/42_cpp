RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
RST = \033[0m

CC = c++
CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98
CXXFLAGS += -Wold-style-cast -Wdeprecated-declarations -Wpedantic

NAME =	main

SRC =	main.cpp \
		Fixed.cpp

OBJ = 	$(SRC:.cpp=.o)

HEADERS =	Fixed.hpp

all: compile $(NAME)

# Function for status messages
define status
	@echo "--------------------------------------------------------------------"
	@echo "$(2)>>>$(1) ${RST}"
	@echo "--------------------------------------------------------------------"
endef

# Linking
$(NAME): $(OBJ)
	$(call status, 🟢 Linking object files..., $(GREEN))
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo ""

# Compilation
compile:
	$(call status, 🟢 Compiling all source files..., $(GREEN))
	@$(MAKE) $(OBJ) --no-print-directory

%.o: %.cpp $(HEADERS)
	@printf "Compiling %-20s → %-20s\n" "$<" "$@"
	@$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	$(call status, 🟡 Performing clean - deleting object files..., $(YELLOW))
	rm -f $(OBJ)
	@echo ""

fclean: clean
	$(call status, 🟡 Performing full clean – deleting binaries..., $(YELLOW))
	rm -f $(NAME)
	@echo ""

re: fclean all

.PHONY: all compile clean fclean re
