#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form()
    : _name("empty_name"),
      _signed(false),
      _grade_to_sign(25),
      _grade_to_exec(25) {
  std::cout << "Form Default Constructor Called" << std::endl;
  if (_grade_to_sign < 1 || _grade_to_exec < 1) {
    throw Form::GradeTooHighException();
  } else if (_grade_to_exec > 150 || _grade_to_exec > 150) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec)
    : _name(name),
      _signed(false),
      _grade_to_sign(grade_to_sign),
      _grade_to_exec(grade_to_exec) {
  std::cout << "Form Parameterized Constructor Called" << std::endl;
  if (grade_to_sign < 1 || grade_to_exec < 1) {
    throw Form::GradeTooHighException();
  } else if (grade_to_sign > 150 || grade_to_exec > 150) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form& other)
    : _name(other._name),
      _signed(other._signed),
      _grade_to_sign(other._grade_to_sign),
      _grade_to_exec(other._grade_to_exec) {
  std::cout << "Form Copy Constructor Called" << std::endl;
}

Form& Form::operator=(const Form& other) {
  if (&other == this) {
    return *this;
  }
  _signed = other._signed;
  return (*this);
}

Form::~Form() { std::cout << "Form Destructor Called" << std::endl; }

char const* Form::GradeTooHighException::what() const throw() {
  return ("Form::GradeTooHighException");
}

char const* Form::GradeTooLowException::what() const throw() {
  return ("Form::GradeTooLowException");
}

std::string Form::getName() const { return (_name); }

bool Form::getSigned() const { return (_signed); }

int Form::getGradeToSign() const { return (_grade_to_sign); }

int Form::getGradeToExec() const { return (_grade_to_exec); }

std::ostream& operator<<(std::ostream& out, Form& form) {
  out << "Name: " << form.getName();
  out << "\nSigned: " << form.getSigned();
  out << "\nGradeToSign: " << form.getGradeToSign();
  out << "\nGradeToExec: " << form.getGradeToExec();
  return out;
}

void Form::beSigned(Bureaucrat& bureau) {
  if (bureau.getGrade() > getGradeToSign()) {
    throw Form::GradeTooLowException();
  }
  if (getSigned() == false) _signed = true;
}
