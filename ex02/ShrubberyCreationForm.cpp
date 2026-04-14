#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <stdexcept>

#include "AForm.hpp"
#include "GradeExceptions.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("") {
  std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << "ShrubberyCreationForm Parameterized Constructor Called"
            << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {
  std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
  if (&other == this) {
    return;
  }
  _target = other._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  // Exec Grade Checker
  if (getGradeToExec() <
      executor.getGrade())  // grade must be less than ToExec grade to execute.
  {
    throw GradeTooLowException("ShrubberyCreationForm::GradeTooLowException");
  }
  std::fstream s1;
  std::string  target_file = _target + "_shrubbery";
  s1.open(target_file.c_str(), std::fstream::out);
  if (!s1)
    throw std::runtime_error(
        "ShrubberyCreataionForm::execute cannot open the target file");
  s1 << "    /\\\n";
  s1 << "   /  \\\n";
  s1 << "  /    \\\n";
  s1 << " /      \\\n";
  s1 << "/________\\\n";
  s1 << "    ||\n";
}
