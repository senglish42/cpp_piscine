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
        ShrubberyCreationForm Declaration("5th district");
        Declaration.Form::beSigned(bb);
        bb.signForm(Declaration);
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
        RobotomyRequestForm Rob("Little Puppy");
        Rob.Form::beSigned(*borya);
        borya->signForm(Rob);
        borya->executeForm(Rob);

        delete borya;
        borya = NULL;
    }
    catch (const std::exception &exc)
    {
        delete borya;
        borya = NULL;
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    std::cout << ".........................." << std::endl;
    try
    {
        Bureaucrat stuff("George", 1);
        std::cout << stuff.getName() << std::endl;
        std::cout << stuff.getValue() << std::endl;
        PresidentalPardonForm President("Bob Dylan");
        President.Form::beSigned(stuff);
        stuff.signForm(President);
        stuff.executeForm(President);
        PresidentalPardonForm Pres(President);
        std::cout << "....copy check...." << std::endl;
        std::cout << President.getName() << " " << Pres.getName() << std::endl;
        PresidentalPardonForm Presi("George Bush");
        std::cout << "...checking BEFORE assignment..." << std::endl;
        std::cout << "Target(const): " << President.getTarget() << " status: "
                  << President.getStatus() << std::endl;
        std::cout << "Target(const): " << Presi.getName() << " status: "
                  << Presi.getStatus() << std::endl;
        Presi = President;
        std::cout << "...checking AFTER assignment operator..." << std::endl;
        std::cout << "Target(const): " << President.getTarget() << " status: "
                  << President.getStatus() << std::endl;
        std::cout << "Target(const): " << Presi.getTarget() << " status: "
                  << Presi.getStatus() << std::endl;
        std::cout << stuff++ << std::endl;
        std::cout << stuff << std::endl;
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    return 0;
}