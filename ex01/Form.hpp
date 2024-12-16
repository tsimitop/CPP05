#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
public:
	Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	Form(std::string name, int signGrade, int execGrade);

	std::string	getName() const;
	bool		getSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void	beSigned(Bureaucrat& bureaucrat);

	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	void	printStatus();
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif