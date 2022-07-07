/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:43:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 16:43:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), type("dog")
{
    std::cout << "Hiii! Here is a dooogie-dog." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()
{
    std::cout << "Copy Dog constructor called." << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog &dog)
{
    std::cout << "Copy Dog assignment operator called." << std::endl;
    if (this == &dog)
        return *this;
    this->type = dog.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Bye, " << type << "!" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << type << " says: woof-woof!" << std::endl;
}

std::string Dog::getType() const
{
    return "Look at this " + type;
    //std::cout << "Look at this " << type << std::endl;
}