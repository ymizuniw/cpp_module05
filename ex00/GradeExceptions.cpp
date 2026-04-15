#include "GradeExceptions.hpp"

GradeTooHighException::GradeTooHighException(std::string msg) : _msg(msg) {}

GradeTooHighException::~GradeTooHighException() throw() {}

char const* GradeTooHighException::what() const throw() {
  return (_msg.c_str());
}

GradeTooLowException::GradeTooLowException(std::string msg) : _msg(msg) {}

GradeTooLowException::~GradeTooLowException() throw() {}

char const* GradeTooLowException::what() const throw() {
  return (_msg.c_str());
}
