/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:39:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/06 12:39:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void fight(ClapTrap &one, ClapTrap &two)
{
    one.beRepaired(two.getHit());
    one.attack(two.getName());
    two.takeDamage(one.getDamage());
}

void loser(ClapTrap &one, ClapTrap &two)
{
    if (one.getEnergy() <= 0)
        one.noEnergy();
    if (one.getHit() <= 0)
        one.noHit();
    two.winner(one);
}

int main()
{
    ClapTrap Jared("Jared");
    ClapTrap *Mickey;

    Mickey = clapTrap("Mickey");

    while (1) {
        Mickey->getRound(Jared);
        if (Mickey->getEnergy() <= 0 || Mickey->getHit() <= 0)
        {
            loser(*Mickey, Jared);
            break ;
        }
        fight(*Mickey, Jared);
        if (Jared.getEnergy() <= 0 || Jared.getHit() <= 0)
        {
            loser(Jared, *Mickey);
            break;
        }
        fight(Jared, *Mickey);
    }
    delete Mickey;
}

