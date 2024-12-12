#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false)
{
	std::cout << "Form: Default constuctor called\n";
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "Form: Copy constructor called\n";
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form: Copy assignement operator called\n";
	if (this == &other)
		return (*this);
	// this->_name = other._name;
	this->_signed = other._signed;
	// this->_signGrade = other._signGrade;
	// this->_execGrade = other._execGrade;

	return (*this);
}

Form::~Form()
{
	std::cout << "Form: Destuctor called\n";
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
	// try
	// {
		// if(bureaucrat.getGrade() <= 0)
		// {
		// 	std::cout << _name << std::endl;
		// 	throw Form::GradeTooHighException();
		// }
		if(bureaucrat.getGrade() >= this->getSignGrade())
		{
			std::cout << _name << std::endl;
			throw Form::GradeTooLowException();
		}
		else if(bureaucrat.getGrade() <= this->getSignGrade())
			_signed = true;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what();
	// }
	// else
	// {
	// 	// std::cout << "Grade of bureaucrat["<< bureaucrat.getGrade() <<"] not high enough ["<< this->getSignGrade() <<"] to be signed\n";
	// 	throw Form::GradeTooLowException();
	// }
}

const char*	Form::GradeTooHighException::what() const noexcept
{
	// std::cout << "Form: Grade is too high!\n";
	// std::cout << _name << std::endl;
	return ("EXCEPTION-Form: Grade is too high!\n");
}

const char*	Form::GradeTooLowException::what() const noexcept
{
	// std::cout << "Form: Grade is too low!\n";
	// std::cout << _name << std::endl;
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