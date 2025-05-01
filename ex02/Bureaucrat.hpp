/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:24:29 by marvin            #+#    #+#             */
/*   Updated: 2025/04/27 11:24:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat 
{
	private:
	const std::string	_name;
	int					_grade;

	public:
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator = (const Bureaucrat &other);
	
	const std::string	&getName() const;
	int		getGrade() const;
	void	increGrade(int num);
	void	decreGrade(int num);

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
	

	void	signForm(AForm &f);
	void	executeForm(AForm &form);
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif