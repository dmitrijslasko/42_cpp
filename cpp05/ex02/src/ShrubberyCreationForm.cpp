#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::SHRUBBERY = 
"                                                         .			\n \
                                             .         ;  			\n \
                .              .              ;%     ;;   			\n \
                  ,           ,                :;%  %;   			\n \
                   :         ;                   :;%;'     .,   	\n \
          ,.        %;     %;            ;        %;'    ,;			\n \
            ;       ;%;  %%;        ,     %;    ;%;    ,%'			\n \
             %;       %;%;      ,  ;       %;  ;%;   ,%;' 			\n \
              ;%;      %;        ;%;        % ;%;  ,%;'				\n \
               `%;.     ;%;     %;'         `;%%;.%;'				\n \
                `:;%.    ;%%. %@;        %; ;@%;%'					\n \
                   `:%;.  :;bd%;          %;@%;'					\n \
                     `@%:.  :;%.         ;@@%;'   					\n \
                       `@%.  `;@%.      ;@@%;         				\n \
                         `@%%. `@%%    ;@@%;        				\n \
                           ;@%. :@%%  %@@%;       					\n \
                             %@bd%%%bd%%:;     						\n \
                               #@%%%%%:;;							\n \
                               %@@%%%::;							\n \
                               %@@@%(o);  . '         				\n \
                               %@@@o%;:(.,'         				\n \
                           `.. %@@@o%::;         					\n \
                              `)@@@o%::;         					\n \
                               %@@(o)::;        					\n \
                              .%@@@@%::;         					\n \
                              ;%@@@@%::;.          					\n \
                             ;%@@@@%%:;;;. 							\n \
                         ...;%@@@@@%%:;;;;,..						\n";


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
    std::cout << "ShrubberyCreationForm desctuctor\n";
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &bureaucrat) {
    (void) bureaucrat;
	std::cout << SHRUBBERY << std::endl;
}
