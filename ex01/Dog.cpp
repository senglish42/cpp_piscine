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

Dog::Dog() : type("dog"), _brain(new Brain())
{
    std::cout << "Hiii! Here is a dooogie-dog." << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Bye, " << type << "!" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << type << " says: woof-woof!" << std::endl;
}

std::string Dog::getType() const
{
    return "Look at this " + type;
}

void Dog::setThoughts() const
{
    int num = rand() % 3;
    if (num == 1)
        _brain->setThoughts("Who Let The Dogs Out? Woof-woof-woof-woof.");
    else if (num == 2)
        _brain->setThoughts("rub against the leg...intensively.");
    else
        _brain->setThoughts("Sometimes it seems that me and other"
                            " fluffy creatures woofing to me are kinda same. "
                            "What if we could unite to get a society where "
                            "everyone life matter...");
}

const std::string& Dog::getThoughts() const
{
    return _brain->getThoughts();
}