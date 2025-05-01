/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:46:34 by marvin            #+#    #+#             */
/*   Updated: 2025/05/01 12:46:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", target, 75, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade())
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
	return (*this);
}

void	RobotomyRequestForm::action(Bureaucrat const &executor) const
{
	srand(time(NULL));
	std::cout << "* Drilling noises... Bzzzzzzzz... * " << std::endl;
	if (rand() % 2  == 0)
	{
		std::cout << this->getTarget() << " has been robotomized succesfully by " << executor.getName() << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed on " << this->getTarget() << std::endl;
	}
}