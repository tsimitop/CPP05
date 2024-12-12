#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade = 20;
	const int			_execGrade = 10;
public:
	Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	std::string	getName() const;
	bool		getSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void	beSigned(Bureaucrat& bureaucrat);

	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const noexcept;
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const noexcept;
	};

	void	printStatus();
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif