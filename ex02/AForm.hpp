#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
public:
	AForm();
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

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

std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif