#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string _target;

 public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();
  void execute(Bureaucrat const& executor) const;
};

#endif
