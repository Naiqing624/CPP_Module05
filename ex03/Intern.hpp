/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:10:58 by marvin            #+#    #+#             */
/*   Updated: 2025/05/01 21:10:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
	public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	
	AForm	*makeForm(const std::string &formName, const std::string &target);

	class FormUnknownException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

typedef struct s_form
{
	std::string target;
	AForm *(*create)(const std::string &target);
}	t_form;


#endif