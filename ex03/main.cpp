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
#include "Intern.hpp"

int	main(void)
{
    Intern intern;
    Bureaucrat boss("Aslan", 1); 

    std::cout << "===== ShrubberyCreationForm =====" << std::endl;
    AForm* f1 = intern.makeForm("shrubbery creation", "Garden");
	try
	{
		    if (f1)
		    {
		        boss.signForm(*f1);
		        boss.executeForm(*f1);
		        delete f1;
		    }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << "\n===== RobotomyRequestForm =====" << std::endl;
	try
	{
		    AForm* f2 = intern.makeForm("robotomy request", "Bender");
		    if (f2)
		    {
		        boss.signForm(*f2);
		        boss.executeForm(*f2);
		        delete f2;
		    }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << "\n===== PresidentialPardonForm =====" << std::endl;
	try
	{
		    AForm* f3 = intern.makeForm("presidential pardon", "Trillian");
		    if (f3)
		    {
		        boss.signForm(*f3);
		        boss.executeForm(*f3);
		        delete f3;
		    }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


    std::cout << "\n===== Form no exist =====" << std::endl;
	try
	{
		intern.makeForm("banana pizza request", "Nobody");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}
