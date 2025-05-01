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

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
	const std::string	_target;
	const std::string	_name;
	bool				_signed;
	const int 			_signGrade;
	const int			_executeGrade;

	public:
	AForm(const std::string &name, const std::string &target, const int signGrade, const int executeGrade);
	virtual	~AForm();
	AForm(const AForm &other);
	AForm &operator = (const AForm &other);

	const std::string	&getName() const;
	const std::string	&getTarget() const;
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

	class FormNotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	
	void			beSigned(Bureaucrat &b);
	void			execute(Bureaucrat const &executor) const;
	virtual void	action(Bureaucrat const &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &out, const AForm &aform);

#endif