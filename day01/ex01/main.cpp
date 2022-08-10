/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:35:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/28 17:35:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    std::string name;

    Zombie *zombie;
    zombie = zombieHorde(100, name);
    std::cout   << "FIRST ZOMBIE: #" << zombie->getIndex() << " "
                << zombie->getName() << std::endl;
    delete [] zombie;
    return 0;
}
