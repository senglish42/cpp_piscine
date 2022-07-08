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

#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat bb("Vasiliy", 146);
        std::cout << bb.getName() << std::endl;
        std::cout << bb.getValue() << std::endl;
        Intern kid;
        Form* form = kid.makeForm("shrubbery creation", "5th district");
        kid.setForm(form);
        form->beSigned(bb);
        bb.signForm(*form);
        bb.executeForm(*form);
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
        Intern kid;
        Form *form = kid.makeForm("robotomy request", "little puppy");
        kid.setForm(form);
        form->beSigned(*borya);
        borya->signForm(*form);
        borya->executeForm(*form);
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
        Intern kid;
        Form *form = kid.makeForm("presidental pardon", "Bob Dylan");
        kid.setForm(form);
        stuff.signForm(*form);
        stuff.executeForm(*form);
        std::cout << stuff++ << std::endl;
        std::cout << stuff << std::endl;
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    std::cout << ".........................." << std::endl;
    try
    {
        Bureaucrat dumb("Stiffler", 100);
        Intern kid;
        Form *form = kid.makeForm("hook", "Paul's mom");
        kid.setForm(form);
        form->beSigned(dumb);
        dumb.signForm(*form);
        dumb.executeForm(*form);
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    return 0;
}