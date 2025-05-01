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
		p1.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------Second test---------------*/
	try
	{
		Bureaucrat	p2("Michael", 30);
		std::cout << p2 << std::endl;
		Form		f2("Document", 29, 1);
		p2.signForm(f2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}