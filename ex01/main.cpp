#include <exception>
#include <sstream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "GradeExceptions.hpp"

int test_00(void) {
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
      std::cerr << "Copy Constructor Test failed!" << std::endl;
      return (1);
    }
    std::cout << "\n==Copy Assignment Operator Test==" << std::endl;
    Bureaucrat br4("br4", 2);
    br4 = br2;
    if (br4.getGrade() == br2.getGrade())
      std::cout << "br2's grade is copied to br4" << std::endl;
    else {
      std::cout << "br2's grade is not copied to br4" << std::endl;
      std::cerr << "Copy Assignment Operator Test failed!" << std::endl;
      return (1);
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
        std::cerr << "GradeTooHighException Test failed!" << std::endl;
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
        std::cerr << "GradeTooLowException Test failed!" << std::endl;
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
          std::cerr << "Increment() GradeTooHighException Test failed!"
                    << std::endl;
          return (1);
        } else {
          std::cout << e.what() << std::endl;
        }
      }
      if (exception_occurred == 0) {
        std::cerr << "Exception is not thrown" << std::endl;
        std::cerr << "Increment() GradeTooHighException Test failed!"
                  << std::endl;
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
          std::cerr << "Decrement() GradeTooLowException Test failed!"
                    << std::endl;
          return (1);
        } else {
          std::cout << e.what() << std::endl;
        }
      }
      if (exception_occurred == 0) {
        std::cerr << "Exception is not thrown" << std::endl;
        std::cerr << "Decrement() GradeTooLowException Test failed!"
                  << std::endl;
        return (1);
      }
    }
  }
  std::cout << "Test_00 is passed!" << std::endl;
  return (0);
}

int test_01(void) {
  // OCF test
  {
    std::cout << "\n==default Constructor Test==" << std::endl;
    Form f1;
    if (f1.getName() != "empty_name" || f1.getSigned() != false ||
        f1.getGradeToSign() != 25 || f1.getGradeToExec() != 25) {
      std::cerr << "Default Constructor Test failed!" << std::endl;
      return (1);
    }
    std::cout << "\n==Parameterized Constructor Test==" << std::endl;
    Form f2("f2", 1, 1);
    if (f2.getName() != "f2" || f2.getSigned() != false ||
        f2.getGradeToSign() != 1 || f2.getGradeToExec() != 1) {
      std::cerr << "Parameterized Constructor Test failed!" << std::endl;
      return (1);
    }
    std::cout << "\n==Copy Constructor Test==" << std::endl;
    Form f3(f2);
    if (f3.getName() == f2.getName() && f3.getSigned() == f2.getSigned() &&
        f3.getGradeToSign() == f2.getGradeToSign() &&
        f3.getGradeToExec() == f2.getGradeToExec())
      std::cout << "f2's attributes are copied to f3" << std::endl;
    else {
      std::cout << "f2's attributes are not copied to f3" << std::endl;
      std::cerr << "Form Copy Constructor Test failed!" << std::endl;
      return (1);
    }
    std::cout << "\n==Copy Assignment Operator Test==" << std::endl;
    Form f4("f4", 2, 2);
    f4 = f2;
    if (f4.getName() == "f4" && f4.getSigned() == f2.getSigned() &&
        f4.getGradeToSign() == 2 && f4.getGradeToExec() == 2)
      std::cout << "f2's signed status is copied to f4" << std::endl;
    else {
      std::cout << "f2's signed status is not copied to f4" << std::endl;
      std::cerr << "Form Copy Assignment Operator Test failed!" << std::endl;
      return (1);
    }
    std::cout << "\n==Destructor Test==" << std::endl;
  }
  // Basic function test
  {
    std::cout << "\n==ostream Overload Test==" << std::endl;
    Form               f1("f1", 1, 2);
    std::ostringstream oss;
    oss << f1;
    if (oss.str() != "Name: f1\nSigned: 0\nGradeToSign: 1\nGradeToExec: 2") {
      std::cerr << "ostream Overload Test failed!" << std::endl;
      return (1);
    }
    std::cout << oss.str() << std::endl;
  }
  // GradeTooHighException test
  {
    std::cout << "\n==GradeTooHighException Test==" << std::endl;
    int exception_occurred = 0;
    try {
      Form f1("f1", 0, 1);
    } catch (const std::exception& e) {
      exception_occurred = 1;
      if (std::string(e.what()) != "Form::GradeTooHighException") {
        std::cerr << "Unexpected Exception is thrown" << std::endl;
        std::cerr << "Form GradeTooHighException Test failed!" << std::endl;
        return (1);
      } else {
        std::cout << e.what() << std::endl;
      }
    }
    if (exception_occurred == 0) {
      std::cerr << "Exception is not thrown" << std::endl;
      std::cerr << "Form GradeTooHighException Test failed!" << std::endl;
      return (1);
    }
  }
  // GradeTooLowException test
  {
    std::cout << "\n==GradeTooLowException Test==" << std::endl;
    int exception_occurred = 0;
    try {
      Form f1("f1", 151, 1);
    } catch (const std::exception& e) {
      exception_occurred = 1;
      if (std::string(e.what()) != "Form::GradeTooLowException") {
        std::cerr << "Unexpected Exception is thrown" << std::endl;
        std::cerr << "Form GradeTooLowException Test failed!" << std::endl;
        return (1);
      } else {
        std::cout << e.what() << std::endl;
      }
    }
    if (exception_occurred == 0) {
      std::cerr << "Exception is not thrown" << std::endl;
      std::cerr << "Form GradeTooLowException Test failed!" << std::endl;
      return (1);
    }
    {
      std::cout << "\n==BeSigned() Form::GradeTooLowException Test=="
                << std::endl;
      {
        int        exception_occurred = 0;
        Bureaucrat br1("br1", 76);
        Form       f1("f1", 75, 75);
        try {
          f1.beSigned(br1);
        } catch (const std::exception& e) {
          exception_occurred = 1;
          if (std::string(e.what()) != "Form::GradeTooLowException") {
            std::cerr << "Unexpected Exception is thrown" << std::endl;
            std::cerr << "BeSigned() Exception Test failed!" << std::endl;
            return (1);
          } else {
            std::cout << e.what() << std::endl;
          }
        }
        if (exception_occurred == 0) {
          std::cerr << "Exception is not thrown" << std::endl;
          std::cerr << "BeSigned() Exception Test failed!" << std::endl;
          return (1);
        }
      }
      {
        std::cout << "\n==BeSigned() No Exception Test==" << std::endl;
        Bureaucrat br1("br1", 75);
        Form       f1("f1", 75, 75);

        try {
          f1.beSigned(br1);
        } catch (const std::exception& e) {
          std::cout << e.what() << std::endl;
          std::cerr << "SignForm Test failed!" << std::endl;
          return (1);
        }
        if (f1.getSigned() == false) {
          std::cerr << "f1 is not signed" << std::endl;
          std::cerr << "SignForm Test failed!" << std::endl;
          return (1);
        }
      }
    }
  }
  std::cout << "Test_01 is passed!" << std::endl;
  return (0);
}

int main(void) {
  if (test_00() != 0) {
    std::cout << "Test_00 Failed!" << std::endl;
    return (1);
  } else if (test_01() != 0) {
    std::cout << "Test_01 Failed!" << std::endl;
    return (1);
  }
  return (0);
}
