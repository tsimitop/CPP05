#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _signGrade(20), _execGrade(10)
{
	// std::cout << "Form: Default constuctor called\n";
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	// std::cout << "Form: Parameterized constuctor called\n";
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	// std::cout << "Form: Copy constructor called\n";
}

Form& Form::operator=(const Form& other)
{
	// std::cout << "Form: Copy assignement operator called\n";
	if (this == &other)
		return (*this);
	this->_signed = other._signed;
	return (*this);
}

Form::~Form()
{
	// std::cout << "Form: Destuctor called\n";
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= this->getSignGrade())
		_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("EXCEPTION-Form: Grade is too high!\n");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("EXCEPTION-Form: Grade is too low!\n");
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << \
	" is signed: " << form.getSigned() << \
	", has sign grade: " << form.getSignGrade() << \
	", has exec grade: " << form.getExecGrade() << ".\n"; 
	return (os);
}

void	Form::printStatus()
{
	std::cout << "Name: " << _name << \
	" _signed: " << _signed << \
	" _signGrade: " << _signGrade << \
	" _execGrade: " << _execGrade << std::endl;
}
