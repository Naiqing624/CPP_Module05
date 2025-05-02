/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:10:59 by marvin            #+#    #+#             */
/*   Updated: 2025/05/01 21:10:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

static AForm *createShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	t_form	formTable[] = {
		{ "shrubbery creation", createShrubbery },
		{ "robotomy request", createRobotomy },
		{ "presidential pardon", createPresidential }
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formTable[i].target) {
			std::cout << "Intern creates " << formName << std::endl;
			return formTable[i].create(target); 
		}
	}
	throw FormUnknownException();
}

const char	*Intern::FormUnknownException::what() const throw()
{
	return "Intern Exception: Unknown Form";
}