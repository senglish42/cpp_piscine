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

int main()
{
//    const AAnimal animal();       // Cause of AAnimal is an abstract class,
//    animal.getType();             // this would not compile

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    delete i;
    delete j;
//    int a = 0;
//    const Cat* meta[5];
//    const Dog *beta[5];
//
//    for (; a < 5; ++a)
//        meta[a] = new Cat();
//    for (a = 0; a < 5; ++a)
//        beta[a] = new Dog();
//
//    for (a = 0; a < 5; ++a)
//        std::cout << meta[a]->getType() << " " << std::endl;
//    for (a = 0; a < 5; ++a)
//        std::cout << beta[a]->getType() << " " << std::endl;
//    for (a = 0; a < 5; ++a)
//        meta[a]->makeSound();
//    for (a = 0; a < 5; ++a)
//        beta[a]->makeSound();
//    for (a = 4; a >= 0; --a)
//        delete meta[a];
//    for (a = 4; a >= 0; --a)
//        delete beta[a];
}