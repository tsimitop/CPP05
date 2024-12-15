#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	// std::cout << "Intern: Constructor called\n";
}

Intern::Intern(const Intern& other)
{
	// std::cout << "Intern: Copy constructor called\n";
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	// std::cout << "Intern: Copy assignement operator called\n";
	(void) other;
	return (*this);
}

Intern::~Intern()
{
	// std::cout << "Intern: Destructor called\n";
}

AForm	*Intern::createRobotomyRequestForm(const std::string name, const std::string target)
{
	return (new RobotomyRequestForm(name, target));
}

AForm	*Intern::createShrubberyCreationForm(const std::string name, const std::string target)
{
	return (new ShrubberyCreationForm(name, target));
}

AForm	*Intern::createPresidentialPardonForm(const std::string name, const std::string target)
{
	return (new PresidentialPardonForm(name, target));
}

const char*	Intern::UnacceptableFormType::what() const noexcept
{
	return ("EXCEPTION-Intern: Unacceptable form type!\n");
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string formTypes[] = {"RobotomyRequest", "ShrubberyCreation", "PresidentialPardon"};

	AForm	*(Intern::*formCreation[3])(const std::string name, const std::string target) = {
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm,
		&Intern::createPresidentialPardonForm
	};

	for(int i = 0; i < 3; i++)
	{
		if (formTypes[i] == name)
			return (this->*formCreation[i])(name, target);
	}

	std::cout << "No form of type '" << name <<"' found!\n";
	throw Intern::UnacceptableFormType();
}
