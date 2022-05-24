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

#include "DiamondTrap.hpp"
#include <unistd.h>

void final(ClapTrap &one, ClapTrap &two, DiamondTrap &three, int end)
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

void get_fives(ClapTrap **clapTrap, ScavTrap *scavTrap, DiamondTrap *diamondTrap)
{
    std::string fragTrap = clapTrap[3]->getName();
    clapTrap[0]->five_boost(fragTrap);
    clapTrap[1]->five_boost(fragTrap);
    scavTrap->five_attack(fragTrap);
    diamondTrap->five_attack(fragTrap);
}

void    fight(ClapTrap &clapTrap, DiamondTrap &scavTrap)
{
    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getDamage());
    clapTrap.beRepaired(scavTrap.getHit());
}

void    fight(ClapTrap &clapTrap, ScavTrap &scavTrap)
{
    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getDamage());
    clapTrap.beRepaired(scavTrap.getHit());
}

bool    scav_attack(ClapTrap &one, ClapTrap &two, DiamondTrap &three)
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
        if (!(ClapTrap::_round % 2))
            final(one, two, three, 2);
        return (true);
    }
    fight(one, three);
    fight(two, three);
    return (false);
}

bool    clap_attack(ClapTrap &one, ClapTrap &two, DiamondTrap &three)
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

bool    clap_attack(ClapTrap &one, ClapTrap &two, ScavTrap &three)
{
    if ((one.getEnergy() <= 0 || one.getHit() <= 0) &&
        (two.getEnergy() <= 0 || two.getHit() <= 0))
    {
        if (!(ClapTrap::_round % 2))
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
    while (true)
    {
        std::cout   << "[TYPE ""START"" TO CONTINUE]" << std::endl;
        std::cin >> start;
        if (start == "START")
            break ;
    }
}

void round(ClapTrap **clapTrap)
{
    std::cout << std::endl;
    std::cout   << "Let's begin the #" << ++ClapTrap::_round << " round"
                << std::endl;
    for (int num = 0; num <= 4; ++num)
    {
        clapTrap[num]->getRound();
    }
}

void title()
{
    std::cout   << "It's been a while since human got back to peaceful life. "
                   "Many things happened so far, and some of derived ScavTrap"
                   " and FragTrap robots learnt how to make interracial "
                   "cyborg love. One day there is an unique derived DiamondTrap"
                   " robot had been created. Using its power, one AI "
                   "ScavTrap robot wanted to battle against of humanity again"
                   ". But the thing is that AI DiamondTrap still doesn't know"
                   " which side of its parents is better to choose. Thus, "
                   "another battle just begun."
                << std::endl;
}

int main()
{
    title();
    start();
    ScavTrap Robert("Robert");
    ClapTrap Jared("Jared");
    ClapTrap *Mickey = clapTrap("Mickey");
    FragTrap Carl("Carl");
    DiamondTrap Pietro("Pietro");
    ClapTrap *claps[] = {&Jared, Mickey, &Robert, &Carl,
                         &Pietro};
    while (true)
    {
        round(claps);
        Robert.guardGate();
        if ((clap_attack(*Mickey, Jared, Robert) ||
            clap_attack(Jared, *Mickey,Robert)) && !(ClapTrap::_round % 2))
            break ;
        sleep(1);
        if ((scav_attack(*Mickey, Jared, Robert)) && !(ClapTrap::_round % 2))
            break ;
        sleep(1);
        Pietro.whoAmI();
        Carl.highFivesGuys();
        get_fives(claps, &Robert, &Pietro);
        if (!(ClapTrap::_round % 2))
        {
            Pietro.highFivesGuys();
            get_fives(claps, &Robert, &Pietro);
        }
        else
        {
            Pietro.guardGate();
            if (clap_attack(*Mickey, Jared, Pietro) ||
                clap_attack(Jared, *Mickey,Pietro))
                break ;
            sleep(1);
            if (scav_attack(*Mickey, Jared, Pietro))
                break ;
            sleep(1);
        }
    }
   delete Mickey;
}

