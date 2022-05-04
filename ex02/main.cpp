/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:45:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/30 15:45:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main ()
{
    std::string brain = "HI THIS IS BRAIN";

    std::string *stringPTR = &brain;
    std::string &stringREF = brain;
    std::cout   << "The memory address of the string variable: "
                << &brain << std::endl;
    std::cout   << "The memory address held by stringPTR: "
                << &stringPTR << std::endl;
    std::cout   << "The memory address held by stringREF: "
                << &stringREF << std::endl;
    std::cout   << "The value of the string variable: "
                << brain << std::endl;
    std::cout   << "The value pointed to by stringPTR: "
                << *stringPTR << std::endl;
    std::cout   << "The value pointed to by stringREF: "
                << stringREF << std::endl;
    return 0;
}