#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& other);
  Intern& operator=(const Intern& other);
  ~Intern();
  AForm* makeForm(std::string form_name, std::string form_target);
};

#endif
