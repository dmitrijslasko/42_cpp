#ifndef SETTINGS_H
# define SETTINGS_H

#define ASCII_LOGO \
" _  _  ____  ____  _                      ____              _    \n" \
"| || ||___ \\|  _ \\| |__   ___  _ __   ___| __ )  ___   ___ | | __\n" \
"| || |_ __) | |_) | '_ \\ / _ \\| '_ \\ / _ \\  _ \\ / _ \\ / _ \\| |/ /\n" \
"|__   _/ __/|  __/| | | | (_) | | | |  __/ |_) | (_) | (_) |   < \n" \
"   |_||_____|_|   |_| |_|\\___/|_| |_|\\___|____/ \\___/ \\___/|_|\\_\\\n" \
"\nSIMPLE YET VERY AWESOME C++ PHONEBOOK v0.1\n"

# define	SHOW_DEBUG		0

# define	MAX_CONTACTS	3

// line break settings
# define	LINE_BREAK_LEN		65
# define	LINE_BREAK_CHAR 	'-'
# define	LINE_BREAK_COLOR 	CYAN

# define	DISPLAY_FIELD_WIDTH		10
# define	SEP_CHAR				'|'
# define	SEP_CLR					GREY

// terminal Colors (ANSI Escape Codes)
# define	BLACK			"\033[30m"
# define	GREY			"\033[90m"
# define	RED				"\033[31m"
# define	GREEN			"\033[32m"
# define	YELLOW			"\033[33m"
# define	BLUE			"\033[34m"
# define	MAGENTA			"\033[35m"
# define	CYAN			"\033[36m"
# define	WHITE			"\033[37m"
# define	B_BLACK			"\033[90m"
# define	B_RED			"\033[38;5;210m"
# define	B_GREEN			"\033[92m"
# define	B_YELLOW		"\033[93m"
# define	B_BLUE			"\033[94m"
# define	B_MAGENTA		"\033[95m"
# define	B_CYAN			"\033[96m"
# define	B_WHITE			"\033[97m"
# define 	RESET			"\033[0m"

// texts
# define	EXIT_TEXT		"Hasta la vista, baby!"
# define	EXIT_TEXT_CLR	B_MAGENTA

# define 	LINE1_TEXT		"Available commands:"
# define 	LINE1_CLR		B_WHITE

// commands
# define	CMD1 			"ADD"
# define	CMD2 			"SEARCH"
// # define	CMD3 			"HELP"
# define	CMD4 			"EXIT"

# define	CMD1_PROMPT 	"add a new contact"
# define	CMD2_PROMPT 	"perform contact search"
// # define	CMD3_PROMPT 	"\t\tprint available commands"
# define	CMD4_PROMPT 	"exit the phonebook"

# define 	CMD_CLR			B_GREEN
# define 	CMD_PROMPT_CLR	YELLOW

// prompty
# define	PROMPT_TEXT		"Enter a command >"
# define	PROMPT_CLR		B_YELLOW
# define 	BAD_PROMPT_TEXT	"❌ I don't recognize this command..."
# define 	BAD_PROMPT_CLR	B_RED

# define	EOF_DETECTED_TEXT	"\n\n >>> EOF detected, quitting the phonebook...\n"

# define PROMPT_FIRST_NAME		"First name:"
# define PROMPT_LAST_NAME		"Last name:"
# define PROMPT_NICKNAME		"Nickname:"
# define PROMPT_PHONE_NUMBER	"Phone number:"
# define PROMPT_DARKEST_SECRET	"Darkest secret:"

#endif