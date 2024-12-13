#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name, std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	void	execute(Bureaucrat const & executor) const;
	void	action() const;
};

#endif
