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

Cat::Cat() : AAnimal(), type("cat"), _brain(new Brain())
{
    std::cout << "Hiii! Here is a kittie-cat." << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(), _brain(new Brain(*copy._brain))
{
    std::cout << "Copy Cat constructor called." << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat &cat)
{
    std::cout << "Copy Cat assignment operator called." << std::endl;
    if (this == &cat)
        return *this;
    this->type = cat.type;
    delete _brain;
    _brain = new Brain(*cat._brain);
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Bye, " << type << "!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << type << " says: meow-meow!" << std::endl;
}

std::string Cat::getType() const
{
    return "Look at this " + type;
}