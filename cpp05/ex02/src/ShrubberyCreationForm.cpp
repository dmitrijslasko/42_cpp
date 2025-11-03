#include "ShrubberyCreationForm.hpp"

#include <ctime>
#include <cstdlib>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", SIGN_GRADE, EXEC_GRADE), target_("default_target") {
	std::cout << "ShrubberyCreationForm DEFAULT constructor.\n";
}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", SIGN_GRADE, EXEC_GRADE), target_(target) {
	std::cout << "ShrubberyCreationForm constructed for target: " << target << "\n";
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target_(other.target_) {
	std::cout << "ShrubberyCreationForm copy constructed\n";
}

// Copy assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target_ = other.target_;
	}
	std::cout << "ShrubberyCreationForm assigned\n";
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor\n";
}

void 	ShrubberyCreationForm::setTarget(const std::string target) {
	target_ = target;
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &bureaucrat) const {

	(void) bureaucrat;

	std::string line;
	std::string ascii_tree;

	std::ifstream myReadFile("./assets/ascii_tree");
	while (getline(myReadFile, line)) {
		ascii_tree += line;
		ascii_tree += '\n';
	}
	myReadFile.close();

	// open file stream in append mode
	std::string filename = target_ + "_shrubbery";
	std::ofstream file((filename).c_str(), std::ios::app);
	//system("afplay drill.wav");

	if (file.is_open()) {
		file << "----------------------------------------------------\n";
		std::time_t now = std::time(NULL);
    	char buf[80];
    	std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
		file << "ASCII tree added on " << buf << std::endl;
		file << ascii_tree;
		file.close();
		setColor(B_GREEN);
		std::cout << "✅ ASCII tree written to file " << filename << std::endl;
		resetColor();
    } else {
        std::cerr << "Failed to open " << filename << std::endl;
	}
}

//const std::string ShrubberyCreationForm::SHRUBBERY =
//"                                                         .			\n \
//											 .         ;  			\n \
//				.              .              ;%     ;;   			\n \
//				  ,           ,                :;%  %;   			\n \
//				   :         ;                   :;%;'     .,   	\n \
//		  ,.        %;     %;            ;        %;'    ,;			\n \
//			;       ;%;  %%;        ,     %;    ;%;    ,%'			\n \
//			 %;       %;%;      ,  ;       %;  ;%;   ,%;' 			\n \
//			  ;%;      %;        ;%;        % ;%;  ,%;'				\n \
//			   `%;.     ;%;     %;'         `;%%;.%;'				\n \
//				`:;%.    ;%%. %@;        %; ;@%;%'					\n \
//				   `:%;.  :;bd%;          %;@%;'					\n \
//					 `@%:.  :;%.         ;@@%;'   					\n \
//					   `@%.  `;@%.      ;@@%;         				\n \
//						 `@%%. `@%%    ;@@%;        				\n \
//						   ;@%. :@%%  %@@%;       					\n \
//							 %@bd%%%bd%%:;     						\n \
//							   #@%%%%%:;;							\n \
//							   %@@%%%::;							\n \
//							   %@@@%(o);  . '         				\n \
//							   %@@@o%;:(.,'         				\n \
//						   `.. %@@@o%::;         					\n \
//							  `)@@@o%::;         					\n \
//							   %@@(o)::;        					\n \
//							  .%@@@@%::;         					\n \
//							  ;%@@@@%::;.          					\n \
//							 ;%@@@@%%:;;;. 							\n \
//						 ...;%@@@@@%%:;;;;,..						\n";
