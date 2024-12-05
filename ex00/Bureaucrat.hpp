#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned short		_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned short n);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string		getName() const;
	unsigned short	getGrade() const;

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

	void	decrementGrade(unsigned short n);
	void	incrementGrade(unsigned short n);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif