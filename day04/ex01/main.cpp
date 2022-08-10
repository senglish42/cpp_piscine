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
    {
        int a = 0;
        const Animal *meta[10];

        for (; a < 5; ++a)
            meta[a] = new Dog();
        for (; a < 10; ++a)
            meta[a] = new Cat();

        for (a = 0; a < 10; ++a) {
            std::cout << "............................"
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
    {
        Dog b;
        Dog c;

        b.setThoughts();
        std::cout << ".......BEFORE......." << std::endl;
        std::cout << b.getThoughts() << std::endl;
        std::cout << c.getThoughts() << std::endl;
        c = b;
        std::cout << ".......AFTER......." << std::endl;
        std::cout << b.getThoughts() << std::endl;
        std::cout << c.getThoughts() << std::endl;
    }
    {
        Cat d;
        d.setThoughts();
        Cat e(d);
        std::cout << ".......COMPARISON OF EQUALITY......." << std::endl;
        std::cout << d.getThoughts() << std::endl;
        std::cout << e.getThoughts() << std::endl;
    }
}