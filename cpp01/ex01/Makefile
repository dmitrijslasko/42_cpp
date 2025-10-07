RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
RST = \033[0m

CC = c++
CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98
CXXFLAGS += -Wold-style-cast -Wdeprecated-declarations -Wpedantic

NAME = main

SRC = main.cpp \
      Zombie.cpp \
	  ZombieHorde.cpp \

OBJ = $(SRC:.cpp=.o)

HEADERS = Zombie.hpp

all: $(NAME)

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
%.o: %.cpp $(HEADERS)
	$(call status, 🟢 Compiling object file $< ..., $(GREEN))
	$(CC) $(CXXFLAGS) -c $< -o $@
	@echo ""

clean:
	$(call status, 🟡 Performing clean - deleting object files..., $(YELLOW))
	rm -f $(OBJ)
	@echo ""

fclean: clean
	$(call status, 🟡 Performing full clean – deleting binaries and object files..., $(YELLOW))
	rm -f $(NAME)
	@echo ""

re: fclean all

.PHONY: all clean fclean re