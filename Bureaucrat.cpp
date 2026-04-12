#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat() : _name("empty_name"), _grade(1) {
  std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
  std::cout << "Bureaucrat Parameterized Constructor Called" << std::endl;
  if (grade < 1) {
    throw(Bureaucrat::GradeTooHighException());
  } else if (150 < grade) {
    throw(Bureaucrat::GradeTooLowException());
  }
  this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
  std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (&other == this) {
    return *this;
  }
  this->_grade = other._grade;
  return (*this);
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat Destructor Called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureau) {
  out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
  return out;
}

char const* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Bureaucrat::GradeTooHighException");
}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Bureaucrat::GradeTooLowException");
}

std::string Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::incrementGrade() {
  if (this->_grade == 1) {
    throw(Bureaucrat::GradeTooHighException());
  }
  this->_grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->_grade == 150) {
    throw(Bureaucrat::GradeTooLowException());
  }
  this->_grade++;
}
