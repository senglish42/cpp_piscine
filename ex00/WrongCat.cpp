/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:27:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 17:27:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : type("wrong cat")
{
    std::cout << "Hiii! Here is a wrong kittie-cat." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Bye, " << type << "!" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << type << " says: meow-meow!" << std::endl;
}

std::string WrongCat::getType() const
{
    return "Look at this " + type;
    //std::cout << "Look at this " << type << std::endl;
}