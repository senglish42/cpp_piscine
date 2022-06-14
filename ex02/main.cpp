/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:36:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/26 11:36:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bb("Vasiliy", 136);
        std::cout << bb.getName() << std::endl;
        std::cout << bb.getValue() << std::endl;
        ShrubberyCreationForm Declaration("Refinement", "5th district");
        Declaration.Form::beSigned(bb);
        Declaration.Form::signForm(bb);
        bb.executeForm(Declaration);
        std::cout << bb-- << std::endl;
        std::cout << bb << std::endl;
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    std::cout << ".........................." << std::endl;
    Bureaucrat *borya;
    try
    {
        borya = new Bureaucrat("Borya", 30);
        std::cout << borya->getName() << std::endl;
        std::cout << borya->getValue() << std::endl;
        std::cout << *borya << std::endl;
        Bureaucrat cc(*borya, "_temp");
        std::cout << cc++ << std::endl;
        std::cout << *borya << std::endl;
        RobotomyRequestForm Rob("Robotomy", "Little Puppy");
        Rob.Form::beSigned(*borya);
        Rob.Form::signForm(*borya);
        borya->executeForm(Rob);

        delete borya;
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    std::cout << ".........................." << std::endl;
    try
    {
        Bureaucrat stuff("George", 1);
        std::cout << stuff.getName() << std::endl;
        std::cout << stuff.getValue() << std::endl;
        PresidentalPardonForm President("Audience", "Bob Dylan");
        President.Form::beSigned(stuff);
        President.Form::signForm(stuff);
        stuff.executeForm(President);
        std::cout << stuff++ << std::endl;
        std::cout << stuff << std::endl;
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    return 0;
}