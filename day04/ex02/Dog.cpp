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

Dog::Dog() : AAnimal(), type("dog"), _brain(new Brain())
{
    std::cout << "Hiii! Here is a dooogie-dog." << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal(), _brain(new Brain(*copy._brain))
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
    delete _brain;
    _brain = new Brain(*dog._brain);
    return *this;
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