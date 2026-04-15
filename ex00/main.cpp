#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "GradeExceptions.hpp"

int main(void) {
  // OCF test
  {
    std::cout << "\n==default Constructor Test==" << std::endl;
    Bureaucrat br1;
    std::cout << "\n==Parameterized Constructor Test==" << std::endl;
    Bureaucrat br2("br2", 1);
    std::cout << "\n==Copy Constructor Test==" << std::endl;
    Bureaucrat br3(br2);
    if (br3.getGrade() == br2.getGrade() && br3.getName() == br2.getName())
      std::cout << "br2's name and grade are copied to br3" << std::endl;
    else {
      std::cout << "br2's name and grade are not copied to br3" << std::endl;
      std::cerr << "Test failed!" << std::endl;
    }
    std::cout << "\n==Copy Assignment Operator Test==" << std::endl;
    Bureaucrat br4("br4", 2);
    br4 = br2;
    if (br4.getGrade() == br2.getGrade())
      std::cout << "br2's grade is copied to br4" << std::endl;
    else {
      std::cout << "br2's grade is not copied to br4" << std::endl;
      std::cerr << "Test failed!" << std::endl;
    }
    std::cout << "\n==Destructor Test==" << std::endl;
  }
  // Basic function test
  {
    std::cout << "\n==ostream Overload Test==" << std::endl;
    Bureaucrat br1("br1", 1);
    std::cout << br1 << std::endl;
  }
  // incrementGrade()
  {
    std::cout << "\n==incrementGrade() Test==" << std::endl;
    Bureaucrat br1("br1", 2);
    std::cout << "from: " << br1 << std::endl;
    br1.incrementGrade();
    std::cout << "to: " << br1 << std::endl;
  }
  // decrementGrade()
  {
    std::cout << "\n==decrementGrade() Test==" << std::endl;
    Bureaucrat br1("br1", 2);
    std::cout << "from: " << br1 << std::endl;
    br1.decrementGrade();
    std::cout << "to: " << br1 << std::endl;
  }
  // Exception test
  {
    // exception when costructing
    {
      std::cout << "\n==GradeTooHighException Test==" << std::endl;
      int exception_occurred = 0;
      try {
        Bureaucrat br1("br1", 0);
      } catch (const GradeTooHighException& e) {
        exception_occurred = 1;
        if (std::string(e.what()) != "Bureaucrat::GradeTooHighException") {
          std::cerr << "Unexpected Exception is thrown" << std::endl;
          std::cerr << "Test failed!" << std::endl;
          return (1);
        } else {
          std::cout << e.what() << std::endl;
        }
      }
      if (exception_occurred == 0) {
        std::cerr << "Exception is not thrown" << std::endl;
        std::cerr << "Test failed!" << std::endl;
        return (1);
      }
    }
    {
      int exception_occurred = 0;
      std::cout << "\n==GradeTooLowException Test==" << std::endl;
      try {
        Bureaucrat br1("br1", 151);
      } catch (const GradeTooLowException& e) {
        exception_occurred = 1;
        if (std::string(e.what()) != "Bureaucrat::GradeTooLowException") {
          std::cerr << "Unexpected Exception is thrown" << std::endl;
          std::cerr << "Test failed!" << std::endl;
          return (1);
        } else {
          std::cout << e.what() << std::endl;
        }
      }
      if (exception_occurred == 0) {
        std::cerr << "Exception is not thrown" << std::endl;
        std::cerr << "Test failed!" << std::endl;
        return (1);
      }
    }
    // exception when increment
    {
      int exception_occurred = 0;
      std::cout << "\n==Increment() GradeTooHighException Test==" << std::endl;
      try {
        Bureaucrat br1("br1", 1);
        br1.incrementGrade();
      } catch (const GradeTooHighException& e) {
        exception_occurred = 1;
        if (std::string(e.what()) != "Bureaucrat::GradeTooHighException") {
          std::cerr << "Unexpected Exception is thrown" << std::endl;
          std::cerr << "Test failed!" << std::endl;
          return (1);
        } else {
          std::cout << e.what() << std::endl;
        }
      }
      if (exception_occurred == 0) {
        std::cerr << "Exception is not thrown" << std::endl;
        std::cerr << "Test failed!" << std::endl;
        return (1);
      }
    }
    {
      int exception_occurred = 0;
      std::cout << "\n==Decrement() GradeTooLowException Test==" << std::endl;
      try {
        Bureaucrat br1("br1", 150);
        br1.decrementGrade();
      } catch (const GradeTooLowException& e) {
        exception_occurred = 1;
        if (std::string(e.what()) != "Bureaucrat::GradeTooLowException") {
          std::cerr << "Unexpected Exception is thrown" << std::endl;
          std::cerr << "Test failed!" << std::endl;
          return (1);
        } else {
          std::cout << e.what() << std::endl;
        }
      }
      if (exception_occurred == 0) {
        std::cerr << "Exception is not thrown" << std::endl;
        std::cerr << "Test failed!" << std::endl;
        return (1);
      }
    }
  }
  std::cout << "All tests are passed!" << std::endl;
  return (0);
}
