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
#include <stdexcept>

int main()
{
    try
    {
        Bureaucrat bb("bb", 150);
        std::cout << bb.getName() << std::endl;
        std::cout << bb.getValue() << std::endl;
        Bureaucrat aa(bb, "_temp");
        std::cout << aa << std::endl;
        std::cout << aa-- << std::endl;
        std::cout << bb << std::endl;
    }
    catch (std::runtime_error& err)
    {
        std::cout << err.what() << " Caught a runtime_error!" << std::endl;
    }
    Bureaucrat *borya;
    try
    {
        borya = new Bureaucrat("Borya", 1);
        std::cout << borya->getName() << std::endl;
        std::cout << borya->getValue() << std::endl;
        std::cout << *borya << std::endl;
        Bureaucrat cc(*borya, "_temp");
        std::cout << cc++ << std::endl;
        std::cout << *borya << std::endl;
        delete borya;
    }
    catch (std::runtime_error& err)
    {
        std::cout << err.what() << " Caught a runtime_error!" << std::endl;
        delete borya;
    }
    return 0;
}