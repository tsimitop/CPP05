#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


static void	execution();
static void	signing();
// static void testCase(Bureaucrat &b, AForm &a, Intern &i)
static void testCase(int buro, int sign, int exec, std::string name, std::string target)
{
	Bureaucrat b;
	// AForm a;
	Intern i;
}

int main()
{
		std::cout << "\nBUREAUCRAT OUT OF BOUNDS - TOO HIGH\n";

		std::cout << "\nBUREAUCRAT OUT OF BOUNDS - TOO LOW\n";

		std::cout << "\nCAN'T SIGN FORM\n";

		std::cout << "\nCAN'T EXECUTE FORM\n";

		std::cout << "\nCAN'T CREATE FORM\n";
	try
	{

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);	
}
