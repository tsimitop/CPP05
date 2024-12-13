#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string name, std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const & executor) const;
	void	action() const;
};

#endif
