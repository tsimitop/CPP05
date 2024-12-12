#include "Bureaucrat.hpp"
#include "Form.hpp"

// static void	signHandler(Bureaucrat bureaucrat, Form form)
// {
// 	try
// 	{
// 		form.beSigned(bureaucrat);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what();
// 	}
// }

int main()
{
	try
	{
		std::cout << "\n------------------------BUREAUCRAT CONSTRUCTION------------------------\n";
		Bureaucrat	highRank("highRank", 1);
		Bureaucrat	lowRank("lowRank", 20);
		Bureaucrat	unacceptableRank("unacceptableRank", 150);

		highRank.printStatus();
		lowRank.printStatus();
		unacceptableRank.printStatus();
		std::cout << "\n----------------------------FORM CONSTRUCTION--------------------------\n";

		Form		application;
		Form		application1;
		Form		application2;

		application.printStatus();
		application1.printStatus();
		application2.printStatus();
		std::cout << "\n---------------------------------SIGNING-------------------------------\n";
		application.beSigned(highRank);
		application1.beSigned(lowRank);
		application2.beSigned(unacceptableRank);
		// signHandler(highRank, application);
		// signHandler(lowRank, application1);
		// signHandler(unacceptableRank, application2);

		application.printStatus();
		application1.printStatus();
		application2.printStatus();

		highRank.signForm(application);
		lowRank.signForm(application1);
		unacceptableRank.signForm(application2);
		std::cout << "\n-------------------------------DESTRUCTION-----------------------------\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);	
}
