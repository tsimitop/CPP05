#ifndef INTERN_H
#define INTERN_H

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	// static std::string	formNames[3];
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm	*makeForm(std::string name, std::string target);

	AForm	*createRobotomyRequestForm(const std::string name, const std::string target);
	AForm	*createShrubberyCreationForm(const std::string name, const std::string target);
	AForm	*createPresidentialPardonForm(const std::string name, const std::string target);

	class	UnacceptableFormType : public std::exception
	{
		public:
			virtual const char* what() const noexcept;
	};
};

#endif
