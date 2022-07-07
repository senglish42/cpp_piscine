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

void AAnimal::makeSound() const
{
    std::cout << type << " says: @#%&?!" << std::endl;
}

std::string AAnimal::getType() const
{
    return "Look at this " + type;
}