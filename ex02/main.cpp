/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:08:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 18:08:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "time.h"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"

Base *generate(void)
{
    srand(static_cast<unsigned int>(time(0)));
    int num = rand() % 3 + 1;
    switch (num)
    {
        case 1:
            return new A;
        case 2:
            return new B;
        case 3:
            return new C;
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Current class has A type." << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Current class has B type." << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Current class has C type." << std::endl;
    else
        std::cout << "Dynamic cast failed" << std::endl;
    std::cout   << "Just for checking: current class has " << p->getType()
                << " type." << std::endl;
}

void identity(Base& p)
{
    try
    {
        A& check = dynamic_cast<A&>(p);
        (void)check;
        std::cout << "Current class has A type." << std::endl;
    }
    catch (...)
    {
        std::cout << "Dynamic cast of A class is failed." << std::endl;
    }
    try
    {
        B& check = dynamic_cast<B&>(p);
        (void)check;
        std::cout << "Current class has B type." << std::endl;
    }
    catch (...)
    {
        std::cout << "Dynamic cast of B class is failed." << std::endl;
    }
    try
    {
        C& check = dynamic_cast<C&>(p);
        (void)check;
        std::cout << "Current class has C type." << std::endl;
    }
    catch (...)
    {
        std::cout << "Dynamic cast of C class is failed." << std::endl;
    }
    std::cout   << "Just for checking: current class has " << p.getType()
                << " type." << std::endl;
}

int main()
{
    Base *rand = generate();
    if (rand == NULL)
    {
        std::cerr << "Base class cannot be created" << std::endl;
        exit (1);
    }
    identify(rand);
    identity(*rand);
    delete rand;
    return 0;
}