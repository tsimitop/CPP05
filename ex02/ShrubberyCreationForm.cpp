#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : \
AForm("ShrubberyCreationForm_Default", 25, 5), _target("Target_Default")
{
	std::cout << "ShrubberyCreationForm: Default constuctor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : \
AForm(name, 25, 5), _target(target)
{
	std::cout << "ShrubberyCreationForm: Parameterized constuctor called\n";	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : \
AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm: Copy constuctor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm: Copy assignement operator called\n";
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Destructor called\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream	file(_target + "_shrubbery", std::ios::trunc);

	(void) executor;
	if(!file)
		std::cout << _target << "_shrubbery: file failed to open\n";
	else
	{
		file << "Ascii trees\n";
		file.close();
	}
}
/*
• ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.
*/

	//empties filename.replace
	// std::ofstream tempFile(filenameReplaced, std::ios::trunc);
	// if(!tempFile)
	// 	std::cout << argv[1] << ": tempFile failed to open" << std::endl;
	// tempFile.close();