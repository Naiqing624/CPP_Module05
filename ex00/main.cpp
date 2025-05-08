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

int	main(void)
{
	try
	{
		Bureaucrat	p1("Aslan", 50);
		std::cout << p1 << std::endl;
		p1.decreGrade();
		std::cout << p1 << std::endl;
		// Bureaucrat	p2("kekel2", 550);
		// std::cout << p2 << std::endl;
		// Bureaucrat	p3(p1);
		// std::cout << p3 << std::endl;
		Bureaucrat	p4("Simba", 1);
		p4.decreGrade();
		std::cout << p4 << std::endl;
		p4.increGrade();
		std::cout << p4 << std::endl;
		p4.increGrade();
		std::cout << p4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}