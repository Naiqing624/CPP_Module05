/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:24:08 by marvin            #+#    #+#             */
/*   Updated: 2025/04/27 11:24:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	/*------------Frist test---------------*/
	try
	{
		Bureaucrat	p1("Michael", 50);
		std::cout << p1 << std::endl;
		Form		f1("Document", 20, 20);
		std::cout << f1 << std::endl;
		p1.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------Second test---------------*/
	try
	{
		Bureaucrat	p2("Michael", 29);
		std::cout << p2 << std::endl;
		Form		f2("Document", 30, 1);
		std::cout << f2 << std::endl;
		p2.signForm(f2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}