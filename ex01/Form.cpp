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

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, const int signGrade, const int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	this->_signed = false;
	if (this->_executeGrade < 1 || this->_signGrade < 1)
		throw GradeTooHighException();
	else if (this->_executeGrade > 150 || this->_signGrade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{

}

Form::Form(const Form &other)
	: _name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_executeGrade(other._executeGrade)
{

}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_signed = other.getSigned();
	}
	return (*this);
}

const std::string	&Form::getName() const
{
	return this->_name;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

int	Form::getSignGrade() const
{
	return this->_signGrade;
}

int	Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

void	Form::beSigned(Bureaucrat &b)
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

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << form.getName();
	out << ", sign grade => ";
	out << form.getSignGrade();
	out << ", execute grade => ";
	out << form.getExecuteGrade();
	return (out);
}