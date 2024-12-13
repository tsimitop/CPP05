#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1)
{
	std::cout << "Bureaucrat: Constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int n) : _name(name)
{
	std::cout << "Bureaucrat: Parameterized constructor called\n";
	if (n < 1)
		throw GradeTooHighException();
	if (n > 150)
		throw GradeTooLowException();
	_grade = n;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
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
	if (_grade++ > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade-- < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
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
