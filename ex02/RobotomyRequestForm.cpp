#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : \
AForm("RobotomyRequestForm_Default", 72, 45), _target("Target_Default")
{
	std::cout << "RobotomyRequestForm: Default constuctor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : \
AForm(name, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm: Parameterized constuctor called\n";	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : \
AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm: Copy constuctor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm: Copy assignement operator called\n";
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Destructor called\n";
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	std::cout << "Drrrrrrrrrrrrrrrilling noises...\n";
	(void) executor;

	// srand(static_cast<unsigned int>(time(0))); // if issue
	srand(time(0)); // simpler
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!\n";
	else
		std::cout << "The robotomy of " << _target << " failed!\n";
}

/*
• RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.
*/
