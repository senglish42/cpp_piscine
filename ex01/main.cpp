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

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bb("Vasiliy", 30);
        std::cout << bb.getName() << std::endl;
        std::cout << bb.getValue() << std::endl;
        Form f("'Very important'", 30, 20);
        std::cout << f.getName() << " " << f.getExecValue() << std::endl;
        bb.signForm(f);
        std::cout << bb-- << std::endl;
        std::cout << bb << std::endl;
        f.beSigned(bb);
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    std::cout << ".........................." << std::endl;
    Bureaucrat *borya;
    try
    {
        borya = new Bureaucrat("Borya", 1);
        std::cout << borya->getName() << std::endl;
        std::cout << borya->getValue() << std::endl;
        Form f("'To go for a lunch'", 149, 148);
        Form m("'Talk to workmates'", 145, 144);
        m = f;
        Form l(f);
        std::cout   << "....comparison check...." << std::endl;
        std::cout   << f.getName() << " " << m.getName() << " "
                    << l.getName() << std::endl;
        std::cout   << f.getExecValue() << " " << m.getExecValue() << " "
                    << l.getExecValue() << std::endl;
        std::cout << *borya << std::endl;
        Bureaucrat cc(*borya, "_temp");
        std::cout << cc++ << std::endl;
        std::cout << *borya << std::endl;
        delete borya;
        borya = NULL;
    }
    catch (const std::exception &exc)
    {
        delete borya;
        borya = NULL;
        std::cerr << exc.what() << ". Caught a runtime_error!" << std::endl;
    }
    return 0;
}