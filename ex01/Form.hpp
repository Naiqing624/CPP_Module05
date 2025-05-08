/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:15:24 by marvin            #+#    #+#             */
/*   Updated: 2025/05/01 11:15:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
	const std::string	_name;
	bool				_signed;
	const int 			_signGrade;
	const int			_executeGrade;

	public:
	Form(std::string name, const int signGrade, const int executeGrade);
	~Form();
	Form(const Form &other);
	Form &operator = (const Form &other);

	const std::string	&getName() const;
	bool			getSigned() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	
	void	beSigned(Bureaucrat &b);
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif