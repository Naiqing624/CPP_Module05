/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:15:04 by marvin            #+#    #+#             */
/*   Updated: 2025/05/01 11:15:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, const std::string &target, const int signGrade, const int executeGrade)
	: _target(target), 
	_name(name),
	_signGrade(signGrade),
	_executeGrade(executeGrade)
{
	this->_signed = false;
	if (this->_executeGrade < 1 || this->_signGrade < 1)
		throw GradeTooHighException();
	else if (this->_executeGrade > 150 || this->_signGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{

}

AForm::AForm(const AForm &other)
	: 	_target(other._target),
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_executeGrade(other._executeGrade)
{

}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_signed = other.getSigned();
	}
	return (*this);
}

const std::string	&AForm::getName() const
{
	return this->_name;
}

const std::string	&AForm::getTarget() const
{
	return this->_target;
}

bool	AForm::getSigned() const
{
	return this->_signed;
}

int	AForm::getSignGrade() const
{
	return this->_signGrade;
}

int	AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form exception: Grade Too High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form exception: Grade Too Low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form exception: Unsigned Form");
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getSignGrade())
	{
		throw GradeTooLowException();
	}
	else
	{
		this->_signed = true;
	}
}


void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() <= this->getExecuteGrade())
	{
		this->action(executor);
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &out, const AForm &aform)
{
	out << aform.getName();
	out << ", sign grade => ";
	out << aform.getSignGrade();
	out << ", execute grade => ";
	out << aform.getExecuteGrade();
	return (out);
}