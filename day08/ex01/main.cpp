/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:33:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/29 16:33:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(10000);
        sp.fillArray();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &exc)
    {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
    std::cout << ".............................." << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(1);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &exc)
    {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
    std::cout << ".............................." << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        Span sp1 = Span(3);
        sp1.addNumber(10);
        sp1.addNumber(9);
        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;
        sp1 = sp;
        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;
        Span sp2(sp1);
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception &exc)
    {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
    std::cout << ".............................." << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(45);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &exc)
    {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
    return 0;
}