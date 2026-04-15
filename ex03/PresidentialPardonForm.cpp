
#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"
#include "GradeExceptions.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("") {
  std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  std::cout << "PresidentialPardonForm Parameterized Constructor Called"
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other) {
  std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
  if (&other == this) {
    return *this;
  }
  AForm::operator=(other);
  _target = other._target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (getGradeToExec() < executor.getGrade()) {
    throw GradeTooLowException("PresidentialPardonForm::GradeTooLowException");
  }
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
