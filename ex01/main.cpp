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

#include "ScavTrap.hpp"
#include <unistd.h>

void final(ClapTrap &one, ClapTrap &two, ScavTrap &three, int end)
{
    if (end == 1)
    {
        std::cout   << "ClapTrap <" << one.getName() << "> and ClapTrap <"
                    << two.getName() << "> lost the battle against of "
                    << "ScavTrap <" << three.getName()
                    << ">. All of humanity unborn and destroyed."
                    << std::endl;
    }
    else
    {
        std::cout   << "ClapTrap <" << one.getName() << "> and ClapTrap <"
                    << two.getName() << "> won the battle against of "
                    << "ScavTrap <" << three.getName()
                    << ">. All of humanity has got another chance to survive."
                    << std::endl;
    }
}

void loser(ClapTrap &one, ClapTrap &two, ScavTrap &three)
{
    bool Clap1 = false;
    bool Clap2 = false;

    if (one.getEnergy() <= 0)
        one.noEnergy(Clap1);
    if (one.getHit() <= 0)
        one.noHit(Clap1);
    if (two.getEnergy() <= 0)
        two.noEnergy(Clap2);
    if (two.getHit() <= 0)
        two.noHit(Clap2);
    if (Clap1 && Clap2)
        final(one, two, three, 1);
}

void    fight(ClapTrap &clapTrap, ScavTrap &scavTrap)
{
    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getDamage());
    clapTrap.beRepaired(scavTrap.getHit());
}

bool    scav_attack(ClapTrap &one, ClapTrap &two, ScavTrap &three)
{
    int energy = three.getEnergy();
    int hit = three.getHit();

    if (energy <= 0 || hit <= 0)
    {
        if (energy <= 0)
            three.noEnergy();
        else
            three.noHit();
        final(one, two, three, 2);
        return (true);
    }
    fight(one, three);
    fight(two, three);
    return (false);
}

bool    clap_attack(ClapTrap &one, ClapTrap &two, ScavTrap &three)
{
    if ((one.getEnergy() <= 0 || one.getHit() <= 0) &&
        (two.getEnergy() <= 0 || two.getHit() <= 0))
    {
        loser(one, two, three);
        return (true);
    }
    one.attack(three.getName());
    three.takeDamage(one.getDamage());
    three.beRepaired(one.getHit());
    return (false);
}

void start()
{
    std::string start;

    sleep(1);
    while (1)
    {
        std::cout   << "[TYPE ""START"" TO CONTINUE]" << std::endl;
        std::cin >> start;
        if (start == "START")
            break ;
    }
}

void title()
{
    std::cout   << "The worldwide is splited by two parts and both are "
                 "depleting sources in needs of war. Humans are not fighting "
                 "but creating ClapTrap cyborgs to battle against each other."
                 " But one day a derived AI ScavTrap robot had been created "
                 "and found out destroying the world is the only way to "
                 "finish war. Thus, human beings are united again, to versus "
                 "their ClapTraps against ScavTrap. Let it begin."
                << std::endl;
}

int main()
{
    title();
    start();
    ScavTrap Robert("Robert");
    ClapTrap Jared("Jared");
    ClapTrap *Mickey = clapTrap("Mickey");

    while (1) {
        Mickey->getRound(Jared);
        Robert.getRound();
        Robert.guardGate();
        if (clap_attack(*Mickey, Jared, Robert) ||
            clap_attack(Jared, *Mickey,Robert))
            break ;
        sleep(1);
        if (scav_attack(*Mickey, Jared, Robert))
            break ;
        sleep(1);
    }
    delete Mickey;
}

