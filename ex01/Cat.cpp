/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:44:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 16:44:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : type("cat"), _brain(new Brain())
{
    std::cout << "Hiii! Here is a kittie-cat." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Bye, " << type << "!" << std::endl;
    delete _brain;
}

void Cat::makeSound() const
{
    std::cout << type << " says: meow-meow!" << std::endl;
}

std::string Cat::getType() const
{
    return "Look at this " + type;
    //std::cout << "Look at this " << type << std::endl;
}