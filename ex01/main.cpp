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
    int a = 0;
    const Animal* meta[10];

    for (; a < 5; ++a)
        meta[a] = new Dog();
    for (; a < 10; ++a)
        meta[a] = new Cat();

    for (a = 0; a < 10; ++a)
    {
        std::cout   << "............................"
                    << meta[a]->getType()
                    << " #" << a
                    << "............................"
                    << std::endl;
        meta[a]->setThoughts();
        meta[a]->makeSound();
        std::cout << meta[a]->getThoughts() << std::endl;
    }
    for (a = 9; a >= 0; --a)
        delete meta[a];
}