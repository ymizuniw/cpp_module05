#include <cstdlib>
#include <ctime>
#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeExceptions.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
        std::cout << e.what() << std::endl;
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

int test_02(void) {
  // Shrubbery test
  //  OCF test
  {
    std::cout << "\n==default Constructor Test==" << std::endl;
    ShrubberyCreationForm sc1;
    std::cout << "\n==Parameterized Constructor Test==" << std::endl;
    ShrubberyCreationForm sc2("home");
    std::cout << "\n==Copy Constructor Test==" << std::endl;
    ShrubberyCreationForm sc3(sc2);
    if (sc3.getName() == sc2.getName() && sc3.getSigned() == sc2.getSigned() &&
        sc3.getGradeToSign() == sc2.getGradeToSign() &&
        sc3.getGradeToExec() == sc2.getGradeToExec())
      std::cout << "sc2's attributes are copied to sc3" << std::endl;
    else {
      std::cout << "sc2's attributes are not copied to sc3" << std::endl;
      std::cerr << "ShrubberyCreationForm Copy Constructor Test failed!"
                << std::endl;
      return (1);
    }
    std::cout << "\n==Destructor Test==" << std::endl;
  }
  // Basic function test
  {
    std::cout << "\n==beSigned() / execute() Test==" << std::endl;
    Bureaucrat            br1("br1", 145);
    ShrubberyCreationForm sc1("home");
    try {
      sc1.beSigned(br1);
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
      std::cerr << "beSigned() Test failed!" << std::endl;
      return (1);
    }
    Bureaucrat br2("br2", 137);
    try {
      sc1.execute(br2);
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
      std::cerr << "execute() Test failed!" << std::endl;
      return (1);
    }
  }
  // Exception test
  {
    std::cout << "\n==execute() GradeTooLowException Test==" << std::endl;
    int exception_occurred = 0;
    try {
      Bureaucrat            br1("br1", 145);
      ShrubberyCreationForm sc1("home");
      sc1.execute(br1);
    } catch (const GradeTooLowException& e) {
      exception_occurred = 1;
      if (std::string(e.what()) !=
          "ShrubberyCreationForm::GradeTooLowException") {
        std::cerr << "Unexpected Exception is thrown" << std::endl;
        std::cerr << "execute() GradeTooLowException Test failed!" << std::endl;
        return (1);
      } else {
        std::cout << e.what() << std::endl;
      }
    }
    if (exception_occurred == 0) {
      std::cerr << "Exception is not thrown" << std::endl;
      std::cerr << "execute() GradeTooLowException Test failed!" << std::endl;
      return (1);
    }
  }
  // RobotomyRequestForm OCF test
  {
    Bureaucrat br1("br1", 1);
    std::cout << "\n==RobotomyRequestForm default Constructor Test=="
              << std::endl;
    RobotomyRequestForm rf1;
    std::cout << "\n==RobotomyRequestForm Parameterized Constructor Test=="
              << std::endl;
    RobotomyRequestForm rf2("target_2");
    rf2.beSigned(br1);
    std::cout << "\n==RobotomyRequestForm Copy Constructor Test==" << std::endl;
    RobotomyRequestForm rf3(rf2);
    if (rf3.getName() == rf2.getName() && rf3.getSigned() == rf2.getSigned() &&
        rf3.getGradeToSign() == rf2.getGradeToSign() &&
        rf3.getGradeToExec() == rf2.getGradeToExec())
      std::cout << "rf2's attributes are copied to rf3" << std::endl;
    else {
      std::cout << "rf2's attributes are not copied to rf3" << std::endl;
      std::cerr << "RobotomyRequestForm Copy Constructor Test failed!"
                << std::endl;
      return (1);
    }
    std::cout << "\n==RobotomyRequestForm Copy Assignment Operator Test=="
              << std::endl;
    RobotomyRequestForm rf4("target_4");
    rf4 = rf2;
    if (rf4.getName() == rf2.getName() && rf4.getSigned() == rf2.getSigned() &&
        rf4.getGradeToSign() == rf2.getGradeToSign() &&
        rf4.getGradeToExec() == rf2.getGradeToExec())
      std::cout << "rf2's visible attributes are copied to rf4" << std::endl;
    else {
      std::cout << "rf2's visible attributes are not copied to rf4"
                << std::endl;
      std::cerr << "RobotomyRequestForm Copy Assignment Operator Test failed!"
                << std::endl;
      return (1);
    }
    std::cout << "\n==RobotomyRequestForm Destructor Test==" << std::endl;
  }
  // Robotomy basic fuction test
  {
    std::srand(std::time(NULL));
    std::cout << "\n==RobotomyRequestForm Execute Test==" << std::endl;
    Bureaucrat          br1("br1", 1);
    RobotomyRequestForm rf1("patient1");
    rf1.execute(br1);
  }
  // Robotomy exception test 72, 45
  {
    std::cout << "\n==RobotomyRequestForm SignTooLowException Test=="
              << std::endl;
    int                 exception_occurred = 0;
    Bureaucrat          br1("br1", 46);
    RobotomyRequestForm rf1("patient1");
    try {
      rf1.execute(br1);
    } catch (const std::exception& e) {
      exception_occurred = 1;
      if (std::string(e.what()) !=
          "RobotomyRequestForm::GradeTooLowException") {
        std::cerr << "Unexpected Exception is thrown" << std::endl;
        std::cerr << "RobotomyRequestForm::GradeTooLowException Test failed!"
                  << std::endl;
        return (1);
      } else {
        std::cout << e.what() << std::endl;
      }
    }
    if (exception_occurred == 0) {
      std::cerr << "Exception is not thrown" << std::endl;
      std::cerr << "RobotomyRequestForm::GradeTooLowException Test failed!"
                << std::endl;
      return (1);
    }
  }
  std::cout << "Test_02 is passed!" << std::endl;
  return (0);
}

int main(void) {
  if (test_00() != 0) {
    std::cout << "Test_00 Failed!" << std::endl;
    return (1);
  } else if (test_02() != 0) {
    std::cout << "Test_02 Failed!" << std::endl;
    return (1);
  }
  return (0);
}
