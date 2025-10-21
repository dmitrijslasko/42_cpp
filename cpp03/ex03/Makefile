# =================== Colors ===================
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
RST    = \033[0m

# =================== Compiler ===================
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -Wold-style-cast -Wdeprecated-declarations -Wpedantic

# =================== Project ===================
NAME = main

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRC = 	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/ClapTrap.cpp \
		$(SRC_DIR)/ScavTrap.cpp \
		$(SRC_DIR)/FragTrap.cpp \

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

INC = 	$(INC_DIR)/ClapTrap.hpp \
		$(INC_DIR)/ScavTrap.hpp \
		$(INC_DIR)/FragTrap.hpp

# =================== Rules ===================
all: compile $(NAME)

# Function for status messages
define status
	@echo "--------------------------------------------------------------------"
	@echo "$(2)>>> $(1) ${RST}"
	@echo "--------------------------------------------------------------------"
endef

# Linking
$(NAME): $(OBJ)
	$(call status,🟢 Linking object files..., $(GREEN))
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo ""

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(call status,🟢 Compiling $< ..., $(GREEN))
	$(CC) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo ""

# Compilation
compile:
	@mkdir -p $(OBJ_DIR)
	$(call status, 🟢 Compiling all source files..., $(GREEN))
	@$(MAKE) $(OBJ) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC)
	@printf "Compiling %-20s → %-20s\n" "$<" "$@"
	@$(CC) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(call status,🟡 Cleaning object files..., $(YELLOW))
	rm -rf $(OBJ_DIR)
	@echo ""

fclean: clean
	$(call status,🟡 Removing binary..., $(YELLOW))
	rm -f $(NAME)
	@echo ""

re: fclean all

.PHONY: all clean fclean re
