/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:30:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/25 14:30:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <cmath>

int main()
{
    Array<int> first(7);
    try
    {
        for (int i = 0; i < 7; ++i)
            first[i] = i * 10;
    }
    catch(std::exception& e)
    {
        std::cerr << "Index of the element is out of bounds." << '\n';
    }
    std::cout << first.size() << std::endl;
    print_arr(first);
    Array<std::string> second(2);
    std::cout << second.size() << std::endl;
    try
    {
        second[0] = "Ludovico";
        second[1] = "Einaudi";
        second[2] = "pianist";
    }
    catch(std::exception& e)
    {
        std::cerr << "Index of the element is out of bounds." << '\n';
    }
    print_arr(second);
    Array<float> third(13);
    std::cout << third.size() << std::endl;
    try
    {
        for (int i = 1; i < 13; ++i)
            third[i] = static_cast<float>(third[i - 1] + M_PI);
    }
    catch(std::exception& e)
    {
        std::cerr << "Index of the element is out of bounds." << '\n';
    }
    print_arr(third);
    Array<double> fourth(13);
    std::cout << fourth.size() << std::endl;
    try
    {
        for (int i = 1; i < 13; ++i)
            fourth[i] = fourth[i - 1] - M_PI;
    }
    catch (std::exception& e)
    {
        std::cerr << "Index of the element is out of bounds." << '\n';
    }
    print_arr(fourth);
    Array<char> fifth(26);
    std::cout << fifth.size() << std::endl;
    try
    {
        for (int i = 0; i < 27; ++i)
            fifth[i] = static_cast<char>(65 + i);
    }
    catch (std::exception& e)
    {
        std::cerr << "Index of the element is out of bounds." << '\n';
    }
    print_arr(fifth);
    Array<double> sixth(2);
    sixth = fourth;
    std::cout << sixth.size() << std::endl;
    print_arr(sixth);
    Array<char> seventh(fifth);
    std::cout << seventh.size() << std::endl;
    print_arr(seventh);
}