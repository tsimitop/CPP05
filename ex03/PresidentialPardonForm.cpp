#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : \
AForm("PresidentialPardonForm_Default", 145, 137), _target("Target_Default")
{
	// std::cout << "PresidentialPardonForm: Default constuctor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : \
AForm(name, 145, 137), _target(target)
{
	// std::cout << "PresidentialPardonForm: Parameterized constuctor called\n";	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : \
AForm(other), _target(other._target)
{
	// std::cout << "PresidentialPardonForm: Copy constuctor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	// std::cout << "PresidentialPardonForm: Copy assignement operator called\n";
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm: Destructor called\n";
}

void PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if(this->getSigned() == false)
		throw FormIsNotSigned();
	if(executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	this->action();
}

/*
• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/