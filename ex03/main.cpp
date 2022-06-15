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
        Form* form;
        form = kid.makeForm("shrubbery creation", "5th district");
        kid.keep_form = form;
        form->beSigned(bb);
        form->signForm(bb);
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
        borya = new Bureaucrat("Borya", 80);
        std::cout << borya->getName() << std::endl;
        std::cout << borya->getValue() << std::endl;
        std::cout << *borya << std::endl;
        Bureaucrat cc(*borya, "_temp");
        std::cout << cc++ << std::endl;
        std::cout << *borya << std::endl;
        Intern kid;
        Form *form;
        form = kid.makeForm("robotomy request", "little puppy");
        kid.keep_form = form;
        form->beSigned(*borya);
        form->signForm(*borya);
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
        Form *form;
        form = kid.makeForm("presidental pardon", "Bob Dylan");
        kid.keep_form = form;
        form->beSigned(stuff);
        form->signForm(stuff);
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
        Form *form;
        form = kid.makeForm("hook", "Paul's mom");
        kid.keep_form = form;
        form->beSigned(dumb);
        form->signForm(dumb);
        dumb.executeForm(*form);
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    return 0;
}