/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:41:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 16:41:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("animal")
{
    std::cout << "Hiii! Here is an animal." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Bye, " << type << "!" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Copy Animal constructor called." << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal &animal)
{
    std::cout << "Copy Animal assignment operator called." << std::endl;
    if (this == &animal)
        return *this;
    this->type = animal.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << type << " says: @#%&?!" << std::endl;
}

std::string Animal::getType() const
{
    return "Look at this " + type;
    //std::cout << "Look at this " << type << std::endl;
}