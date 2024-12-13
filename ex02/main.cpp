#include "Bureaucrat.hpp"
// #include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		std::cout << "\n------------------------BUREAUCRAT CONSTRUCTION------------------------\n";
		Bureaucrat	highRank("highRank", 1);
		Bureaucrat	lowRank("lowRank", 20);
		Bureaucrat	unacceptableRank("unacceptableRank", 150);

		// highRank.printStatus();
		// lowRank.printStatus();
		// unacceptableRank.printStatus();
		std::cout << "\n----------------------------FORM CONSTRUCTION--------------------------\n";

		PresidentialPardonForm		application;
		RobotomyRequestForm			application1;
		ShrubberyCreationForm		application2;

		std::cout << std::endl;

		application.printStatus();
		application1.printStatus();
		application2.printStatus();
		std::cout << "\n---------------------------------SIGNING-------------------------------\n";
		// application.beSigned(highRank);
		// application1.beSigned(lowRank);
		// application2.beSigned(unacceptableRank);

		// application.printStatus();
		// application1.printStatus();
		// application2.printStatus();

		// highRank.signForm(application);
		// lowRank.signForm(application1);
		// unacceptableRank.signForm(application2);
		std::cout << "\n--------------------------------EXECUTOR-------------------------------\n";
		application.execute(highRank);
		application1.execute(lowRank);
		application2.execute(unacceptableRank);
		std::cout << "\n-------------------------------DESTRUCTION-----------------------------\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);	
}
