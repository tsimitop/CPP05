#include "Bureaucrat.hpp"
#include "Form.hpp"

static void testCaseBuro(int b)
{
	try
	{
		Bureaucrat	bureauRat("bureauRat", b);
		Form		form;
		form.beSigned(bureauRat);
		bureauRat.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

static void testCaseForm(int fs, int fx)
{
	try
	{
		Bureaucrat	bureauRat("bureauRat", 5);
		Form		form("BestForm", fs, fx);
		form.beSigned(bureauRat);
		bureauRat.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

int main()
{
	std::cout << "\n___________________BURO___________________\n";
	std::cout << "\t\tTEST 1\n";
	testCaseBuro(155);
	std::cout << "\t\tTEST 2\n";
	testCaseBuro(0);
	std::cout << "\t\tTEST 3\n";
	testCaseBuro(1);
	std::cout << "\t\tTEST 4\n";
	testCaseBuro(150);
	std::cout << "\t\tTEST 5\n";
	testCaseBuro(100);
	std::cout << "\n___________________FORM___________________\n";
	std::cout << "\t\tTEST 1\n";
	testCaseForm(155, 1);
	std::cout << "\t\tTEST 2\n";
	testCaseForm(1, -2);
	std::cout << "\t\tTEST 3\n";
	testCaseForm(1, 150);
	std::cout << "\t\tTEST 4\n";
	testCaseForm(150, 1);
	std::cout << "\t\tTEST 5\n";
	testCaseForm(36, 78);
	return (0);
}
