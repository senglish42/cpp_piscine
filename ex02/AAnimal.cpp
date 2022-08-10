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

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("animal")
{
    std::cout << "Hiii! Here is an animal." << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Bye, " << type << "!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std::cout << "Copy Animal constructor called." << std::endl;
    *this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal &animal)
{
    std::cout << "Copy Animal assignment operator called." << std::endl;
    if (this == &animal)
        return *this;
    this->type = animal.type;
    return *this;
}

void AAnimal::makeSound() const
{
    std::cout << type << " says: @#%&?!" << std::endl;
}

std::string AAnimal::getType() const
{
    return "Look at this " + type;
}