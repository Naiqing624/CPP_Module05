/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:45:50 by marvin            #+#    #+#             */
/*   Updated: 2025/05/01 12:45:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade())
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return (*this);
}

void	ShrubberyCreationForm::action(Bureaucrat const &executor) const
{
	std::ofstream	outfile;

	outfile.open((this->getTarget() + "_Shrubbery").c_str(), std::ios::out | std::ofstream::trunc);
	outfile << "    v .   ._, |_  .,            " << std::endl;
	outfile << "    `-._\\/  .  \\ /    |/_         " << std::endl;
	outfile << "        \\\\  _\\\\, y | \\//           " << std::endl;
	outfile << " _\\\\_.___\\\\, \\\\/ -.\\||             " << std::endl;
	outfile << "    `7-,--.`._||  / / ,         " << std::endl;
	outfile << "    /'     `-. `./ / |/_.       " << std::endl;
	outfile << "            |    |//            " << std::endl;
	outfile << "            |_    /             " << std::endl;
	outfile << "            |-   |              " << std::endl;
	outfile << "            |   =|              " << std::endl;
	outfile << "            |    |              " << std::endl;
	outfile << "-----------/ ,  . \\--------._   " << std::endl;
	outfile << "Signed by " << executor.getName() << std::endl;
}