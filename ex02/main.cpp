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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "--------Frist test----------" << std::endl;
	try
	{
		Bureaucrat	p1("Michael", 50);
		std::cout << p1 << std::endl;
		ShrubberyCreationForm form1("garden");
		std::cout << form1 << std::endl;
		p1.signForm(form1);
		p1.executeForm(form1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------Second test----------" << std::endl;
	try
	{
		Bureaucrat p2("Aslan", 1);
		std::cout << p2 << std::endl;
		RobotomyRequestForm form2("Bender");
		std::cout << form2 << std::endl;
		p2.signForm(form2);
		p2.executeForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------Third test----------" << std::endl;
	try
	{
		Bureaucrat p3("Simba", 10);
		std::cout << p3 << std::endl;
		PresidentialPardonForm form3("Cyber");
		std::cout << form3 << std::endl;
		p3.signForm(form3);
		p3.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}