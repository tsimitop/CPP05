#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() :_grade(1), _name("Default")
{
	std::cout << "Bureaucrat: Constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int n) : _name(name)
{
	std::cout << "Bureaucrat: Parameterized constructor called\n";
	// try
	// {
		if (n < 1)
			throw GradeTooHighException();
		if (n > 150)
			throw GradeTooLowException();
		_grade = n;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what();
	// }
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

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("EXCEPTION-Bureaucrat: Grade is too high!\n");
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("EXCEPTION-Bureaucrat: Grade is too low!\n");
}

void	Bureaucrat::decrementGrade()
{
	// try
	// {
		if (_grade++ > 150)
			throw Bureaucrat::GradeTooLowException();
		_grade++;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}

void	Bureaucrat::incrementGrade()
{
	// try
	// {
		if (_grade-- < 1)
			throw Bureaucrat::GradeTooHighException();
		_grade--;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}

void	Bureaucrat::signForm(Form form)
{
	if(form.getSigned() == true)
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because\n";
		std::cout << "\tGrade of bureaucrat["<< this->getGrade() <<"] not high enough ["<< form.getSignGrade() <<"] to be signed\n";
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return (os);
}

void	Bureaucrat::printStatus()
{
	std::cout << "Name: " << _name << \
	" _grade: " << _grade << std::endl;
}
