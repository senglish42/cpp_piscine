/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:35:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/28 17:35:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"
#include <cstdlib>

Zombie* zombieHorde( int N, std::string &name )
{
    int num;
    Zombie *zombie = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        num = rand() % 5 + 1;
        if (num == 1)
            name = "Eugene";
        else if (num == 2)
            name = "Clare";
        else if (num == 3)
            name = "Rick";
        else if (num == 4)
            name = "Negan";
        else
            name = "Daryl";
        zombie[i].set_name(name, i);
        zombie[i].announce();
    }
    return zombie;
}