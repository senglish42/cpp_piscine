/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:30:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 16:30:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
//    const Animal* meta = new Animal();
//    const Animal* j = new Dog();
//    const Animal* i = new Cat();
//
//    std::cout << j->getType() << " " << std::endl;
//    std::cout << i->getType() << " " << std::endl;
//    i->makeSound(); //will output the cat sound!
//    j->makeSound();
//    meta->makeSound();
//    delete i;
//    delete j;
//    delete meta;
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    meta->makeSound();
    delete i;
    delete meta;
    return 0;
}