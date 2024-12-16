#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// void leak(void)
// {
// 	system("leaks exec");
// }

static void testCase(int buro, std::string name, std::string target)
{
	AForm*	form = NULL;
	Intern	i;

	try
	{
		Bureaucrat	b(target+"_Crat", buro);

		form = i.makeForm(name, target);
		form->beSigned(b);
		b.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		if(form)
			delete form;
		std::cerr << e.what();
	}
}

int main()
{
	// atexit(&leak);

	std::cout << "\nBUREAUCRAT OUT OF BOUNDS - TOO LOW\n";
	testCase(151, "RobotomyRequest", "TOO-HIGH");

	std::cout << "\nBUREAUCRAT OUT OF BOUNDS - TOO HIGH\n";
	testCase(0, "ShrubberyCreation", "TOO-LOW");

	std::cout << "\nCAN'T SIGN FORM\n";
	testCase(145, "PresidentialPardon", "CAN'T_SIGN");

	std::cout << "\nCAN'T EXECUTE FORM\n";
	testCase(138, "RobotomyRequest", "CAN'T_EXECUTE");

	std::cout << "\nCAN'T CREATE FORM\n";
	testCase(138, "OtherName", "HOME");
	return (0);
}
