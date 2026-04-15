#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Bureaucrat {
 private:
  const std::string _name;
  int               _grade;

 public:
  Bureaucrat();
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);
  ~Bureaucrat();
  std::string getName() const;
  int         getGrade() const;
  void        incrementGrade();
  void        decrementGrade();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureau);

#endif
