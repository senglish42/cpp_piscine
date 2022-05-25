/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:28:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 17:28:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrong animal")
{
    std::cout << "Hiii! Here is a wrong animal." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Bye, " << type << "!" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << type << " says: @#%&?!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return "Look at this " + type;
    //std::cout << "Look at this " << type << std::endl;
}