# =================== Colors ===================
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
RST    = \033[0m

# =================== Compiler ===================
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -Wold-style-cast -Wdeprecated-declarations -Wpedantic
CXXFLAGS += -MMD -MP

# =================== Project ===================
NAME = main

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
UTILS_DIR = ../utils

SRC =	$(SRC_DIR)/main.cpp 	\
		$(SRC_DIR)/Bureaucrat.cpp 	\
		$(SRC_DIR)/AForm.cpp 	\
		$(SRC_DIR)/ShrubberyCreationForm.cpp 	\
		$(SRC_DIR)/RobotomyRequestForm.cpp 	\
		$(SRC_DIR)/PresidentialPardonForm.cpp 	\
		$(UTILS_DIR)/utils.cpp		\

# Convert all .cpp to .o inside obj folder (regardless of location)
OBJ = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRC)))

# =================== Rules ===================
all: compile $(NAME)

define status
	@echo "--------------------------------------------------------------------"
	@echo "$(2)>>> $(1) ${RST}"
	@echo "--------------------------------------------------------------------"
endef

$(NAME): $(OBJ)
	$(call status,🟢 Linking object files..., $(GREEN))
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo ""

# Pattern rule for source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -I$(INC_DIR) -I$(UTILS_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -I$(INC_DIR) -I$(UTILS_DIR) -c $< -o $@

# Auto-include generated dependency files (.d)
-include $(OBJ:.o=.d)

compile:
	@mkdir -p $(OBJ_DIR)
	$(call status,🟢 Compiling all source files..., $(GREEN))
	@$(MAKE) $(OBJ) --no-print-directory

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
