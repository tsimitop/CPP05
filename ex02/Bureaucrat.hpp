#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int n);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;

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

	void	decrementGrade();
	void	incrementGrade();
	void	signForm(AForm& aform);
	void	executeForm(AForm const & aform);

	void	printStatus();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif