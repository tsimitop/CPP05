#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void testCase(AForm* form, int buro)
{
	try
	{
		Bureaucrat	BurocRat("BurocRat", buro);

		form->beSigned(BurocRat);
		BurocRat.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

int main()
{
	PresidentialPardonForm	Presidential;
	RobotomyRequestForm		Robotomy;
	ShrubberyCreationForm	Shrubbery;

	std::cout << "\n__________________ONLY EXCEPTIONS__________________\n";

	std::cout << "\nBUREAUCRAT OUT OF BOUNDS - TOO LOW\n";
	testCase(&Presidential, 151);

	std::cout << "\nBUREAUCRAT OUT OF BOUNDS - TOO HIGH\n";
	testCase(&Robotomy, 0);

	std::cout << "\nCAN'T SIGN FORM\n";
	testCase(&Shrubbery, 145);

	std::cout << "\nCAN'T EXECUTE FORM\n";
	testCase(&Presidential, 138);

	std::cout << "\n___________________NO EXCEPTIONS___________________\n";

	std::cout << "\nBUREAUCRAT IN BOUNDS\n";
	testCase(&Presidential, 150); // WON'T BE SIGNED BUT BUREAUCRAT IS CREATED

	std::cout << "\nBUREAUCRAT IN BOUNDS\n";
	testCase(&Robotomy, 1);

	std::cout << "\nFORM GETS SIGNED\n";
	testCase(&Shrubbery, 25);

	std::cout << "\nFORM GETS EXECUTED\n";
	testCase(&Presidential, 137);
	return (0);
}
