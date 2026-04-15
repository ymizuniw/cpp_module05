#include "Intern.hpp"

#include <exception>
#include <stdexcept>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//   AForm* makeForm(std::string form_name, std::string form_target);

Intern::Intern() {
  std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern& other) {
  (void)other;
  std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return (*this);
}

Intern::~Intern() { std::cout << "Intern Destructor Called" << std::endl; }

AForm* Intern::makeForm(std::string form_name, std::string form_target) {
  std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm",
                          "PresidentialPardonForm"};
  std::size_t form_idx = 3;
  for (std::size_t i = 0; i < 3; i++) {
    if (form_name == forms[i]) {
      form_idx = i;
      break;
    }
  }
  AForm* form = NULL;
  try {
    switch (form_idx) {
      case 0:
        form = new ShrubberyCreationForm(form_target);
        break;
      case 1:
        form = new RobotomyRequestForm(form_target);
        break;
      case 2:
        form = new PresidentialPardonForm(form_target);
        break;
      default:
        std::cout << form_name << " is not in the forms table" << std::endl;
        return (NULL);
    }
  } catch (const std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << "\nIntern creates " << *form << "\n" << std::endl;
  return (form);
}
