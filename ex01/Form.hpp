// Let’s create a Form class. It has:
// • A constant name.
// • A boolean indicating whether it is signed (at construction, it is not).
// • A constant grade required to sign it.
// • A constant grade required to execute it.
// All these attributes are private, not protected.

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  bool              _signed;
  const int         _grade_to_sign;
  const int         _grade_to_exec;

 public:
  Form();
  Form(std::string name, int grade_to_sign, int gade_to_exec);
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();

  std::string getName() const;
  bool        getSigned() const;
  int         getGradeToSign() const;
  int         getGradeToExec() const;
  void        beSigned(Bureaucrat& bureau);
};

std::ostream& operator<<(std::ostream& out, Form& form);

#endif
