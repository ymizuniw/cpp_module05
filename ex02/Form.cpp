#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeExceptions.hpp"

AForm::AForm()
    : _name("empty_name"),
      _signed(false),
      _grade_to_sign(25),
      _grade_to_exec(25) {
  std::cout << "AForm Default Constructor Called" << std::endl;
  if (_grade_to_sign < 1 || _grade_to_exec < 1) {
    throw GradeTooHighException("AForm::GradeTooHighException");
  } else if (_grade_to_exec > 150 || _grade_to_exec > 150) {
    throw GradeTooLowException("AForm::GradeTooLowException");
  }
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec)
    : _name(name),
      _signed(false),
      _grade_to_sign(grade_to_sign),
      _grade_to_exec(grade_to_exec) {
  std::cout << "AForm Parameterized Constructor Called" << std::endl;
  if (grade_to_sign < 1 || grade_to_exec < 1) {
    throw GradeTooHighException("AForm::GradeTooHighException");
  } else if (grade_to_sign > 150 || grade_to_exec > 150) {
    throw GradeTooLowException("AForm::GradeTooLowException");
  }
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _signed(other._signed),
      _grade_to_sign(other._grade_to_sign),
      _grade_to_exec(other._grade_to_exec) {
  std::cout << "AForm Copy Constructor Called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
  if (&other == this) {
    return *this;
  }
  _signed = other._signed;
  return (*this);
}

AForm::~AForm() { std::cout << "AForm Destructor Called" << std::endl; }

std::string AForm::getName() const { return (_name); }

bool AForm::getSigned() const { return (_signed); }

int AForm::getGradeToSign() const { return (_grade_to_sign); }

int AForm::getGradeToExec() const { return (_grade_to_exec); }

std::ostream& operator<<(std::ostream& out, AForm& form) {
  out << "Name: " << form.getName();
  out << "\nSigned: " << form.getSigned();
  out << "\nGradeToSign: " << form.getGradeToSign();
  out << "\nGradeToExec: " << form.getGradeToExec();
  return out;
}

void AForm::beSigned(Bureaucrat& bureau) {
  if (bureau.getGrade() > getGradeToSign()) {
    throw GradeTooLowException("AForm::GradeTooLowException");
  }
  if (getSigned() == false) _signed = true;
}
