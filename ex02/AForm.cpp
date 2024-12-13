#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _signGrade(20), _execGrade(10)
{
	// std::cout << "AForm: Default constuctor called\n";
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	// std::cout << "AForm: Parameterized constuctor called\n";
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	// std::cout << "AForm: Copy constructor called\n";
}

AForm& AForm::operator=(const AForm& other)
{
	// std::cout << "AForm: Copy assignement operator called\n";
	if (this == &other)
		return (*this);
	this->_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{
	// std::cout << "AForm: Destuctor called\n";
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() >= this->getSignGrade())
	{
		std::cout << _name << std::endl;
		throw AForm::GradeTooLowException();
	}
	else if(bureaucrat.getGrade() <= this->getSignGrade())
		_signed = true;
}

const char*	AForm::GradeTooHighException::what() const noexcept
{
	return ("EXCEPTION-AForm: Grade is too high!\n");
}

const char*	AForm::GradeTooLowException::what() const noexcept
{
	return ("EXCEPTION-AForm: Grade is too low!\n");
}

const char*	AForm::FormIsNotSigned::what() const noexcept
{
	return ("EXCEPTION-AForm: Form is not signed!\n");
}

std::ostream&	operator<<(std::ostream& os, const AForm& aform)
{
	os << aform.getName() << \
	" is signed: " << aform.getSigned() << \
	", has sign grade: " << aform.getSignGrade() << \
	", has exec grade: " << aform.getExecGrade() << ".\n"; 
	return (os);
}

void	AForm::printStatus()
{
	std::cout << "Name: " << _name << \
	" _signed: " << _signed << \
	" _signGrade: " << _signGrade << \
	" _execGrade: " << _execGrade << std::endl;
}
