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
	virtual ~Form();

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

	virtual void	execute(Bureaucrat const & executor) const = 0;

	void	printStatus();
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif