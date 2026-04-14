#include "RobotomyRequestForm.hpp"

#include <cstdlib>

#include "AForm.hpp"
#include "GradeExceptions.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("") {
  std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  std::cout << "RobotomyRequestForm Parameterized Constructor Called"
            << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {
  std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (&other == this) {
    return *this;
  }
  AForm::operator=(other);
  _target = other._target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (getGradeToExec() < executor.getGrade()) {
    throw GradeTooLowException("RobotomyRequestForm::GradeTooLowException");
  }
  std::cout << "drrrr! drrrr!" << std::endl;
  int random_value = std::rand();
  if (random_value % 2 == 0) {
    std::cout << _target << " has been robotomized." << std::endl;
  } else {
    std::cout << "Robotomy to " << _target << " was failed." << std::endl;
  }
}
