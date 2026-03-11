# =================== Colors ===================
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
RST    = \033[0m

# =================== Compiler ===================
CC = c++
CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98
# This will enable warnings for old-style casts, deprecated declarations, and enforce strict ISO compliance
CXXFLAGS += -Wold-style-cast -Wdeprecated-declarations -Wpedantic
# These flags will generate dependency files (.d) for each source file, which will be included in the Makefile to automatically handle header dependencies
CXXFLAGS += -MMD -MP

# =================== Project ===================
NAME = serializer

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./include
UTILS_DIR = ./../utils

SRC =	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/Serializer.cpp \
		$(UTILS_DIR)/utils.cpp		\

# Convert all .cpp to .o inside obj folder (regardless of location)
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.cpp=.o)))

# =================== Functions ===================
define status
	@echo "--------------------------------------------------------------------"
	@echo "$(2)>>> $(1) ${RST}"
	@echo "--------------------------------------------------------------------"
endef

# =================== Rules ===================
all: compile $(NAME)


$(NAME): $(OBJ)
	$(call status,🟢 Linking object files..., $(GREEN))
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo ""

# Pattern rule for source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) -I$(INC_DIR) -I$(UTILS_DIR) -c $< -o $@

$(OBJ_DIR)/utils.o: $(UTILS_DIR)/utils.cpp
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

# Phony targets to prevent conflicts with files named 'all', 'clean', etc.
.PHONY: all clean fclean re
