#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

// virtual keyword allows derived class to override the function, and "=0"
// keyword enforces  derived class to override the function
class AForm {
 private:
  const std::string _name;
  bool              _signed;
  const int         _grade_to_sign;
  const int         _grade_to_exec;

 public:
  AForm();
  AForm(std::string name, int grade_to_sign, int gade_to_exec);
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);
  virtual ~AForm();
  std::string  getName() const;
  bool         getSigned() const;
  int          getGradeToSign() const;
  int          getGradeToExec() const;
  void         beSigned(Bureaucrat& bureau);
  virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, AForm& form);

#endif
