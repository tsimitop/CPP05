#include "Bureaucrat.hpp"

static void testCase1()
{
	try
	{
		Bureaucrat bureauRat("bureauRat", -900);
		bureauRat.decrementGrade();
		bureauRat.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

static void testCase2()
{
	try
	{
		Bureaucrat bureauRat("bureauRat", 900);
		bureauRat.decrementGrade();
		bureauRat.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

static void testCase3()
{
	try
	{
		Bureaucrat bureauRat("bureauRat", 1);
		bureauRat.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

static void testCase4()
{
	try
	{
		Bureaucrat bureauRat("bureauRat", 150);
		bureauRat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}
static void testCase5()
{
	try
	{
		Bureaucrat bureauRat("bureauRat", 15);
		bureauRat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

int main()
{
	std::cout << "\t\tTEST 1\n";
	testCase1();
	std::cout << "\t\tTEST 2\n";
	testCase2();
	std::cout << "\t\tTEST 3\n";
	testCase3();
	std::cout << "\t\tTEST 4\n";
	testCase4();
	std::cout << "\t\tTEST 5\n";
	testCase5();

	return (0);
}
