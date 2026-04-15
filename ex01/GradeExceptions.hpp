#ifndef GRADE_EXCEPTIONS_HPP
#define GRADE_EXCEPTIONS_HPP

#include <exception>
#include <string>

class GradeTooHighException : public std::exception {
 private:
  std::string _msg;

 public:
  GradeTooHighException(std::string msg);
  virtual ~GradeTooHighException() throw();
  virtual char const* what() const throw();
};
class GradeTooLowException : public std::exception {
 private:
  std::string _msg;

 public:
  GradeTooLowException(std::string msg);
  virtual ~GradeTooLowException() throw();
  virtual char const* what() const throw();
};

#endif
