#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :_grade(1), _name("Default")
{
	std::cout << "Bureaucrat: Constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, unsigned short n) : _name(name), _grade(n)
{
	std::cout << "Bureaucrat: Parameterized constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _grade(other._grade), _name(other._name)
{
	std::cout << "Bureaucrat: Copy constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat: Copy assignement operator called\n";
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called\n";
}

std::string		Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned short	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::GradeTooHighException()
{
	try
	{
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	Bureaucrat::GradeTooLowException()
{
	try
	{
		//
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::decrementGrade(unsigned short n)
{
	_grade += n;
}

void	Bureaucrat::incrementGrade(unsigned short n)
{
	_grade -= n;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return (os);
}
