/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:24:58 by marvin            #+#    #+#             */
/*   Updated: 2025/04/27 11:24:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() 
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &other) 
{
	if (this != &other) 
	{
		this->_grade = other.getGrade();
		if (this->_grade < 1)
			throw GradeTooHighException();
		else if (this->_grade > 150)
			throw GradeTooLowException();
	}
	return *this;
}

const std::string	&Bureaucrat::getName() const 
{
	return this->_name;
}

int	Bureaucrat::getGrade() const 
{
	return this->_grade;
}

void	Bureaucrat::increGrade() 
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::decreGrade() 
{
	this->_grade += 1;
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw () 
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw () 
{
	return "Grade too low";
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat) 
{
	out << bureaucrat.getName();
	out << ", bureaucrat grade ";
	out << bureaucrat.getGrade();
	return (out);
}