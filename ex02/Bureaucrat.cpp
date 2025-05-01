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
#include "AForm.hpp"

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

void	Bureaucrat::increGrade(int num) 
{
	this->_grade -= num;
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::decreGrade(int num) 
{
	this->_grade += num;
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

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " beacause " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't executed " << form.getName() << " beacause " << e.what() << std::endl;
	}
	
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat) 
{
	out << bureaucrat.getName();
	out << ", bureaucrat grade ";
	out << bureaucrat.getGrade();
	return (out);
}